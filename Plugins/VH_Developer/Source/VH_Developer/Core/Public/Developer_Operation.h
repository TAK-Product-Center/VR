#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Tickable.h"

// Generated Includes
#include "Developer_Operation.generated.h"

class UDeveloper_Subsystem_Operation;
class UInputAction;
class UInputMappingContext;

UCLASS(BlueprintType, Blueprintable)
class VH_DEVELOPER_API UDeveloper_Operation : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

	friend class UDeveloper_Subsystem_Operation;

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSet<UInputAction*> InputActions;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 InputMappingContextPriority;

private:
	bool bShouldTick;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Operation(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- FTickableGameObject
	// ---------------------------------

public:
	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;

	virtual TStatId GetStatId() const override;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual class UWorld* GetWorld() const override;

	virtual void BeginDestroy() override;
	 
	 
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveStart();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveStop();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTick(float deltaSeconds);

	UFUNCTION(BlueprintNativeEvent)
	void ActionInput(const FInputActionInstance& inputActionInstance);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void PostStart();

	virtual void PostStop();

	virtual void PostTick(float deltaSeconds);

private:
	void Start();

	void Stop();
};