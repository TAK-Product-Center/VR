// Required Includes
#include "VH_COTGameInstanceSubsystem.h"

// Engine Includes
#include "UObject/UObjectGlobals.h"
#include "UObject/Package.h"
#include "Engine/GameInstance.h"

// Module Includes
#include "VH_MilStd2525.h"

void UVH_COTGameInstanceSubsystem::SetMilStd2525Class(TSubclassOf<class UVH_MilStd2525> milStd2525Class)
{
	MilStd2525 = NewObject<UVH_MilStd2525>(GetGameInstance(), milStd2525Class);
}

UVH_MilStd2525* UVH_COTGameInstanceSubsystem::GetMilStd2525()
{
	return MilStd2525;
}
