#pragma once

// Engine Includes
#include "Interfaces/IPluginManager.h"
#include "Framework/Commands/UICommandInfo.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/SWidget.h"

struct FVH_PluginsCommand
{
	TSharedPtr<IPlugin> PluginInfo;
	TSharedPtr<FUICommandInfo> CommandInfo;
};

class FVH_PluginsPackager : public TSharedFromThis<FVH_PluginsPackager>
{
public:
	FVH_PluginsPackager();
	~FVH_PluginsPackager();

	void OpenPluginPackager(TSharedRef<IPlugin> Plugin);

	void PackagePlugin(TSharedRef<IPlugin> Plugin, const FString& OutputDirectory);

	/** Generates submenu content for the plugin packager command */
	void GeneratePackagerMenuContent(FMenuBuilder& MenuBuilder);

	/** Generates the menu content for the plugin packager toolbar button */
	TSharedRef<SWidget> GeneratePackagerComboButtonContent();

private:
	/** Gets all available game mod plugin packages  */
	void FindAvailableGameMods(TArray<TSharedRef<IPlugin>>& OutAvailableGameMods);

	/** Gets all available game mod plugins and registers command info for them */
	void GetAvailableUGCCommands(const TArray<TSharedRef<IPlugin>>& AvailableUGC);

	/** Generates menu content for the supplied set of commands */
	void GeneratePackagerMenuContent_Internal(FMenuBuilder& MenuBuilder, const TArray<TSharedPtr<FUICommandInfo>>& Commands);

	/**
	* Checks if a plugin has any unsaved content
	*
	* @param	Plugin			The plugin to check for unsaved content
	* @return	True if all mod content has been saved, false otherwise
	*/
	bool IsAllContentSaved(TSharedRef<IPlugin> Plugin);

private:
	TArray<TSharedPtr<FUICommandInfo>> UGCCommands;
};
