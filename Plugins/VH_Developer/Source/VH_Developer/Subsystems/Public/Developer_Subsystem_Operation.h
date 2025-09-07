#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// Engine Includes
#include "Engine/EngineBaseTypes.h"

// Generated Includes
#include "Developer_Subsystem_Operation.generated.h"

class UDeveloper_Operation;

UCLASS()
class VH_DEVELOPER_API UDeveloper_Subsystem_Operation : public UWorldSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DELEGATE_ThreeParams(FInputActionHandler, FString, FString, EInputEvent);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	// TPair is <priority, operation>
	TArray<TPair<double, UDeveloper_Operation*>> PrioritizedOperations;

	UPROPERTY()
	TSet<UDeveloper_Operation*> Operations;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Subsystem_Operation();

	
	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UDeveloper_Subsystem_Operation* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;
	

	// ---------------------------------
	// --- API
	// ---------------------------------

public: 
	/* \brief Starts an operation by class
	*  \param operationClass Class of operation to start
	*  \param priority Operations receive input in order of priority (highest to lowest).
	*  \return Created operation
	*/
	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "operationClass"))
	UDeveloper_Operation* StartOperationByClass(TSubclassOf<UDeveloper_Operation> operationClass, double priority);

	/* \brief Starts an operation 
	*  \param operation Operation to start
	*  \param priority Operations receive input in order of priority (highest to lowest). 
	*  \return False if operation already started
	*/
	UFUNCTION(BlueprintCallable)
	bool StartOperation(UDeveloper_Operation* operation, double priority);

	UFUNCTION(BlueprintCallable)
	void StopOperation(UDeveloper_Operation* operation);

	template <class T>
	TSet<T*> GetOperationsByClass() const
	{
		TSet<T*> operations;

		for (const TPair<double, UObject*>& entry : PrioritizedOperations)
		{
			if (entry.Value->GetClass()->IsChildOf(T::StaticClass()))
			{
				operations.Add(Cast<T>(entry.Value));
			}
		}

		return operations;
	}

	UFUNCTION(BlueprintPure)
	TSet<UDeveloper_Operation*> GetOperationsByClass(TSubclassOf<UDeveloper_Operation> operationClass) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void BindOperationInputs(UDeveloper_Operation* operation);

	void UnbindOperationInputs(UDeveloper_Operation* operation);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleInputAction(const FInputActionInstance& inputActionInstance);
};