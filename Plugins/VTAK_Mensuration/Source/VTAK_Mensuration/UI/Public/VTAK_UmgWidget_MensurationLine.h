#pragma once

// Required includes
#include "Game_UserWidget_Arrow.h"

// Generated include
#include "VTAK_UmgWidget_MensurationLine.generated.h"

UCLASS(Blueprintable, BlueprintType)
class VTAK_MENSURATION_API UVTAK_UmgWidget_MensurationLine : public UGame_UserWidget_Arrow
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetAngle(const FString& angleText);
};
