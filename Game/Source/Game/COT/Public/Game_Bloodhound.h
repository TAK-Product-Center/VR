#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "Game_Bloodhound.generated.h"

class AGame_Arrow;
class AVH_GlobeReferenceActor;
class AGame_VirtualObjective;

UCLASS()
class GAME_API AGame_Bloodhound : public AActor
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Arrow> ChaserToTargetArrowClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Arrow> InterceptArrowClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> InterceptActorClass;

	/* maps min/max intercept time to color for intercept line */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FVector2D, FColor> InterceptTimeToColor;

protected:
	UPROPERTY(BlueprintReadOnly)
	AGame_Arrow* ChaserToTargetArrow;

	UPROPERTY(BlueprintReadOnly)
	AGame_Arrow* InterceptArrow;

	UPROPERTY(BlueprintReadOnly)
	AActor* InterceptActor;

	UPROPERTY(BlueprintReadOnly)
	FString ChaserUID;

	UPROPERTY(BlueprintReadOnly)
	FString TargetUID;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
    AGame_Bloodhound();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void Tick(float deltaSec) override;

	virtual void SetActorScale3D(FVector newScale3D) override;

	virtual void SetActorHiddenInGame(bool bNewHidden) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void SpawnActors(AGame_VirtualObjective* virtualObjective, const int32& detailStatus);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSpawnActors(AGame_VirtualObjective* virtualObjective, const int32& detailStatus);

	UFUNCTION(BlueprintCallable)
	void SetChaser(const FString& inChaserUID);

	UFUNCTION(BlueprintCallable)
	void SetTarget(const FString& inTargetUID);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	AActor* GetActor(const FString& entityUID) const;

	AVH_GlobeReferenceActor* GetGlobeReference() const;
	
	void UpdateInterceptInfo();

	float GetVelocitySize(AActor* actor) const;

	FRotator GetRotation(AActor* actor) const;

	bool GetInterceptData(float& interceptTime, FVector& interceptLocation, float& interceptBearing);

	void SetInterceptLineColor(float interceptTime);

    /*
     returns FALSE if quadratic formula is unable to find a solution cases
     where the a solution is not found: #a: Discriminate is negative which then
     makes the actual answer imaginary (example: sqrt(-25) = 5i) #b: both x1 and
     x2 are negative, which means the intercept occurs in the past which cant
     provide valid intercept #c: a is zero, which causes a division by zero
    */
    bool QuadraticCalc(float& x1, float& x2, float a, float b, float c);
};
