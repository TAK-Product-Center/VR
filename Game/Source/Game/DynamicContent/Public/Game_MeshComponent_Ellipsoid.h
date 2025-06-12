#pragma once

// Parent Includes
#include "Game_TileComponent_Mesh.h"

// Generated Includes
#include "Game_MeshComponent_Ellipsoid.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MeshComponent_Ellipsoid : public UGame_TileComponent_Mesh
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MeshComponent_Ellipsoid();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void ExecuteHelperThreadLogic() override;
};