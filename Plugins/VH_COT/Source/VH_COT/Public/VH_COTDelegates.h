#pragma once

#include "VH_COT.h"

#include "Misc/Variant.h"

class VH_COT_API FVH_COTDelegates
{
	// ---------------------------------
	// --- Constructors
	// ---------------------------------
private:
	FVH_COTDelegates() {}

	// ---------------------------------
	// --- Delegates
	// ---------------------------------
private:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnCOTMessageReceived, const FString& /*messageType*/, const FVariant& /*variant*/);

	// ---------------------------------
	// --- Members
	// ---------------------------------
public:
	static FOnCOTMessageReceived OnCOTMessageReceived;
};
