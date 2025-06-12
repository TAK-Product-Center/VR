#pragma once

// Parent Includes
#include "Engine/GameInstance.h"
#include "Tickable.h"

// Engine Includes
#include "GameFramework/InputSettings.h"
#include "Misc/SecureHash.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Game Includes
#include "Game.h"

// Generated Includes
#include "Game_GameInstance.generated.h"

class UDeveloper_PersistentSettings_XML;
class UVH_GlobeCoordConverter;
class UGame_ImportManager;
class UGame_BloodhoundManager;
class UGame_EntityDB;
class UGame_HandlerService;
class UGame_VirtualObjectiveManager;
class UGame_TutorialManager;
class UGame_TOCBoardDB;
class UTexture2D;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPostGameModeInit);

UCLASS()
class GAME_API UGame_GameInstance : public UGameInstance, public FTickableGameObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

protected:
	UPROPERTY(BlueprintAssignable)
	FOnPostGameModeInit OnPostGameModeInit;
	

    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
	TSet<FName> MUCDeletedEntityUIDs;

	TSet<FName> MUCCreatedEntityUIDs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> TerrainCollisionChannel;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "VTAKGameInstance|Singleton Classes")
	TSubclassOf<UGame_BloodhoundManager> BloodhoundManagerClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "VTAKGameInstance|Singleton Classes")
	TSubclassOf<UDeveloper_PersistentSettings_XML> GameSettingsXMLClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "VTAKGameInstance|Singleton Classes")
	TSubclassOf<UGame_HandlerService> HandlerServiceClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "VTAKGameInstance|Singleton Classes")
	TSubclassOf<UGame_ImportManager> ImportManagerClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "VTAKGameInstance|Singleton Classes")
	TSubclassOf<UGame_TutorialManager> TutorialManagerClass;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "VTAKGameInstance|Singleton Classes")
	TSubclassOf<UGame_VirtualObjectiveManager> VirtualObjectiveManagerClass;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "VTAKGameInstance|Singleton Classes")
	TSubclassOf<UGame_TOCBoardDB> TOCBoardDBClass;

	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Singletons")
	UGame_BloodhoundManager* BloodhoundManager;

	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Singletons")
	UDeveloper_PersistentSettings_XML* GameSettingsXML;

	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Singletons")
	UGame_HandlerService* HandlerService;

	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Singletons")
	UGame_ImportManager* ImportManager;

	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Singletons")
	UGame_TutorialManager* TutorialManager;

	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Singletons")
	UGame_VirtualObjectiveManager* VirtualObjectiveManager;

	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Singletons")
	UGame_TOCBoardDB* TOCBoardDB;

	/* Tables that contain additional settings to be used by the main VR settings widget. */
	UPROPERTY(BlueprintReadOnly, Category = "VTAKGameInstance|Settings")
	TSet<TObjectPtr<UDataTable>> SettingsSubmenuList;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* LoadingScreenTexture;
	
private:
	UPROPERTY()
	UVH_GlobeCoordConverter* WGS84GlobeCoordConverter;

    static UGame_GameInstance* GlobalInstance;

	TMap<FString, FMD5Hash> FileToHash;

	TMap<FString, FString> HashToFile;

	// TODO: This is temporary, just for level transitions
	FGeodeticCoord3D TransitionGeoLocation;

	FCriticalSection FileToHashCritSection;

	FCriticalSection HashToFileCritSection;


    // ---------------------------------
    // --- Inherited
    // ---------------------------------

public:
    UGame_GameInstance(const FObjectInitializer& ObjectInitializer);

    virtual void Init() override;

    virtual bool IsTickable() const override;
    
	virtual void Tick(float deltaSeconds) override;
    
	virtual TStatId GetStatId() const override;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure, Category = "VTAKGameInstance|API", meta = (DisplayName = "Get VTAK Game Instance"))
	static UGame_GameInstance* Get();

	UFUNCTION(BlueprintPure, Category = "VTAKGameInstance")
	static UVH_GlobeCoordConverter* GetWGS84GlobeCoordConverter_Static();

	UFUNCTION(BlueprintPure)
	static ECollisionChannel GetTerrainCollisionChannel();

    
	// ---------------------------------
    // --- API
    // ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void PostInit();

    // NOTE: This will be called each time loading into a new persistent map!
    UFUNCTION()
    virtual void OnGameModeInit();

    // NOTE: This will be called each time leaving a persistent map!
    UFUNCTION()
    void OnGameModeStartToLeaveMap();

	UFUNCTION(BlueprintPure, Category = "VTAKGameInstance")
	UVH_GlobeCoordConverter* GetWGS84GlobeCoordConverter();

	// thread-safe
	bool GetHashFromFile(const FString& fullPathToFile, FMD5Hash& hash);

	// thread-safe
	bool GetFileFromHash(const FMD5Hash& hash, FString& file);

	// thread-safe
	void AddHashForFile(const FMD5Hash& hash, const FString& fullPathToFile);

	UFUNCTION(BlueprintCallable)
	void MUC_AddCreatedEntityUID(const FName& entityUID);

	void MUC_RemoveCreatedEntityUID(const FName& entityUID);

	bool MUC_HasCreatedEntityUID(const FName& entityUID) const;

	/* Only tables of struct SSettingsSubmenus are valid. */
	UFUNCTION(BlueprintCallable)
	void AddSettingsSubmenuTable(UDataTable* inDataTable);


	// ---------------------------------
    // --- Implementation
    // ---------------------------------

protected:
    virtual void Shutdown() override;

private:
	UFUNCTION()
	void PopulateDefaultSettings();

	void PopulateGameSettingsXML();

	template<typename T>
	T* CreateSingletonManager(UClass* singletonClass, const FString& nameForError)
	{
		T* newSingleton = nullptr;

		if (singletonClass != nullptr)
		{
			newSingleton = NewObject<T>(GetTransientPackage(), singletonClass);
		}
			
		if (singletonClass == nullptr || newSingleton == nullptr)
		{
			UE_LOG(Game, Warning, TEXT("%s"), *FString::Printf(TEXT("Could not create singleton manager (%s) with class (%s)"), *nameForError, singletonClass ? *singletonClass->GetName() : TEXT("nullptr")));
		}

		return newSingleton;
	}


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void OpenLoadingScreen(const FString& mapName);
};
