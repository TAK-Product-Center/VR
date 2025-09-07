// Required Includes
#include "Game_VideoPlayer_VLC.h"
#include "Game.h"

// Engine Includes
#include "Engine/Texture2D.h"

// VH Plugin Includes
#include "Developer_Statics.h"

// Game Includes
#include "Game_VideoPlayer_VLC_Thread.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_VideoPlayer_VLC::UGame_VideoPlayer_VLC() :
	URL(TEXT("")),
	PixelUpdateCooldown(0),
    Texture(nullptr),
    ThreadVLC(nullptr),
	bRenderToTexture(true)
{
	DefaultPixelUpdateCooldown = 0;
}

UGame_VideoPlayer_VLC::~UGame_VideoPlayer_VLC()
{
    if (ThreadVLC != nullptr)
    {
        ThreadVLC->~FGame_VideoPlayer_VLC_Thread();
    }
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_VideoPlayer_VLC::IsTickable() const
{
    return ThreadVLC != nullptr && ThreadVLC->CritSection != nullptr;
}

TStatId UGame_VideoPlayer_VLC::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UGame_VideoPlayer_VLC, STATGROUP_Tickables);
}

void UGame_VideoPlayer_VLC::Tick(float deltaSeconds)
{
	if (ThreadVLC->bQueueVideoEndedDelegate)
	{
		OnVideoEnded.Broadcast(this);
		ThreadVLC->bQueueVideoEndedDelegate = false;
	}

	if (ThreadVLC->bQueueAspectDelegate)
	{
		OnReceivedAspectRatio.Broadcast(ThreadVLC->GetAspectRatio());
		ThreadVLC->bQueueAspectDelegate = false;
	}

	PixelUpdateCooldown = FMath::Clamp<float>(PixelUpdateCooldown - deltaSeconds, 0, FLT_MAX);
	if (bRenderToTexture && PixelUpdateCooldown == 0)
	{
		if (ThreadVLC->CritSection->TryLock())
		{
			UDeveloper_Statics::UpdateTexture2DPixels(GetTexture(), 0, ThreadVLC->FramePixels);

			PixelUpdateCooldown = DefaultPixelUpdateCooldown;

			ThreadVLC->CritSection->Unlock();
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_VideoPlayer_VLC::SetRenderToTexture(bool bRenderToTextureArg)
{
	bRenderToTexture = bRenderToTextureArg;
}

void UGame_VideoPlayer_VLC::SetVolume(float volume)
{
	if (ThreadVLC != nullptr)
	{
		ThreadVLC->SetVolume(volume);
	}
}

void UGame_VideoPlayer_VLC::SetURL(const FString& url)
{
    URL = url;

    if (ThreadVLC == nullptr)
    {
        ThreadVLC = new FGame_VideoPlayer_VLC_Thread();
    }

    ThreadVLC->SetURL(URL);
}

const FString UGame_VideoPlayer_VLC::GetURL() const
{
	return URL;
}

void UGame_VideoPlayer_VLC::SetPause(bool bPause)
{
    if (ThreadVLC != nullptr)
    {
        ThreadVLC->SetPause(bPause);
    }
}

void UGame_VideoPlayer_VLC::PlayVideo()
{
    if (ThreadVLC != nullptr)
    {
        ThreadVLC->PlayVideo();
    }
}

bool UGame_VideoPlayer_VLC::IsPaused() const
{
    if (ThreadVLC != nullptr)
    {
        return ThreadVLC->IsPaused();
    }

    return false;
}

UTexture2D* UGame_VideoPlayer_VLC::GetTexture()
{
    if (Texture == nullptr)
    {
        Texture = UTexture2D::CreateTransient(1024, 1024);  
        Texture->UpdateResource();                          

        TArray<uint8> defaultPixels;
        UDeveloper_Statics::UpdateTexture2DPixels(GetTexture(), 0, defaultPixels);
    }

    return Texture;
}

float UGame_VideoPlayer_VLC::GetAspectRatio() const
{
    if (ThreadVLC != nullptr)
    {
        return ThreadVLC->GetAspectRatio();
    }

    return -1.f;
}

double UGame_VideoPlayer_VLC::GetSecondsElapsed() const
{
    if (ThreadVLC != nullptr)
    {
        return ThreadVLC->GetSecondsElapsed();
    }

    return -1;
}

void UGame_VideoPlayer_VLC::SetSecondsElapsed(double secondsElapsed)
{
    if (ThreadVLC != nullptr)
    {
        return ThreadVLC->SetSecondsElapsed(secondsElapsed);
    }
}