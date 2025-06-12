#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_ListItemObject.generated.h"

UINTERFACE(Blueprintable)
class GAME_API UInterface_ListItemObject : public UInterface
{
	GENERATED_BODY()
};

class GAME_API IInterface_ListItemObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FString GetID();
};