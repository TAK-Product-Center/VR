#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Serialization/BufferArchive.h"
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"

// VH Plugin Includes
#include "Database_Spatialite.h"
#include "VH_UtmCoord.h"
#include "VH_GeodeticCoord.h"

// Generated Include
#include "Game_ImportManager.generated.h"


UCLASS(Config = "Game")
class GAME_API UGame_ImportManager : public UObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	/* 1st param is full path to file
	*  2nd param is coordinate derived from file
	*  return true if coordinate is valid
	*/
	DECLARE_DELEGATE_RetVal_TwoParams(bool, FGetGeoLocationFromFile, const FString&, FGeodeticCoord3D&);

	
	// ---------------------------------
    // --- Variables
    // ---------------------------------

public:
	TArray<FGetGeoLocationFromFile> GetGeoLocationFromFileLambdas;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> ImportManagerWidgetClass;

private:
	static UGame_ImportManager* GlobalInstance;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_ImportManager();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
    UFUNCTION(BlueprintPure, meta = (DisplayName = "VH Get ImportManager"))
    static UGame_ImportManager* Get();

	static void ExtractIfNecessary(const FString& entityUID, const FString& fullPathToFile);

	static bool GetZipReference(const FString& entityUID, FString& fullPathToZipArchive, FMD5Hash& md5Hash);
	static bool GetZipReference(const FSpatialiteResult_BP& result, FString& fullPathToZipArchive, FMD5Hash& md5Hash);
	static bool GetZipReference(const SpatialiteResult& result, FString& fullPathToZipArchive, FMD5Hash& md5Hash);

	static void AddZipReferenceToData(const FString& entityUID, const FString& fullPathToZipArchive);

	static void AddZipReferenceToData(FBufferArchive& toBinary, const FString& fullPathToZipArchive);

	static bool GetGeoLocationForFile(const FString& fullPathToFile, FGeodeticCoord3D& coordinate);

	static void RecursivelyExtractZipArchives(const FString& fullPath, bool bDeleteZipArchives);

private:
	static bool GetGeoLocationFromFile(const FString& fullPathToFile, FGeodeticCoord3D& coordinate);

	static FString StringFromBlob(const uint8* srcBuffer, uint32 srcSize);

	static void LoadCoordinatesFromPRJ(const FString& prjFile, const FString& offsetFile, FUtmCoord& outCoord, double& outAltitude);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void RegisterFileToDatabase(const FString& fullPathToFile);

	UFUNCTION(BlueprintCallable)
	void RegisterDirectoryToDatabase(const FString& fullPath);

	UFUNCTION(BlueprintCallable)
	void OpenImportDialog();

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void RegisterDirectoryToDatabase(const FString& fullPath, const FString& fullPathToZipArchive);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleRegisterSuccess(UGame_HandlerService* handlerService, const FString& fullPathToFile);

	UFUNCTION()
	void HandleRegisterFail(const FString& fullPathToFile);
};
