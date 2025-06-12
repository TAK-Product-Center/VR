#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Templates/SubclassOf.h"
#include "Fonts/SlateFontInfo.h"
#include "FindSessionsCallbackProxy.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_Statics.generated.h"

class UGame_GameInstance;
class AGame_GameMode;
class AGame_PlayerController;
class AGame_PlayerState;
class UVH_MilStd2525;
struct FBlueprintSessionResult;
class AGame_Pawn;
class AVH_GlobeReferenceActor;
class AActor;

UCLASS()
class GAME_API UGame_Statics : public UObject
{
    GENERATED_BODY()

    // ---------------------------------
    // --- API
    // ---------------------------------
public:
    UFUNCTION(BlueprintPure, Category = "VhGame")
    static bool GetVHIsWithEditor();

    UFUNCTION(BlueprintPure, Category = "VhGame")
    static bool GetVHIsBuildShipping();

    UFUNCTION(BlueprintPure, Category = "VhGame")
    static bool GetVHIsBuildTest();

    UFUNCTION(BlueprintPure, Category = "VhGame")
    static UGame_GameInstance* GetVHGameInstance();

    UFUNCTION(BlueprintPure, Category = "VhGame")
    static AGame_GameMode* GetVHGameMode();

    UFUNCTION(BlueprintPure, Category = "VhGame")
    static AGame_PlayerController* GetVHPlayerController();

	UFUNCTION(BlueprintPure, Category = "VhGame")
	static AGame_Pawn* GetVHPlayerPawn();

	UFUNCTION(BlueprintPure, Category = "VhGame")
	static AGame_GameState* GetVHGameState();

	/**
	 * @brief	This static function is used to get the full directory of the game layer plugins. This is useful more useful 
	 *			than the FPaths::ProjectPluginsDir() engine function since we place the VTAK plugins in the Program Data. This
	 *			way we, don't have to use #if #else directives in every plugin we have.
	 *
	 * @note	This will point to ../VTAK/Game/Plugins when in the editor and %PROGRAMDATA%/ExtPlugins/ExtPluginDirectories
	 *			when in everything else.
	 * 
	 * @return	FString - The return will be the full path of the plugins directory in VTAK.
	 */
	static FString GetVTAKPluginPath();

    // %ProgramData%/VTAK (all users)
    UFUNCTION(BlueprintPure, Category = "VhGame", meta = (DisplayName = "VTAK Get Common AppData Path"))
    static FString GetVTAKCommonAppDataPath();

    // %AppData%/VTAK (current user)
    UFUNCTION(BlueprintPure, Category = "VhGame", meta = (DisplayName = "VTAK Get User AppData Path"))
    static FString GetVTAKUserAppDataPath();

	/**
	 * @brief	This static function is used to get the full directory of the download folder for VTAK. This folder is used to
	 *			place data files that have been downloaded via VTAK. The files are kept for use in VTAK.
	 *
	 * @note	This will point to %AppData%/VTAK/Downloads/ (for the current user)
	 *
	 * @return	FString - The return will be the full path of the download folder in VTAK.
	 */
	UFUNCTION(BlueprintPure, Category = "VhGame", meta = (DisplayName = "VTAK Get Download Path"))
	static FString GetVTAKDownloadPath();

	/**
	 * @brief	This static function is used to get the full directory of the temp folder for VTAK. This folder is used to
	 *			place data temporarily (such as like downloading a zip from the TAK server and then extracting).
	 *
	 * @note	This will point to %AppData%/VTAK/Temp/ (for the current user)
	 *
	 * @return	FString - The return will be the full path of the temp folder in VTAK.
	 */
	UFUNCTION(BlueprintPure, Category = "VhGame", meta = (DisplayName = "VTAK Get Temp Path"))
	static FString GetVTAKTempPath();

    UFUNCTION(BlueprintCallable)
    static int32 GetStringWidth(const FString& message, const FSlateFontInfo& fontInfo);

    UFUNCTION(BlueprintCallable)
    static int32 GetStringHeight(const FString& message, const FSlateFontInfo& fontInfo);

    UFUNCTION(BlueprintPure)
    static FString ByteArrayToString(const TArray<uint8>& byteArray);

	UFUNCTION(BlueprintPure)
	static TArray<uint8> StringToByteArray(FString string);

	UFUNCTION(BlueprintPure)
	static FString GetClassPathName(UClass* inClass);

	UFUNCTION(BlueprintCallable)
	static void GetAllLevelActorsOfClass(ULevelStreaming* level, TSubclassOf<AActor> actorClass, TArray<AActor*>& outActors);

	UFUNCTION(BlueprintPure)
	static bool IsWorldTearingDown(UWorld* world);

	UFUNCTION(BlueprintPure)
	static bool IsLocalPlayerInSession();

	UFUNCTION(BlueprintCallable)
	static void RemoveConnectedPlayersFromSession();

	UFUNCTION(BlueprintCallable)
	static void ClearWebCache();

	UFUNCTION(BlueprintCallable)
	static void ClearObjectCache();

	UFUNCTION(BlueprintCallable)
	static void ClearTerrainTileCache();

	UFUNCTION(BlueprintCallable)
	static AGame_PlayerState* GetLocalPlayerState();

	UFUNCTION(BlueprintPure)
	static bool IsLocalPlayerInTOC();

	UFUNCTION(BlueprintCallable)
	static void SnapToGround(AActor* actor);

	UFUNCTION(BlueprintCallable)
	static void SetAdvertisedSessionName(const FString& advertisedSessionName);

	UFUNCTION(BlueprintPure)
	static FString GetAdvertisedSessionName(const FBlueprintSessionResult& blueprintSession);

	UFUNCTION(BlueprintCallable)
	static TArray<FString> AlphabetizeStringArray(const TArray<FString>& inArray);

	UFUNCTION(BlueprintPure)
	static FString GetSmallestDistanceUnit(const FString& currentUnit, const float& distanceInMeters);

	UFUNCTION(BlueprintCallable)
	static UMaterialInstanceDynamic* PopulateContactMaterial(UVH_COTEvent* cotEvent, UMaterialInstanceDynamic* mid, UTexture* machineGeneratedIcon, UTexture* userIcon);

	UFUNCTION(BlueprintPure)
	static bool IsSessionPlaybackRecording();

	static bool WithinConvexHull2D(const TArray<FGeodeticCoord3D>& convexHull, const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintPure)
	static UVH_MilStd2525* GetMilStd2525();

	/* expects string in format from FColor::ToString */
	UFUNCTION(BlueprintPure)
	static FColor GetColorFromString(const FString& colorString);

	static void StoreB3DMAsGLTF(const FString& fullPathToB3DM, const FString& fullPathToGLTF);

	static void StoreGLTFAsGLB(const FString& fullPathToGLTF, const FString& fullPathToGLB);

	static bool ConvertB3DMToGLBInPlace(const FString& fullPathToB3DM);

	static float VectorSign(const FVector2D& vec, const FVector2D& a, const FVector2D& b);

	static bool IsPointInTriangle(const FVector2D& testPoint, const FVector2D& a, const FVector2D& b, const FVector2D& c);

	UFUNCTION(BlueprintCallable)
	static bool IsPointInBox(const FVector2D& testPoint, const FBox2D& box);

	UFUNCTION(BlueprintPure)
	static bool IsMouseCaptured();

	/* returns originalTOCScale / ((currentVO scale) / 0.01) */
	UFUNCTION(BlueprintPure)
	static FVector GetTOCScale(const FVector& originalTOCScale);
	
	UFUNCTION(BlueprintCallable)
	static void RegisterInputMap(UInputMappingContext* mapToAdd, int priority);
	
	UFUNCTION(BlueprintCallable)
	static void UnregisterInputMap(UInputMappingContext* mapToRemove);

	UFUNCTION(BlueprintCallable)
	static void SetDisableDepthTest(UMaterialInterface* materialInterface, bool bDisable);
	
	UFUNCTION(BlueprintPure)
	static float GetRangePct(const float& minValue, const float& maxValue, const float& value);

	UFUNCTION(BlueprintPure)
	static FString GetCoordinateStringInPreferredUnits(const FGeodeticCoord3D& coordinate, AVH_GlobeReferenceActor* globeReference);

	static FTransform GetWorldTransformOverride(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintCallable)
	static FTransform GetWorldTransformOverride(const FVector& worldLocation);

	static FTransform GetPlayerWorldTransformOverride();

	UFUNCTION(BlueprintPure)
	static FString Coordinate2DToString(const FGeodeticCoord2D& coordinate);

	UFUNCTION(BlueprintPure)
	static FString Coordinate3DToString(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintPure)
	static FGeodeticCoord2D Coordinate2DFromString(const FString& inString);

	UFUNCTION(BlueprintPure)
	static FGeodeticCoord3D Coordinate3DFromString(const FString& inString);

	UFUNCTION(BlueprintPure)
	static FGeodeticCoord2D To2DCoordinate(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintPure)
	static FGeodeticCoord3D GetPlayerCoordinate();

	UFUNCTION(BlueprintPure)
	static bool IsInnerTileLoaded();

	/// @brief Finds coordinate at location, then modifies altitude to DTED0 altitude
	/// should be used when dragging entities while zoomed out far enough that Inner terrain tile is not loaded
	UFUNCTION(BlueprintPure)
	static FVector GetModifiedDragLocation(const FVector& location);
};
