#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "Interface_UI_ContextMenu.h"

// Generated Includes
#include "Game_UserWidget_ContextMenu_Radial.generated.h"


// ---------------------------------
// --- Structs
// ---------------------------------

// work-around because cannot have TArray in TMap
USTRUCT(BlueprintType)
struct FPositionsStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector2D> Positions;
};

// work-around because cannot have TSet in TArry
USTRUCT()
struct FObjectSet
{
	GENERATED_BODY()

	UPROPERTY()
	TSet<UObject*> Objects;
};

typedef TSet<UObject*> ObjectSet;

class UCanvasPanel;

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_ContextMenu_Radial : public UUserWidget, public IInterface_UI_ContextMenu
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bTrackSource;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> ContextMenuOptionClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int32, FPositionsStruct> ContextMenuOptionPositions;

private:
	UPROPERTY()
	UObject* Source;

	UPROPERTY()
	AActor* Instigator;

	UPROPERTY()
	TArray<FObjectSet> OptionsHistory;

	bool bSkipSyncToGameTool;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_ContextMenu_Radial(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- IInterface_UI_ContextMenu
	// ---------------------------------
	
public:
	void SetContextMenuInformation_Implementation(AActor* instigator, UObject* source, const TSet<UObject*>& contextOptions);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void NativeTick(const FGeometry& myGeometry, float deltaSeconds) override;


	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintCallable)
	void LoadMostRecentPreviousOptions();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetBackAvailable(bool bAvailable) const;

	UFUNCTION(BlueprintImplementableEvent)
	UCanvasPanel* GetCanvasPanel() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveContextMenuOptionCreated(int32 numberOfOptions, int32 contextMenuOptionIndex, UUserWidget* contextMenuOptionWidget, UObject* contextOption);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void MoveToSourceLocation();

	void CreateContextMenuOptions(const TSet<UObject*>& contextOptions);
};