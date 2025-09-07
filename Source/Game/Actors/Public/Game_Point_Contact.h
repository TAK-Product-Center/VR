#pragma once

// Parent Includes
#include "Game_Point_Icon.h"

// Generated Includes
#include "Game_Point_Contact.generated.h"

class UTexture;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Point_Contact : public AGame_Point_Icon
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Point_Contact(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture* MachineGeneratedIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture* UserIcon;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

private:
	virtual bool PostClickPressed(AActor* actor, const FKey& buttonPressed) override;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	virtual void HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent) override;
};
