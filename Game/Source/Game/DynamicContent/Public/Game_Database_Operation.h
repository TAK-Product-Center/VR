#pragma once

// Parent Includes
#include "Database_Spatialite.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_Database_Operation.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_Database_Operation : public UDatabase_Spatialite
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Database_Operation();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void Initialize();

	void DuplicateOperation(int32 operationID);

	int32 AddOperation(const FString& name, const FString& start);

	void RemoveOperation(int32 operationID);

	void UpdateOperation(int32 operationID, const FString& name, const FString& start);

	SpatialiteResults GetOperations(const FString& orderBy, bool bAsc) const;

	SpatialiteResult GetOperation(int32 operationID) const;

	SpatialiteResult GetView(int32 viewID) const;

	SpatialiteResults GetViews(int32 operationID) const;

	SpatialiteResults GetViews(int32 operationID, const FString& orderBy, bool bAsc) const;

	SpatialiteResults GetViewItems(int32 viewID, const FString& orderBy, bool bAsc) const;

	SpatialiteResult GetViewItem(int32 viewID, const FString& uid) const;

	int32 AddView(int32 operationID, const FString& name, int32 index, const FGeodeticCoord3D& cameraCoordinate, const FRotator& cameraRotation);

	int32 GetIndexForNewView(int32 operationID) const;

	void UpdateView(int32 viewID, const FString& name, int32 index);

	void UpdateViewCamera(int32 viewID, const FGeodeticCoord3D& cameraCoordinate, const FRotator& cameraRotation);

	void RemoveView(int32 viewID);
			
	void AddViewItems(bool bRemoveExisting, int32 viewID, const TSet<FString>& uids);

	void UpdateViewItem(int32 viewID, const FString& uid, bool bVisible);

	void RemoveViewItem(int32 viewID, const FString& uid);

	bool IsViewNameInUse(int32 operationID, int32 viewID, const FString& viewName) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateLastModifiedFromOperationID(int32 operationID);

	void UpdateLastModifiedFromViewID(int32 viewID);

	FString GetNowDateTime() const;

	void Connect();

	FString GetFullPathToDatabase() const;
};
