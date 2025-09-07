#pragma once

// Parent Includes
#include "Game_EditPoint.h"

// Generated Includes
#include "VTAK_EditPoint_Mensuration.generated.h"

class AVTAK_Actor_Mensuration;
class AGame_Tool;

UCLASS(Blueprintable, BlueprintType)
class VTAK_MENSURATION_API AVTAK_EditPoint_Mensuration : public AGame_EditPoint
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY()
	AVTAK_Actor_Mensuration* MensurationActor;

	bool bBase;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCollideDuringManipulation;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
	UStaticMeshComponent* LevelMeshComponent;

private:
	bool bWorldLocationCacheValid;

	FVector WorldLocationCache;

	UPROPERTY()
	AGame_Tool* DraggingTool;

	FVector ManipulationBeginEditPointLocation;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_EditPoint_Mensuration(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_Developer_Manipulation
	// ---------------------------------

public:
	virtual bool GetWorldTransform_Implementation(FTransform& localToWorld);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual bool GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList) override;

	virtual bool GetRotationAxisList_Implementation(EAxisListBlueprint& axisList) override;

	virtual void PostManipulationBegin() override;

	virtual void PostManipulationInProgress() override;

	virtual void PostManipulationEnd() override;

	virtual bool PostClickPressed(AActor* actor, const FKey& buttonPressed) override;

	virtual void PostClickReleased(AActor* actor, const FKey& buttonPressed) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void ShowLevel(bool bShowLevel);
};