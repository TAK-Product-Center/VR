#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Developer_Subsystem_UnitConverter_Settings.generated.h"

class UDeveloper_ConverterUnit;

UCLASS(BlueprintType, Blueprintable, Config = Game)
class VH_DEVELOPER_API UDeveloper_Subsystem_UnitConverter_Settings : public UObject
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TSet<TSubclassOf<UDeveloper_ConverterUnit>> DefaultConverters;
};