#pragma once

// Generated Includes
#include "UI_Statics.generated.h"

class UWidget;

UCLASS()
class VH_UI_API UUI_Statics : public UObject
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDialogComplete, bool, bSuccess, const TArray<FString>&, files);

	
	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	/* \brief Sets keyboard focus to widget if widget or any of its descendants has focus
	*  \param widget Widget to test and set focus
	*  \param bHasFocus Set to true if widget or descendants have focus
	*  \param bAlreadyHadKeyboardFocus Set to true if widget already had keyboard focus
	*/
	UFUNCTION(BlueprintCallable)
	static void SyncKeyboardFocus(UWidget* widget, bool& bHasFocus, bool& bAlreadyHadKeyboardFocus);

	/** Parses a string of extensions into an array while stripping extraneous characters -- e.g. passing in ".fbx;kml, *.xyz, .obj" yields { "fbx", "kml", "xyz", "obj" } */
    UFUNCTION(BlueprintCallable, Category = "VH_UI|Archive", meta = (DisplayName = "VH Parse Extensions Into Array"))
    static TArray<FString> ParseExtensionsIntoArray(const FString& extensions);

	// Async method to call OpenFileBrowser
	static void OpenNativeFileBrowserDialogAsync(const FString& dialogTitle, const FString& defaultPath, const TMap<FString, FString>& fileTypes, bool multiSelect, TFunction<void(bool, const TArray<FString>&)> onDialogComplete);

	UFUNCTION(BlueprintCallable, Category="VH_UI|FileBrowser")
	static void OpenNativeFileBrowserDialogAsync(const FString& dialogTitle, const FString& defaultPath, const TMap<FString, FString>& fileTypes, bool multiSelect, FOnDialogComplete onDialogComplete);

	UFUNCTION(BlueprintCallable, Category = "VH_UI|FileBrowser")
	static void SaveNativeFileBrowserDialogAsync(const FString& dialogTitle, const FString& defaultPath, const FString& initialFilename, const TMap<FString, FString>& fileTypes, FOnDialogComplete onDialogComplete);

	/**
	 * @brief	This function will open a folder in the File Explorer of Windows (and potentially other platforms in the future if we decide to).
	 * 
	 * @param	absolutePath - This is the path to the folder the user would like to be opened.
	 * @return	bool - Returns true if the function is able to find the folder and opens the folder. Returns false if the function is unable
	 *			to find the folder or open the folder.
	 */
	UFUNCTION(BlueprintCallable, Category = "VH_UI|FileExplorer", meta = (DisplayName = "VH Open File Explorer"))
	static bool OpenFileExplorer(const FString& absolutePath);

	// Open File Browser window
	UFUNCTION(BlueprintCallable, Category = "VH_UI|FileBrowser")
	static bool OpenFileBrowser(const FString& windowTitle, const FString& initialPath, const FString& initialFilename, const TMap<FString, FString>& fileTypes, bool bIsMultiSelect, TArray<FString>& outSelectedFilenames);

	// Save File Browser window
	UFUNCTION(BlueprintCallable, Category = "VH_UI|FileBrowser")
	static bool SaveFileBrowser(const FString& windowTitle, const FString& initialPath, const FString& initialFilename, const TMap<FString, FString>& fileType, FString& outSelectedFilename);

	// Open Folder Browser window
	UFUNCTION(BlueprintCallable, Category = "VH_UI|FileBrowser")
	static bool SelectFolderBrowser(const FString& windowTitle, const FString& initialPath, FString& outSelectedFolder);

	UFUNCTION(BlueprintCallable, Category = "VH_UI|FileBrowser")
	static bool SelectFileBrowser(const FString& windowTitle, const FString& initialPath, const FString& initialFilename, const TMap<FString, FString>& fileTypes, bool bIsSaving, bool bIsMultiSelect, TArray<FString>& outSelectedFilenames, int32& outSelectedFilterIndex);

};
