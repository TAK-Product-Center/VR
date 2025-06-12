#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_Developer_Task.generated.h"


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class ETaskStatus : uint8
{
	Invalid,
	Initialized,
	Started,
	Finished
};

UINTERFACE(Blueprintable)
class VH_DEVELOPER_API UInterface_Developer_Task : public UInterface
{
	GENERATED_BODY()
};

class VH_DEVELOPER_API IInterface_Developer_Task
{
	GENERATED_BODY()

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent)
	ETaskStatus GetTaskStatus() const;

	UFUNCTION(BlueprintNativeEvent)
	bool InitializeTask();

	UFUNCTION(BlueprintNativeEvent)
	void StartTask();
};
