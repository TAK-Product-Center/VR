#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"

// Game Includes
#include "Database_Spatialite.h"

// Generated Includes
#include "Game_HandlerService.generated.h"

class AVH_GlobeReferenceActor;
class AGame_VirtualObjective;

DECLARE_LOG_CATEGORY_EXTERN(LogVhHandlerService, Warning, All);

// ---------------------------------
// --- Structs
// ---------------------------------

// work-around because UE does not support array as value in a TMap
USTRUCT()
struct FSEntityClassHandlers
{
    GENERATED_BODY()

public:
    UPROPERTY()
    TArray<UObject*> Handlers;
};

UCLASS(Blueprintable, Config = "Game")
class GAME_API UGame_HandlerService : public UObject
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_HandlerService();

	// ---------------------------------
	// --- Variables
	// ---------------------------------
protected:
	static UGame_HandlerService* GlobalInstance;

	bool bIsInitialized;
	bool bIsShuttingDown;

	// maps classUID to array of handlers
	UPROPERTY()
	TMap<FString, FSEntityClassHandlers> EntityHandlerMap;

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	UFUNCTION(BlueprintPure, Category = "Game|VhHandlerService", meta = (DisplayName = "VH Get HandlerService"))
	static UGame_HandlerService* Get();

    // ---------------------------------
    // --- API
    // ---------------------------------
public:
    bool Initialize();

	void Shutdown();

    void OnGameModeInit();

    void OnGameModeStartToLeaveMap();

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<UObject*> GetEntityHandlers(const FString& classUID) const;

	TArray<UObject*> GetAllEntityHandlers() const;

    /*
	* \brief Registers a handler object that implements Interface_EntityHandler
	* \param handler Object that implements Interface_EntityHandler
	*/
    UFUNCTION(BlueprintCallable)
    void RegisterEntityHandler(const TScriptInterface<IInterface_EntityHandler>& handler, bool bLoadHandlerObjects = false);

	UFUNCTION(BlueprintCallable)
	void UpdateEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler = nullptr);

    UFUNCTION(BlueprintCallable)
    void SetEntityDetailStatus(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus, UObject* handler = nullptr);

    UFUNCTION(BlueprintCallable)
    void SetEntityVisibility(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible, UObject* handler = nullptr);

    UFUNCTION(BlueprintCallable)
    void GetEntityOverlayInfo(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues, UObject* handler = nullptr);

    UFUNCTION(BlueprintCallable)
    void DeleteEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	void SetEntityScale3D(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	void PreModifyVOGlobeReference(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	void PostModifyVOGlobeReference(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	void SnapEntityToGround(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	void GetGoToCoord(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	TSubclassOf<UUserWidget> GetDetailsWidgetClass(const FSpatialiteResult_BP& result, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	TMap<FString, FString> GetHashesToSyncForMUC(const FSpatialiteResult_BP& result, UObject* handler = nullptr);

	UFUNCTION(BlueprintCallable)
	bool RegisterFileToDatabaseFirstPass(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs);

	UFUNCTION(BlueprintCallable)
	bool RegisterFileToDatabaseSecondPass(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs);

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	void HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources);
};
