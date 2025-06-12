#pragma once

// Parent Includes
#include "Game_WorldActor.h"

// VH Plugin Includes
#include "Interface_Developer_Manipulation.h"
#include "Interface_UI_ContextMenuSource.h"

// Generated Includes
#include "Game_WorldInteractableActor.generated.h"

class UGame_CameraScalingComponent;
class UGame_Operation_Drag;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_WorldInteractableActor : public AGame_WorldActor, public IInterface_Developer_Manipulation, public IInterface_UI_ContextMenuSource
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_WorldInteractableActor(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManipulationInProgress, AActor*, manipulatedActor);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManipulationBegin, AActor*, manipulatedActor);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManipulationEnd, AActor*, manipulatedActor);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<UObject>> ContextOptionClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_CameraScalingComponent* CameraScalingComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCenterOnTraceBeam;

	UPROPERTY(BlueprintAssignable)
	FOnManipulationInProgress OnManipulationInProgress;

	UPROPERTY(BlueprintAssignable)
	FOnManipulationBegin OnManipulationBegin;

	UPROPERTY(BlueprintAssignable)
	FOnManipulationEnd OnManipulationEnd;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double HoverScaleModifier;

	/* seconds of delay before drag operation begins moving actor */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double DragDelaySeconds;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_Operation_Drag> DragOperationClass;

protected:
	UPROPERTY()
	UGame_Operation_Drag* DragOperation;

	double ClickPressedTime;

	
	// ---------------------------------
	// --- IInterface_UI_ContextMenuSource
	// ---------------------------------

public:
	void GetContextOptionClasses_Implementation(TSet<TSubclassOf<UObject>>& contextOptionClasses);


	// ---------------------------------
	// --- Interface_Developer_Manipulation
	// ---------------------------------

public:
	virtual bool GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList);

	virtual bool GetRotationAxisList_Implementation(EAxisListBlueprint& axisList);

	virtual bool GetRotationDisabled_Implementation();

	virtual bool GetScaleAxisList_Implementation(EAxisListBlueprint& axisList);

	virtual void ManipulationBegin_Implementation();

	virtual void ManipulationInProgress_Implementation();

	virtual void ManipulationEnd_Implementation();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveBeginHover(AActor* actor);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveEndHover(AActor* actor);
	
	/* return true to halt base class implemenation (selection and context menu) */
	UFUNCTION(BlueprintImplementableEvent)
	bool ReceiveClickPressed(AActor* actor, const FKey& buttonReleased);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveClickReleased(AActor* actor, const FKey& buttonReleased);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveManipulationBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveManipulationInProgress();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveManipulationEnd();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void PostBeginHover(AActor* actor);

	virtual void PostEndHover(AActor* actor);

	/* return true to halt base class implementation of starting UGame_Operation_Drag */
	virtual bool PostClickPressed(AActor* actor, const FKey& buttonPressed);

	/* opens context menu if Execute_GetContextOptionClasses() returns any options */
	virtual void PostClickReleased(AActor* actor, const FKey& buttonReleased);

	virtual void PostManipulationBegin();

	virtual void PostManipulationInProgress();

	virtual void PostManipulationEnd();

	virtual double GetSettingScaleMultiplier() const;

private:
	void BeginHover(AActor* actor);

	void EndHover(AActor* actor);

	void ClickPressed(AActor* actor, const FKey& buttonPressed);

	void ClickReleased(AActor* actor, const FKey& buttonPressed);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:
	UFUNCTION()
	void HandleBeginCursorOver(AActor* actor);

	UFUNCTION()
	void HandleEndCursorOver(AActor* actor);

	UFUNCTION()
	void HandleClickPressed(AActor* actor, FKey buttonPressed);

	UFUNCTION()
	void HandleClickReleased(AActor* actor, FKey buttonPressed);
};
