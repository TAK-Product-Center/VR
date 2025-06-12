#pragma once

// Engine Includes
#include "CoreMinimal.h"
#include "InputCore.h"

// Generated Includes
#include "KeyData.generated.h"

USTRUCT(BlueprintType)
struct FKeyData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FKey Key;

	/* if true, key sent as characters (e.g. 'p'); if false, key sent as command (e.g. [enter] or [leftArrow] */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bSendAsString;

	/* string to send when key is pressed without shift; if empty, defaults to Key.GetDisplayName().ToString().ToLower() */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString KeyString;

	/* string to send when key is pressed with shift; if empty, defaults to Key.GetDisplayName() */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ShiftKeyString;

	FKeyData() :
		bSendAsString(true),
		KeyString(TEXT("")),
		ShiftKeyString(TEXT(""))
	{

	}
};