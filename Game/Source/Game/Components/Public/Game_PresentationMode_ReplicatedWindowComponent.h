#pragma once

// Parent Includes
#include "Components/ActorComponent.h"
#include "Interface_UI_Tab.h"

// Engine Includes
#include "HAL/ThreadSafeBool.h"

// Generated Includes
#include "Game_PresentationMode_ReplicatedWindowComponent.generated.h"

class UReplication_DataChannel;
class UButton;
class UGame_CameraComponent;
class UTextureRenderTarget2D;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class UGame_PresentationMode_ReplicatedWindowComponent : public UActorComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTextureRenderTarget2D* RenderTarget2D;

private:
	UPROPERTY()
	UTexture2D* Texture;

	UPROPERTY(Replicated)
	FString ReplicationID;

	FCriticalSection* LastCapturedPixelsCriticalSection;

	TArray<FColor> LastCapturedPixels;

	FTransform LastCaptureTransform;

	FThreadSafeBool bPixelsDirty;

	double LastCaptureTime;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_PresentationMode_ReplicatedWindowComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	UTexture2D* GetTexture() const;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateTexture(const TArray<uint8>& pixelData);
	
	void CreateDataChannels();

	bool IsClientReadyToSend() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleDataReceived(const TArray<uint8>& data, UReplication_DataChannel* channel);

	UFUNCTION()
	void PeriodicCapturePixels();

	UFUNCTION()
	void PeriodicSendPixels();
};
