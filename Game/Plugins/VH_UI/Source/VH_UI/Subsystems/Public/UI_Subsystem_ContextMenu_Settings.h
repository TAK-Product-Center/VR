#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Module Includes
#include "UI_Subsystem_ContextMenu.h"

// Generated Includes
#include "UI_Subsystem_ContextMenu_Settings.generated.h"

UCLASS(BlueprintType, Blueprintable, Config = Game)
class VH_UI_API UUI_Subsystem_ContextMenu_Settings : public UDeveloperSettings
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TMap<TSubclassOf<UObject>, FContextOptionClasses> AdditionalContextOptionsPerClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TSubclassOf<UUserWidget> DefaultContextMenuClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TEnumAsByte<ECollisionChannel> ContextMenuCollisionChannel;

	/* only allows one context menu of this class to be open at a time */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TSet<TSubclassOf<UUserWidget>> UniqueContextMenuClasses;
};