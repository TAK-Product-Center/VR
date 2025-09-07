#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"

// Generated Includes
#include "Keyboard_Subsystem_Core_Settings.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable, Config = Game)
class VH_KEYBOARD_API UKeyboard_Subsystem_Core_Settings : public UObject
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TSubclassOf<AActor> DefaultKeyboardClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TEnumAsByte<ECollisionChannel> KeyboardCollisionChannel;
};