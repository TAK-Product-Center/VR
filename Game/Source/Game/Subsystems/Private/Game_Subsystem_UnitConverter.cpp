// Required Includes
#include "Game_Subsystem_UnitConverter.h"
#include "Game.h"

// VH Plugin Includes
#include "Globe_ConverterUnit_AltitudeRef_HAE.h"
#include "Globe_ConverterUnit_AltitudeRef_MSL.h"

// Game Includes
#include "Game_ConverterUnit_AltitudeRef_AGL.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_UnitConverter::UGame_Subsystem_UnitConverter()
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Subsystem_UnitConverter::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	collection.InitializeDependency(UGame_Subsystem_Core::StaticClass());

	RegisterConverterUnitByClass(UGame_ConverterUnit_AltitudeRef_AGL::StaticClass());
	RegisterConverterUnitByClass(UGlobe_ConverterUnit_AltitudeRef_HAE::StaticClass());
	RegisterConverterUnitByClass(UGlobe_ConverterUnit_AltitudeRef_MSL::StaticClass());
}

bool UGame_Subsystem_UnitConverter::ShouldCreateSubsystem(UObject* outer) const
{
	return true;
}
