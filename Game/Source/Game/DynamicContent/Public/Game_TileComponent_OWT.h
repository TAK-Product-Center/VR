#pragma once

#include "Components/SceneComponent.h"

#include "Game_TerrainTile.h"
#include "Game_TileComponent_3DTile.h"
#include "Game_TileComponent_OWT.generated.h"


UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_TileComponent_OWT : public UGame_TileComponent_3DTile
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TileComponent_OWT();


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
	virtual void InitializeForRemoteTileset(const FString& accessToken, FString assetIDs) override;

	void MakeInitialRequest();

	virtual void RequestFile(const FString& fullPathToFile, FOnReceiveFile& receiveFileDelegate) override;
};
