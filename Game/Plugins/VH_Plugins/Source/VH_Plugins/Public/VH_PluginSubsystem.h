#pragma once

// Engine Includes
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/IPluginManager.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Styling/SlateBrush.h"

// Module Includes
#include "VH_PluginActor.h"

// Generated Includes
#include "VH_PluginSubsystem.generated.h"

/**
 * Holds basic information for each plugin
 */
UENUM(BlueprintType)
enum class EPluginLoadError : uint8
{
	NoError,

	VersionMismatch,

	UnknownError,
};

USTRUCT(Blueprintable)
struct FPluginInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FName PluginName;

	EPluginType PluginType;

	UPROPERTY(BlueprintReadOnly)
	FString PluginPath; // path to plugin's root dir; we don't want the user changing this.

	UPROPERTY(BlueprintReadOnly)
	FString DescriptorPath; // path to .uplugin file; we don't want the user changing this.

	/**
	 * Longer form of the name, does not need to match class name of the plugin
	 */
	UPROPERTY(BlueprintReadOnly)
	FString FriendlyName;

	UPROPERTY(BlueprintReadOnly)
	FString Description;

	UPROPERTY(BlueprintReadOnly)
	FSlateBrush Icon;

	UPROPERTY(BlueprintReadOnly)
	int32 VersionNum;

	UPROPERTY(BlueprintReadOnly)
	FString VersionName;

	UPROPERTY(BlueprintReadOnly)
	FString Author;

	/**
	 * Whether this plugin is currently enabled
	 */
	UPROPERTY(BlueprintReadOnly)
	bool bEnabled;

	/**
	 * Reason why plugin was not loaded correctly.
	 */
	UPROPERTY(BlueprintReadOnly)
	EPluginLoadError PluginError;

	/**
	 * Whether this plugin should be deleted.
	 */
	UPROPERTY(BlueprintReadOnly)
	bool bSlatedForDeletion;

	/**
	 * if true, then we'll want to propagate the changes to the plugin descriptor (.uplugin) file.
	 */
	UPROPERTY(BlueprintReadOnly)
	bool bDirty;

	FPluginInfo()
	{
		PluginError = EPluginLoadError::UnknownError;
		VersionNum = 0;
		bEnabled = false;
		bSlatedForDeletion = false;
		bDirty = false;
	}
};

/**
 * The VH_PluginSubsystem tracks and manages app-level plugins.
 */
UCLASS()
class VH_PLUGINS_API UVH_PluginSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Members
	// ---------------------------------
private:
	/**
	 * List of all registered plugins, whether they are loaded or not. Changes here are eventually propagated
	 * to the plugin descriptors and then written to disk.
	 */
	TMap<FName, FPluginInfo> RegisteredPlugins;

	/**
	 * Original state of all registered plugins, as they are added and initialized. Used to keep track of whether a 
	 * plugin should be regarded as dirty and requires an update.
	 */
	TMap<FName, FPluginInfo> OriginalPluginState;

	/**
	 * List of all descriptors associated with the registered plugins. 
	 */
	TMap<FName, TSharedRef<const FPluginDescriptor>> RegisteredPluginDescriptors;

	/**
	 * Plugin actors for all loaded plugins
	 */
	TArray<TSubclassOf<AVH_PluginActor>> PluginActorClasses;
	TArray<AVH_PluginActor*> PluginActors;

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	/**
	 * Register a new plugin.
	 *
	 * @param pluginName Name of new plugin to register.
	 * @return False if 'pluginName' is already a registered plugin.
	 * @note Looks up a plugin that has already been loaded by plugin manager and adds it to the plugin list and descriptor cache.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	virtual bool RegisterPlugin(const FName& pluginName);

	/**
	 * Unregister a plugin.
	 *
	 * @param pluginName Name of plugin to unregister.
	 * @return False if 'pluginName' is not a registered plugin.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	virtual bool UnregisterPlugin(const FName& pluginName);

	/**
	 * Get all registered plugin info.
	 *
	 * @return Map of plugin name -> isLoaded.
	 */
	UFUNCTION(BlueprintPure, Category = "VhPlugins|PluginSubsystem")
	TMap<FName, FPluginInfo>& GetRegisteredPlugins();

	// General DLC Asset Access. Create Similar Methods For Getting Materials, Textures, etc.

	/**
	 * Get all subclasses of the specified class within the specified plugin
	 * WARNING: This function does not seem to work as of 4.26 upgrade
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VhPlugins|PluginSubsystem")
	bool GetClassesInPlugin(const FString& packageName, TArray<UClass*>& classes, UClass* classFilter); //= TSubclassOf(TClassType(UClass) ));
	//There will have to be a plugin actor class in native that we can derive from for all plugin actors, and we can use that as a search param for finding plugin actors to spawn.

	/**
	 *  Returns All Maps in a Plugin.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VhPlugins|PluginSubsystem")
	bool GetMapsInPlugin(const FString& packagePath, TArray<FName>& maps);

	/**
	 * Loads or unloads a plugin dynamically.
	 *
	 * @param pluginName Name of plugin to load/unload.
	 * @param bIsLoaded Set TRUE to load the plugin, or FALSE to unload the plugin.
	 * @note This currently just sets a bool. Actual dynamic/runtime loading and unloading of plugins is WIP.
	 * @return False if 'pluginName' is not a registered plugin.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	virtual bool SetPluginLoaded(const FName& pluginName, bool bIsLoaded);

	/**
	 * Sets a plugin to be enabled or disabled. On its own, it only sets the boolean
	 * for the corresponding plugin entry in the list of plugins and marks it as dirty.
	 *
	 * @param pluginName Name of plugin to be enabled or disabled.
	 * @param bEnabled boolean to determine whether a plugin should be enabled or disabled.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	void SetPluginEnabled(const FName& pluginName, bool bIsEnabled = true);

	/**
	 * Sets a plugin to be deleted. On its own, it only sets the slated for deletion boolean 
	 * for the corresponding plugin entry in the list of plugins and marks it as dirty.
	 *
	 * @param pluginName Name of plugin to be deleted.
	 * @param bEnabled boolean to determine whether a plugin should be deleted on next restart or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	void SetPluginDeletion(const FName& pluginName, bool bShouldDelete);

	/**
	 * Sets the friendly name for a plugin.
	 *
	 * @param pluginName Name of plugin.
	 * @param friendlyName new friendly name of this plugin.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	void SetPluginFriendlyName(const FName& pluginName, const FString& friendlyName);

	/**
	 * Sets the description for a plugin.
	 *
	 * @param pluginName Name of plugin.
	 * @param friendlyName new description of this plugin.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	void SetPluginDescription(const FName& pluginName, const FString& pluginDescription);

	/**
	 * Sets the version and version name for a plugin.
	 *
	 * @param pluginName Name of plugin.
	 * @param versionNum version number for this plugin.
	 * @param veresionName version string for this plugin.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	void SetPluginVersion(const FName& pluginName, int32 versionNum, const FString& versionName);

	/**
	 * Sets the author for a plugin.
	 *
	 * @param pluginName Name of plugin.
	 * @param pluginAuthor author for this plugin.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	void SetPluginAuthor(const FName& pluginName, const FString& pluginAuthor);

	/**
	 * Update the plugin descriptor file for one plugin. 
	 *
	 * @param pluginName Name of plugin to update.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	bool UpdatePlugin(const FName& pluginName);

	/**
	 * Update the plugin descriptor files for all "dirty" plugins.
	 * If the plugin descriptor update succeeds, fully restart game to run with new settings.
	 * 
	 * @param bWithRestart If false, this function will update the descriptors, but will not fully restart.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	void UpdateAllPlugins(bool bWithRestart = true);

	/**
	 * Import a new plugin zip from an external location.
	 *
	 * @param importFile full path to the plugin zip file
	 * @return False if the unzip failed or if a uplugin file was not found in the zip.
	 * @note Currently assumes all plugin files are in a zipped archive file, and they are auto-extracted to a local cache.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhPlugins|PluginSubsystem")
	bool ImportPlugin(const FString& importFile);

	/**
	 * Go through the array of plugin actors to make sure it matches the array of plugin classes
	 * This involves adding new and removing null actor references
	 */
	void UpdatePluginActors(UWorld* world);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	/**
	 * Initial registration of all currently discovered external plugins.
	 */
	void InitialPluginRegistration();

	/**
	 * Handle invalid plugins registration or deletion.
	 * @return true if invalid plugin handled correctly, false otherwise.
	 */
	bool HandleInvalidPlugin(const FInvalidPlugin& invalidPlugin);

	/**
	 * Gets the asset registry, cached or not
	 */
	FAssetRegistryModule* CachedAssetRegistryModule;
	IAssetRegistry& GetAsstRegistry();

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
protected:
	/*
	 * \brief Collects extra info (in JSON format) to be included in a crash log header.
	 * \param logLines The string array to which to append the extra crash info.
	 * \note logLines expects properly formatted JSON entries.
	 * \note *IMPORTANT* Must end by adding a final ',' to logLines.
	 * \note Currently unsupported for BP's.
	 */
	UFUNCTION()
	void HandleGenerateCrashLog(TArray<FString>& logLines);
};
