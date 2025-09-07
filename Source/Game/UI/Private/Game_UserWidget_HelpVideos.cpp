// Required Includes
#include "Game_UserWidget_HelpVideos.h"
#include "Game.h"

// Engine Includes
#include "Materials/MaterialInstanceDynamic.h"

// Game Includes
#include "Game_Subsystem_Help.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_HelpVideos::UGame_UserWidget_HelpVideos(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_HelpVideos::PlayHelpVideo(UGame_HelpVideo* helpVideo)
{
	if (UGame_Subsystem_Help* subsystem = UGame_Subsystem_Help::Get())
	{
		UGame_Subsystem_Help::FCallbackString callback;
		callback.BindLambda([this](const FString& result)
		{
			ReceiveVideoURL(result);
		});

		subsystem->GetVideoURL(helpVideo, callback);
	}
}