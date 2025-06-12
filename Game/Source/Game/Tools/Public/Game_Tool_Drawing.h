#pragma once

// Parent Includes
#include "Game_Tool.h"

// Generated Includes
#include "Game_Tool_Drawing.generated.h"

class AGame_DrawContainer;
class AGame_SimpleSegmentedLineActor;
class UGame_COTComponent_Draw;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Tool_Drawing : public AGame_Tool
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor DefaultDrawColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_DrawContainer> DrawContainerClass;
	 
protected:
	UPROPERTY()
	AGame_DrawContainer* DrawContainer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AGame_SimpleSegmentedLineActor* Line;

	 
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Tool_Drawing(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void EndPlay(EEndPlayReason::Type endPlayReason) override;

protected:
	virtual void PostTriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults) override;

	virtual void PostTriggerReleased() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SpawnDrawContainer();

	UFUNCTION(BlueprintCallable)
	UGame_COTComponent_Draw* GetDrawComponent() const;

	UFUNCTION(BlueprintCallable)
	void SetDrawContainer(AGame_DrawContainer* drawContaineerArg);

	UFUNCTION(BlueprintCallable)
	AGame_DrawContainer* GetDrawContainer() const;
};