#pragma once

// Engine includes
#include "Subsystems/GameInstanceSubsystem.h"

// Generated include
#include "VH_COTGameInstanceSubsystem.generated.h"

class UVH_MilStd2525;

UCLASS()
class VH_COT_API UVH_COTGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Members
	// ---------------------------------

public:

	UPROPERTY()
	UVH_MilStd2525* MilStd2525;
	
	// ---------------------------------
	// --- Public Methods
	// ---------------------------------

public:

	UFUNCTION(BlueprintCallable)
	void SetMilStd2525Class(TSubclassOf<class UVH_MilStd2525> milStd2525Class);

	UFUNCTION(BlueprintPure)
	UVH_MilStd2525* GetMilStd2525();
};