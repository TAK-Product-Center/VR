#pragma once

// Parent Includes
#include "Game_SimpleSegmentedLineActor.h"

// Generated Includes
#include "VTAK_Line_Mensuration.generated.h"

class AVTAK_Actor_Mensuration;

UCLASS(Blueprintable, BlueprintType)
class VTAK_MENSURATION_API AVTAK_Line_Mensuration : public AGame_SimpleSegmentedLineActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY()
	AVTAK_Actor_Mensuration* MensurationActor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double FixedUILineScaleTOC;

private:
	// relative transform from center of line at beginning of manipulation
	FTransform ManipulationBeginBaseTransform;

	// relative transform from center of line at beginning of manipulation
	FTransform ManipulationBeginArrowTransform;

	FVector ManipulationBeginBaseLocation;
	FVector ManipulationBeginArrowLocation;


	// --------------------------------- 
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_Line_Mensuration(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_Developer_Manipulation
	// ---------------------------------

public:
	virtual bool GetWorldTransform_Implementation(FTransform& localToWorld);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	
protected:
	virtual bool GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList) override;

	virtual bool GetRotationAxisList_Implementation(EAxisListBlueprint& axisList) override;

	virtual void PostManipulationBegin() override;

	virtual void PostManipulationInProgress() override;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	FTransform GetLineManipulationTransform() const;
};
