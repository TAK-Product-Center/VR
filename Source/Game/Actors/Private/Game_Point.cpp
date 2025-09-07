// Required Includes
#include "Game_Point.h"
#include "Game.h"

// Engine Includes
#include "Components/SceneCaptureComponent2D.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "Developer_Statics.h"
#include "VH_GlobeReferenceActor.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_CameraScalingComponent.h"
#include "Game_Pawn.h"
#include "Game_UserWidget_SendTo.h"
#include "Game_Tracking.h"
#include "Game_COTComponent.h"
#include "Game_UserWidget_Point.h"
#include "Game_VirtualObjective.h"
#include "Game_Subsystem_Core.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_WidgetComponent.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Point::AGame_Point(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer)
{
	CallsignComponent = CreateDefaultSubobject<UGame_WidgetComponent>(TEXT("CallsignComponent"));
	CallsignComponent->SetupAttachment(CameraScalingComponent);

	COTComponent = CreateDefaultSubobject<UGame_COTComponent>(TEXT("COTComponent"));
}

// ---------------------------------
// --- Interface_COTReceiver
// ---------------------------------

UVH_COTComponent* AGame_Point::GetCOTComponent_Implementation() const
{
	return COTComponent;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Point::BeginPlay()
{
	Super::BeginPlay();

	Tags.Add(TEXT("ignoreLOS"));

	if (COTComponent != nullptr)
	{
		COTComponent->OnReceivedCOTUpdate.AddDynamic(this, &AGame_Point::HandleReceivedCOTUpdate);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_Point::BeginPlay | COTComponent is nullptr | %s"), *GetName());
	}

	if (CallsignWidgetClass != nullptr)
	{
		CallsignWidget = NewObject<UGame_UserWidget_Point>(this, CallsignWidgetClass);
		if (CallsignWidget != nullptr)
		{
			CallsignComponent->SetWidget(CallsignWidget);

			SyncCallsignWidget();
		}

		if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
		{
			CameraScalingComponent->AddDistanceThreshold(subsystem->GetCallsignShowDistanceMeters());
			CameraScalingComponent->OnThresholdCrossed.AddDynamic(this, &AGame_Point::HandleDistanceThresholdCrossed);

			PostEndHover(UGame_Statics::GetVHPlayerPawn());
		}
	}

	CameraScalingComponent->CustomScaleMultiplier = GetSettingScaleMultiplier();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->OnDoubleSettingStored.AddDynamic(this, &AGame_Point::HandleDoubleSettingStored);
	}
}

void AGame_Point::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	if (Breadcrumb != nullptr)
	{
		Breadcrumb->Destroy();
		Breadcrumb = nullptr;
	}
}

void AGame_Point::ManipulationEnd_Implementation()
{
	Super::ManipulationEnd_Implementation();

	if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
	{
		COTComponent->GetCurrentCOTEvent()->SetPoint(globeRef->WorldToGeodeticDouble(GetActorLocation()));

		COTComponent->RegisterWithDatabase();
	}
}

double AGame_Point::GetSettingScaleMultiplier() const
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		return gameSettings->GetSettingDouble(TEXT("IconScale"));
	}

	return 1;
}

void AGame_Point::PostBeginHover(AActor* actor)
{
	CallsignComponent->SetHiddenInGame(false);
}

void AGame_Point::PostEndHover(AActor* actor)
{
	bool bCallsignHidden = true;
	if (UGame_Subsystem_Core* subsytem = UGame_Subsystem_Core::Get())
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			double distanceMeters = FVector::Distance(playerPawn->GetActorLocation(), GetActorLocation()) / 100.0;
			if (distanceMeters < subsytem->GetCallsignShowDistanceMeters())
			{
				bCallsignHidden = false;
			}
		}
	}

	CallsignComponent->SetHiddenInGame(bCallsignHidden);
}

// ---------------------------------
// --- API
// ---------------------------------

float AGame_Point::GetBearingToPoint(FVector locationOfOrigin) const
{
	if (AVH_GlobeReferenceActor* globeRef = AGame_WorldActor::GetGlobeReference())
	{
		FVector direction = GetActorLocation() - locationOfOrigin;

		return globeRef->WorldRotationToBearing(direction.ToOrientationRotator());
	}

	return -1.f;
}

FString AGame_Point::GetCallsign() const
{
	return COTComponent->GetCurrentCOTEvent()->GetAttribute(TEXT("callsign"));
}

void AGame_Point::SyncCallsignWidget()
{
	if (CallsignWidget != nullptr)
	{
		CallsignWidget->SetCallsignText(COTComponent->GetCurrentCOTEvent()->GetAttribute(TEXT("callsign")));
	}
}

void AGame_Point::SetType(const FName& type)
{
	COTComponent->GetCurrentCOTEvent()->SetAttribute(TEXT("type"), type);
}

void AGame_Point::InitTracking()
{
	if (UWorld* world = GetWorld())
	{
		Breadcrumb = Cast<AGame_Tracking>(world->SpawnActor(AGame_Tracking::StaticClass()));

		if (Breadcrumb != nullptr)
		{
			Breadcrumb->InitializeTrackingActor(this);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("AGame_Point::InitTracking() | unable to spawn breadcrumb"));
		}
	}
}

void AGame_Point::SyncGeolocationToWorldLocation(AGame_VirtualObjective* virtualObjective)
{
	AVH_GlobeReferenceActor* globeRef = nullptr;

	if (virtualObjective != nullptr)
	{
		globeRef = virtualObjective->GetGlobeReference();
	}
	else
	{
		globeRef = GetGlobeReference();
	}
	
	if (globeRef != nullptr)
	{
		COTComponent->GetCurrentCOTEvent()->SetPoint(globeRef->WorldToGeodeticDouble(GetActorLocation()));
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_Point::SyncGeolocationToWorldLocation | globeRef is nullptr"));
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AGame_VirtualObjective* AGame_Point::GetVirtualObjective() const
{
	AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this, false);

	if (virtualObjective == nullptr)
	{
		// try owners
		AActor* owner = GetOwner();

		int32 count = 0;
		while (owner != nullptr && virtualObjective == nullptr)
		{
			virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(owner, false);

			owner = owner->GetOwner();
		}
	}

	if (virtualObjective == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("AGame_EditPoint::GetVirtualObjective | virtualObjective is nullptr | %s | returning nullptr"), *GetName());
	}

	return virtualObjective;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Point::HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters)
{
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		CallsignComponent->SetHiddenInGame(distanceMeters > subsystem->GetCallsignShowDistanceMeters());
	}
}

void AGame_Point::HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent)
{
	SyncCallsignWidget();

	SetType(FName(*cotEvent->GetAttribute(TEXT("type"))));
}

void AGame_Point::HandleDoubleSettingStored(const FString& setting, double value)
{
	if (setting.Equals(TEXT("IconScale")))
	{
		CameraScalingComponent->CustomScaleMultiplier = GetSettingScaleMultiplier();
	}
}