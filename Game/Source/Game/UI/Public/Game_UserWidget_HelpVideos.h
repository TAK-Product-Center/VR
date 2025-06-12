#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_HelpVideos.generated.h"

class UGame_HelpVideo;
class UMaterialInstanceDynamic;

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_HelpVideos : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInstanceDynamic* VideoMaterial;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_HelpVideos(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveVideoURL(const FString& url);

	UFUNCTION(BlueprintCallable)
	void PlayHelpVideo(UGame_HelpVideo* helpVideo);
};