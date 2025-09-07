#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_FileArrayDisplay.generated.h"


/**
 *	This class is to allow the user to select a path on the user's machine.
 */
UCLASS()
class GAME_API UGame_UserWidget_FileArrayDisplay : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
protected:

	/** This variable is to hold the future value of the Aysnc process when the user selects the desired tileset files. */
	TFuture<TArray<FString>> TilesetFiles;
	
	/** This variable is to prevent the user from having multiple async processes. Typically, that's a good thing but in this case,
	 *	we only want a single async process just to prevent locking up of the game thread. No need for multiple async processes.
	 */
	FThreadSafeCounter ThreadCounter;


	// ---------------------------------
	// --- API
	// ---------------------------------
protected:

	/**
	 * @brief	This Blueprint Implementable Event is called whenever the user has selected a file from the Windows Prompt. This way, developers
	 *			on the blueprint side can handle that string. 
	 *
	 * @param	selectedFile - This is the string of the file that the user selects from the Windows prompt.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Events|Protected", meta = (DisplayName = "SelectedFileUpdate"))
	void ReceiveSelectedFile(const FString& selectedFile);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------
protected:

	/**
	 * @brief	This function is designed to call the Windows file selection prompt. It does this asynchronously so that it does not hold up
	 *			the game thread. When a file is selected, it then calls the ReceiveSelectedPath blueprint implementable event to send to the
	 *			blueprints.
	 *
	 * @param	windowTitle - This FString parameter defines what the title of the Windows file selection prompt will be at the top of the screen.
	 * @param	initialPath - This FString parameter defines what the path will be when the Windows file selection prompt is opened for the user.
	 * @param	initialFilename - This FString is the initial filename to look for when the Windows file selection prompt is opened for the user.
	 * @param	fileTypes - This FString is the file types that the Windows file selection prompt filters for when the user is looking for a file.
	 * @param	bIsMultiSelect - This bool is determines weather or not the user can select multiple files in the Windows file selection prompt.
	 */
	UFUNCTION(BlueprintCallable, Category = "Implementation|Protected")
	void SelectFile(const FString& windowTitle, const FString& initialPath, const FString& initialFilename, const TMap<FString, FString>& fileTypes, bool bIsMultiSelect);

};
