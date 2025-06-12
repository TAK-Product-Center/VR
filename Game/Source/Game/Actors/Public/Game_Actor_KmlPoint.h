#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Game_Actor_KmlPoint.generated.h"

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
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetTexture(UTexture2D* texture);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetColor(const FLinearColor& color);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetText(const FLinearColor& color, const FString& text);
};