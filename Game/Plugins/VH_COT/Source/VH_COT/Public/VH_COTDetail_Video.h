#pragma once

// VH Plugin includes
#include "Database_Spatialite.h"
#include "VH_URI.h"

// Generated includes
#include "VH_COTDetail_Video.generated.h"

// Forward declarations
class FXmlNode;

UCLASS(BlueprintType)
class VH_COT_API UVH_COTDetail_Video : public UObject
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Member
	// ---------------------------------

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString RawPath;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Address;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Alias;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 BufferTime;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IgnoreEmbeddedKLV;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 NetworkTimeout;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Path;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Port;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ESchemeTypeEnum Protocol;

	// may need to add preferred mac address?

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 RoverPort;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool RTSPReliable;

	// todo ohg | documentation
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName UID;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:

	UVH_COTDetail_Video();

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------

public:

	UFUNCTION(BlueprintPure)
	FString GetVideoURL() const;

	/* this will take a url string and parse everything out to make a UVH_COTDetail */
	UFUNCTION(BlueprintCallable)
	bool PopulateFromURL(FString url, UVH_COTDetail_Video*& outVideo);

	bool PopulateFromXML(const FXmlNode* xmlNode);

	bool PopulateFromXMLRest(const FXmlNode* xmlNode);

	void PopulateFromDB(const SpatialiteResult& result);

	void AddToDatabase(UDatabase_Spatialite* database);

	void RemoveFromDatabase(UDatabase_Spatialite* database);

	FString ToXML() const;

	// ---------------------------------
	// --- Debug/Testing
	// ---------------------------------

public:

	FString ToString() const;
};