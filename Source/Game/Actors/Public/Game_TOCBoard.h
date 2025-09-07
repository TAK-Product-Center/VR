#pragma once

// Parent Includes
#include "Game_WorldInteractableActor.h"

// Engine Includes
#include "Input/Events.h"

// VH Platform Includes
#include "Database_Spatialite.h"

// Generated Includes
#include "Game_TOCBoard.generated.h"

class UBoxComponent;
class AGame_PopoutInputListener;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_TOCBoard : public AGame_WorldInteractableActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnURLChanged, const FString&, url);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnURLChanged OnURLChanged;

	/* amount to increment/decrement ScaleMultipler by during ScaleUp() and ScaleDown() */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double ScaleMultiplerIncrement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBoxComponent* CollisionMesh;

private:
	static TSharedPtr<AGame_PopoutInputListener> SharedListener;
	
	double ScaleMultiplier;
	
	FVector OriginalScale;

	FString ID;

	bool bCanAdjustDist;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_TOCBoard(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual bool PostClickPressed(AActor* actor, const FKey& buttonPressed) override;

	virtual void PostClickReleased(AActor* actor, const FKey& buttonReleased) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ReceiveSetURL(const FString& url);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FString ReceiveGetURL();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void AttemptShortcutToggle();

	UFUNCTION(BlueprintCallable)
	void ScaleUp();

	UFUNCTION(BlueprintCallable)
	void ScaleDown();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hit);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex);

	void SyncToResult(const SpatialiteResult& result);

	void SetID(const FString& id);

	FString GetID() const;

	bool GetCanAdjustDist() const;

	void SetCanAdjustDist(bool bNewCanAdjustDist);
	
	void HandleKeyDownEvent(const FKeyEvent& inKeyEvent);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool AllowInteraction(AActor* actor) const;
};
