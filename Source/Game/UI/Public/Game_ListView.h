#pragma once

// Parent Includes
#include "Components/ListView.h"

// Generated Includes
#include "Game_ListView.generated.h"

UCLASS()
class GAME_API UGame_ListView : public UListView
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, TSubclassOf<UUserWidget>> IDToWidgetClass;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;
};