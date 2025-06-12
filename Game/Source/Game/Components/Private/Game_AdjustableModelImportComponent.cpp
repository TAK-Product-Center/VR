// Required Includes
#include "Game_AdjustableModelImportComponent.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_ImportManager.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_AdjustableModelImportComponent::UGame_AdjustableModelImportComponent() :
	ArchivedSize(-1)
{
	
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

void UGame_AdjustableModelImportComponent::AddDefaultRubbersheetData(FMemoryArchive& archive, const FGeodeticCoord3D& geoLocation)
{
	FRotator rotation = FRotator(0, 0, 0);
	FVector scale = FVector(1, 1, 1);
	bool bInvertNormals = false;
	FGeodeticCoord3D coordinate = geoLocation;

	archive << rotation;
	archive << scale;
	archive << bInvertNormals;
	archive << coordinate;
}

bool UGame_AdjustableModelImportComponent::GetUnloadedEntityGeoLocation(const FString& entityUID, FGeodeticCoord3D& geoLocation)
{
	FRotator rotation = FRotator(0, 0, 0);
	FVector scale = FVector(1, 1, 1);
	bool bInvertNormals = false;

	return LoadDataFromDatabase(entityUID, scale, rotation, bInvertNormals, geoLocation);
}

bool UGame_AdjustableModelImportComponent::LoadDataFromDatabase(const FString& entityUID, FVector& scale, FRotator& rotation, bool& bOutInvertNormals, FGeodeticCoord3D& geoLocation)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			FString dataVersion = UDatabase_Spatialite::GetString(TEXT("dataVersion"), results[0]);

			TArray<FString> dataVersionArray;
			dataVersion.ParseIntoArray(dataVersionArray, TEXT("|"));
			if (dataVersionArray.Num() > 0 && dataVersionArray[0].Equals("1"))
			{
				TArray<uint8> blob = UDatabase_Spatialite::GetBlob(TEXT("data"), results[0]);

				// [data] [rubbersheet data] [zip] [offsetBeforeZip]
				// get index at start of zip data
				FMemoryReader fromBinary = FMemoryReader(blob);
				fromBinary.Seek(fromBinary.TotalSize() - sizeof(int64));

				int64 indexStartZip;
				fromBinary << indexStartZip;

				// get index at start of rubbersheet data
				int64 indexStartRubbersheet = indexStartZip - GetArchivedSize();

				fromBinary.Seek(indexStartRubbersheet);

				fromBinary << rotation;
				fromBinary << scale;
				fromBinary << bOutInvertNormals;
				fromBinary << geoLocation;
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_AdjustableModelImportComponent::LoadDataFromDatabase | incorrect data version, re-import this entity to fix | entityUID: %s"), *entityUID);
				return false;
			}

			return true;
		}
	}

	return false;
}

int64 UGame_AdjustableModelImportComponent::GetArchivedSize()
{
	FRotator rotation = FRotator(0, 0, 0);
	FVector scale = FVector(1, 1, 1);
	bool bInvertNormals = false;
	FGeodeticCoord3D coordinate;

	FBufferArchive toBinary;
	
	toBinary << rotation;
	toBinary << scale;
	toBinary << bInvertNormals;
	toBinary << coordinate;

	return toBinary.TotalSize();
}

// ---------------------------------
// --- API
// ---------------------------------

FRotator UGame_AdjustableModelImportComponent::GetRotation() const
{
	return Rotation;
}

FVector UGame_AdjustableModelImportComponent::GetScale() const
{
	return Scale;
}

bool UGame_AdjustableModelImportComponent::GetInvertNormals() const
{
	return bInvertNormals;
}

FGeodeticCoord3D UGame_AdjustableModelImportComponent::GetGeoLocation() const
{
	return GeoLocation;
}

void UGame_AdjustableModelImportComponent::SetScale(const FVector& inScale)
{
	Scale = inScale;
}

void UGame_AdjustableModelImportComponent::SetRotation(const FRotator& inRotation)
{
	auto adjustDegrees = [](float degrees)
	{
		while (degrees >= 360)
		{
			degrees -= 360;
		}

		while (degrees < 0)
		{
			degrees += 360;
		}

		return degrees;
	};

	Rotation = inRotation;

	// adjust degrees between 0 and 360
	Rotation.Roll = adjustDegrees(Rotation.Roll);
	Rotation.Yaw = adjustDegrees(Rotation.Yaw);
	Rotation.Pitch = adjustDegrees(Rotation.Pitch);
}

void UGame_AdjustableModelImportComponent::SetNormalFlip(bool bInNormalsFlipped)
{
	bInvertNormals = bInNormalsFlipped;
}

void UGame_AdjustableModelImportComponent::SetGeoLocation(const FGeodeticCoord3D& geoLocation)
{
	GeoLocation = geoLocation;
}

void UGame_AdjustableModelImportComponent::ApplySettings(AVH_GlobeReferenceActor* globeReference)
{
	if (LoadDataFromDatabase())
	{
		AActor* owner = GetOwner();

		owner->SetActorRelativeRotation(UGame_Statics::GetWorldTransformOverride(GeoLocation).TransformRotation(Rotation.Quaternion()).Rotator());

		owner->SetActorScale3D(globeReference->GetActorScale3D() * Scale);

		if (globeReference != nullptr)
		{
			owner->SetActorLocation(globeReference->GeodeticToWorldDouble(GeoLocation));
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_AdjustableModelImportComponent::ApplySettings | globeReference is nullptr | not able to apply rubbersheet translation"));
		}
	}
}

void UGame_AdjustableModelImportComponent::SaveDataToDatabase()
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	FString entityUID = UGame_VirtualObjectiveManager::GetObjectEntityUID(GetOwner());

	if (entityDB != nullptr && !entityUID.IsEmpty())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			FString fullPathToZipArchive = TEXT("");
			FMD5Hash md5Hash;
			UGame_ImportManager::GetZipReference(results[0], fullPathToZipArchive, md5Hash);

			TArray<uint8> blob = UDatabase_Spatialite::GetBlob(TEXT("data"), results[0]);

			// [data] [rubbersheet data] [zip] [offsetBeforeZip]
			// get index at start of zip data
			FMemoryReader fromBinary = FMemoryReader(blob);
			fromBinary.Seek(fromBinary.TotalSize() - sizeof(int64));

			int64 indexStartZip;
			fromBinary << indexStartZip;

			// get index at start of rubbersheet data
			int64 indexStartRubbersheet = indexStartZip - GetArchivedSizeCached();

			// keep data
			FBufferArchive toBinary;
			toBinary.Serialize(blob.GetData(), indexStartRubbersheet);

			// add new data
			HandleData(toBinary);

			// add zip
			UGame_ImportManager::AddZipReferenceToData(toBinary, fullPathToZipArchive);

			TArray<uint8> data = (TArray<uint8>&)toBinary;
			entityDB->SetData(entityUID, data);

			OnRubbersheetDataModified.Broadcast();
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_AdjustableModelImportComponent::LoadDataFromDatabase()
{
	bool bLoadSuccessful =  LoadDataFromDatabase(UGame_VirtualObjectiveManager::GetObjectEntityUID(GetOwner()), Scale, Rotation, bInvertNormals, GeoLocation);

	OnRubbersheetDataModified.Broadcast();

	return bLoadSuccessful;
}

int64 UGame_AdjustableModelImportComponent::GetArchivedSizeCached()
{
	if (ArchivedSize == -1)
	{
		ArchivedSize = GetArchivedSize();
	}

	return ArchivedSize;
}

void UGame_AdjustableModelImportComponent::HandleData(FMemoryArchive& archive)
{
	archive << Rotation;
	archive << Scale;
	archive << bInvertNormals;
	archive << GeoLocation;
}
