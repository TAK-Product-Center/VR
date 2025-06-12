#pragma once

// Parent Includes
#include "UObject/Object.h"
#include "Tickable.h"

// Engine Includes
#include "Templates/SubclassOf.h"
#include "Styling/SlateBrush.h"

// VH Plugin Includes
#include "Interface_UI_ContextMenuOption.h"

// Generated Includees
#include "Game_ContextMenuOption.generated.h"

class APlayerController;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_ContextMenuOption : public UObject, public FTickableGameObject, public IInterface_UI_ContextMenuOption
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExecuted, UGame_ContextMenuOption*, contextMenuOption);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVisualsChanged);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FExecuted OnExecuted;

	/* must be called to notify context option's UI when Icon, Text, or Tooltip is changed */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FVisualsChanged OnVisualsChanged;

	/* used by default if GetIcon does not have a blueprint implementation */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FSlateBrush Icon;

	/* used by default if GetText does not have a blueprint implementation */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Text;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Tooltip;

	/* if true and SubOptionClasses is empty, closes owning context menu after Execute() */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCloseAfterExecute;

	/* execute will switch to these options; ignores bCloseAfterExecute and remains open to show suboptions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UObject>> SubOptionClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bShouldTick;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	AActor* Instigator;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UObject* Source;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_ContextMenuOption(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------

public:
	virtual TStatId GetStatId() const override;

	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;


	// ---------------------------------
	// --- Interface_UI_ContextMenuOption
	// ---------------------------------

public:
	void SetInstigatorAndSource_Implementation(AActor* instigatorParam, UObject* sourceParam);

	void Execute_Implementation();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	static UGame_ContextMenuOption* CreateContextMenuOption(const FSlateBrush& iconArg, const FString& textArg, const FString& tooltipArg);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual class UWorld* GetWorld() const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void CloseContextMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FSlateBrush GetIcon() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FString GetText() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FString GetTooltip() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetSubOptions(TSet<UObject*>& subOptions) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TSet<TSubclassOf<UObject>> GetSubOptionClasses() const;

	/*
	* \brief Determines if this option should show when the context menu it belongs to is opened
	* \param instigator PlayerController that interacted with the source
	* \param source Object that was interacted with by the instigator
	* \return True if option should show
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure = false)
	bool GetVisible() const;

	/*
	* \brief Determines if this option should be enabled the context menu it belongs to is opened
	* \param instigator PlayerController that interacted with the source
	* \param source Object that was interacted with by the instigator
	* \return True if option should show
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintPure = false)
	bool GetEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveExecute();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTick(float deltaSeconds);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void PostExecute();
};
