// Required Includes
#include "Game_GameInstance.h"

// Engine Includes
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "IHeadMountedDisplay.h"
#include "IXRTrackingSystem.h"
#include "Components/WidgetComponent.h"
#include "Slate/SObjectWidget.h"
#include "MoviePlayer.h"
#include "Styling/SlateBrush.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/Images/SImage.h"
#include "GameFramework/GameUserSettings.h"

// VH Plugins Includes
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "Developer_PersistentSettings.h"
#include "Developer_PersistentSettings_XML.h"
#include "VH_GeodeticCoord.h"
#include "VH_GlobeCoordConverter.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_KmlCoordinates.h"
#include "VH_KmlGroundOverlay.h"
#include "VH_KmlGxLatLonQuad.h"
#include "VH_KmlIcon.h"
#include "VH_KmlInfo.h"
#include "VH_MgrsCoord.h"
#include "SessionPlayback_Subsystem_Core.h"
#include "VH_UpsCoord.h"
#include "VH_UtmCoord.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_Subsystem_Core.h"
#include "Game_BloodhoundManager.h"
#include "Game_HandlerService.h"
#include "Game_ImportManager.h"
#include "Game_PlayerController.h"
#include "Game_SessionPlayback_Impl.h"
#include "Game_Statics.h"
#include "Game_TutorialManager.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_TOCBoardDB.h"
#include "Game_EntityDB.h"

#include "gdal.h"

class SLoadingWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLoadingWidget) :
		_LoadingTexture(nullptr)
	{
		
	}

	SLATE_ARGUMENT(UTexture2D*, LoadingTexture);

	SLATE_END_ARGS()
	
	void Construct(const FArguments& InArgs)
	{
		UTexture2D* loadingTexture = InArgs._LoadingTexture;

		ImageBrush.SetResourceObject(loadingTexture);
		ImageBrush.SetImageSize(FVector2D(loadingTexture->GetSizeX(), loadingTexture->GetSizeY()));

		ChildSlot
		[
			SNew(SOverlay)
				+ SOverlay::Slot()
				.VAlign(VAlign_Fill)
				.HAlign(HAlign_Fill)
				[
					SNew(SScaleBox)
						.Stretch(EStretch::ScaleToFit)
						[
							SNew(SImage)
							.Image(&ImageBrush)
						]
				]
		];
	}

private:
	FSlateBrush ImageBrush;
};

UGame_GameInstance* UGame_GameInstance::GlobalInstance = nullptr;

UGame_GameInstance::UGame_GameInstance(const FObjectInitializer& objectInitializer) :
    Super(objectInitializer)
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		GlobalInstance = this;
	}

	GameSettingsXMLClass = UDeveloper_PersistentSettings_XML::StaticClass();
	GameSettingsXML = nullptr;

	HandlerServiceClass = UGame_HandlerService::StaticClass();
	HandlerService = nullptr;

    ImportManagerClass = UGame_ImportManager::StaticClass();
    ImportManager = nullptr;

	TutorialManagerClass = UGame_TutorialManager::StaticClass();
	TutorialManager = nullptr;

    VirtualObjectiveManagerClass = UGame_VirtualObjectiveManager::StaticClass();
    VirtualObjectiveManager = nullptr;

	WGS84GlobeCoordConverter = nullptr;
}

// ---------------------------------
// --- FTickable
// ---------------------------------

bool UGame_GameInstance::IsTickable() const
{
	return true;
}

void UGame_GameInstance::Tick(float deltaSeconds)
{

}

TStatId UGame_GameInstance::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UGame_GameInstance, STATGROUP_Tickables);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_GameInstance::Init()
{
	Super::Init();

	GDALAllRegister();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UGame_GameInstance::OpenLoadingScreen);

	BloodhoundManager = CreateSingletonManager<UGame_BloodhoundManager>(BloodhoundManagerClass, TEXT("BloodhoundManager"));
	GameSettingsXML = CreateSingletonManager<UDeveloper_PersistentSettings_XML>(GameSettingsXMLClass, TEXT("GameSettingsXML"));
	HandlerService = CreateSingletonManager<UGame_HandlerService>(HandlerServiceClass, TEXT("HandlerService"));
	ImportManager = CreateSingletonManager<UGame_ImportManager>(ImportManagerClass, TEXT("ImportManager"));
	VirtualObjectiveManager = CreateSingletonManager<UGame_VirtualObjectiveManager>(VirtualObjectiveManagerClass, TEXT("VirtualObjectiveManager"));
	TutorialManager = CreateSingletonManager<UGame_TutorialManager>(TutorialManagerClass, TEXT("TutorialManager"));
	TOCBoardDB = CreateSingletonManager<UGame_TOCBoardDB>(TOCBoardDBClass, TEXT("TOCBoardDB"));

	BloodhoundManager->Initialize();
	HandlerService->Initialize();
	VirtualObjectiveManager->Initialize();
	TutorialManager->Initialize();

	PopulateGameSettingsXML();
	PopulateDefaultSettings();

	TOCBoardDB->Connect();

	PostInit();
}

// ---------------------------------
// --- API
// ---------------------------------

UGame_GameInstance* UGame_GameInstance::Get()
{
    return GlobalInstance;
}

void UGame_GameInstance::OnGameModeInit()
{
    if (HandlerService != nullptr)
    {
        HandlerService->OnGameModeInit();
    }

    if (VirtualObjectiveManager)
    {
        VirtualObjectiveManager->OnGameModeInit();
    }

	if (!UGame_Statics::IsLocalPlayerInSession())
	{
		MUCDeletedEntityUIDs.Empty();

		MUCCreatedEntityUIDs.Empty();
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnGameModeInit();
	}

	GetSubsystem<USessionPlayback_Subsystem_Core>()->RegisterImplementation(TEXT("vtak.core"), NewObject<UGame_SessionPlayback_Impl>());

	OnPostGameModeInit.Broadcast();
}

void UGame_GameInstance::OnGameModeStartToLeaveMap()
{
    if (HandlerService != nullptr)
    {
        HandlerService->OnGameModeStartToLeaveMap();
    }

    if (VirtualObjectiveManager)
    {
        VirtualObjectiveManager->OnGameModeStartToLeaveMap();
    }

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnGameModeStartToLeaveMap();
	}
}

UVH_GlobeCoordConverter* UGame_GameInstance::GetWGS84GlobeCoordConverter()
{
	if (WGS84GlobeCoordConverter == nullptr)
	{
		WGS84GlobeCoordConverter = NewObject<UVH_GlobeCoordConverter>(this, FName(TEXT("WGS84 GlobeCoordConverter")));
	}

	return WGS84GlobeCoordConverter;
}

UVH_GlobeCoordConverter* UGame_GameInstance::GetWGS84GlobeCoordConverter_Static()
{
	UVH_GlobeCoordConverter* globeConverter = nullptr;

	if (UGame_GameInstance* gi = UGame_GameInstance::Get())
	{
		globeConverter = gi->GetWGS84GlobeCoordConverter();
	}

	return globeConverter;
}

ECollisionChannel UGame_GameInstance::GetTerrainCollisionChannel()
{
	if (UGame_GameInstance* gameInstance = UGame_GameInstance::Get())
	{
		return gameInstance->TerrainCollisionChannel;
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_GameInstance::GetTerrainCollisionChannel | gameInstance is nullptr | return ECC_Visibility"));

	return ECC_Visibility;
}

bool UGame_GameInstance::GetHashFromFile(const FString& fullPathToFile, FMD5Hash& hash)
{
	FScopeLock scopeLock(&FileToHashCritSection);

	if (FMD5Hash* hashPtr = FileToHash.Find(fullPathToFile))
	{
		hash = *hashPtr;

		return true;
	}

	return false;
}

bool UGame_GameInstance::GetFileFromHash(const FMD5Hash& hash, FString& file)
{
	FScopeLock scopeLock(&HashToFileCritSection);

	if (FString* filePtr = HashToFile.Find(LexToString(hash)))
	{
		file = *filePtr;

		return true;
	}

	return false;
}

void UGame_GameInstance::AddHashForFile(const FMD5Hash& hash, const FString& fullPathToFile)
{
	{
		FScopeLock scopeLock(&HashToFileCritSection);
		HashToFile.Add(LexToString(hash), fullPathToFile);
	}

	{
		FScopeLock scopeLock(&FileToHashCritSection);
		FileToHash.Add(fullPathToFile, hash);
	}
}

void UGame_GameInstance::MUC_AddCreatedEntityUID(const FName& entityUID)
{
	MUCCreatedEntityUIDs.Add(entityUID);
}

void UGame_GameInstance::MUC_RemoveCreatedEntityUID(const FName& entityUID)
{
	MUCCreatedEntityUIDs.Remove(entityUID);
}

bool UGame_GameInstance::MUC_HasCreatedEntityUID(const FName& entityUID) const
{
	return MUCCreatedEntityUIDs.Contains(entityUID);
}

void UGame_GameInstance::AddSettingsSubmenuTable(UDataTable* inDataTable)
{
	SettingsSubmenuList.Add(inDataTable);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_GameInstance::Shutdown()
{
	if (BloodhoundManager)
	{
		BloodhoundManager->Shutdown();
		BloodhoundManager = nullptr;
	}

	if (GameSettingsXML != nullptr)
	{
		GameSettingsXML = nullptr;
	}

	if (HandlerService)
	{
		HandlerService->Shutdown();
		HandlerService = nullptr;
	}

	if (VirtualObjectiveManager)
	{
		VirtualObjectiveManager->Shutdown();
		VirtualObjectiveManager = nullptr;
	}

	TOCBoardDB = nullptr;

	// NOTE: Do cleanup BEFORE setting GlobalInstance = nullptr
    GlobalInstance = nullptr;

	Super::Shutdown();
}

void UGame_GameInstance::PopulateDefaultSettings()
{
	if (UDeveloper_PersistentSettings* gameSettings = GetSubsystem<UGame_Subsystem_Core>()->GetGameSettingsDirect())
	{
		// video settings
		gameSettings->StoreDefaultSettingBool(TEXT("vsync"), false);
		gameSettings->StoreDefaultSettingDouble(TEXT("fpsLimit"), 0);

		if (UGameUserSettings* userSettings = GEngine->GetGameUserSettings())
		{
			userSettings->SetVSyncEnabled(gameSettings->GetSettingBool(TEXT("vsync")));
			userSettings->SetFrameRateLimit(gameSettings->GetSettingDouble(TEXT("fpsLimit")));
		}

		gameSettings->StoreDefaultSettingInt(TEXT("tocTableZoomIndex"), 1);

		gameSettings->StoreDefaultSettingBool(TEXT("CenterAllPlaceables"), false);
		gameSettings->StoreDefaultSettingBool(TEXT("CloseAllTabs"), false);
		gameSettings->StoreDefaultSettingBool(TEXT("FadeEdgeWhenMoving"), false);
		gameSettings->StoreDefaultSettingBool(TEXT("InvertLook"), true);
		gameSettings->StoreDefaultSettingBool(TEXT("ReopenUIonStart"), false);
		gameSettings->StoreDefaultSettingBool(TEXT("TutorialPrompted"), false);
		gameSettings->StoreDefaultSettingBool(TEXT("ShouldUserRotate"), true);
		gameSettings->StoreDefaultSettingBool(TEXT("XRayIcons"), true);

		gameSettings->StoreDefaultSettingDouble(TEXT("IconScale"), 0.7f);
		gameSettings->StoreDefaultSettingDouble(TEXT("ApplicationScale"), 1.0f);
		gameSettings->StoreDefaultSettingDouble(TEXT("LineScale"), 1.f);
		gameSettings->StoreDefaultSettingDouble(TEXT("MovementSpeed"), 0.75);
		gameSettings->StoreDefaultSettingString(TEXT("Keyboard"), TEXT("Computer Keyboard"));
		gameSettings->StoreDefaultSettingDouble(TEXT("ObjectViewDistance"), 3000.f);

		gameSettings->StoreDefaultSettingString(TEXT("AltitudeReference"), TEXT("altitudeRef_MSL"));
		gameSettings->StoreDefaultSettingString(TEXT("AltitudeUnit"), TEXT("feet"));
		gameSettings->StoreDefaultSettingString(TEXT("BearingUnit"), TEXT("degrees"));
		gameSettings->StoreDefaultSettingString(TEXT("CollaborationColor"), TEXT("0|0|0|-1"));
		gameSettings->StoreDefaultSettingString(TEXT("CoordinatesDisplay"), TEXT("mgrs"));
		gameSettings->StoreDefaultSettingString(TEXT("RangeUnit"), TEXT("miles"));
		gameSettings->StoreDefaultSettingString(TEXT("TimeUnit"), TEXT("hours"));
		
		if (!gameSettings->HasDefaultSetting(TEXT("AdvertisedSessionNameOverride")))
		{
			gameSettings->StoreDefaultSettingString(TEXT("AdvertisedSessionNameOverride"), FGuid::NewGuid().ToString());
		}

		gameSettings->StoreDefaultSettingString(TEXT("ToolVehicleClass"), TEXT("/Game/VTAK/BP/ActorRepresentatives/Vehicles/Vehicle_Humvee.Vehicle_Humvee_C"));
		gameSettings->StoreDefaultSettingString(TEXT("Tool2525Type"), TEXT("u-G"));

		gameSettings->StoreDefaultSettingInt(TEXT("MaxConcurrentMeshBuilders"), 5);
		gameSettings->StoreDefaultSettingDouble(TEXT("ModelTrianglesPerComponent"), 200000);
		gameSettings->StoreDefaultSettingDouble(TEXT("ModelSecondsBetweenComponentCreate"), 0.05);
		gameSettings->StoreDefaultSettingDouble(TEXT("ModelVerticesPerComponent"), 100000);
		gameSettings->StoreDefaultSettingDouble(TEXT("ModelTextureRenderDistance"), 1500);

		gameSettings->StoreDefaultSettingString(TEXT("HeartbeatCoordinate"), TEXT("0, 0, 0"));
		gameSettings->StoreDefaultSettingString(TEXT("InitialCoordinate"), TEXT("-79.16243, 35.122585, 75"));
		gameSettings->StoreDefaultSettingBool(TEXT("bInitialInTOC"), true);
		gameSettings->StoreDefaultSettingBool(TEXT("bStartAtLastLocation"), true);
		
		gameSettings->StoreDefaultSettingString(TEXT("LoadedRibbonLayout"), TEXT("Default"));

		gameSettings->StoreDefaultSettingBool(TEXT("bShowBeamEndMesh"), false);
		gameSettings->StoreDefaultSettingDouble(TEXT("BeamEndMeshScale"), 1);
		gameSettings->StoreDefaultSettingString(TEXT("BeamEndMeshColor"), FLinearColor(1, 1, 0, 0.25).ToString());
	}
}

void UGame_GameInstance::PopulateGameSettingsXML()
{
	if (GameSettingsXML != nullptr)
	{
		GameSettingsXML->SetFilename(FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Settings"), TEXT("gameSettings.xml")));
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_GameInstance::OpenLoadingScreen(const FString& mapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes loadingScreenAttributes;
		loadingScreenAttributes.bAutoCompleteWhenLoadingCompletes = false;
		loadingScreenAttributes.WidgetLoadingScreen = SNew(SLoadingWidget).LoadingTexture(LoadingScreenTexture);

		GetMoviePlayer()->SetupLoadingScreen(loadingScreenAttributes);
	}
}