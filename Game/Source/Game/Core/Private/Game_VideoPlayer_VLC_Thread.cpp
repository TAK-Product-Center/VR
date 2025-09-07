// Required Includes
#include "Game_VideoPlayer_VLC_Thread.h"

// Game Includes
#include "Game_VideoPlayer_VLC.h"

static void* lock(void* data, void** pixelsPtr)
{
    FGame_VideoPlayer_VLC_Thread* thread = (FGame_VideoPlayer_VLC_Thread*)data;

    thread->CritSection->Lock();

    *pixelsPtr = thread->FramePixels.GetData();

	thread->CritSection->Unlock();

    return NULL;
}

static void unlock(void* data, void* id, void* const* pixelsPtr)
{
}

static void videoEndedCallback(const struct libvlc_event_t *p_event, void *p_data)
{
	if (FGame_VideoPlayer_VLC_Thread* thread = (FGame_VideoPlayer_VLC_Thread*)p_data)
	{
		thread->bQueueVideoEndedDelegate = true;
	}
}

// ---------------------------------
// --- Constructors
// ---------------------------------

FGame_VideoPlayer_VLC_Thread::FGame_VideoPlayer_VLC_Thread() :
	bQueueVideoEndedDelegate(false),
	bQueueAspectDelegate(false),
	bStopping(false),
    bPendingClean(false),
    URL(TEXT("")),
	NewURL(TEXT("")),
	VLC_Instance(nullptr),
    VLC_MediaPlayer(nullptr),
	VLC_EventManager(nullptr),
	CachedVolume(-1)
{
    CritSection = new FCriticalSection();

    Thread = FRunnableThread::Create(this, *FGuid::NewGuid().ToString());

	FramePixels.Empty();
	FramePixels.AddDefaulted(1024 * 1024 * 4);
}

FGame_VideoPlayer_VLC_Thread::~FGame_VideoPlayer_VLC_Thread()
{
    if (Thread != nullptr)
    {
        Stop();
        Thread->WaitForCompletion();
        delete Thread;
        Thread = nullptr;
    }

    delete CritSection;
    CritSection = nullptr;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool FGame_VideoPlayer_VLC_Thread::Init()
{
    bStopping = false;

    bReceivedAspectRatio = false;

    return true;
}

uint32 FGame_VideoPlayer_VLC_Thread::Run()
{
	while (!bStopping)
	{
		if (!NewURL.IsEmpty())
		{
			if (VLC_Instance == nullptr)
			{
				// setting volume on one media player in libvlc 3.0+ sets volume on all VLC_MediaPlayers; fix is to use directsound
				// https://forum.videolan.org/viewtopic.php?t=147229
				const char* const argv[] = { "--aout=directsound" };

				VLC_Instance = libvlc_new(1, argv);
			}

			libvlc_media_t* media = libvlc_media_new_location(VLC_Instance, TCHAR_TO_ANSI(*NewURL));

			if (VLC_MediaPlayer == nullptr)
			{
				VLC_MediaPlayer = libvlc_media_player_new_from_media(media);

				libvlc_video_set_format(VLC_MediaPlayer, "RV32", 1024, 1024, 1024 * 4);
				libvlc_video_set_callbacks(VLC_MediaPlayer, lock, unlock, nullptr, this);

				VLC_EventManager = libvlc_media_player_event_manager(VLC_MediaPlayer);
				libvlc_event_attach(VLC_EventManager, libvlc_MediaPlayerEndReached, videoEndedCallback, this);
			}
			else
			{
				libvlc_media_player_set_media(VLC_MediaPlayer, media);
			}

			libvlc_media_release(media);

			PlayVideo();

			URL = NewURL;
			NewURL = TEXT("");
		}

		if (CachedVolume != -1)
		{
			float tempVolume = CachedVolume;
			CachedVolume = -1;
			SetVolume(tempVolume);
		}

		if (!bReceivedAspectRatio && VLC_MediaPlayer != nullptr)
		{
			unsigned int width = 0;
			unsigned int height = 0;

			if (libvlc_video_get_size(VLC_MediaPlayer, 0, &width, &height) == 0 && width != 0 && height != 0)
			{
				AspectRatio = ((float)width) / ((float)height);

				bQueueAspectDelegate = true;
				bReceivedAspectRatio = true;
			}
		}
		
		FPlatformProcess::Sleep(0.01);
	}

	return 0;
}

void FGame_VideoPlayer_VLC_Thread::Stop()
{
    bStopping = true;

    CleanupVLC();
}

void FGame_VideoPlayer_VLC_Thread::Exit()
{

}

// ---------------------------------
// --- API
// ---------------------------------

void FGame_VideoPlayer_VLC_Thread::SetURL(const FString& url)
{
    NewURL = url;
}

int32 FGame_VideoPlayer_VLC_Thread::GetVolume() const
{
	if (VLC_MediaPlayer != nullptr)
	{
		return libvlc_audio_get_volume(VLC_MediaPlayer);
	}

	return 0;
}

void FGame_VideoPlayer_VLC_Thread::SetVolume(int32 volume)
{
	if (VLC_MediaPlayer != nullptr)
	{
		libvlc_audio_set_volume(VLC_MediaPlayer, volume);
	}
	else
	{
		CachedVolume = volume;
	}
}

void FGame_VideoPlayer_VLC_Thread::SetPause(bool bPause)
{
    if (VLC_MediaPlayer != nullptr)
    {
        libvlc_media_player_set_pause(VLC_MediaPlayer, bPause);
    }
}

bool FGame_VideoPlayer_VLC_Thread::IsPaused() const
{
    if (VLC_MediaPlayer != nullptr)
    {
        libvlc_state_t state = libvlc_media_player_get_state(VLC_MediaPlayer);

        return state == libvlc_Paused;
    }

    return false;
}

void FGame_VideoPlayer_VLC_Thread::PlayVideo()
{
    if (VLC_MediaPlayer != nullptr)
    {
		bReceivedAspectRatio = false;

        libvlc_media_player_play(VLC_MediaPlayer);
    }
}

float FGame_VideoPlayer_VLC_Thread::GetAspectRatio() const 
{ 
	return AspectRatio;
}

bool FGame_VideoPlayer_VLC_Thread::IsAspectRatioSet() const 
{ 
	return bReceivedAspectRatio; 
}

double FGame_VideoPlayer_VLC_Thread::GetSecondsElapsed() const
{
	if (VLC_MediaPlayer != nullptr)
	{
		return libvlc_media_player_get_time(VLC_MediaPlayer) / 1000.0;
	}

	return -1;
}

void FGame_VideoPlayer_VLC_Thread::SetSecondsElapsed(double secondsElapsed)
{
	if (VLC_MediaPlayer != nullptr)
	{
		libvlc_media_player_set_time(VLC_MediaPlayer, secondsElapsed * 1000);
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void FGame_VideoPlayer_VLC_Thread::CleanupVLC()
{
    if (VLC_MediaPlayer != nullptr)
    {
        libvlc_media_player_release(VLC_MediaPlayer);

        VLC_MediaPlayer = nullptr;
    }

    if (VLC_Instance != nullptr)
    {
        libvlc_release(VLC_Instance);

        VLC_Instance = nullptr;
    }

    CritSection->Lock();

	FramePixels.Empty();
	FramePixels.AddDefaulted(1024 * 1024 * 4);

    CritSection->Unlock();
}
