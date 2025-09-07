#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Module Includes
#include "UI_Subsystem_Core.h"

// Generated Includes
#include "UI_Subsystem_Core_Settings.generated.h"

UCLASS(BlueprintType, Blueprintable, Config = Game)
class VH_UI_API UUI_Subsystem_Core_Settings : public UDeveloperSettings
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* default viewport settings; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	FOpenUserWidgetViewportSettings DefaultViewportSettings;

	/* default world settings; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	FOpenUserWidgetWorldSettings DefaultWorldSettings;

	/* default window settings; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	FOpenUserWidgetWindowSettings DefaultWindowSettings;

	/* default tab settings; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	FTabContainerSettings DefaultTabContainerSettings;

	/* holds default opening behavior based on hardware interface mode; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<EHardwareInterfaceMode, EUIType> DefaultOpenBehavior;

	/* if true, allows multiple instances of a widget from a particular class */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	bool bDefaultAllowMultipleInstances;

	/* overrides DefaultViewportSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenUserWidgetViewportSettings> DefaultClassViewportSettings;
	
	/* overrides DefaultWorldSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenUserWidgetWorldSettings> DefaultClassWorldSettings;
	
	/* overrides DefaultWindowSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenUserWidgetWindowSettings> DefaultClassWindowSettings;
	
	/* overrides DefaultTabContainerSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FTabContainerSettings> DefaultClassTabContainerSettings;
	
	/* overrides DefaultOpenBehavior for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenBehavior> DefaultClassOpenBehavior;
};
