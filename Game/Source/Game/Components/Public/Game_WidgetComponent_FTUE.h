#pragma once

// Parent Includes
#include "Components/WidgetComponent.h"

// VH Platform Includes
#include "Developer_Subsystem_Core.h"

// Generated Includes
#include "Game_WidgetComponent_FTUE.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_WidgetComponent_FTUE : public UWidgetComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EHardwareInterfaceMode, FVector> HardwareModeToRelativeLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EHardwareInterfaceMode, FVector2D> HardwareModeToSize;
	 

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_WidgetComponent_FTUE(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);
};