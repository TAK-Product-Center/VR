// Required Includes
#include "Game_UserWidget_FileArrayDisplay.h"
#include "Game.h"

// Engine Plugins
#include "Async/Async.h"

// VH Plugin Includes
#include "UI_Statics.h"

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_FileArrayDisplay::SelectFile(const FString& windowTitle, const FString& initialPath, const FString& initialFilename, const TMap<FString, FString>& fileTypes, bool bIsMultiSelect)
{
	// if there is any current running threads, don't run another one
	if (ThreadCounter.GetValue() == 0)
	{
		// perform an async task to select the json file. if it is not performed asynchronously, then
		// the game thread will get locked up while the user is selecting files.
		TUniqueFunction<TArray<FString>()> task = [this, windowTitle, initialPath, initialFilename, fileTypes, bIsMultiSelect]()
		{
			// inrease the thread counter to indicate that there is a thread currently running for this object instance. 
			ThreadCounter.Increment();

			// this is the array that will hold the selected json files
			TArray<FString> outSelectedTilesets;

			// the select file browser will return false if no file is selected. if no file is selected, then there's no file to pass back
			// so simply end logic. if true, then go into the game thread and return the selected file paths.
			if (UUI_Statics::OpenFileBrowser(windowTitle, initialPath, initialFilename, fileTypes, bIsMultiSelect, outSelectedTilesets))
			{
				// return the string to the thread
				return outSelectedTilesets;
			}

			// return empty string array if something goes wrong
			return TArray<FString>();
		};

		// this is the function that is called whenever the Async function at the bottom is done
		TUniqueFunction<void()> callback = [this]()
		{
			// send a task to the game thread so we can call the BlueprintImplementableEvent
			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				// ensure that this object is still valid, ensure that the TFuture<TArray<FString>> TilesetFiles is still valid and ensure that the
				// string array is not empty
				if (IsValid(this) && TilesetFiles.IsValid() && !TilesetFiles.Get().IsEmpty())
				{
					// iterate throught the Tilesets and add each one
					for (const FString& tilesetFile : TilesetFiles.Get())
					{
						// send the selected tileset to blueprints
						ReceiveSelectedFile(tilesetFile);
					}
				}

				// reset the TilesetFiles since we don't need it any more. also needs to be done in the game thread
				TilesetFiles.Reset();
			});

			// decrement the thread counter to allow the set path function to be ran again
			ThreadCounter.Decrement();
		};

		// perform the async tasks and callback
		TilesetFiles = Async(EAsyncExecution::ThreadPool, MoveTemp(task), MoveTemp(callback));
	}
}