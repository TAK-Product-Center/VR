#pragma once

// Parent Includes
#include "Components/SceneComponent.h"

// Engine Includes
#include "Serialization/MemoryArchive.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_AdjustableModelImportComponent.generated.h"

class AVH_GlobeReferenceActor;

/* The AdjustableModelImport component provides a way of saving, editing, and applying metadata to imported models. */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAME_API UGame_AdjustableModelImportComponent : public USceneComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_AdjustableModelImportComponent();


	// ---------------------------------
	// --- Delegates
	// ---------------------------------
private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRubbersheetDataModified);


	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	UPROPERTY(BlueprintAssignable)
	FRubbersheetDataModified OnRubbersheetDataModified;
	

protected:
	FVector Scale;

	FRotator Rotation;
	
	/* If true, the normals for the model should be inverted. */
	bool bInvertNormals;

	FGeodeticCoord3D GeoLocation;

private:
	int32 ArchivedSize;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	static void AddDefaultRubbersheetData(FMemoryArchive& archive, const FGeodeticCoord3D& geoLocation);

	static bool GetUnloadedEntityGeoLocation(const FString& entityUID, FGeodeticCoord3D& geoLocation);

private:
	static bool LoadDataFromDatabase(const FString& entityUID, FVector& scale, FRotator& rotation, bool& bOutInvertNormals, FGeodeticCoord3D& geoLocation);

	static int64 GetArchivedSize();


	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	UFUNCTION(BlueprintPure)
	FRotator GetRotation() const;

	UFUNCTION(BlueprintPure)
	FVector GetScale() const;

	bool GetInvertNormals() const;

	UFUNCTION(BlueprintPure)
	FGeodeticCoord3D GetGeoLocation() const;

	/*
	 * Stores scale values relative to the original model.
	 * @param inScale - scale of the model, as a percent
	 */
	UFUNCTION(BlueprintCallable)
	void SetScale(const FVector& inScale);
	
	/*
	 * Stores rotation values relative to the original model.
	 * @param inRotation - rotation of the model, in degrees
	 */
	UFUNCTION(BlueprintCallable)
	void SetRotation(const FRotator& inRotator);
	
	/*
	 * Stores a bool related to whether the model's normals should be flipped or not.
	 * @param bInNormalsFlipped - Whether or not to flip the normals.
	 */
	void SetNormalFlip(bool bInNormalsFlipped);

	UFUNCTION(BlueprintCallable)
	void SetGeoLocation(const FGeodeticCoord3D& geoLocation);

	UFUNCTION(BlueprintCallable)
	void ApplySettings(AVH_GlobeReferenceActor* globeReference);
	
	UFUNCTION(BlueprintCallable)
	void SaveDataToDatabase();
	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	bool LoadDataFromDatabase();

	int64 GetArchivedSizeCached();

	void HandleData(FMemoryArchive& archive);
};