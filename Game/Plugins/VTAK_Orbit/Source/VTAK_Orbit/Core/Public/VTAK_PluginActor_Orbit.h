#pragma once

// Parent includes
#include "Game_PluginActor.h"

// Generated include
#include "VTAK_PluginActor_Orbit.generated.h"

// Forward declarations
class AVTAK_Actor_Orbit;
class UGame_ListEntry_Overlay_Base;
class UGame_ListEntry_Overlay_Gen;

UCLASS()
class VTAK_ORBIT_API AVTAK_PluginActor_Orbit : public AGame_PluginActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_PluginActor_Orbit();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly)
	FName ControllerID;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* OverlayCategoryIcon;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AVTAK_Actor_Orbit> OrbitActorClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGame_ListEntry_Overlay_Base> CategoryListItemClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGame_ListEntry_Overlay_Gen> ItemListItemClass;

protected:
	const FName ID;

	const FString Type;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void PostHandleCOTMessageReceived(const FString& messageType) override;
};