#pragma once

#include "Components/SceneComponent.h"

#include "Game_TerrainTile.h"
#include "Game_TileComponent_3DTile.h"
#include "Game_TileComponent_NGAGrid.generated.h"


UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_TileComponent_NGAGrid : public UGame_TileComponent_3DTile
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TileComponent_NGAGrid();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void ExecuteHelperThreadLogic() override;

	virtual void PopulateComponentFromInfoArray(UGame_TileComponent* component, TArray<FString> assetInfo) override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------
	 
private:
	virtual void InitializeForRemoteTileset(const FString& accessToken, FString assetID) override;

	virtual void RequestFile(const FString& fullPathToFile, FOnReceiveFile& receiveFileDelegate) override;
};
