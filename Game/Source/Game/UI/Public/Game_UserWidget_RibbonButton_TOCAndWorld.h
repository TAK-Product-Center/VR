#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonButton.h"

// Generated Includes
#include "Game_UserWidget_RibbonButton_TOCAndWorld.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_RibbonButton_TOCAndWorld : public UGame_UserWidget_RibbonButton
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FSlateBrush IconToTOC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FSlateBrush IconToWorld;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	float CooldownSeconds;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonButton_TOCAndWorld(const FObjectInitializer& objectInitializer);


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
	void Cooldown();

	UFUNCTION()
	void HandleIsInTOCUpdated(bool bIsInTOC);
};