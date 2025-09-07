#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Engine Includes
#include "Engine/EngineTypes.h"
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Game_Subsystem_Gizmo_Settings.generated.h"

class AGame_TransformGizmo;

/*
* Represents settings read from DefaultGame.ini for the Gizmo world subsystem.
* 
* Properties for this class are stored in the ini file under the header
* [/Script/Game.Game_Subsystem_Gizmo_Settings].
*/
UCLASS(BlueprintType, Blueprintable, Config = Game)
class GAME_API UGame_Subsystem_Gizmo_Settings : public UDeveloperSettings
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/*
	* The default gizmo class that the Gizmo subsystem will use to spawn a new gizmo.
	* For this example, the ini file specifies a blueprint type for this property.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TSubclassOf<AGame_TransformGizmo> DefaultGizmoClass;

	/* 
	* Collision channel used by the gizmo
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TEnumAsByte<ECollisionChannel> GizmoCollisionChannel;
};
