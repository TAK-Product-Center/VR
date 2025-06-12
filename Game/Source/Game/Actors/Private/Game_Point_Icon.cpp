// Required Includes
#include "Game_Point_Icon.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "VH_COTUserIcons.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_COTComponent.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_Subsystem_Core.h"
#include "Game_CameraScalingComponent.h"
#include "Game_WidgetComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Point_Icon::AGame_Point_Icon(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer),
	CallsignRelativeHeight(120.f)
{
	PlaneStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneStaticMeshComponent"));
	PlaneStaticMeshComponent->SetupAttachment(CameraScalingComponent);

	CallsignComponent->SetRelativeLocation(FVector(0.f, 0.f, CallsignRelativeHeight));
}


// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Point_Icon::BeginPlay()
{
	Super::BeginPlay();

	IconMID = PlaneStaticMeshComponent->CreateDynamicMaterialInstance(0, PlaneStaticMeshComponent->GetMaterial(0));

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bIsXRay = gameSettings->GetSettingBool(TEXT("XRayIcons"));
	}

	if (UGame_VirtualObjectiveManager* VOManager = UGame_VirtualObjectiveManager::Get())
	{
		VOManager->OnObjectAddedToVO.AddUObject(this, &AGame_Point_Icon::HandleObjectAddedToVO);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Point_Icon::SetIconTexture(UTexture2D* inIconTexture)
{
	if (IconTexture != inIconTexture)
	{
		IconTexture = inIconTexture;

		IconMID->SetTextureParameterValue(FName(TEXT("IconTexture")), IconTexture);

		if (IconTexture != nullptr)
		{
			float aspectRatio = (float)IconTexture->GetSizeX() / (float)IconTexture->GetSizeY();

			IconMID->SetScalarParameterValue(FName(TEXT("aspectRatio")), aspectRatio);
		}

		OnIconChanged.Broadcast();
	}
}

void AGame_Point_Icon::SetIconColor(const FLinearColor& linearColor)
{
	IconMID->SetVectorParameterValue(FName(TEXT("color")), linearColor);

	OnIconChanged.Broadcast();
}

UTexture2D* AGame_Point_Icon::GetIconTexture() const
{
	return IconTexture;
}

bool AGame_Point_Icon::GetIsXRay() const
{
	return bIsXRay;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Point_Icon::HandleObjectAddedToVO(UObject* object, AGame_VirtualObjective* vo)
{
	if (object == this)
	{
		int32 voIndex = vo->GetVOIndex();
		IconMID->SetScalarParameterValue(FName(TEXT("VOIndex")), voIndex);
		if (UMaterialInstanceDynamic* mid = CallsignComponent->GetMaterialInstance())
		{
			mid->SetScalarParameterValue(FName(TEXT("VOIndex")), voIndex);
		}

		if (voIndex == 0)
		{
			// TODO: Expose this value as a setting!
			IconMID->SetScalarParameterValue(FName(TEXT("FadeOpacity")), 0);
		}
	}
}
