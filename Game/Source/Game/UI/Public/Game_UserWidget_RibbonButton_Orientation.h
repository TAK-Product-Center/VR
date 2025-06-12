#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonButton.h"

// Generated Includes
#include "Game_UserWidget_RibbonButton_Orientation.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_RibbonButton_Orientation : public UGame_UserWidget_RibbonButton
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TSubclassOf<UUserWidget> DesktopOrientationWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TSubclassOf<UUserWidget> VROrientationWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FVector VROffsetFromTool;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FVector2D VRScale;

private:
	UPROPERTY()
	UUserWidget* OrientationWidget;

	UPROPERTY()
	UVR_MotionControllerComponent* AttachedController;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonButton_Orientation(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool Initialize() override;

	virtual void NativeConstruct() override;

protected:
	virtual void PostClicked() override;

	virtual void PostSetSelected(bool bSelected) override;



	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void AttachWidgetToTool(AActor* tool);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	virtual void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode) override;

	virtual void HandleInputStackTopChanged(AActor* tool) override;
};
