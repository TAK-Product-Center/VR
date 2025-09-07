#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Game_SessionPlaybackAvatar.generated.h"

UCLASS()
class GAME_API AGame_SessionPlaybackAvatar : public AActor
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_SessionPlaybackAvatar();

	// ---------------------------------
	// --- Variables
	// ---------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseInterpolation;

private:
	float InterpolationTime;

	FVector TargetPosition;

	FRotator TargetRotation;

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetHeadLocation(const FVector& location);

	UFUNCTION(BlueprintImplementableEvent)
	void SetHeadRotation(const FRotator& rotation);

	UFUNCTION(BlueprintImplementableEvent)
	void SetCallsign(const FString& callsign);

	UFUNCTION(BlueprintImplementableEvent)
	void SetControllerTransform(const FString& controllerName, const FTransform& transform);

	void SetTargetPosition(const FVector& position);

	void SetTargetRotation(const FRotator& rotation);

	virtual void Tick(float deltaSeconds) override;
};
