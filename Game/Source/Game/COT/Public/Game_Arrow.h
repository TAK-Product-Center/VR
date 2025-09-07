#pragma once

#include "GameFramework/Actor.h"

#include "Game_Arrow.generated.h"

class AGame_SimpleSegmentedLineActor;
class AGame_EditPoint;
class UGame_UserWidget_Arrow;
class UWidgetComponent;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Arrow : public AActor
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Arrow();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_SimpleSegmentedLineActor> LineClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_EditPoint> BaseEditPointClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_EditPoint> ArrowEditPointClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bSyncLineToEditPoints;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bPointArrowEditPoint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    AActor* LinkedBaseActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    AActor* LinkedArrowActor;

	/* Percentage (between 0 and 1) of the distance between the player and the widget that the widget will be moved to */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double PercentageOfDistance;

protected:
	UPROPERTY()
    AGame_EditPoint* BaseEditPoint;

    UPROPERTY()
    AGame_EditPoint* ArrowEditPoint;

	UPROPERTY()
	AGame_SimpleSegmentedLineActor* Line;

	UPROPERTY()
	UGame_UserWidget_Arrow* ArrowWidget;

private:
	bool bInitialSetLocation;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
    virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

    virtual void Tick(float deltaSec) override;

	virtual void SetActorHiddenInGame(bool bNewHidden) override;

	virtual void SetActorScale3D(FVector newScale3D) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetInitialLocation(const FVector& location);

	UFUNCTION(BlueprintImplementableEvent)
	UGame_UserWidget_Arrow* CreateUIWidget();

	UFUNCTION(BlueprintImplementableEvent)
	UWidgetComponent* GetWidgetComponent();

	UFUNCTION(BlueprintPure)
	AGame_SimpleSegmentedLineActor* GetLine() const;

	UFUNCTION(BlueprintPure)
	AGame_EditPoint* GetBaseEditPoint() const;

	UFUNCTION(BlueprintPure)
	AGame_EditPoint* GetArrowEditPoint() const;

	UFUNCTION(BlueprintCallable)
	UGame_UserWidget_Arrow* GetUIWidget() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void SpawnEditPointsAndLine();

private:
	void SyncLineToEditPoints();
};
