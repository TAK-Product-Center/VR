#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "UObject/ScriptInterface.h"
#include "Engine/EngineTypes.h"

// Module Includes
#include "Interface_Developer_Task.h"

// Generated Includes
#include "Developer_TaskScheduler.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_TaskScheduler : public UObject
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskAdded, TScriptInterface<IInterface_Developer_Task>, task);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskStarted, TScriptInterface<IInterface_Developer_Task>, task);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskFinished, TScriptInterface<IInterface_Developer_Task>, task);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FTaskAdded OnTaskAdded;

	UPROPERTY(BlueprintAssignable)
	FTaskStarted OnTaskStarted;

	UPROPERTY(BlueprintAssignable)
	FTaskFinished OnTaskFinished;

private:
	FString ID;

	FTimerHandle TaskCheckTimerHandle;

	int32 MaxConcurrentTasks;

	int32 ConcurrentTasks;

	float SecondsBetweenChecks;

	UPROPERTY()
	TArray<TScriptInterface<IInterface_Developer_Task>> Tasks;

	UPROPERTY()
	TArray<TScriptInterface<IInterface_Developer_Task>> ActiveTasks;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UDeveloper_TaskScheduler();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void Start(const FString& inID);

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION(BlueprintPure)
	FString GetID() const;

	UFUNCTION(BlueprintPure)
	float GetSecondsBetweenChecks() const;

	UFUNCTION(BlueprintCallable)
	void SetSecondsBetweenChecks(float secondsBetweenChecks);

	UFUNCTION(BlueprintPure)
	int32 GetMaxConcurrentTasks() const;

	UFUNCTION(BlueprintCallable)
	void SetMaxConcurrentTasks(int32 maxConcurrentTasks);

	UFUNCTION(BlueprintCallable)
	bool HasTask(const TScriptInterface<IInterface_Developer_Task>& task) const;

	UFUNCTION(BlueprintCallable)
	void InsertTaskAt(int32 index, const TScriptInterface<IInterface_Developer_Task>& task);

	/* Adds a task to the scheduler queue. Returns FALSE if task could not be added. */
	UFUNCTION(BlueprintCallable)
	bool AddTask(const TScriptInterface<IInterface_Developer_Task>& task);

	/* Removes a task from the scheduler queue. */
	UFUNCTION(BlueprintCallable)
	void RemoveTask(const TScriptInterface<IInterface_Developer_Task>& task);

	UFUNCTION(BlueprintPure)
	int32 GetNumTasksOfType(TSubclassOf<UObject> objectClass) const;

	UFUNCTION(BlueprintPure)
	int32 GetNumTasks() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumActiveTasks() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void CheckTasks();
};
