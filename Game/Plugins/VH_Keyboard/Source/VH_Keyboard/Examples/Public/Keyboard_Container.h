#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Module Includes
#include "Interface_Keyboard_Container.h"

// Generated Includes
#include "Keyboard_Container.generated.h"

class UKeyboard_ContainerComponent;

UCLASS(Blueprintable, BlueprintType)
class VH_KEYBOARD_API AKeyboard_Container : public AActor, public IInterface_Keyboard_Container
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UKeyboard_ContainerComponent* ContainerComponent;

	/* from player viewpoint */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector SpawnRelativeLocation;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AKeyboard_Container(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_Keyboard_Container
	// ---------------------------------

public:
	virtual void InitializeAtTransform_Implementation(const FTransform& transform) override;

	virtual void InitializeForObject_Implementation(UObject* object) override;
	
	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;


	// ---------------------------------
	// --- API
	// ---------------------------------
	 
public:
	UFUNCTION(BlueprintPure)
	FString GetFocusedWidgetText() const;
	

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void SetKeysContainerComponent();
};