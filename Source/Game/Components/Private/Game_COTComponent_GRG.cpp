// Required Includes
#include "Game_COTComponent_GRG.h"
#include "Game.h"

// Engine Includes
#include "Http.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Misc/FileHelper.h"
#include "GameFramework/Character.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "VH_COTManager.h"
#include "VH_COTEvent.h"
#include "VH_FileIOStatics.h"
#include "VH_COTStatics.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_KmlDocument.h"
#include "VH_KmlInfo.h"
#include "VH_KmlIcon.h"
#include "VH_KmlGroundOverlay.h"
#include "VH_KmlLatLonBox.h"
#include "VH_KmlGxLatLonQuad.h"
#include "VH_KmlCoordinates.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"
#include "Game_TerrainTile.h"
#include "Game_GameInstance.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_GRG::UGame_COTComponent_GRG()
{
    
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_GRG::TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaSeconds, tickType, thisTickFunction);

	if (AActor* owner = GetOwner())
	{
		if (!owner->GetActorLocation().Equals(CachedLocation))
		{
			UpdateDecalInfo();

			CachedLocation = owner->GetActorLocation();
		}
	}
}

void UGame_COTComponent_GRG::SnapToGround()
{
	if (AVH_GlobeReferenceActor* globeRef = UGame_VirtualObjectiveManager::GetObjectGlobeReference(GetOwner()))
	{
		FVector worldLocation = globeRef->GeodeticToWorldDouble(Center);

		FVector globeRefScale3D = globeRef->GetActorScale3D();

		// assumes uniform scale
		FVector scale3D = Scale3D * (globeRefScale3D.X / OriginalGlobeScale3D.X);

		OnReceivedGRG.Broadcast(Texture, worldLocation, WorldRotation, scale3D, EntityUID, UVH_COTManager::GetDataLoader_File_ClassUID());
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_COTComponent_GRG::LoadFromKML(UVH_KmlInfo* kmlInfo)
{
	AVH_GlobeReferenceActor* globeRef = UGame_VirtualObjectiveManager::GetObjectGlobeReference(GetOwner());
	if (globeRef == nullptr)
	{
		FTimerDelegate timerDel;
		FTimerHandle timerHandle;

		timerDel.BindUFunction(this, FName("LoadFromKML"), kmlInfo);
		GetWorld()->GetTimerManager().SetTimer(timerHandle, timerDel, 0.5f, false);

		return;
	}

	TArray<FGeodeticCoord3D> bounds;

	const FKmlDocument& kmlDoc = kmlInfo->GetKmlDocument();
	if (kmlDoc.FeatureListMap.Contains(EKmlElementType::GroundOverlay))
	{
		TArray<uint8> pictureData;

		const TArray<FKmlFeature*>& features = kmlDoc.FeatureListMap[EKmlElementType::GroundOverlay];
		for (const FKmlFeature* feature : features)
		{
			if (const FKmlGroundOverlay* overlay = (FKmlGroundOverlay*)feature)
			{
				// determine image type
				EImageFormat imageFormat = EImageFormat::JPEG;

				FString path = TEXT("");
				FString filename = TEXT("");
				FString extension = TEXT("");
				FPaths::Split(overlay->Icon->HRef, path, filename, extension);
				if (extension.Equals(TEXT("png"), ESearchCase::IgnoreCase))
				{
					imageFormat = EImageFormat::PNG;
				}
				else if (extension.Equals(TEXT("bmp"), ESearchCase::IgnoreCase))
				{
					imageFormat = EImageFormat::BMP;
				}

				FFileHelper::LoadFileToArray(pictureData, *(FPaths::GetPath(kmlInfo->FullPathToFile) / overlay->Icon->HRef));
				Texture = UVH_COTStatics::CreateTexture(pictureData, imageFormat);

				if (overlay->LatLonBox)
				{
					// TODO: This code rotates the corners, before processing them below. HOWEVER, this might break once when rotating the image > 90 deg!
					//		 So instead, just save off the corners/bbox and rotation here, and use it below without the need to detect the corners from arbitrary lon/lat values.
					FKmlLatLonBox* latLonBox = overlay->LatLonBox;
					bounds.Add(FGeodeticCoord3D(latLonBox->West, latLonBox->South, 0, true));
					bounds.Add(FGeodeticCoord3D(latLonBox->East, latLonBox->South, 0, true));
					bounds.Add(FGeodeticCoord3D(latLonBox->East, latLonBox->North, 0, true));
					bounds.Add(FGeodeticCoord3D(latLonBox->West, latLonBox->North, 0, true));

					double rotDeg = -latLonBox->Rotation;
					if (!FMath::IsNearlyZero(rotDeg))
					{
						FVector center = FVector(latLonBox->UnrotatedBBox.GetCenter(), 0);

						FRotator rot = FRotator::ZeroRotator;
						rot.Add(0, rotDeg, 0);
						FVector rotForward = rot.Quaternion().GetAxisX();
						FVector rotRight = rot.Quaternion().GetAxisY();
						FVector rotUp = rot.Quaternion().GetAxisZ();

						for (FGeodeticCoord3D& corner : bounds)
						{
							FVector pos = FVector(corner.Latitude, corner.Longitude, 0);
							FVector delta = pos - center;
							FVector newPos = rot.RotateVector(delta) + center;
							corner = FGeodeticCoord3D(newPos.Y, newPos.X, corner.Altitude, corner.bIsAltitudeRelativeToGround);
						}
					}
				}
				else if (overlay->GxLatLonQuad)
				{
					TArray<FGeodeticCoord3D>& coords = overlay->GxLatLonQuad->Coordinates->CoordinateList;
					bounds.Append(coords);
				}

				break;  // todo ohg | OK to handle only first kmz?
			}
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- kml file did not contain <GroundOverlay>"));
	}

	if (Texture != nullptr)
	{
		FGeodeticCoord3D northWest = bounds[3];
		FGeodeticCoord3D northEast = bounds[2];
		FGeodeticCoord3D southWest = bounds[0];
		FGeodeticCoord3D southEast = bounds[1];

		FVector northWestUU = globeRef->GeodeticToWorldDouble(northWest);
		FVector northEastUU = globeRef->GeodeticToWorldDouble(northEast);
		FVector southWestUU = globeRef->GeodeticToWorldDouble(southWest);
		FVector southEastUU = globeRef->GeodeticToWorldDouble(southEast);

		// update bounding box
		SouthEastBB.Longitude = southEast.Longitude;
		SouthEastBB.Latitude = southEast.Latitude;

		NorthWestBB.Longitude = northWest.Longitude;
		NorthWestBB.Latitude = northWest.Latitude;

		double lon = (northWest.Longitude + northEast.Longitude + southWest.Longitude + southEast.Longitude) / 4.0;
		double lat = (northWest.Latitude + northEast.Latitude + southWest.Latitude + southEast.Latitude) / 4.0;
		Center = FGeodeticCoord3D(lon, lat, 0, true);

		// set rotation based on corners
		WorldRotation = (northEastUU - northWestUU).Rotation();
		WorldRotation.Pitch = -90;

		FVector worldLocation = globeRef->GeodeticToWorldDouble(Center);

		FTransform surfaceTransform = UGame_Statics::GetWorldTransformOverride(worldLocation);
		surfaceTransform.SetLocation(worldLocation);

		FVector startLocation = surfaceTransform.TransformPosition(FVector(0, 0, 10000000));
		FVector endLocation = surfaceTransform.TransformPosition(FVector(0, 0, -10000000));

		FCollisionQueryParams queryParams(NAME_None, true);
		queryParams.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		queryParams.AddIgnoredActor(GetOwner());

		float scaleX = 1000000;  // todo ohg: don't hardcode; this will not work with all GRGs

		FHitResult hitResult;
		if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, UGame_GameInstance::GetTerrainCollisionChannel(), queryParams))
		{
			scaleX = FMath::Abs<float>(worldLocation.Z - hitResult.Location.Z) + 1000.f;
		}

		float scaleY = (northWestUU - southWestUU).Size() / 2.0f;
		float scaleZ = (northWestUU - northEastUU).Size() / 2.0f;
		Scale3D = FVector(scaleX, scaleY, scaleZ);

		OriginalGlobeScale3D = globeRef->GetActorScale3D();

		EntityUID = kmlInfo->FullPathToFile;

		OnReceivedGRG.Broadcast(Texture, worldLocation, WorldRotation, Scale3D, EntityUID, UVH_COTManager::GetDataLoader_File_ClassUID());
	}
}

void UGame_COTComponent_GRG::GetBoundingBox(FGeodeticCoord2D& northWest, FGeodeticCoord2D& southEast)
{
	northWest = NorthWestBB;
	southEast = SouthEastBB;
}

void UGame_COTComponent_GRG::UpdateDecalInfo()
{
	if (AVH_GlobeReferenceActor* globeRef = UGame_VirtualObjectiveManager::GetObjectGlobeReference(GetOwner()))
	{
		if (!EntityUID.IsEmpty())
		{
			FVector globeRefScale3D = globeRef->GetActorScale3D();

			// assumes uniform scale
			FVector scale3D = Scale3D * (globeRefScale3D.X / OriginalGlobeScale3D.X);

			FVector worldLocation = globeRef->GeodeticToWorldDouble(Center);

			OnReceivedGRG.Broadcast(Texture, worldLocation, WorldRotation, scale3D, EntityUID, UVH_COTManager::GetDataLoader_File_ClassUID());
		}
	}
}
