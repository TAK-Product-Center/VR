#pragma once

// Engine includes
#include "UObject/Interface.h"

// Generated include
#include "Interface_COTReceiver.generated.h"

// Forward declarations
class UVH_COTComponent;

namespace vh_cot
{
    class COTEvent;
}

UINTERFACE(BlueprintType, Blueprintable)
class VH_COT_API UInterface_COTReceiver : public UInterface
{
    GENERATED_BODY()
};

class VH_COT_API IInterface_COTReceiver
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    UVH_COTComponent* GetCOTComponent() const;
};