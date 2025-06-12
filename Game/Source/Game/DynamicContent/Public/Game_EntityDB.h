#pragma once

#include "Database_Spatialite.h"
#include "VH_GeodeticCoord.h"
#include "VH_UmgListEntry.h"

#include "Interface_EntityHandler.h"
#include "Game_EntityDB.generated.h"

class AGame_VirtualObjective;
class AVH_GlobeReferenceActor;

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EOverlayCategoryVisibility : uint8
{
    Visible,
    Hidden,
    Mixed,
    Empty
};

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FSOverlayCategory
{
    GENERATED_BODY()

    FSOverlayCategory() :
        ID(NAME_None),
        DisplayName(TEXT("")),
        ParentID(NAME_None),
        Icon(nullptr),
        Item_ListItemClass(nullptr),
        Category_ListItemClass(nullptr)
    {}

    /* unique identifier for category */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName ID;

    /* name to display in application */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString DisplayName;

    /* ID of parent category */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName ParentID;

    /* texture for icon to display for this category */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UTexture2D* Icon;

    /* class to use listing items in this category */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<class UVH_UmgListEntry> Item_ListItemClass;

    /* class to use listing categories in this category */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<class UVH_UmgListEntry> Category_ListItemClass;
};

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_EntityDB : public UDatabase_Spatialite
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_EntityDB();


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPageEvent, const FString&, entityUID, AGame_VirtualObjective*, virtualObjective);

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FDBEvent OnInsertOrUpdate;

	UPROPERTY(BlueprintAssignable)
	FDBEvent OnDelete;

	UPROPERTY(BlueprintAssignable)
	FPageEvent OnPageIn;

	UPROPERTY(BlueprintAssignable)
	FPageEvent OnPageOut;

private:
	bool bConnected;

	FString DatabasePath;

	FString DatabaseFilename;

	FString PrimaryTableName;
	TMap<FString, FString> PrimaryTableFields;
	TArray<FString> PrimaryTableAdditionalInitQueries;

	// maps overlay category id to overlay category
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FSOverlayCategory> OverlayCategories;

	
	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get EntityDB"))
	static UGame_EntityDB* Get();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
    void OnGameModeInit();

    void OnGameModeStartToLeaveMap();

    /*
	* \brief Unloads an entity, then removes from database
	* \param classUID UID of entity to unload and remove from database
	* \param entityUID UID of entity to unload and remove from database
	* \param bBroadcast broadcasts OnDelete delegate when true
	* \return True if found entity in database
	*/
    UFUNCTION(BlueprintCallable)
    bool Delete(const FString& classUID, const FString& entityUID, bool bBroadcast = true);

	void DeleteResults(const SpatialiteResults& results);

	void DeleteFromResult(const SpatialiteResult& row);

    /*
	* \brief Unloads all entities, then removes from database
	*/
    UFUNCTION(BlueprintCallable)
    void Clear();

    UFUNCTION(BlueprintCallable)
    void GetEntityOverlayInfo(TMap<FString, FString>& keyValues, const FSpatialiteResult_BP& result);

    UFUNCTION(BlueprintPure)
    bool IsCategoryOrChildOf(const FName& categoryID, const FName& otherCategoryID) const;

    // Plugins add their own categories and subcategories through this function
    UFUNCTION(BlueprintCallable)
    void AddCategory(const FSOverlayCategory& categoryToAdd);

    UFUNCTION(BlueprintPure)
    bool GetCategory(const FName& id, FSOverlayCategory& category) const;

	/* \brief Returns set of category IDs that do not have a child
	*  \returns set of category IDs that do not have a child
	*/
	UFUNCTION(BlueprintCallable)
	TSet<FName> GetLeafCategoryIDs() const;

    UFUNCTION(BlueprintCallable, BlueprintPure = false)
    TArray<FSOverlayCategory> GetSubcategories(const FName& parentID) const;

    // Retrieves items are within specified category
    UFUNCTION(BlueprintCallable)
    FSpatialiteResults_BP GetCategoryEntities(const FName& id);

    UFUNCTION(BlueprintCallable)
    FSpatialiteResults_BP GetContactCategoryEntities(const FName& id);

    /* \brief Gets visibility state of category
	*  \param id ID of category to query
	*  \returns category visibility enum value
	*/
    UFUNCTION(BlueprintCallable)
    EOverlayCategoryVisibility GetCategoryVisibility(const FName& id);

    // sets category, subcategories, and all entities in category and subcategories
    UFUNCTION(BlueprintCallable)
    void SetCategoryVisibility(const FName& id, bool bVisible);

    UFUNCTION(BlueprintCallable)
    void SetEntityVisibility(const FString& entityUID, bool bVisible);

    UFUNCTION(BlueprintPure)
    bool GetEntityVisibility(const FName& entityUID) const;

	void UpdateBoundingBox(const FString& entityUID, const FGeodeticCoord2D& northWestBB, const FGeodeticCoord2D& southEastBB);

	void SetData(const FString& entityUID, const TArray<uint8>& data);

    /*
	* \brief Inserts or updates row in EntityDB
	* \param entityUID UID of entity to insert/update
	* \param classUID UID of class to insert/update
	* \param categoryID ID of category (for OverlayManager UI)
	* \param northWestBB Position of northwest bounding box for this object
	* \param southEastBB Position of southeast bounding box for this object
	*\ param data Data to be added as blob in database
	* \param bTransient True if entity should be deleted from EntityDB when application is shutdown
	* \param bVisible True if entity should be visible
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure = false)
    void InsertOrUpdate(const FString& entityUID, const FString& classUID, const FName& categoryID, const FGeodeticCoord2D& northWestBB, const FGeodeticCoord2D& southEastBB, const TArray<uint8>& data, bool bTransient = false, bool bVisible = true) const;

	void InsertOrUpdateResult(const SpatialiteResult& result);

	void InsertOrUpdateResults(const SpatialiteResults& results);

	bool LoadEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UObject* handler = nullptr, int32 detailLevel = 1);
	bool LoadEntity(AGame_VirtualObjective* virtualObjective, const SpatialiteResult& result, UObject* handler = nullptr, int32 detailLevel = 1);

    bool UnloadEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UObject* handler = nullptr);
    
	SpatialiteResults QuerySquare2D(const FGeodeticCoord2D& center, double halfWidthMeters) const;

	UFUNCTION(BlueprintPure)
	FSpatialiteResult_BP QueryUIDForResult(const FString& entityUID) const;

	UFUNCTION(BlueprintPure)
	void QueryUID(const FString& entityUID, FString& classUID, FString& categoryID, TArray<uint8>& blobData, bool& bTransient, bool& bVisible, FString& dataVersion) const;

    SpatialiteResults QueryUID(const FString& entityUID) const;

	SpatialiteResults QueryCategory(const FString& categoryID) const;

	UFUNCTION(BlueprintPure)
	bool IsEntityInDB(const FString& entityUID) const;

	UFUNCTION(BlueprintPure)
	FString GetDatabasePath() const;

	UFUNCTION(BlueprintPure)
	FString GetDatabaseFilename() const;

	UFUNCTION(BlueprintCallable)
	void SetDatabasePath(const FString& databasePath);

	/*
	* \brief Creates (if needed), then connects to new entityDB; pages out all existing entities first
	* \param databaseFilename Filename for new database; full path is GetDatabasePath() \ GetDatabaseFilename()
	*/
	UFUNCTION(BlueprintCallable)
	void SetDatabaseFilename(const FString& databaseFilename);

	SpatialiteResults QueryAllEntities() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false, meta = (DisplayName = "QueryAllEntities"))
	FSpatialiteResults_BP K2_QueryAllEntities() const;

	void SetEntityDataVersion(const FString& entityUID, const FString& dataVersion) const;

	void SetEntityTransient(const FString& entityUID, bool bTransient);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateConnection();

    void Connect();

    void BroadcastEvent(const FDBEvent* eventDelegate, SpatialiteResults results) const;

    void SetEntityVisibilityByCategory(const FName& categoryID, bool bVisible);

    EOverlayCategoryVisibility GetCategoryVisiblity_Helper(const FName& id, int32& numVisible, int32& numHidden);

	FString MatchInsideSquareForQuery(const FGeodeticCoord2D& center, double halfWidthMeters) const;

	void RebuildDatabaseTable() const;
};
