#pragma once

// Parent Includes
#include "Developer_Subsystem_UnitConverter.h"

// Generated Includes
#include "Game_Subsystem_UnitConverter.generated.h"

UCLASS()
class GAME_API UGame_Subsystem_UnitConverter : public UDeveloper_Subsystem_UnitConverter
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Subsystem_UnitConverter();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual bool ShouldCreateSubsystem(UObject* outer) const override;
};