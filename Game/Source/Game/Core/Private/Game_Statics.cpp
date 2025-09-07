// Required Includes
#include "Game_Statics.h"
#include "Game.h"

// Engine Includes
#include "Engine/GameViewportClient.h"
#include "EnhancedInputSubsystems.h"
#include "OnlineSubsystemUtils.h"
#include "GeomTools.h"
#include "Serialization/BufferArchive.h"
#include "Kismet/GameplayStatics.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/Material.h"
#include "Engine/LevelStreaming.h"
#include "Engine/Font.h"
#include "Engine/Level.h"
#include "GameFramework/Character.h"
#include "UnrealClient.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "Developer_Statics.h"
#include "SessionPlayback_Subsystem_Core.h"
#include "VH_GlobeMathStatics.h"
#include "VH_COTGameInstanceSubsystem.h"
#include "VH_MilStd2525.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeCoordConverter.h"
#include "Developer_Subsystem_UnitConverter.h"

// Game Includes
#include "Game_GameInstance.h"
#include "Game_PlayerController.h"
#include "Game_GameMode.h"
#include "Game_EntityDB.h"
#include "Game_TileManager.h"
#include "Game_Subsystem_Core.h"
#include "Game_GameState.h"
#include "Game_PlayerState.h"
#include "Game_TerrainTile.h"
#include "Game_Pawn.h"
#include "Game_VirtualObjective.h"
#include "Game_MovementComponent.h"
#include "Game_GlobeReferenceActor_Ellipsoid.h"
#include "Game_EntityHandler_COT.h"
#include "Game_COTManager.h"

#include <fx/gltf.h>

// TODO: Consider moving to Developer_Statics
bool UGame_Statics::GetVHIsWithEditor()
{
#if WITH_EDITOR
    return true;
#else
    return false;
#endif
}

// TODO: Consider moving to Developer_Statics
bool UGame_Statics::GetVHIsBuildShipping()
{
#if UE_BUILD_SHIPPING
    return true;
#else
    return false;
#endif
}

// TODO: Consider moving to Developer_Statics
bool UGame_Statics::GetVHIsBuildTest()
{
#if UE_BUILD_TEST
    return true;
#else
    return false;
#endif
}

UGame_GameInstance* UGame_Statics::GetVHGameInstance()
{
    UGame_GameInstance* gameInstance = UGame_GameInstance::Get();
    if (gameInstance == nullptr)
    {
        UE_LOG(Game, Warning, TEXT("UGame_GameInstance::Get returning nullptr"));
    }

    return gameInstance;
}

AGame_GameMode* UGame_Statics::GetVHGameMode()
{
    AGame_GameMode* gameMode = nullptr;
    if (UDeveloper_Statics::GetVHWorld() != nullptr)
    {
        gameMode = Cast<AGame_GameMode>(UDeveloper_Statics::GetVHWorld()->GetAuthGameMode());
    }

    if (gameMode == nullptr)
    {
        UE_LOG(Game, Error, TEXT("UGame_Statics::GetVHGameMode returning nullptr"));
    }

    return gameMode;
}

AGame_PlayerController* UGame_Statics::GetVHPlayerController()
{
	if (const UGameInstance* gameInstance = UGameplayStatics::GetGameInstance(UDeveloper_Statics::GetVHWorld()))
	{
		return Cast<AGame_PlayerController>(gameInstance->GetFirstLocalPlayerController());
	}
	
	return nullptr;
}

AGame_Pawn* UGame_Statics::GetVHPlayerPawn()
{
	return Cast<AGame_Pawn>(UGameplayStatics::GetPlayerPawn(UDeveloper_Statics::GetVHWorld(), 0));
}

AGame_GameState* UGame_Statics::GetVHGameState()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		return Cast<AGame_GameState>(world->GetGameState());
	}

	UE_LOG(Game, Warning, TEXT("UGame_Statics::GetVHGameState returning nullptr"));

	return nullptr;
}

FString UGame_Statics::GetVTAKPluginPath()
{
	FString path;

#if PLATFORM_WINDOWS
	
	#if (UE_BUILD_SHIPPING || UE_BUILD_TEST)
		// Create the path for the game layer plugins on builds. This should be %PROGRAMDATA%/ExtPlugins/ExtPluginDirectories/ (currently).
		path = FPaths::Combine(UGame_Statics::GetVTAKCommonAppDataPath(), TEXT("ExtPlugins"), TEXT("ExtPluginDirectories"));
	#else // (UE_BUILD_SHIPPING || UE_BUILD_TEST)
		// If it is not a build (but more importantly, if it's the editor), just use the engine default game layer plugin.
		path = FPaths::ProjectPluginsDir();
	#endif // (UE_BUILD_SHIPPING || UE_BUILD_TEST)
		// Ensure that the path is a full path compared to a relative path since we want only to return full paths.
		path = FPaths::ConvertRelativePathToFull(path);

#endif // PLATFORM_WINDOWS

	return path;
}

FString UGame_Statics::GetVTAKCommonAppDataPath()
{
#if PLATFORM_WINDOWS
    return FPaths::Combine(UDeveloper_Statics::GetCommonAppDataPath(), TEXT("VRTAK"));
#else // PLATFORM_WINDOWS
	return TEXT("");
#endif // PLATFORM_WINDOWS
}

FString UGame_Statics::GetVTAKUserAppDataPath()
{
#if PLATFORM_WINDOWS
    return FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"));
#else // PLATFORM_WINDOWS
	return TEXT("");
#endif // PLATFORM_WINDOWS
}

FString UGame_Statics::GetVTAKDownloadPath()
{
#if PLATFORM_WINDOWS
	return FPaths::Combine(GetVTAKUserAppDataPath(), TEXT("Downloads"));
#else // PLATFORM_WINDOWS
	return TEXT("");
#endif // PLATFORM_WINDOWS
}

FString UGame_Statics::GetVTAKTempPath()
{
#if PLATFORM_WINDOWS
	return FPaths::Combine(GetVTAKUserAppDataPath(), TEXT("Temp"));
#else // PLATFORM_WINDOWS
	return TEXT("");
#endif // PLATFORM_WINDOWS
}

// TODO: Consider moving to Developer_Statics (or maybe VH_UIStatics?)
int32 UGame_Statics::GetStringWidth(const FString& message, const FSlateFontInfo& fontInfo)
{
    const UFont* labelFontObject = Cast<UFont>(fontInfo.FontObject);
    return (labelFontObject != nullptr) ? labelFontObject->GetStringSize(*message) : -1;
}

// TODO: Consider moving to Developer_Statics (or maybe VH_UIStatics?)
int32 UGame_Statics::GetStringHeight(const FString& message, const FSlateFontInfo& fontInfo)
{
    const UFont* labelFontObject = Cast<UFont>(fontInfo.FontObject);
    return (labelFontObject != nullptr) ? labelFontObject->GetStringHeightSize(*message) : -1;
}

// TODO: Consider moving to Developer_Statics
FString UGame_Statics::ByteArrayToString(const TArray<uint8>& byteArray)
{
    FMemoryReader fromBinary = FMemoryReader(byteArray);
    fromBinary.Seek(0);

    FString generatedString;
    fromBinary << generatedString;

    return generatedString;
}

// TODO: Consider moving to Developer_Statics
TArray<uint8> UGame_Statics::StringToByteArray(FString string)
{
	FBufferArchive toBinary;
	toBinary << string;
	TArray<uint8> data = (TArray<uint8>&)toBinary;

	return data;
}

FString UGame_Statics::GetClassPathName(UClass* inClass)
{
	if (inClass != nullptr)
	{
		return inClass->GetPathName();
	}

	return TEXT("");
}

void UGame_Statics::GetAllLevelActorsOfClass(ULevelStreaming* level, TSubclassOf<AActor> actorClass, TArray<AActor*>& outActors)
{
	if (level != nullptr)
	{
		TArray<AActor*> levelActors = level->GetLoadedLevel()->Actors;
		for (AActor* actor : levelActors)
		{
			if (IsValid(actor) && actor->IsA(actorClass))
			{
				outActors.Add(actor);
			}
		}
	}
}

bool UGame_Statics::IsWorldTearingDown(UWorld* world)
{
	if (world != nullptr)
	{
		return world->bIsTearingDown;
	}

	return true;
}

bool UGame_Statics::IsLocalPlayerInSession()
{
	if (IOnlineSubsystem* onlineSub = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(UDeveloper_Statics::GetVHWorld());

		if (UGame_GameInstance* gi = UGame_GameInstance::Get())
		{
			if (sessionInterface->IsPlayerInSession(NAME_GameSession, *gi->GetPrimaryPlayerUniqueIdRepl()))
			{
				return true;
			}
		}
	}

	if (AGame_GameState* gameState = GetVHGameState())
	{
		return gameState->PlayerArray.Num() > 1;
	}

	return false;
}

void UGame_Statics::RemoveConnectedPlayersFromSession()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		if (world->GetNetMode() != NM_Client)
		{
			for (FConstPlayerControllerIterator iterator = world->GetPlayerControllerIterator(); iterator; ++iterator)
			{
				if (AGame_PlayerController* pc = Cast<AGame_PlayerController>(iterator->Get()))
				{
					if (pc != GetVHPlayerController())
					{
						pc->bForceLeaveSession = !pc->bForceLeaveSession;
					}
				}
			}
		}
	}
}

void UGame_Statics::ClearWebCache()
{
	FString fullPathOnDisk = FPaths::Combine(GetVTAKUserAppDataPath(), TEXT("Game"), TEXT("Saved"), TEXT("webcache"));

	IFileManager& fileManager = IFileManager::Get();
	fileManager.DeleteDirectory(*fullPathOnDisk, true, true);
}

void UGame_Statics::ClearObjectCache()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->Clear();
	}

	FString fullPathOnDiskCache = FPaths::Combine(GetVTAKUserAppDataPath(), TEXT("Cache"));
	FString fullPathOnDiskTemp = FPaths::Combine(GetVTAKUserAppDataPath(), TEXT("Temp"));

	IFileManager& fileManager = IFileManager::Get();
	fileManager.DeleteDirectory(*fullPathOnDiskCache, true, true);
	fileManager.DeleteDirectory(*fullPathOnDiskTemp, true, true);
}

void UGame_Statics::ClearTerrainTileCache()
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->ClearTiles();
	}

	FString fullPathOnDisk = FPaths::Combine(GetVTAKUserAppDataPath(), TEXT("TileCache"));

	IFileManager& fileManager = IFileManager::Get();
	fileManager.DeleteDirectory(*fullPathOnDisk, true, true);
}

AGame_PlayerState* UGame_Statics::GetLocalPlayerState()
{
	if (AGame_PlayerController* pc = GetVHPlayerController())
	{
		// Note: PlayerController->PlayerState and Pawn->GetPlayerState return separate variables that 
		if (AGame_PlayerState* playerControllerPlayerState = Cast<AGame_PlayerState>(pc->PlayerState))
		{
			return playerControllerPlayerState;
		}
		
		if (APawn* pawn = pc->GetPawn())
		{
			if (AGame_PlayerState* pawnPlayerState = Cast<AGame_PlayerState>(pawn->GetPlayerState()))
			{
				return pawnPlayerState;
			}
		}
	}

	return nullptr;
}

bool UGame_Statics::IsLocalPlayerInTOC()
{
	if (AGame_PlayerState* playerState = GetLocalPlayerState())
	{
		return playerState->GetIsInTOC();
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Statics::IsLocalPlayerInTOC | playerState is nullptr | returning false"));
	return false;
}

void UGame_Statics::SnapToGround(AActor* actor)
{
	if (actor != nullptr)
	{
		if (UWorld* world = actor->GetWorld())
		{
			FVector worldLocation = actor->GetActorLocation();

			FTransform surfaceTransform = GetWorldTransformOverride(worldLocation);
			surfaceTransform.SetLocation(worldLocation);

			// snap to ground to find Z
			FVector startLocation = surfaceTransform.TransformPosition(FVector(0, 0, 10000000));
			FVector endLocation = surfaceTransform.TransformPosition(FVector(0, 0, -10000000));

			FCollisionQueryParams queryParams(NAME_None, true);
			queryParams.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(world, 0));
			queryParams.AddIgnoredActor(actor);

			FHitResult hit;
			if (world->LineTraceSingleByChannel(hit, startLocation, endLocation, UGame_GameInstance::GetTerrainCollisionChannel(), queryParams))
			{
				actor->SetActorLocation(hit.Location);
			}
		}
	}
}

void UGame_Statics::SetAdvertisedSessionName(const FString& advertisedSessionName)
{
	if (IOnlineSubsystem* onlineSub = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(UDeveloper_Statics::GetVHWorld());

		if (FOnlineSessionSettings* onlineSessionSettings = sessionInterface->GetSessionSettings(NAME_GameSession))
		{
			onlineSessionSettings->Set<FString>(TEXT("AdvertisedSessionNameOverride"), advertisedSessionName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing, INVALID_SESSION_SETTING_ID);

			sessionInterface->UpdateSession(NAME_GameSession, *onlineSessionSettings);
		}
	}

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("AdvertisedSessionNameOverride"), advertisedSessionName);
	}
}

FString UGame_Statics::GetAdvertisedSessionName(const FBlueprintSessionResult& blueprintSession)
{
	FString advertisedSessionName;
	if (blueprintSession.OnlineResult.Session.SessionSettings.Get<FString>(TEXT("AdvertisedSessionNameOverride"), advertisedSessionName))
	{
		return advertisedSessionName;
	}

	return TEXT("");
}

TArray<FString> UGame_Statics::AlphabetizeStringArray(const TArray<FString>& inArray)
{
	TArray<FString> alphabetizedArray;
	alphabetizedArray.Append(inArray);

	alphabetizedArray.Sort([](const FString& a, const FString& b) { return a < b; });

	return alphabetizedArray;
}

FString UGame_Statics::GetSmallestDistanceUnit(const FString& currentUnit, const float& distanceInMeters)
{
	if (currentUnit == TEXT("kilometers") && distanceInMeters < 1000)
	{
		return TEXT("meters");
	}
	else if (currentUnit == TEXT("miles") && distanceInMeters < 1609.34)
	{
		return TEXT("feet");
	}
	else return currentUnit;
}

UMaterialInstanceDynamic* UGame_Statics::PopulateContactMaterial(UVH_COTEvent* cotEvent, UMaterialInstanceDynamic* mid, UTexture* machineGeneratedIcon, UTexture* userIcon)
{
	// m-g is machine generated
	if (cotEvent->GetAttribute(TEXT("how")).Equals(TEXT("m-g")))
	{
		mid->SetTextureParameterValue(FName(TEXT("IconTexture")), machineGeneratedIcon);
	}
	else
	{
		mid->SetTextureParameterValue(FName(TEXT("IconTexture")), userIcon);
	}

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		FName groupName = FName(*cotEvent->GetAttribute(TEXT("groupName")));
		FLinearColor groupLinearColor = FLinearColor();

		if (cotManager->GetGroupColor(groupName, groupLinearColor))
		{
			mid->SetVectorParameterValue(FName(TEXT("Color")), groupLinearColor);
		}
		else
		{
			mid->SetVectorParameterValue(FName(TEXT("Color")), FColor(1, 1, 1, 1));
		}
	}

	return mid;
}

bool UGame_Statics::IsSessionPlaybackRecording()
{
	if (UGame_GameInstance* gameInstance = UGame_Statics::GetVHGameInstance())
	{
		if (USessionPlayback_Subsystem_Core* playbackSubsystem = gameInstance->GetSubsystem<USessionPlayback_Subsystem_Core>())
		{
			return playbackSubsystem->GetPlaybackStatus() == EPlaybackStatus::EPS_PlaybackRecording;
		}
	}

	return false;
}

// https://stackoverflow.com/questions/4901959/find-if-a-point-is-inside-a-convex-hull-for-a-set-of-points-without-computing-th
// The point lies outside of the convex hull of the other points if and only if the direction of all the vectors from it to those other points are on less than one half of a circle/sphere/hypersphere around it.
bool UGame_Statics::WithinConvexHull2D(const TArray<FGeodeticCoord3D>& convexHull, const FGeodeticCoord3D& coordinate)
{
	double minBearing = 0;
	double maxBearing = 0;

	bool bCircleSide = false;

	for (int32 i = 0; i < convexHull.Num(); i++)
	{
		double bearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(coordinate.ToGeodeticCoord2D(), convexHull[i].ToGeodeticCoord2D());

		if (i == 0)
		{
			minBearing = bearing - 90;
			maxBearing = bearing + 90;
		}
		else
		{
			bool bLess = false;
			bool bMore = false;

			if (maxBearing >= 360)  // 270.1 - 359.9
			{
				double max = maxBearing - 360;

				// 0 - maxBearing && minBearing - 360
				if ((bearing >= minBearing && bearing < 360) ||
					(bearing >= 0 && bearing <= max))
				{
					
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- bearing: %f | min: %f | max: %f"), bearing, minBearing, maxBearing);
					return true;
				}
			}
			else if (minBearing < 0)  // 0 - 89.9
			{
				double min = minBearing + 360;

				// min - 0 && 0 - maxBearing
				if ((bearing >= min && bearing < 360) ||
					(bearing >= 0 && bearing <= maxBearing))
				{
					
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- bearing: %f | min: %f | max: %f"), bearing, minBearing, maxBearing);
					return true;
				}

			}
			else // 90 - 270
			{
				if (bearing < minBearing || bearing > maxBearing)
				{
					UE_LOG(Game, Warning, TEXT("-- bearing: %f | min: %f | max: %f"), bearing, minBearing, maxBearing);
					return true;
				}
			}
		}
	}

	return false;
}

UVH_MilStd2525* UGame_Statics::GetMilStd2525()
{
	UGame_GameInstance* gi = UGame_Statics::GetVHGameInstance();
	if (gi == nullptr)
	{
		//
		UE_LOG(Game, Error, TEXT("Failed to find VH GameInstance | No MilStd2525 returned"));
		return nullptr;
	}

	UVH_COTGameInstanceSubsystem* cotSubsystem = gi->GetSubsystem<UVH_COTGameInstanceSubsystem>();
	if (cotSubsystem == nullptr)
	{
		UE_LOG(Game, Error, TEXT("Failed to find COT Game Instance Subsystem | No MilStd2525 returned"));
		return nullptr;
	}

	UVH_MilStd2525* milStd2525 = cotSubsystem->GetMilStd2525();
	if (milStd2525 == nullptr)
	{
		UE_LOG(Game, Error, TEXT("Failed to find MilStd2525 | No MilStd2525 returned"));
		return nullptr;
	}

	return milStd2525;
}

FColor UGame_Statics::GetColorFromString(const FString& colorString)
{
	FColor color;

	color.InitFromString(colorString);

	return color;
}

void UGame_Statics::StoreB3DMAsGLTF(const FString& fullPathToB3DM, const FString& fullPathToGLTF)
{
	// b3dm https://github.com/CesiumGS/3d-tiles/tree/main/specification/TileFormats/Batched3DModel#binary-gltf

	TArray<uint8> data;
	FFileHelper::LoadFileToArray(data, *fullPathToB3DM);
	
	if (data.Num() < 28)
	{
		// bad b3dm file; abort
		return;
	}

	// remove magic field
	//data.RemoveAt(0, 4);

	FMemoryReader fromBinary = FMemoryReader(data);
	fromBinary.Seek(4);

	uint32 version;
	fromBinary << version;

	uint32 byteLength;
	fromBinary << byteLength;

	uint32 featureTableJSONByteLength;
	fromBinary << featureTableJSONByteLength;

	uint32 featureTableBinaryByteLength;
	fromBinary << featureTableBinaryByteLength;

	uint32 batchTableJSONByteLength;
	fromBinary << batchTableJSONByteLength;

	uint32 batchTableBinaryByteLength;
	fromBinary << batchTableBinaryByteLength;

	// todo ohg | try removing instead of copying memory
	// remove header
	//data.RemoveAt(0, 24);

	// remove header tables
	//data.RemoveAt(0, featureTableJSONByteLength + featureTableBinaryByteLength + batchTableJSONByteLength + batchTableBinaryByteLength);

	int32 glbOffset = 28 + featureTableJSONByteLength + featureTableBinaryByteLength;
	
	if (batchTableJSONByteLength < (uint32)data.Num())
	{
		glbOffset += batchTableJSONByteLength;
	}
	
	if (batchTableBinaryByteLength < (uint32)data.Num())
	{
		glbOffset += batchTableBinaryByteLength;
	}

	TArray<uint8> glbData;
	glbData.AddZeroed(data.Num() - glbOffset);
	FMemory::Memcpy(glbData.GetData(), data.GetData() + glbOffset, glbData.Num());

	FFileHelper::SaveArrayToFile(glbData, *fullPathToGLTF);
}

void UGame_Statics::StoreGLTFAsGLB(const FString& fullPathToGLTF, const FString& fullPathToGLB)
{
	// https://github.com/jessey-git/fx-gltf
	
	if (FPaths::FileExists(fullPathToGLTF))
	{
		if (IFileManager::Get().FileSize(*fullPathToGLTF) == 0)
		{
			// abort
			return;
		}

		try
		{
			fx::gltf::Document gltf = fx::gltf::LoadFromBinary(TCHAR_TO_ANSI(*fullPathToGLTF));

			fx::gltf::Save(gltf, TCHAR_TO_ANSI(*fullPathToGLB), true);
		}
		catch (fx::gltf::invalid_gltf_document error)
		{
			FString errorString = FString(error.what());

			UE_LOG(Game, Warning, TEXT("-- UGame_Statics::StoreGLTFAsGLB | error: %s"), *errorString);
		}
		catch (...)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_Statics::StoreGLTFAsGLB | unknown error"));
		}
	}
}

bool UGame_Statics::ConvertB3DMToGLBInPlace(const FString& fullPathToB3DM)
{
	FString extension = FPaths::GetExtension(fullPathToB3DM);

	if (extension.Equals(TEXT("b3dm"), ESearchCase::IgnoreCase))
	{
		FString fullPathToGLTF = FPaths::Combine(FPaths::GetPath(fullPathToB3DM), FString::Printf(TEXT("%s.gltf"), *FPaths::GetBaseFilename(fullPathToB3DM)));
		FString fullPathToGLB = FPaths::Combine(FPaths::GetPath(fullPathToB3DM), FString::Printf(TEXT("%s.glb"), *FPaths::GetBaseFilename(fullPathToB3DM)));

		if (FPaths::FileExists(fullPathToGLB))
		{
			return true;
		}

		UGame_Statics::StoreB3DMAsGLTF(fullPathToB3DM, fullPathToGLTF);
		UGame_Statics::StoreGLTFAsGLB(fullPathToGLTF, fullPathToGLB);

		if (IFileManager::Get().FileSize(*fullPathToGLB) == 0)
		{
			// something bad happened when attempting to convert to glb; abort!
			return false;
		}

		return true;
	}

	return false;
}

float UGame_Statics::VectorSign(const FVector2D& vec, const FVector2D& a, const FVector2D& b)
{
	return FMath::Sign((b.X - a.X) * (vec.Y - a.Y) - (b.Y - a.Y) * (vec.X - a.X));
}

// Returns true when the point is inside the triangle
// Should not return true when the point is on one of the edges
bool UGame_Statics::IsPointInTriangle(const FVector2D& testPoint, const FVector2D& a, const FVector2D& b, const FVector2D& c)
{
	float ba = VectorSign(b, a, testPoint);
	float cb = VectorSign(c, b, testPoint);

	// point is in the same direction of all 3 tri edge lines
	// must be inside, regardless of tri winding
	return cb == ba && cb == VectorSign(a, c, testPoint);
}

bool UGame_Statics::IsPointInBox(const FVector2D& testPoint, const FBox2D& box)
{
	return box.IsInside(testPoint);
}

bool UGame_Statics::IsMouseCaptured()
{
	if (UGameViewportClient* viewportClient = UDeveloper_Statics::GetVHWorld()->GetGameViewport())
	{
		return viewportClient->Viewport->HasMouseCapture();
	}

	return false;
}

FVector UGame_Statics::GetTOCScale(const FVector& originalTOCScale)
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		FVector currentScale = virtualObjective->GetActorScale3D();

		return originalTOCScale / (currentScale / FVector(0.01, 0.01, 0.01));
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Statics::GetTOCScale | virtualObjective is nullptr | returning originalTOCScale"));
	return originalTOCScale;
}

void UGame_Statics::RegisterInputMap(UInputMappingContext* mapToAdd, int priority)
{
	if (AGame_PlayerController* playerController = GetVHPlayerController())
	{
		if(UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			inputSubsystem->AddMappingContext(mapToAdd, priority);
			UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("Bound new Input Mapping to Priority - %i"), priority), false, true, true, false, ELogMessageColor::White);
		}
	}
}

void UGame_Statics::UnregisterInputMap(UInputMappingContext* mapToRemove)
{
	if (AGame_PlayerController* playerController = GetVHPlayerController())
	{
		if(UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			inputSubsystem->RemoveMappingContext(mapToRemove);
			UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("Unbound Input Mapping")), false, true, true, false, ELogMessageColor::White);
		}
	}
}

void UGame_Statics::SetDisableDepthTest(UMaterialInterface* materialInterface, bool bDisable)
{
	if (materialInterface != nullptr)
	{
		if (UMaterial* material = materialInterface->GetMaterial())
		{
			material->bDisableDepthTest = bDisable;
		}
	}
}

float UGame_Statics::GetRangePct(const float& minValue, const float& maxValue, const float& value)
{
	return FMath::GetRangePct(minValue, maxValue, value);
}

FString UGame_Statics::GetCoordinateStringInPreferredUnits(const FGeodeticCoord3D& coordinate, bool bIncludeAltitude)
{
	AVH_GlobeReferenceActor* globeReference = nullptr;
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		globeReference = virtualObjective->GetGlobeReference();
	}

	if (!IsValid(globeReference))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Statics::GetCoordinateStringInPreferredUnits | globeReference is nullptr | returning empty string"));

		return TEXT("");
	}

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		if (UDeveloper_Subsystem_UnitConverter* unitConverter = UDeveloper_Subsystem_UnitConverter::Get())
		{
			FString desiredAltitudeUnit = gameSettings->GetSettingString(TEXT("AltitudeReference"));
			FString desiredMeasurementUnit = gameSettings->GetSettingString(TEXT("AltitudeUnit"));

			double altitude = coordinate.Altitude;

			FString convertedAltitude;
			if (desiredAltitudeUnit.Equals(TEXT("altitudeRef_MSL")))
			{
				// msl converter takes coordinate as string and returns string of coordinate
				FString coordinateString = unitConverter->ConvertUnits(TEXT("altitudeRef_HAE"), coordinate.ToString(), desiredAltitudeUnit);
				FGeodeticCoord3D mslCoordinate;
				mslCoordinate.FromString(coordinateString);

				convertedAltitude = FString::Printf(TEXT("%.2f"), mslCoordinate.Altitude);
			}
			else
			{
				convertedAltitude = unitConverter->ConvertUnits(TEXT("altitudeRef_HAE"), FString::Printf(TEXT("%.6f"), altitude), desiredAltitudeUnit);
			}

			convertedAltitude = unitConverter->ConvertUnitsAndFormat(TEXT("meters"), convertedAltitude, desiredMeasurementUnit, 2);

			FString altitudeAbbreviation = unitConverter->GetAbbreviationFromName(desiredAltitudeUnit);

			FString desiredCoordinateUnit = gameSettings->GetSettingString(TEXT("CoordinatesDisplay"));
			if (desiredCoordinateUnit.Equals(TEXT("mgrs"), ESearchCase::IgnoreCase))
			{
				// MGRS
				FString mgrs = globeReference->GetGlobeCoordConverter()->GeodeticToMGRSDouble(coordinate.ToGeodeticCoord2D()).ToString();

				if (bIncludeAltitude)
				{
					return FString::Printf(TEXT("%s %s %s"), *mgrs, *convertedAltitude, *altitudeAbbreviation);
				}
				else
				{
					return mgrs;
				}
			}
			else
			{
				// geodetic
				if (bIncludeAltitude)
				{
					return FString::Printf(TEXT("%.6Lf, %.6Lf, %s %s"), coordinate.Latitude, coordinate.Longitude, *convertedAltitude, *altitudeAbbreviation);
				}
				else
				{
					return FString::Printf(TEXT("%.6Lf, %.6Lf"), coordinate.Latitude, coordinate.Longitude);
				}
			}
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Statics::GetCoordinateStringInPreferredUnits | error | returning empty string"));

	return TEXT("");
}
FTransform UGame_Statics::GetWorldTransformOverride(const FGeodeticCoord3D& coordinate)
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(virtualObjective->GetGlobeReference()))
		{
			return globeReferenceEllipsoid->GetSurfaceTransform(coordinate.ToGeodeticCoord2D());
		}
	}

	return FTransform::Identity;
}

FTransform UGame_Statics::GetWorldTransformOverride(const FVector& worldLocation)
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(virtualObjective->GetGlobeReference()))
		{
			return globeReferenceEllipsoid->GetSurfaceTransform(worldLocation);
		}
	}

	return FTransform::Identity;
}

FTransform UGame_Statics::GetPlayerWorldTransformOverride()
{
	if (AGame_Pawn* pawn = GetVHPlayerPawn())
	{
		return pawn->VRMovement->GetWorldTransformOverride();
	}

	return FTransform::Identity;
}

FString UGame_Statics::Coordinate2DToString(const FGeodeticCoord2D& coordinate)
{
	return coordinate.ToString();
}

FString UGame_Statics::Coordinate3DToString(const FGeodeticCoord3D& coordinate)
{
	return coordinate.ToString();
}

FGeodeticCoord2D UGame_Statics::Coordinate2DFromString(const FString& inString)
{
	FGeodeticCoord2D coordinate = FGeodeticCoord2D::Invalid;
	coordinate.FromString(inString);
	
	return coordinate;
}

FGeodeticCoord3D UGame_Statics::Coordinate3DFromString(const FString& inString)
{
	FGeodeticCoord3D coordinate = FGeodeticCoord3D::Invalid;
	coordinate.FromString(inString);

	return coordinate;
}

FGeodeticCoord2D UGame_Statics::To2DCoordinate(const FGeodeticCoord3D& coordinate)
{
	return coordinate.ToGeodeticCoord2D();
}

FGeodeticCoord3D UGame_Statics::GetPlayerCoordinate()
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			if (AGame_Pawn* playerPawn = GetVHPlayerPawn())
			{
				return globeReference->WorldToGeodeticDouble(playerPawn->GetActorLocation());
			}
		}
	}

	return FGeodeticCoord3D::Invalid;
}

bool UGame_Statics::IsInnerTileLoaded()
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		return IsValid(tileManager->GetTile(ETileID::Inner));
	}

	return false;
}

FVector UGame_Statics::GetModifiedDragLocation(const FVector& location)
{
	FVector modifiedLocation = location;

	if (!IsInnerTileLoaded())
	{
		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
			{
				if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
				{
					FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(location);

					double hae;
					if (tileManager->GetHAEFromDTED(coordinate.ToGeodeticCoord2D(), hae))
					{
						coordinate.Altitude = hae;

						modifiedLocation = globeReference->GeodeticToWorldDouble(coordinate);
					}
				}
			}
		}
	}

	return modifiedLocation;
}

bool UGame_Statics::IsEntityWithinPolygon(const FString& entityUID, const TArray<FGeodeticCoord2D>& polygonCoordinates)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		TArray<FVector2D> polygonVectors;
		for (const FGeodeticCoord2D& coordinate : polygonCoordinates)
		{
			polygonVectors.Add(coordinate.ToVector());
		}

		FSpatialiteResult_BP resultBP = entityDB->QueryUIDForResult(entityUID);
		SpatialiteResult result = resultBP.Result;

		TArray<double> nw = UDatabase_Spatialite::GetPoint(TEXT("northWestBB"), result);
		TArray<double> se = UDatabase_Spatialite::GetPoint(TEXT("southEastBB"), result);

		FGeodeticCoord2D nwCoordinate = FGeodeticCoord2D(nw[0], nw[1]);
		FGeodeticCoord2D seCoordinate = FGeodeticCoord2D(se[0], se[1]);
		
		double longitudeDelta = (seCoordinate.Longitude - nwCoordinate.Longitude) / 10.0;
		double latitudeDelta = (nwCoordinate.Latitude - seCoordinate.Latitude) / 10.0;

		for (double longitude = seCoordinate.Longitude; longitude >= nwCoordinate.Longitude; longitude -= longitudeDelta)
		{
			for (double latitude = nwCoordinate.Latitude; latitude >= seCoordinate.Latitude; latitude -= latitudeDelta)
			{
				if (FGeomTools2D::IsPointInPolygon(FVector2D(longitude, latitude), polygonVectors))
				{
					return true;
				}

				if (latitudeDelta == 0)
				{
					break;
				}
			}

			if (longitudeDelta == 0)
			{
				break;
			}
		}
	}
	
	return false;
}

FString UGame_Statics::MakeStringSafeForFolderName(const FString& input)
{
	FString safeString = input;

	safeString.ReplaceInline(TEXT(" "), TEXT(""));
	safeString.ReplaceInline(TEXT("<"), TEXT(""));
	safeString.ReplaceInline(TEXT(">"), TEXT(""));
	safeString.ReplaceInline(TEXT(":"), TEXT(""));
	safeString.ReplaceInline(TEXT("\""), TEXT(""));
	safeString.ReplaceInline(TEXT("/"), TEXT(""));
	safeString.ReplaceInline(TEXT("\\"), TEXT(""));
	safeString.ReplaceInline(TEXT("|"), TEXT(""));
	safeString.ReplaceInline(TEXT("?"), TEXT(""));
	safeString.ReplaceInline(TEXT("*"), TEXT(""));

	return safeString;
}

// todo ohg | doesn't take deletions into account | add (1), add (2), delete (1), add (get duplicate 2s)
// for now, just returning prefix
FString UGame_Statics::GetUniqueCOTEntityCallsign(UVH_COTEvent* cotEvent, const FString& prefix)
{
	if (UGame_COTManager* cotManager = UGame_COTManager::Get())
	{
		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			int32 count = 0;

			FString type = cotEvent->GetAttribute(TEXT("type"));

			SpatialiteResults results = entityDB->QueryClassUID(UGame_EntityHandler_COT::StaticGetClassUID());
			for (const SpatialiteResult& result : results)
			{
				FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

				UVH_COTEvent* cotEventFromDB = cotManager->GetCotEventFromUID(entityUID);

				if (cotEventFromDB->GetAttribute(TEXT("type")).Equals(type))
				{
					count++;
				}
			}

			//return FString::Printf(TEXT("%s %d"), *prefix, count);
			return FString::Printf(TEXT("%s"), *prefix);
		}
	}

	return prefix;
}