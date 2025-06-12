#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_SendTo.generated.h"

class UVH_COTComponent;

UCLASS()
class GAME_API UGame_UserWidget_SendTo : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_SendTo(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UVH_COTComponent* COTComponent;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetCOTComponent(UVH_COTComponent* inCOTComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCOTComponent(UVH_COTComponent* receivedCOTComponent);
};
