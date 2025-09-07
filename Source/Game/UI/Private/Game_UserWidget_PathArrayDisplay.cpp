// Required Includes
#include "Game_UserWidget_PathArrayDisplay.h"
#include "Game.h"

// Engine Includes
#include "Misc/Paths.h"
#include "Async/Async.h"

// VH Plugin Includes
#include "UI_Statics.h"

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_PathArrayDisplay::SelectPath(const FString& windowTitle, const FString& initialPath)
{
	// if there is any current running threads, don't run another one
	if (ThreadCounter.GetValue() == 0)
	{
		// perform an async task to select the path. if it is not performed asynchronously, then
		// the game thread will get locked up while the user is selecting paths.
		TUniqueFunction<FString()> task = [this, windowTitle, initialPath]()
		{
			// inrease the thread counter to indicate that there is a thread currently running for this object instance. 
			ThreadCounter.Increment();

			// this is the string that is selected from the Windows folder selection prompt
			FString outSelectedPath;

			// the select folder browser will return false if no folder is selected. if no folder is selected, then there's no folder to pass back
			// so simply end logic. if true, then go into the game thread and return the selected folder paths.
			if (UUI_Statics::SelectFolderBrowser(windowTitle, initialPath, outSelectedPath))
			{
				// by this point, the user should have selected the path
				if (!outSelectedPath.IsEmpty() && FPaths::DirectoryExists(outSelectedPath))
				{
					// return the string to the thread
					return outSelectedPath;
				}
			}

			// return empty string if something goes wrong
			return FString();
		};

		// this is the function that is called whenever the Async function at the bottom is done
		TUniqueFunction<void()> callback = [this]()
		{
			// send a task to the game thread so we can call the BlueprintImplementableEvent
			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				// ensure that this object is still valid, ensure that the TFuture<FString> Path is still valid and ensure that the string is
				// not empty
				if (IsValid(this) && Path.IsValid() && !Path.Get().IsEmpty())
				{
					// send the selected path to blueprints
					ReceiveSelectedPath(Path.Get());
				}

				// reset the path since we don't need it any more. also needs to be done in the game thread
				Path.Reset();
			});

			// decrement the thread counter to allow the set path function to be ran again
			ThreadCounter.Decrement();
		};

		// perform the async tasks and callback
		Path = Async(EAsyncExecution::ThreadPool, MoveTemp(task), MoveTemp(callback));
	}
}

void UGame_UserWidget_PathArrayDisplay::SelectFile(const FString& windowTitle, const FString& initialPath, const FString& initialFilename, const TMap<FString, FString>& fileTypes, bool bIsSaving)
{
	// if there is any current running threads, don't run another one
	if (ThreadCounter.GetValue() == 0)
	{
		// perform an async task to select the path. if it is not performed asynchronously, then
		// the game thread will get locked up while the user is selecting paths.
		TUniqueFunction<FString()> task = [this, windowTitle, initialPath, initialFilename, fileTypes, bIsSaving]()
		{
			// inrease the thread counter to indicate that there is a thread currently running for this object instance. 
			ThreadCounter.Increment();

			// this is the string that is selected from the Windows folder selection prompt
			TArray<FString> outSelectedFilenames;

			int32 outSelectedFilterIndex;

			// the select folder browser will return false if no folder is selected. if no folder is selected, then there's no folder to pass back
			// so simply end logic. if true, then go into the game thread and return the selected folder paths.
			if (UUI_Statics::SelectFileBrowser(windowTitle, initialPath, initialFilename, fileTypes, bIsSaving, false, outSelectedFilenames, outSelectedFilterIndex))
			{
				// by this point, the user should have selected the path
				if (!outSelectedFilenames.IsEmpty() && FPaths::FileExists(outSelectedFilenames[0]))
				{
					// return the string to the thread
					return outSelectedFilenames[0];
				}
			}

			// return empty string if something goes wrong
			return FString();
		};

		// this is the function that is called whenever the Async function at the bottom is done
		TUniqueFunction<void()> callback = [this]()
		{
			// send a task to the game thread so we can call the BlueprintImplementableEvent
			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				// ensure that this object is still valid, ensure that the TFuture<FString> Path is still valid and ensure that the string is
				// not empty
				if (IsValid(this) && Path.IsValid() && !Path.Get().IsEmpty())
				{
					// send the selected path to blueprints
					ReceiveSelectedFile(Path.Get());
				}

				// reset the path since we don't need it any more. also needs to be done in the game thread
				Path.Reset();
			});

			// decrement the thread counter to allow the set path function to be ran again
			ThreadCounter.Decrement();
		};

		// perform the async tasks and callback
		Path = Async(EAsyncExecution::ThreadPool, MoveTemp(task), MoveTemp(callback));
	}
}
