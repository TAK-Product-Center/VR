// Required Includes
#include "Game_WidgetComponent_FTUE.h"
#include "Game.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_WidgetComponent_FTUE::UGame_WidgetComponent_FTUE(const FObjectInitializer& objectInitializer)
{
	
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_WidgetComponent_FTUE::BeginPlay()
{
	Super::BeginPlay();

	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{ 
		subsystem->OnHardwareInterfaceModeChanged.AddDynamic(this, &UGame_WidgetComponent_FTUE::HandleHardwareInterfaceModeChanged);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_WidgetComponent_FTUE::HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode)
{
	FVector relativeLocation = GetRelativeLocation();
	
	if (FVector* relativeLocationPtr = HardwareModeToRelativeLocation.Find(newMode))
	{
		relativeLocation = *relativeLocationPtr;
	}

	SetRelativeLocation(relativeLocation);

	FVector2D size = GetDrawSize();
	
	if (FVector2D* sizePtr = HardwareModeToSize.Find(newMode))
	{
		size = *sizePtr;
	}

	SetDrawSize(size);
}