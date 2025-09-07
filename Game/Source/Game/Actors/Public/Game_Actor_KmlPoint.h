#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Game_Actor_KmlPoint.generated.h"

class UGame_CameraScalingComponent;
class USceneComponent;

UCLASS()
class GAME_API AGame_Actor_KmlPoint : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Actor_KmlPoint(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
		
public:
	virtual void BeginPlay() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetTexture(UTexture2D* texture, double scale);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetColor(const FLinearColor& color);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetText(const FLinearColor& color, const FString& text);

	UFUNCTION(BlueprintImplementableEvent)
	UGame_CameraScalingComponent* ReceiveGetTextScalingComponent();

	UFUNCTION(BlueprintImplementableEvent)
	USceneComponent* ReceiveGetTextComponent();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleBeginCursorOver(AActor* actor);

	UFUNCTION()
	void HandleEndCursorOver(AActor* actor);

	UFUNCTION()
	void HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters);
};