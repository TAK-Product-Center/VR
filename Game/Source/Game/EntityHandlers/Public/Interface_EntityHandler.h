#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Engine Includes
#include "Misc/Guid.h"
#include "Templates/SubclassOf.h"

// Game Includes
#include "Database_Spatialite.h"

// Generated Includes
#include "Interface_EntityHandler.generated.h"

/*
* \brief UInterface_EntityHandler queries a database (ex: entity database)
*        and feeds registered loaders blobs for rows that match a loader's ClassUID.
*/

class AGame_VirtualObjective;
class UUserWidget;

UINTERFACE(Blueprintable)
class GAME_API UInterface_EntityHandler : public UInterface
{
    GENERATED_BODY()
};

class GAME_API IInterface_EntityHandler
{
    GENERATED_BODY()

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
    /*
	* \brief Returns class UID
	* \return Class UID FString
	*/
    UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
    FString GetClassUID();

	/* syncs entity's objects to database; called when database is updated while entity is loaded */
	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	void UpdateEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

    /*
	* \brief Sets the entity status
	* \param result database result of entity
	* \param detailStatus contextual detail status -- e.g. 0 = only listed in Overlay UI, 1 = show full visuals (and load models), 2 = proxy with nameplate
	*/
    UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
    void SetEntityDetailStatus(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus);

    UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
    void SetEntityVisibility(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible);

    UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
    void GetEntityOverlayInfo(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues);

    UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
    void DeleteEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	void SetEntityScale3D(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D);

	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	void PreModifyVOGlobeReference(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	void PostModifyVOGlobeReference(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	void SnapEntityToGround(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	void GetGoToCoord(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	TSubclassOf<class UUserWidget> GetDetailsWidgetClass(const FSpatialiteResult_BP& result);

	/*
	* \brief returns TMap of md5 hash to filename for files that should be synced for MUC for a particular entityUID
	* \param result database result of entity
	* \return TMap of md5 hash to filename for files that should be synced for MUC
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	TMap<FString, FString> GetHashesToSyncForMUC(const FSpatialiteResult_BP& result);

	/*
	* \brief inserts entries to EntityDB based on passed in file
	* \param fullPathToFile local full path to file to register
	* \param registeredEntityUIDs TSet of registered entity UIDs
	* \return true if registration succeeds
	* \note asynchronous; not called on the game thread
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	bool RegisterFileToDatabaseFirstPass(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs);

	/*
	* \brief inserts entries to EntityDB based on passed in file
	* \param fullPathToFile local full path to file to register
	* \param registeredEntityUIDs TSet of registered entity UIDs
	* \return true if registration succeeds
	* \note asynchronous; not called on the game thread
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	bool RegisterFileToDatabaseSecondPass(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs);

	/*
	* \brief pages in file with default settings; meant to be called from entity handlers when paging in files that aren't individually registered
	* \param virtualObjective virtual objective to use when registering entityUID to virtual objective
	* \param entityUID entityUID to use when registering entityUID to virtual objective
	* \param fullPathToFile full path on local disk for file to page in
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Game|EntityHandler")
	void PageInFileWithDefaultSettings(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const FString& fullPathToFile);
};
