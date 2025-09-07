#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonButton.h"

// Game Includes
#include "Game_MovementComponent.h"

// Generated Includes
#include "Game_UserWidget_RibbonButton_GlobeTransform.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_RibbonButton_GlobeTransform : public UGame_UserWidget_RibbonButton
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FSlateBrush IconFirstPerson;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FSlateBrush IconTopDown;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonButton_GlobeTransform(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool Initialize() override;

	virtual void NativeConstruct() override;

protected:
	virtual void PostClicked() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void RenewBinding();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleIsInTOCUpdated(bool bIsInTOC);

	UFUNCTION()
	void HandleWorldTransformOverrideUpdated(const FTransform& transform);
};