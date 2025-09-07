#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// VH Plugin Includes
#include "Database_Spatialite.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_Subsystem_Operation.generated.h"

class UGame_Database_Operation;

UCLASS()
class GAME_API UGame_Subsystem_Operation : public UWorldSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOperationUpdated, int32, operationID);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOperationsUpdated);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOperationExport, int32, operationID);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOperationViewRemoved, UUserWidget*, widget, bool, bIsSelected);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTextUpdated, int32, operationID, int32, viewID, bool, bIsSelected);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOperationUpdated OnOperationUpdated;

	UPROPERTY(BlueprintAssignable)
	FOperationsUpdated OnOperationsUpdated;

	UPROPERTY(BlueprintAssignable)
	FOperationExport OnOperationExportBegin;

	UPROPERTY(BlueprintAssignable)
	FOperationExport OnOperationExportEnd;

	UPROPERTY(BlueprintAssignable)
	FOperationViewRemoved OnOperationViewRemoved;

	UPROPERTY(BlueprintAssignable)
	FTextUpdated OnTextUpdated;

private:
	UPROPERTY()
	UGame_Database_Operation* OperationDB;

	int32 CurrentOperationID;
	int32 CurrentViewID;

	int32 CurrentOperationIDCache;
	int32 CurrentViewIDCache;

	FTimerHandle ExportTimerHandle;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Subsystem_Operation();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_Operation* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	FSpatialiteResults_BP GetOperations(const FString& orderBy, bool bAsc) const;

	UFUNCTION(BlueprintPure)
	FSpatialiteResults_BP GetViews(int32 operationID, const FString& orderBy, bool bAsc) const;

	UFUNCTION(BlueprintPure)
	FSpatialiteResults_BP GetViewItems(int32 viewID, const FString& orderBy, bool bAsc) const;

	UFUNCTION(BlueprintPure)
	bool GetCurrentOperation(FSpatialiteResult_BP& result) const;

	UFUNCTION(BlueprintPure)
	bool GetCurrentView(FSpatialiteResult_BP& result) const;

	UFUNCTION(BlueprintCallable)
	void AddOperation(const FString& name, const FString& start);

	UFUNCTION(BlueprintCallable)
	void UpdateOperation(int32 operationID, const FString& name, const FString& start);

	UFUNCTION(BlueprintCallable)
	void RemoveOperation(int32 operationID);

	UFUNCTION(BlueprintCallable)
	void DuplicateOperation(int32 operationID);

	UFUNCTION(BlueprintCallable)
	void LoadOperation(int32 operationID);

	UFUNCTION(BlueprintCallable)
	void UnloadCurrentOperation();

	UFUNCTION(BlueprintCallable)
	void AddView(const FString& name, int32 index);

	UFUNCTION(BlueprintPure)
	FSpatialiteResult_BP GetView(int32 viewID) const;

	UFUNCTION(BlueprintCallable)
	void UpdateView(int32 viewID, const FString& name, int32 index, bool bIsSelected);

	UFUNCTION(BlueprintCallable)
	void UpdateViewCamera(int32 viewID);

	UFUNCTION(BlueprintCallable)
	void RemoveView(int32 viewID, UUserWidget* widget);

	UFUNCTION(BlueprintCallable)
	void LoadView(int32 viewID);

	UFUNCTION(BlueprintCallable)
	void UnloadCurrentView();

	UFUNCTION(BlueprintPure)
	int32 GetIndexForNewView(int32 operationID) const;

	UFUNCTION(BlueprintCallable)
	void UpdateViewItem(int32 viewID, const FString& uid, bool bVisible);

	UFUNCTION(BlueprintCallable)
	void RemoveViewItem(const FString& uid);

	UFUNCTION(BlueprintPure)
	bool IsExporting() const;

	UFUNCTION(BlueprintCallable)
	void ExportOperation(int32 operationID, const TArray<int32>& viewIndices, double timeoutOverride, const FString& fullPathToScreenshots, const FString& fullPathToDataPackages);

	UFUNCTION(BlueprintPure)
	bool IsViewNameInUse(int32 operationID, int32 viewID, const FString& viewName);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------	

private:
	FGeodeticCoord3D GetCoordinate(const FVector& worldLocation) const;

	FVector GetWorldLocation(const FGeodeticCoord3D& coordinate) const;

	UFUNCTION()
	void StoreDefaultSettings();

	UFUNCTION()
	void BindToEntityDB();

	void RestoreCurrentEntitiesToEntityDB();

	TSet<FString> GetViewItems() const;

	void UpdateEntityToOperation(const SpatialiteResult& result);

	void UpdateEntityToEntityDB(const SpatialiteResult& result);

	UFUNCTION()
	void LatentInitialize();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------	

private:
	UFUNCTION()
	void HandleDatabaseDelete(const FSpatialiteResults_BP& results);

	UFUNCTION()
	void HandleScreenshotTimer(int32 currentViewIndex, const TArray<int32>& viewIndices, double timeoutOverride, const FString& fullPathToScreenshots);

	UFUNCTION()
	void HandleExportTimer(int32 currentViewIndex, const TArray<int32>& viewIndices, double timeoutOverride, const FString& screenshotPath);
};