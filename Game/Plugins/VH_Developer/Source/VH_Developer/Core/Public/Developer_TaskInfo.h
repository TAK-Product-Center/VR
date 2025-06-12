#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "HAL/ThreadSafeCounter.h"

// Generated Includes
#include "Developer_TaskInfo.generated.h"

UCLASS(Blueprintable)
class VH_DEVELOPER_API UDeveloper_TaskInfo : public UObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskInfoChanged, UDeveloper_TaskInfo*, taskInfo);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTaskInfoIDChanged, UDeveloper_TaskInfo*, taskInfo, const FString&, oldID);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* called if Description or PercentComplete changes */
	UPROPERTY(BlueprintAssignable)
	FTaskInfoChanged OnTaskInfoChanged;

	/* called if ID changes */
	UPROPERTY(BlueprintAssignable)
	FTaskInfoIDChanged OnTaskInfoIDChanged;

private:
	FString ID;

	FString Description;

	float PercentComplete;

	FThreadSafeCounter DestroyCounter;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_TaskInfo();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginDestroy() override;

	virtual bool IsReadyForFinishDestroy() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetID(const FString& id);

	UFUNCTION(BlueprintCallable)
	void SetDescription(const FString& description);

	UFUNCTION(BlueprintCallable)
	void SetPercentComplete(float percentComplete);

	UFUNCTION(BlueprintPure)
	FString GetID() const;

	UFUNCTION(BlueprintPure)
	FString GetDescription() const;

	UFUNCTION(BlueprintPure)
	float GetPercentComplete() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool IsSafeToExecute();

	void BroadcastTaskInfoChanged();
};
