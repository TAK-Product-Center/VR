// Developed by Virtual Heroes, 2019-2020

#pragma once

// Engine includes
#include "Tickable.h"

// Gv2F includes
#pragma warning(push)
#pragma warning(disable:4290)
#pragma warning(disable:4800)

#include "mediaprocessor.h"
#include "mediaexception.h"
#include "mediaformats.h"
#include "mediaconsumers.h"
#include "mediamultiplexer.h"
#include "mediaconsumers.h"
#include "mediaformatconvert.h"

#pragma warning(pop)

// Generated include
#include "VH_TAKVideoPlayer.generated.h"

// Forward declarations
class UVH_COTDetail_Video;

// Using declaratives
using PGSCMedia::VideoConsumer;
using PGSCMedia::KLVConsumer;
using PGSCMedia::StatusUpdateConsumer;

/**
 * Creates videos using the VH_COTDetail_Video objects and also from populating from URL strings
 */
UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_TAKVideoPlayer : public UObject, public FTickableGameObject, public VideoConsumer, public KLVConsumer, public StatusUpdateConsumer
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleAspectRatioUpdate, float, aspectRatio);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FHandleAspectRatioUpdate OnAspectRatioUpdate;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "TAK Video Player")
	float AspectRatio;

protected:
	PGSCMedia::MediaProcessor* Media;

	FCriticalSection* CritSection;

	UPROPERTY()
	UTexture2D* Texture;

	TArray<uint8> FramePixels;

	bool bAspectRatioReceived;

	bool bAspectRatioSent;

	bool bIsPaused;

	UPROPERTY(BlueprintReadWrite, Category = "TAK Video Player")
	bool bIsVideoLoaded;

private:
	FString LicenseDirectory;

	FVector2D VideoSize;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVH_TAKVideoPlayer();

	~UVH_TAKVideoPlayer();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintCallable)
	static bool IsVideoSupported(const FString& fullPathToFile);

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Tick(float deltaTime) override;

	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UVH_TAKVideoPlayer, STATGROUP_Tickables); }

	virtual void mediaVideoFrame(const VideoFrameData *frame) override;

	virtual void mediaKLVData(KLVData *data) override;

	virtual void mediaEOF(void) override;

	virtual void mediaFatalError(const char *info) override;

	virtual void mediaStreamExtentsUpdate(long startMillis, long endMillis) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool Initialize();

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool Play();

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool Pause();

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	float GetTime();

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool SetTime(float seconds);

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	float GetDuration();

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool Prefetch();

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool CreateVideoFromCOT(UVH_COTDetail_Video* cotVideo);

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	void PopoutVideo(UVH_TAKVideoPlayer*& popoutVideo);

	UFUNCTION(BlueprintPure, Category = "TAK Video Player")
	UTexture2D* GetTexture();

	UFUNCTION(BlueprintPure, Category = "TAK Video Player")
	float GetAspectRatio() const;

	UFUNCTION(BlueprintPure, Category = "TAK Video Player")
	bool GetVideoSize(FVector2D& videoSize) const;

	UFUNCTION(BlueprintPure, Category = "TAK Video Player")
	bool IsVideoPaused() const;

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	void DestroyVideoPlayer();

	//////////////////////////
	/* Connection Functions */
	//////////////////////////

	/* includes RTMPS as well */
	// not sure if this works, haven't been able to test since I don't have a source connection of RTMP or RTMPS- David
	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenRTMPVideo(const UVH_COTDetail_Video* cotVideo);

	/* includes HTTPS as well */
	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenHTTPVideo(const UVH_COTDetail_Video* cotVideo);

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenFILEVideo(const UVH_COTDetail_Video* cotVideo);

	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenRTSPVideo(const UVH_COTDetail_Video* cotVideo);

	// not sure if this works, haven't been able to test since I don't have a source connection of UDP- David
	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenUDPVideo(const UVH_COTDetail_Video* cotVideo);

	// not sure if this works, haven't been able to test since I don't have a source connection of TCP- David
	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenTCPVideo(const UVH_COTDetail_Video* cotVideo);

	// not sure if this works, haven't been able to test since I don't have a source connection of RTP- David
	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenRTPVideo(const UVH_COTDetail_Video* cotVideo);

	// not sure if this works, haven't been able to test since I don't have a source connection of SRT- David
	UFUNCTION(BlueprintCallable, Category = "TAK Video Player")
	bool OpenSRTVideo(const UVH_COTDetail_Video* cotVideo);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	FString CreateTempDirectory() const;

	bool CreateVideoFromFile(const FString& fileDirectory);

	bool CreateVideoFromURL(const FString& address);

	bool CreateVideoFromStream(FString multicastAddress, const int32 port, const uint32 timeout = 0U, const int64 bufferTime = 0i64, const uint64 maxByteSize = 0Ui64, FString tempDirectory = TEXT(""), FString localAddress = TEXT(""));

	bool CreateVideoFromRTSP(FString addr, uint32 timeout, int64 bufferTime, uint64 maxByteSize, FString tmp_dir = TEXT(""));

	void UpdateTexture2DPixels(UTexture2D* texture, int32 mipIndex, const TArray<uint8>& pixelData);

	bool SetConsumers(PGSCMedia::MediaProcessor* mdPrcssr);


	// ---------------------------------
	// --- Debug/Testing
	// ---------------------------------

protected:
	FString GetFrameFormat(MediaPixelFormat frameFormat);
};
