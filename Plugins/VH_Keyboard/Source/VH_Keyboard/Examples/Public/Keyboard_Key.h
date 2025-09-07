#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Module Includes
#include "KeyData.h"

// Generated Includes
#include "Keyboard_Key.generated.h"

class UKeyboard_ContainerComponent;

UCLASS(Blueprintable, BlueprintType)
class VH_KEYBOARD_API AKeyboard_Key : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FKeyData KeyData;

private:
	UPROPERTY()
	UKeyboard_ContainerComponent* ContainerComponent;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AKeyboard_Key(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	 
public:
	virtual void OnConstruction(const FTransform& transform) override;
	
	virtual void BeginPlay() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetDisplayString(const FString& keyString);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveBeginHover(AActor* actor);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveEndHover(AActor* actor);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveClickPressed(AActor* actor, const FKey& buttonReleased);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveClickReleased(AActor* actor, const FKey& buttonReleased);

	UFUNCTION(BlueprintCallable)
	void Pressed();

	void SetContainerComponent(UKeyboard_ContainerComponent* containerComponent);


	// ---------------------------------
	// --- Implemenation
	// ---------------------------------

private:
	void SyncDisplayString(bool bShiftActive);
	

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleShiftModified(bool bShiftActive);

	UFUNCTION()
	void HandleBeginCursorOver(AActor* actor);

	UFUNCTION()
	void HandleEndCursorOver(AActor* actor);

	UFUNCTION()
	void HandleClickPressed(AActor* actor, FKey buttonPressed);

	UFUNCTION()
	void HandleClickReleased(AActor* actor, FKey buttonPressed);
};
