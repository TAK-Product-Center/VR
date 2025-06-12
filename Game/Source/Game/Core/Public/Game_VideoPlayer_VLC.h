#pragma once

// Parent Includes
#include "UObject/Object.h"
#include "Tickable.h"

// Generated Includes
#include "Game_VideoPlayer_VLC.generated.h"

class UTexture2D;
class FGame_VideoPlayer_VLC_Thread;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_VideoPlayer_VLC : public UObject, public FTickableGameObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVideoEnded, UGame_VideoPlayer_VLC*, videoPlayer);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedAspectRatio, float, aspectRatio);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FVideoEnded OnVideoEnded;

	UPROPERTY(BlueprintAssignable)
	FReceivedAspectRatio OnReceivedAspectRatio;
	
	float DefaultPixelUpdateCooldown;

	bool bQueueVideoEndedDelegate;

	bool bQueueAspectDelegate;

private:
	FString URL;

	float PixelUpdateCooldown;

	UPROPERTY()
	UTexture2D* Texture;

	FGame_VideoPlayer_VLC_Thread* ThreadVLC;

	bool bRenderToTexture;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_VideoPlayer_VLC();

	~UGame_VideoPlayer_VLC();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool IsTickable() const override;
	
	virtual TStatId GetStatId() const override;

	virtual void Tick(float deltaTime) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void SetRenderToTexture(bool bRenderToTextureArg);

	UFUNCTION(BlueprintCallable)
	void SetVolume(float volume);

	UFUNCTION(BlueprintCallable)
	void SetURL(const FString& url);

	UFUNCTION(BlueprintCallable)
	const FString GetURL() const;

	UFUNCTION(BlueprintCallable)
	void SetPause(bool bPause);

	UFUNCTION(BlueprintCallable)
	void PlayVideo();

	UFUNCTION(BlueprintPure)
	bool IsPaused() const;

	UFUNCTION(BlueprintPure)
	UTexture2D* GetTexture();

	UFUNCTION(BlueprintPure)
	float GetAspectRatio() const;

	UFUNCTION(BlueprintPure)
	double GetSecondsElapsed() const;

	UFUNCTION(BlueprintCallable)
	void SetSecondsElapsed(double secondsElapsed);
};