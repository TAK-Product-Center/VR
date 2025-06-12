// Parent Includes
#include "UObject/Object.h"

// Game Includes
#include "Game_UserWidget_RibbonButton.h"

// Generated Includes
#include "Game_RibbonButtonRegistrar.generated.h"

class AGame_Tool;
class UWorld;


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FRibbonButtonInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_UserWidget_RibbonButton> RibbonButtonClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Tab;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Category;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Text;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString RibbonToolTipText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double IndexInCategory;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FSlateBrush Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Tool> ToolClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> DropdownClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCollapseOnDisable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, int32> EnableConditions;

	FRibbonButtonInfo()
	{
		RibbonButtonClass = UGame_UserWidget_RibbonButton::StaticClass();
		ID = TEXT("");
		Tab = TEXT("");
		Category = TEXT("");
		Text = TEXT("");
		RibbonToolTipText = TEXT("");
		IndexInCategory = 0;
		bCollapseOnDisable = true;
		EnableConditions = TMap<FString, int>();
	}
};

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_RibbonButtonRegistrar : public UObject
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FRibbonButtonInfo> RibbonButtonInfos;

private:
	UPROPERTY()
	UWorld* World;

	 
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_RibbonButtonRegistrar(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	
public:
	virtual UWorld* GetWorld() const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void RegisterRibbonButtons(UWorld* world);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveRegisterRibbonButtons();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveFinishedRegisterRibbonButtons();
};