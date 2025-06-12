// Required Includes
#include "Game_EditPoint.h"
#include "Game.h"

// Engine Includes
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "Interface_COTReceiver.h"

// Game Includes
#include "Game_COTComponent.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_DrawContainer.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_Subsystem_Core.h"
#include "Game_CameraScalingComponent.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_EditPoint::AGame_EditPoint(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer),
	bSelectionEnabled(true)
{
	ShapeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShapeMeshComponent"));
	ShapeMeshComponent->SetupAttachment(CameraScalingComponent);

	MaterialBillboardComponent = CreateDefaultSubobject<UMaterialBillboardComponent>(TEXT("MaterialBillboardComponent"));
	MaterialBillboardComponent->SetupAttachment(CameraScalingComponent);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_EditPoint::BeginPlay()
{
	Super::BeginPlay();

	if (ShapeMeshComponent)
	{
		ShapeMID = ShapeMeshComponent->CreateDynamicMaterialInstance(0);
	}

	UpdateMaterial();

	SetActorHiddenInGame(true);
}

void AGame_EditPoint::SetActorHiddenInGame(bool bNewHidden)
{
	if (!GetActive())
	{
		bNewHidden = true;
	}

	Super::SetActorHiddenInGame(bNewHidden);

	ShapeMeshComponent->SetCollisionEnabled(bNewHidden ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
}

AVH_GlobeReferenceActor* AGame_EditPoint::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;
}

void AGame_EditPoint::PostBeginHover(AActor* actor)
{
	bIsHovered = true;

	UpdateMaterial();
}

void AGame_EditPoint::PostEndHover(AActor* actor)
{
	bIsHovered = false;

	UpdateMaterial();
}

void AGame_EditPoint::ManipulationEnd_Implementation()
{
	Super::ManipulationEnd_Implementation();

	PersistWorldLocation();
}

double AGame_EditPoint::GetSettingScaleMultiplier() const
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		return gameSettings->GetSettingDouble(TEXT("LineScale"));
	}

	return 1;
}


// ---------------------------------
// --- API
// ---------------------------------

void AGame_EditPoint::SyncGeoLocationToWorldLocation()
{
	if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
	{
		SetGeoLocation(globeRef->WorldToGeodeticDouble(GetActorLocation()));
	}
}

void AGame_EditPoint::SyncWorldLocationToGeoLocation()
{
	if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
	{
		SetActorLocation(globeRef->GeodeticToWorldDouble(GeoLocation));
	}
}

void AGame_EditPoint::SetActive(bool bActive)
{
	if (bIsActive != bActive)
	{
		bIsActive = bActive;

		UpdateMaterial();

		SetActorHiddenInGame(!bActive);
	}
}

void AGame_EditPoint::SetLineActor(AGame_SimpleSegmentedLineActor* inLineActor)
{	
	if (LineActor != nullptr)
	{
		LineActor->OnColorChanged.RemoveDynamic(this, &AGame_EditPoint::HandleLineColorChanged);
	}

	if (inLineActor != nullptr)
	{
		inLineActor->OnColorChanged.AddDynamic(this, &AGame_EditPoint::HandleLineColorChanged);
	}

	LineActor = inLineActor;
}

bool AGame_EditPoint::GetActive() const
{
	return bIsActive;
}

AGame_SimpleSegmentedLineActor* AGame_EditPoint::GetLineActor() const
{
	return LineActor;
}

FVector AGame_EditPoint::GetLineDrawLocation_Implementation() const
{
	return GetActorLocation();
}

void AGame_EditPoint::SetSelectionEnabled(bool bEnabled)
{
	bSelectionEnabled = bEnabled;
}

void AGame_EditPoint::PersistWorldLocation()
{
	if (DrawContainer != nullptr)
	{
		if (UGame_COTComponent* cotComponent = Cast<UGame_COTComponent>(IInterface_COTReceiver::Execute_GetCOTComponent(DrawContainer)))
		{
			SyncGeoLocationToWorldLocation();

			cotComponent->RegisterWithDatabase();
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_EditPoint::PersistWorldLocation | DrawContainer is nullptr"));
	}
}

void AGame_EditPoint::SetDrawContainer(AGame_DrawContainer* container)
{
	DrawContainer = container;

	UpdateMaterial();
}

void AGame_EditPoint::SetColor(const FColor& color)
{
	Color = color;

	ShapeMID->SetVectorParameterValue(FName(TEXT("Color")), color);
	ReceiveSetColor(color);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_EditPoint::UpdateMaterial()
{
	bool bHoveredAndVisible = bIsHovered && ShapeMeshComponent->IsVisible();
	MaterialBillboardComponent->SetVisibility(bHoveredAndVisible, false);

	if (ShapeMID != nullptr)
	{
		ShapeMID->SetScalarParameterValue(FName(TEXT("isHighlighted")), bIsHovered ? 1.f : 0.f);

		if (AGame_SimpleSegmentedLineActor* line = GetLineActor())
		{
			ShapeMID->SetVectorParameterValue(FName(TEXT("Color")), line->GetColor());
			ReceiveSetColor(line->GetColor());
		}
	}
}

AGame_VirtualObjective* AGame_EditPoint::GetVirtualObjective() const
{
	// try DrawContainer
	AGame_VirtualObjective* virtualObjective = nullptr;
	if (DrawContainer != nullptr)
	{
		virtualObjective = DrawContainer->GetVirtualObjective();
	}

	// default to player	
	if (virtualObjective == nullptr)
	{
		virtualObjective = AGame_PlayerController::GetPlayerActiveVO();
	}

	return virtualObjective;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_EditPoint::HandleLineColorChanged(FLinearColor inColor)
{
	UpdateMaterial();
}

void AGame_EditPoint::HandleDoubleSettingStored(const FString& setting, double value)
{
	if (setting.Equals(TEXT("LineScale")))
	{
		CameraScalingComponent->CustomScaleMultiplier = GetSettingScaleMultiplier();
	}
}