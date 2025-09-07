// Required Includes
#include "VH_TAKVideoPlayer.h"
#include "VH_COT.h"

// Engine Includes
#include "Misc/Paths.h"
#include "Rendering/Texture2DResource.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"
#include "Engine/Texture2D.h"
#include "RenderingThread.h"

// VH Plugin includes
#include "Developer_Statics.h"
#include "VH_COTDetail_Video.h"
#include "VH_URI.h"

using PGSCMedia::VideoMediaFormat;
using PGSCMedia::MediaFormatConvert;
using PGSCMedia::MediaProcessor;
using PGSCMedia::MediaFormat;
using PGSCMedia::MediaException;
using std::vector;
using std::ifstream;

// ---------------------------------
// --- Constructors
// ---------------------------------

UVH_TAKVideoPlayer::UVH_TAKVideoPlayer() :
	AspectRatio(-1.f),
	Media(nullptr),
	Texture(nullptr),
	bAspectRatioReceived(false),
	bAspectRatioSent(false),
	bIsPaused(true),
	bIsVideoLoaded(false),
	LicenseDirectory(FPaths::RootDir() / TEXT("Data") / TEXT("Gv2F") / TEXT("gv2f.lic"))
{
	if (CritSection == nullptr)
	{
		CritSection = new FCriticalSection();
	}

	FramePixels.Empty();
	// the 4 determines how many channels the video is using for colors for individual pixels
	FramePixels.AddDefaulted(1024 * 1024 * 4);
}

// ---------------------------------
// --- Destructor
// ---------------------------------

UVH_TAKVideoPlayer::~UVH_TAKVideoPlayer()
{
	if (Media != nullptr)
	{
		MediaProcessor::destroyProcessor(Media);
		Media = nullptr;
	}

	if (CritSection != nullptr)
	{
		delete CritSection;
		CritSection = nullptr;
	}
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

bool UVH_TAKVideoPlayer::IsVideoSupported(const FString& fullPathToFile)
{
	if (UVH_TAKVideoPlayer* videoPlayer = NewObject<UVH_TAKVideoPlayer>())
	{
		if (videoPlayer->Initialize())
		{
			return videoPlayer->CreateVideoFromURL(fullPathToFile);
		}
	}

	return false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVH_TAKVideoPlayer::Tick(float deltaSeconds)
{
	if (!bIsPaused)
	{
		if (bAspectRatioSent == false && bAspectRatioReceived == true)
		{
			OnAspectRatioUpdate.Broadcast(AspectRatio);

			bAspectRatioSent = true;
		}

		if (CritSection != nullptr)
		{
			if (CritSection->TryLock())
			{
				if (UTexture2D* videoFrameTexture = GetTexture())
				{
					UpdateTexture2DPixels(videoFrameTexture, 0, FramePixels);
				}
				else
				{
					UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Tick() -- The videoFrameTexture is nullptr."));
				}

				CritSection->Unlock();
			}
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Tick() -- The CritSection is nullptr."));
		}
	}
}

bool UVH_TAKVideoPlayer::IsTickable() const
{
	return true;
}

void UVH_TAKVideoPlayer::mediaVideoFrame(const VideoFrameData *frame)
{
	if (frame != nullptr)
	{
		if (!bAspectRatioReceived)
		{
			VideoSize = FVector2D((float)frame->width, (float)frame->height);

			AspectRatio = VideoSize.X / VideoSize.Y;

			bAspectRatioReceived = true;
		}

		if (VideoMediaFormat* vidFmt = new VideoMediaFormat(0, frame->pixel_format, 1.f, frame->width, frame->height))
		{
			if (MediaFormatConvert* converter = new MediaFormatConvert(*vidFmt, MediaPixelFormat::PIXELS_RGB_PACKED))
			{
				// temporary frame buffer to handle operations
				TArray<uint8> frameBuffer;

				try
				{
					converter->setScaleForAspect(false);
					converter->setScaleOutputSize(1024, 1024);
					
					frameBuffer.AddDefaulted(converter->getRequiredBufferSize());

					// this sets where the converter should put it's frame data when using the "convert" method
					converter->setOutputBuffer(frameBuffer.GetData(), converter->getRequiredBufferSize());

					// this will convert the frame to the desired "MediaFormatConvert" settings and set it to the buffer set in the setOutputBuffer method above
					converter->convert(frame);
				}
				catch (MediaException)
				{
					UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::mediaVideoFrame() -- A MediaException was caught while trying to setup and convert a frame."));
				}

				if (CritSection != nullptr)
				{
					// put a lock here
					CritSection->Lock();

					FramePixels.Empty();
					FramePixels.Append(frameBuffer);

					// unlock here
					CritSection->Unlock();
				}
				else
				{
					UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::mediaVideoFrame() -- The CritSection is nullptr."));
				}

				delete converter;
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::mediaVideoFrame() -- The converter is nullptr."));
			}

			delete vidFmt;
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::mediaVideoFrame() -- The vidFmt is nullptr."));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::mediaVideoFrame() -- The frame parameter is nullptr."));
	}
}

void UVH_TAKVideoPlayer::mediaKLVData(KLVData *data)
{
	// do something with KLV data here

	FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UVH_TAKVideoPlayer::mediaKLVData"));
}

void UVH_TAKVideoPlayer::mediaEOF(void)
{
	
}

void UVH_TAKVideoPlayer::mediaFatalError(const char *info)
{
	
}

void UVH_TAKVideoPlayer::mediaStreamExtentsUpdate(long startMillis, long endMillis)
{

}

// ---------------------------------
// --- API
// ---------------------------------

bool UVH_TAKVideoPlayer::Initialize()
{
	FString fileData;

	if (FFileHelper::LoadFileToString(fileData, *LicenseDirectory))
	{
		try
		{
			PGSCMediaInit(TCHAR_TO_ANSI(*fileData), (unsigned int)fileData.Len());
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Initialize() -- There was an exception thrown when attempting to initializing the Gv2F video player with the license"));
			return false;
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Initialize() -- Failed to load file to string."));
	}

	return true;
}

bool UVH_TAKVideoPlayer::Play()
{
	if (Media != nullptr)
	{
		if (!Media->isProcessing())
		{
			try
			{
				Media->start();
			}
			catch (MediaException)
			{
				UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Play() -- Caught a MediaException when attempting to play the video."));
				return false;
			}

			bIsPaused = false;
			return true;
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Play() -- The Media is already playing."));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Play() -- The Media is nullptr."));
	}

	return false;
}

bool UVH_TAKVideoPlayer::Pause()
{
	if (Media != nullptr)
	{
		if (Media->isProcessing())
		{
			try
			{
				Media->stop();
			}
			catch (MediaException)
			{
				UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Pause() -- Caught a MediaException when attempting to play the video."));
				return false;
			}

			bIsPaused = true;
			return true;
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Pause() -- The Media is already paused."));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Pause() -- The Media is nullptr."));
	}

	return false;
}

float UVH_TAKVideoPlayer::GetTime()
{
	float currentTime = 0.0f;

	if (Media != nullptr)
	{
		try
		{
			currentTime = ((float)Media->getTime() / 1000);
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::GetTime() -- Caught a MediaException when attempting to get the video time."));
		}
		
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::GetTime() -- The Media is nullptr."));
	}

	return currentTime;
}

bool UVH_TAKVideoPlayer::SetTime(float seconds)
{
	if (Media != nullptr)
	{
		try
		{
			Media->setTime(seconds * 1000);
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::SetTime() -- Caught a MediaException when attempting to seek the video."));
			return false;
		}

		return true;
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::SetTime() -- The Media is nullptr."));
	}

	return false;
}

float UVH_TAKVideoPlayer::GetDuration()
{
	float duration = 0.0f;

	if (Media != nullptr)
	{
		try
		{
			duration = ((float)Media->getDuration() / 1000);
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::GetTime() -- Caught a MediaException when attempting to get the video duration."));
		}

	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::GetTime() -- The Media is nullptr."));
	}

	return duration;
}

bool UVH_TAKVideoPlayer::Prefetch()
{
	if (Media != nullptr)
	{
		try
		{
			Media->prefetch();
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Prefetch() -- Caught a MediaException when attempting to prefetch the video."));
			return false;
		}
		bIsPaused = false;

		return true;
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::Prefetch() -- The Media is nullptr."));
	}

	return false;
}

bool UVH_TAKVideoPlayer::CreateVideoFromCOT(UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		switch (cotVideo->Protocol)
		{
		case ESchemeTypeEnum::EST_UDP:
			return OpenUDPVideo(cotVideo);
		case ESchemeTypeEnum::EST_RTSP:
			return OpenRTSPVideo(cotVideo);
		case ESchemeTypeEnum::EST_HTTP:
		case ESchemeTypeEnum::EST_HTTPS:
			return OpenHTTPVideo(cotVideo);
		case ESchemeTypeEnum::EST_TCP:
			return OpenTCPVideo(cotVideo);
		case ESchemeTypeEnum::EST_RTMP:
		case ESchemeTypeEnum::EST_RTMPS:
			return OpenRTMPVideo(cotVideo);
		case ESchemeTypeEnum::EST_RTP:
			return OpenRTPVideo(cotVideo);
		case ESchemeTypeEnum::EST_SRT:
			return OpenSRTVideo(cotVideo);
		case ESchemeTypeEnum::EST_FILE:
			return OpenFILEVideo(cotVideo);
		case ESchemeTypeEnum::EST_DIRECTORY:
		case ESchemeTypeEnum::EST_UNKNOWN:
		default:
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromCOT() -- Directory or Unknown is an unsupported protocol for this function."))
			return false;
		}
	}

	return false;
}

void UVH_TAKVideoPlayer::PopoutVideo(UVH_TAKVideoPlayer*& popoutVideo)
{
	UVH_TAKVideoPlayer* popVid = NewObject<UVH_TAKVideoPlayer>();
	popVid->AspectRatio = AspectRatio;
	popVid->Media = Media;
	popVid->Texture = Texture;
	popVid->FramePixels = FramePixels;
	popVid->bAspectRatioReceived = bAspectRatioReceived;
	popVid->bAspectRatioSent = bAspectRatioSent;
	popVid->bIsPaused = bIsPaused;
	popVid->bIsVideoLoaded = bIsVideoLoaded;
	popVid->SetConsumers(Media);

	popoutVideo = popVid;

	AspectRatio = -1.f;
	Media = nullptr;
	Texture = nullptr;
	bAspectRatioReceived = false;
	bAspectRatioSent = false;
	bIsPaused = true;
	bIsVideoLoaded = false;

	FramePixels.Empty();
	// the 4 determines how many channels the video is using for colors for individual pixels
	FramePixels.AddDefaulted(1024 * 1024 * 4);
}

UTexture2D* UVH_TAKVideoPlayer::GetTexture()
{
	if (Texture == nullptr)
	{
		Texture = UTexture2D::CreateTransient(1024, 1024);  // todo ohg | OK to hardcode texture size?
		Texture->UpdateResource();                          // todo ohg | needed?
	}

	return Texture;
}

float UVH_TAKVideoPlayer::GetAspectRatio() const
{
	return AspectRatio;
}

bool UVH_TAKVideoPlayer::GetVideoSize(FVector2D& videoSize) const
{
	if (bAspectRatioReceived)
	{
		videoSize = VideoSize;

		return true;
	}

	return false;
}

bool UVH_TAKVideoPlayer::IsVideoPaused() const
{
	return bIsPaused;
}

void UVH_TAKVideoPlayer::DestroyVideoPlayer()
{
	if (Media != nullptr)
	{
		MediaProcessor::destroyProcessor(Media);
		Media = nullptr;
	}

	Texture = nullptr;

	ConditionalBeginDestroy();
}

//////////////////////////
/* Connection Functions */
//////////////////////////

/* includes RTMPS as well */
// not sure if this works, haven't been able to test since I don't have a source connection of RTMP or RTMPS- David
bool UVH_TAKVideoPlayer::OpenRTMPVideo(const UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		if (!cotVideo->Address.IsEmpty())
		{
			return CreateVideoFromURL(cotVideo->GetVideoURL());
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTMPVideo() -- The address of the video is empty"));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTMPVideo() -- The cotVideo is nullptr"));
	}

	return false;
}

/* includes HTTPS as well */
bool UVH_TAKVideoPlayer::OpenHTTPVideo(const UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		if (!cotVideo->RawPath.IsEmpty())
		{
			return CreateVideoFromURL(cotVideo->RawPath);
		}

		if (!cotVideo->Address.IsEmpty())
		{
			if (UVH_URI* videoURI = NewObject<UVH_URI>())
			{
				videoURI->SetFromString(cotVideo->GetVideoURL());

				if (cotVideo->Protocol != ESchemeTypeEnum::EST_UNKNOWN)
				{
					FString vidProtocol = UVH_URI::GetStringFromProtocol(cotVideo->Protocol) + TEXT("://");
					FString port = (videoURI->IsPortNull()) ? TEXT("") : FString::Printf(TEXT(":%d"), videoURI->GetPort());
					FString query = (videoURI->IsQueryNull()) ? TEXT("") : videoURI->GetQuery();
					int32 timeout = (cotVideo->NetworkTimeout >= 0) ? cotVideo->NetworkTimeout : 3000;
					timeout *= 1000;

					FString httpRequest = vidProtocol + videoURI->GetHost() + port + videoURI->GetPath() + TEXT("?") + query + TEXT("&") + FString::Printf(TEXT("timeout=%d"), timeout);

					return CreateVideoFromURL(httpRequest);
				}
				else
				{
					UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenHTTPVideo() -- The protocol is unknown"));
				}
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenHTTPVideo() -- The videoURI is nullptr"));
			}
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenHTTPVideo() -- The cotVideo address is empty"));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenHTTPVideo() -- The cotVideo is nullptr"));
	}

	return false;
}

bool UVH_TAKVideoPlayer::OpenFILEVideo(const UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		// cotVideo->Path should only return the directory file (i.e. C:\User\fun.mp4 instead of file:///C:\User\fun.mp4)
		if (FPaths::FileExists(cotVideo->Path))
		{
			return CreateVideoFromFile(cotVideo->Path);
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenFILEVideo() -- The file from the cotVideo is not valid."));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenFILEVideo() -- The cotVideo is nullptr."));
	}

	return false;
}

bool UVH_TAKVideoPlayer::OpenRTSPVideo(const UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		if (!cotVideo->Address.IsEmpty())
		{
			FString programData = CreateTempDirectory();

			FString port = (cotVideo->Port < 0) ? TEXT("") : FString::Printf(TEXT(":%d"), cotVideo->Port);

			FString rtspAddr = cotVideo->Address + port + cotVideo->Path;
			rtspAddr += (cotVideo->RTSPReliable) ? TEXT("?tcp") : TEXT("");

			uint32 timeout = (cotVideo->NetworkTimeout < 0) ? 0 : cotVideo->NetworkTimeout;
			int64 bufferTime = (cotVideo->BufferTime < 0) ? 0 : cotVideo->BufferTime;

			return CreateVideoFromRTSP(rtspAddr, timeout, bufferTime, 0, programData);
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTSPVideo() -- The address is empty"));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTSPVideo() -- The cotVideo is nullptr"));
	}

	return false;
}

bool UVH_TAKVideoPlayer::OpenUDPVideo(const UVH_COTDetail_Video* cotVideo)
{
	/*
	TArray<TSharedPtr<FInternetAddr>> localAdapterAddresses;
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalAdapterAddresses(localAdapterAddresses);

	for (TSharedPtr<FInternetAddr> localAdapterAddress : localAdapterAddresses)
	{
		if (localAdapterAddress != nullptr)
		{
			TArray<uint8> ipAddress = localAdapterAddress->GetRawIp();

			FString ipString;
			for (uint8 part : ipAddress)
			{
				ipString += FString::Printf(TEXT("%d."), part);
			}

			UE_LOG(VH_COT, Warning, TEXT("%s"), *ipString);
		}
	}
	*/

	if (ensure(cotVideo))
	{
		if (ensure(!cotVideo->Address.IsEmpty()))
		{ 
			FString udpAddr = cotVideo->Address;
			int32 port = (cotVideo->Port < 0) ? 0 : cotVideo->Port;
			uint32 timeout = (cotVideo->NetworkTimeout < 0) ? 0 : cotVideo->NetworkTimeout;
			int64 bufferTime = (cotVideo->BufferTime < 0) ? 0 : cotVideo->BufferTime;
			FString programData = CreateTempDirectory();

			return CreateVideoFromStream(udpAddr, port, timeout, bufferTime, 0, programData);
		}
	}

	return false;
}

// not sure if this works, haven't been able to test since I don't have a source connection of TCP- David
bool UVH_TAKVideoPlayer::OpenTCPVideo(const UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		if (!cotVideo->Address.IsEmpty())
		{
			return CreateVideoFromURL(cotVideo->GetVideoURL());
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenTCPVideo() -- The address is empty"));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenTCPVideo() -- The cotVideo is nullptr"));
	}

	return false;
}

// not sure if this works, haven't been able to test since I don't have a source connection of RTP- David
bool UVH_TAKVideoPlayer::OpenRTPVideo(const UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		if (!cotVideo->Address.IsEmpty())
		{
			if (UVH_URI* videoURI = NewObject<UVH_URI>())
			{
				videoURI->SetFromString(cotVideo->GetVideoURL());

				if (cotVideo->Protocol != ESchemeTypeEnum::EST_UNKNOWN)
				{
					FString vidProtocol = UVH_URI::GetStringFromProtocol(cotVideo->Protocol) + TEXT("://");
					FString port = (videoURI->IsPortNull()) ? TEXT("") : FString::Printf(TEXT(":%d"), videoURI->GetPort());
					int32 timeout = 5 * 1000;

					FString rtpURL = vidProtocol + videoURI->GetHost() + port + videoURI->GetPath() + TEXT("?") + FString::Printf(TEXT("timeout=%d"), timeout);

					return CreateVideoFromURL(rtpURL);
				}
				else
				{
					UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTPVideo() -- The protocol of the rtp stream could not be determined from the Video URL or the address is empty"));
				}
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTPVideo() -- uri is nullptr"));
			}
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTPVideo() -- The COT video address is empty"));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenRTPVideo() -- The cotVideo is nullptr"));
	}

	return false;
}

// not sure if this works, haven't been able to test since I don't have a source connection of SRT- David
bool UVH_TAKVideoPlayer::OpenSRTVideo(const UVH_COTDetail_Video* cotVideo)
{
	if (cotVideo != nullptr)
	{
		if (!cotVideo->Address.IsEmpty())
		{
			if (UVH_URI* videoURI = NewObject<UVH_URI>())
			{
				videoURI->SetFromString(cotVideo->GetVideoURL());

				if (cotVideo->Protocol != ESchemeTypeEnum::EST_UNKNOWN)
				{
					FString vidProtocol = UVH_URI::GetStringFromProtocol(cotVideo->Protocol) + TEXT("://");
					FString port = (videoURI->IsPortNull()) ? TEXT("") : FString::Printf(TEXT(":%d"), videoURI->GetPort());
					int32 timeout = (cotVideo->NetworkTimeout <= 0) ? 3000 : cotVideo->NetworkTimeout;
					timeout *= 1000;

					// this may need a passcode to work. It's in the wintak source code but we don't have it as a variable in the VH_COTDetail_Video
					FString srtURL = vidProtocol + videoURI->GetHost() + port + videoURI->GetPath() + TEXT("?") + FString::Printf(TEXT("timeout=%d"), timeout);

					return CreateVideoFromURL(srtURL);
				}
				else
				{
					UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenSRTVideo() -- The protocol of the srtv stream could not be determined from the Video URL or the address is empty"));
				}
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenSRTVideo() -- uri is nullptr"));
			}
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenSRTVideo() -- The COT Video address is empty"));
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::OpenSRTVideo() -- The cotVideo is nullptr"));
	}

	return false;
}

// ---------------------------------
// --- Implementation Methods
// ---------------------------------

FString UVH_TAKVideoPlayer::CreateTempDirectory() const
{
	// this might need to be changed
	FString programDataAddr = UDeveloper_Statics::GetCommonAppDataPath() + FString(TEXT("/VTAK/Cache/Videos/"));

	//  * @param tmp_dir temporary directory (which must exist) into which
	//  * files can be created to buffer the stream as needed.
	//	*                Can be NULL if buffering is disabled.
	if (!programDataAddr.IsEmpty())
	{
		IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();

		bool bDirExists = platformFile.DirectoryExists(*programDataAddr);
		if (!bDirExists)
		{
			bDirExists = platformFile.CreateDirectory(*programDataAddr);
		}
	}

	return programDataAddr;
}

bool UVH_TAKVideoPlayer::CreateVideoFromFile(const FString& fileDirectory)
{
	if (FPaths::FileExists(fileDirectory))
	{
		try
		{
			Media = MediaProcessor::createFromFile(TCHAR_TO_ANSI(*fileDirectory));
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromFile() -- Caught a MediaException when attempting to open the video."));
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromFile() -- Video file: %s"), *fileDirectory);
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromFile() -- If the file path appears correct, be sure that \"Initialize\" method has been called before CreateVideoFromFile("));
			return false;
		}

		return SetConsumers(Media);
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromFile() -- Could not find video file under the directory: %s"), *fileDirectory);
	}

	return false;
}

bool UVH_TAKVideoPlayer::CreateVideoFromURL(const FString& address)
{
	if (!address.IsEmpty())
	{
		try
		{
			Media = MediaProcessor::createFromFile(TCHAR_TO_ANSI(*address));
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromURL() -- Video url: %s"), *address);
			return false;
		}

		return SetConsumers(Media);
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromURL() -- The address is empty. Unable to make a connection"));
	}

	return false;
}

bool UVH_TAKVideoPlayer::CreateVideoFromStream(FString multicastAddress, const int32 port, const uint32 timeout, const int64 bufferTime, const uint64 maxByteSize, FString tempDirectory, FString localAddress)
{
	if (!multicastAddress.IsEmpty())
	{
		try
		{
			Media = MediaProcessor::createFromStream(TCHAR_TO_ANSI(*multicastAddress), port, (unsigned int)timeout, (long)bufferTime, (unsigned long)maxByteSize, TCHAR_TO_ANSI(*tempDirectory), TCHAR_TO_ANSI(*localAddress));
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromStream() -- Caught a MediaException when attempting to create a connection to the stream."));
			return false;
		}

		return SetConsumers(Media);
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromStream() -- The multicast address is empty so a connection can not be made"));
	}

	return false;
}

bool UVH_TAKVideoPlayer::CreateVideoFromRTSP(FString addr, uint32 timeout, int64 bufferTime, uint64 maxByteSize, FString tmp_dir)
{
	if (!addr.IsEmpty())
	{
		try
		{
			Media = MediaProcessor::createFromRtsp(TCHAR_TO_ANSI(*addr), (unsigned int)timeout, (long)bufferTime, (unsigned long)maxByteSize, TCHAR_TO_ANSI(*tmp_dir));
		}
		catch (MediaException)
		{
			UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromRTSP() -- Caught a MediaException when attempting to create a connection to the stream."));
			return false;
		}

		return SetConsumers(Media);
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::CreateVideoFromRTSP() -- The address is empty so cannot create a video."));
	}

	return false;
}

void UVH_TAKVideoPlayer::UpdateTexture2DPixels(UTexture2D* texture, int32 mipIndex, const TArray<uint8>& pixelData)
{
	if (IsValid(this) && IsValid(texture) && texture->GetResource() != nullptr)
	{
		struct FMipUpdateParams
		{
			int32 MipIndex;
			TArray<uint8> PixelData;
			FTexture2DResource* Resource;
		};

		FMipUpdateParams* mipUpdateData = new FMipUpdateParams();
		mipUpdateData->MipIndex = mipIndex;
		mipUpdateData->PixelData = pixelData;
		mipUpdateData->Resource = (FTexture2DResource*)texture->GetResource();

		ENQUEUE_RENDER_COMMAND(FUpdateMipData) (
			[mipUpdateData](FRHICommandListImmediate& RHICmdList)
		{
			if (mipUpdateData->Resource->GetTexture2DRHI() != nullptr)
			{
				uint32 destStride;
				uint8* lockedMipData = (uint8*)RHILockTexture2D(mipUpdateData->Resource->GetTexture2DRHI(), mipUpdateData->MipIndex, RLM_WriteOnly, destStride, false);
				if (lockedMipData)
				{
					if (mipUpdateData->PixelData.Num() == 0)
					{
						FMemory::Memzero(lockedMipData, sizeof(lockedMipData));
					}
					else
					{
						FMemory::Memcpy(lockedMipData, mipUpdateData->PixelData.GetData(), mipUpdateData->PixelData.Num());
					}

					RHIUnlockTexture2D(mipUpdateData->Resource->GetTexture2DRHI(), mipUpdateData->MipIndex, false);
				}
			}
			delete mipUpdateData;
		}
		);
	}
}

bool UVH_TAKVideoPlayer::SetConsumers(MediaProcessor* mdPrcssr)
{
	if (mdPrcssr != nullptr)
	{
		vector<MediaFormat*> trackInfo = mdPrcssr->getTrackInfo();

		for (MediaFormat* format : trackInfo)
		{
			if (format != nullptr)
			{
				switch (format->format_type)
				{
				case FORMAT_VIDEO:
					mdPrcssr->setVideoConsumer(format->track_num, this);
					break;

				case FORMAT_KLV:
					mdPrcssr->setKLVConsumer(format->track_num, this);
					break;

				default:
					UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::SetConsumers() -- Unknown MediaFormat."));
					return false;
				}
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::SetConsumers() -- The format is nullptr."));
				return false;
			}
		}

		mdPrcssr->setStatusUpdateConsumer(this);

		return true;
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("UVH_TAKVideoPlayer::SetConsumers() -- The mdPrcssr is nullptr."));
	}

	return false;
}

// ---------------------------------
// --- Debug/Testing
// ---------------------------------

FString UVH_TAKVideoPlayer::GetFrameFormat(MediaPixelFormat frameFormat)
{
	switch (frameFormat)
	{
	case MediaPixelFormat::PIXELS_RGB:
		return TEXT("PIXELS_RGB");
	case MediaPixelFormat::PIXELS_YUV_420:
		return TEXT("PIXELS_YUV_420");
	case MediaPixelFormat::PIXELS_RGB_PACKED:
		return TEXT("PIXELS_RGB_PACKED");
	case MediaPixelFormat::PIXELS_BGR8_PACKED:
		return TEXT("PIXELS_BGR8_PACKED");
	case MediaPixelFormat::PIXELS_YUV_422J:
		return TEXT("PIXELS_YUV_422J");
	case MediaPixelFormat::PIXELS_YUV_420J:
		return TEXT("PIXELS_YUV_420J");
	case MediaPixelFormat::PIXELS_NV21:
		return TEXT("PIXELS_NV21");
	case MediaPixelFormat::PIXELS_NV12:
		return TEXT("PIXELS_NV12");
	case MediaPixelFormat::PIXELS_YUYV:
		return TEXT("PIXELS_YUYV");
	default:
		return TEXT("MediaPixelFormat not found");
	}

	return TEXT("MediaPixelFormat not found");
}