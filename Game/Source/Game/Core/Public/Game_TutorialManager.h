#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Tickable.h"
#include "Misc/EnumRange.h"

// Generated Includes
#include "Game_TutorialManager.generated.h"

class UWorld;
class UInputMappingContext;
class UMaterial;


// ---------------------------------
// --- Global Variables
// ---------------------------------

const FString QUICKTURN_ACTION = TEXT("quickturn");
const FString LOOKED_AT_ORB_ACTION = TEXT("lookedAtOrb");
const FString TOGGLE_NOPOINTER_ACTION = TEXT("toggleNoPointer");  
const FString TOGGLE_POINTER_ACTION = TEXT("togglePointer"); 
const FString RIBBON_VISIBLE_ACTION = TEXT("ribbonVisible");
const FString MOVEMENT_MODE_WALK_ACTION = TEXT("movementMode_Walk");
const FString PLAYER_FINISHED_MOVE_ACTION = TEXT("playerFinishedMove");
const FString TOC_ZOOM_IN_ACTION = TEXT("tocZoomIn");
const FString TOC_ZOOM_OUT_ACTION = TEXT("tocZoomOut");
const FString GO_TO_WORLD_ACTION = TEXT("goToWorld");
const FString MOVEMENT_MODE_TELEPORT_ACTION = TEXT("movementMode_Teleport"); 
const FString TELEPORT_KEY_DOWN_ACTION = TEXT("teleportKeyDown");  
const FString TELEPORT_ROTATE_ACTION = TEXT("teleportRotate");  
const FString TELEPORT_KEY_UP_ACTION = TEXT("teleportKeyUp");  
const FString NAVIGATE_TO_CREATE_AREA_ACTION = TEXT("navigateToCreateArea");
const FString POINT_CREATED_ACTION = TEXT("pointCreated");
const FString POINT_MODIFIED_ACTION = TEXT("pointModified");
const FString MOVEMENT_MODE_FLY_ACTION = TEXT("movementMode_Fly"); 
const FString PLAYER_FINISHED_FLY_ACTION = TEXT("playerFinishedFly");
const FString GO_TO_TOC_ACTION = TEXT("goToTOC");


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class ETutorialStage : uint8
{
	Inactive,
	Initial,
	Quickturn_VR,
	CameraControl,
	MouseLook_Desktop,
	NoMouseLook_Desktop,
	Ribbon,
	WalkMovementMode,
	WalkPlayerMovement,
	LookTable,
	Table,
	GoToWorld,
	TeleportMovementMode,
	TeleportKeyDown,
	TeleportRotate,
	NavigateToCreateArea,
	CreateEntity,
	ModifyEntity,
	FlyMovementMode,
	FlyPlayerMovement,
	CreateEntity2,
	Finish
};
ENUM_RANGE_BY_FIRST_AND_LAST(ETutorialStage, ETutorialStage::Inactive, ETutorialStage::Finish);

/**
 *	manager for the tutorial to track the progress and various operations for the tutorial
 */
UCLASS(Blueprintable)
class GAME_API UGame_TutorialManager : public UObject, public FTickableGameObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTutorialActionOccurred, const FString&, tutorialAction);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTutorialStageChanged, ETutorialStage, tutorialStage);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTutorialStageCompleted, ETutorialStage, tutorialStage);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FUpdateUI, UTexture2D*, image, UTexture2D*, checkbox, bool, bShowEnter, const FString&, header, const FString&, body, bool, bIsVR);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FConfirmProgressInput);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnTutorialActionOccurred OnTutorialActionOccurred;

	UPROPERTY(BlueprintAssignable)
	FOnTutorialStageChanged OnTutorialStageChanged;

	UPROPERTY(BlueprintAssignable)
	FOnTutorialStageCompleted OnTutorialStageCompleted;

	UPROPERTY(BlueprintAssignable)
	FUpdateUI OnUpdateUI;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FConfirmProgressInput OnConfirmProgressInput;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString TutorialModelFilename;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector TOCTableScale;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector TOCTableOffset;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AActor*> CameraOrbs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AActor*> MovementOrbs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* TeleportMovementOrb;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* FlyMovementOrb;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bWaitingOnProgressInput;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterial* TutorialUIMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UInputMappingContext* TutorialInputMap;

private:
	static UGame_TutorialManager* GlobalInstance;

	ETutorialStage TutorialStage;

	FString PreviousCompletedAction;

	int32 CameraOrbsFound;

	int32 NumberOfQuickturns;

	int32 NumberOfZooms;

	bool bCanSwitchMouseLook;

	bool bHasSwitchedMouseLook;

	TArray<ETutorialStage> DesktopStages { ETutorialStage::Inactive,
											ETutorialStage::Initial,
											ETutorialStage::CameraControl,
											ETutorialStage::MouseLook_Desktop,
											ETutorialStage::NoMouseLook_Desktop,
											ETutorialStage::Ribbon,
											ETutorialStage::WalkMovementMode,
											ETutorialStage::WalkPlayerMovement,
											ETutorialStage::LookTable,
											ETutorialStage::Table,
											ETutorialStage::GoToWorld,
											ETutorialStage::TeleportMovementMode,
											ETutorialStage::TeleportKeyDown,
											ETutorialStage::TeleportRotate,
											ETutorialStage::NavigateToCreateArea,
											ETutorialStage::CreateEntity,
											ETutorialStage::ModifyEntity,
											ETutorialStage::FlyMovementMode,
											ETutorialStage::FlyPlayerMovement,
											ETutorialStage::CreateEntity2,
											ETutorialStage::Finish };

	TArray<ETutorialStage> VrStages { ETutorialStage::Inactive,
											ETutorialStage::Initial,
											ETutorialStage::CameraControl,
											ETutorialStage::Ribbon,
											ETutorialStage::WalkMovementMode,
											ETutorialStage::WalkPlayerMovement,
											ETutorialStage::LookTable,
											ETutorialStage::Table,
											ETutorialStage::GoToWorld,
											ETutorialStage::TeleportMovementMode,
											ETutorialStage::TeleportKeyDown,
											ETutorialStage::TeleportRotate,
											ETutorialStage::NavigateToCreateArea,
											ETutorialStage::CreateEntity,
											ETutorialStage::ModifyEntity,
											ETutorialStage::FlyMovementMode,
											ETutorialStage::FlyPlayerMovement,
											ETutorialStage::CreateEntity2,
											ETutorialStage::Finish };
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TutorialManager();


    // ---------------------------------
    // --- FTickableObjectBase
    // ---------------------------------

public:
	virtual TStatId GetStatId() const override;

    virtual bool IsTickable() const override;

    virtual void Tick(float deltaSeconds) override;


    // ---------------------------------
    // --- Static Functions
    // ---------------------------------

public:
    UFUNCTION(BlueprintPure, Category = "Game|TutorialManager", meta = (DisplayName = "Get Game Tutorial Manager"))
    static UGame_TutorialManager* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual UWorld* GetWorld() const;
	

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	bool IsInTutorial() const;

	UFUNCTION(BlueprintCallable)
	bool ClearTutorialDatabase();

	UFUNCTION(BlueprintCallable)
	ETutorialStage GetTutorialStage() const;

	UFUNCTION(BlueprintCallable)
	void SetTutorialStage(ETutorialStage tutorialStage);

	UFUNCTION(BlueprintCallable)
	void TutorialActionOccurred(const FString& actionID);

	bool Initialize();

	/* resets tutorial and opens MainMap_P */
	UFUNCTION(BlueprintCallable)
	void AbortTutorial();

	UFUNCTION(BlueprintCallable)
	void GoToNextDesktopStage();

	UFUNCTION(BlueprintCallable)
	void GoToNextVRStage();

	UFUNCTION(BlueprintCallable)
	void UpdateUI(UTexture2D* image, UTexture2D* checkbox, bool bShowEnter, const FString& header, const FString& body, bool bIsVR);

	bool GetHasSwitchedMouseLook();

	void SetHasSwitchedMouseLook(bool bNewHasSwitched);
	
	bool GetCanSwitchMouseLook();

	/////// Implementable Events ///////

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTutorialActionOccurred(const FString& actionID);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTutorialStageChanged(ETutorialStage tutorialStage);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveTutorialStageCompleted(ETutorialStage tutorialStage);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool ProgressIfWaiting();
};
