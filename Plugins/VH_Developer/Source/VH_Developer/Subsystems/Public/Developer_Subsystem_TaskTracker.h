#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"

// Engine Includes
#include "HAL/ThreadSafeCounter.h"
#include "HAL/ThreadSafeBool.h"

// Generated Includes
#include "Developer_Subsystem_TaskTracker.generated.h"

class UDeveloper_TaskInfo;

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_Subsystem_TaskTracker : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActiveNumChanged);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHistoryNumChanged);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskInfoChanged, UDeveloper_TaskInfo*, taskInfo);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FActiveNumChanged OnActiveNumChanged;

	UPROPERTY(BlueprintAssignable)
	FHistoryNumChanged OnHistoryNumChanged;

	UPROPERTY(BlueprintAssignable)
	FTaskInfoChanged OnTaskInfoChanged;

private:
	UPROPERTY()
	TMap<FString, UDeveloper_TaskInfo*> ActiveTasks;

	TMap<FString, FString> HistoryTasks;

	static UDeveloper_Subsystem_TaskTracker* GlobalInstance;

	FThreadSafeCounter DestroyCounter;

	double SecondsSinceLastBroadcast;

	FThreadSafeBool bHistoryDirty;

	FThreadSafeBool bActiveDirty;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Subsystem_TaskTracker();

	
	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UDeveloper_Subsystem_TaskTracker* Get(UWorld* world);


	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------

public:
	virtual TStatId GetStatId() const override;

	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	TMap<FString, UDeveloper_TaskInfo*> GetActiveTasks() const;

	UFUNCTION(BlueprintPure)
	TMap<FString, FString> GetHistoryTasks() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TSet<FString> GetHistoryIDs() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TSet<FString> GetActiveIDs() const;

	UFUNCTION(BlueprintCallable)
	void AddActiveTask(const FString& id, const FString& description, float percentComplete);

	UFUNCTION(BlueprintCallable)
	void RemoveActiveTask(const FString& taskInfoID);

	UFUNCTION(BlueprintCallable)
	void SetPercentComplete(const FString& taskInfoID, float percentComplete, bool bAdd);

	UFUNCTION(BlueprintCallable)
	void SetDescription(const FString& taskInfoID, const FString& description, bool bAdd);

	UFUNCTION(BlueprintCallable)
	void AddHistoryTask(const FString& id, const FString& description);

	UFUNCTION(BlueprintCallable)
	void RemoveHistoryTask(const FString& id);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool IsSafeToExecute();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleTaskInfoChanged(UDeveloper_TaskInfo* taskInfo);
};
