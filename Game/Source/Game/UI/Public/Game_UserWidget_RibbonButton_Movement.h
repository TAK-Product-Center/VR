#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonButton.h"

// Game Includes
#include "Game_MovementComponent.h"

// Generated Includes
#include "Game_UserWidget_RibbonButton_Movement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_RibbonButton_Movement : public UGame_UserWidget_RibbonButton
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	EMovementType TrackedMovementType;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonButton_Movement(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool Initialize() override;

	virtual void NativeConstruct() override;

protected:
	virtual void PostClicked();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION()
	void SetTrackedMovementType(EMovementType newMoveType);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleMovementTypeChanged(EMovementType movementType);
};