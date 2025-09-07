// Required Includes
#include "Game_Point_2525.h"
#include "Game.h"

// Engine Includes
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Texture2D.h"

// VH Plugin Includes
#include "VH_COTGameInstanceSubsystem.h"
#include "VH_COTManager.h"
#include "VH_COTUserIcons.h"
#include "VH_MilStd2525.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_COTComponent.h"
#include "Game_Pawn.h"
#include "Game_Statics.h"
#include "Game_GameInstance.h"
#include "Game_CameraScalingComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Point_2525::AGame_Point_2525(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	AttachmentComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AttachmentComponent"));
	AttachmentComponent->SetupAttachment(CameraScalingComponent);
	AttachmentComponent->SetRelativeScale3D(FVector(8, 8, 8));
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Point_2525::BeginPlay()
{
	Super::BeginPlay();

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		cotManager->OnUpdateContacts.AddDynamic(this, &AGame_Point_2525::HandleUpdateContacts);

		cotManager->OnAttachmentsModified.AddDynamic(this, &AGame_Point_2525::HandleAttachmentsModified);
	}

	AttachmentDefaultRelativeScale = AttachmentComponent->GetRelativeScale3D();
}

void AGame_Point_2525::SetType(const FName& type)
{
	UVH_COTEvent* cotEvent = COTComponent->GetCurrentCOTEvent();

	if (UVH_COTManager::IsVTAKGhost(cotEvent))
	{
		ContextOptionClasses.Empty();

		ContextOptionClasses = GhostContextOptionClasses;

		FString iconPath = cotEvent->GetAttribute(TEXT("detail\tusericon\ticonsetpath"));
		if (!iconPath.IsEmpty())
		{
			if (UTexture2D* texture = UVH_COTManager::Get()->GetUserIcons()->GetIcon(iconPath))
			{
				SetIconTexture(texture);

				SetIconColor(FLinearColor(cotEvent->GetAttribute<FColor>(TEXT("detail\tcolor\targb"))));
			}
		}
	}
	else
	{
		FString updatedType = type.ToString();
		if (!updatedType.StartsWith(FString(TEXT("a-")), ESearchCase::IgnoreCase))
		{
			updatedType = FString(TEXT("a-")).Append(updatedType);
		}

		Super::SetType(FName(*updatedType));

		if (UGame_GameInstance* gi = UGame_Statics::GetVHGameInstance())
		{
			if (UVH_COTGameInstanceSubsystem* cotSubsystem = gi->GetSubsystem<UVH_COTGameInstanceSubsystem>())
			{
				if (UVH_MilStd2525* milStd2525 = cotSubsystem->GetMilStd2525())
				{
					SetIconTexture(milStd2525->GetIconData(type).Texture);

					SetIconColor(FLinearColor(1, 1, 1, 1));
				}
			}
		}

		SyncToAttachments();
	}
}

bool AGame_Point_2525::PostClickPressed(AActor* actor, const FKey& buttonPressed)
{
	// return true prevents selection and opening context menu as a ghost
	return UVH_COTManager::IsVTAKGhost(COTComponent->GetCurrentCOTEvent());
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Point_2525::SetAuthor(const FString& author)
{
	UVH_COTEvent* cotEvent = COTComponent->GetCurrentCOTEvent();

	cotEvent->SetAttribute(TEXT("detail\tlink\tparent_callsign"), author);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_Point_2525::SyncToAttachments()
{
	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		FVector2D dimensions;
		if (UTexture2D* texture = cotManager->GetAttachmentTexture(COTComponent->GetCurrentCOTEvent()->GetAttribute(TEXT("uid")), dimensions))
		{
			AttachmentMID = AttachmentComponent->CreateDynamicMaterialInstance(0, AttachmentComponent->GetMaterial(0));
			AttachmentMID->SetTextureParameterValue(TEXT("IconTexture"), texture);
			AttachmentMID->SetVectorParameterValue(TEXT("color"), FLinearColor(1, 1, 1, 1));

			// default scale is FVector(8, 8, 8)
			FVector scale = AttachmentDefaultRelativeScale;
			scale.Y *= (dimensions.X / dimensions.Y);
			AttachmentComponent->SetRelativeScale3D(scale);
			
			AttachmentComponent->SetHiddenInGame(false, false);
		}
		else
		{
			AttachmentComponent->SetHiddenInGame(true, true);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Point_2525::HandleUpdateContacts()
{
	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		FString uid = COTComponent->GetCurrentCOTEvent()->GetAttribute(TEXT("uid"));
		if (cotManager->GetContacts().Find(FName(*uid)))
		{
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				entityDB->Delete(UVH_COTManager::GetDataLoader_COT_ClassUID(), uid);
			}
		}
	}
}

void AGame_Point_2525::HandleAttachmentsModified(const FString& entityUID)
{
	if (UVH_COTEvent* cotEvent = COTComponent->GetCurrentCOTEvent())
	{
		if (cotEvent->GetAttribute(TEXT("uid")).Equals(entityUID))
		{
			SyncToAttachments();
		}
	}
}
