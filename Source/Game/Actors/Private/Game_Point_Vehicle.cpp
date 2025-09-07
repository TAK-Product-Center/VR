// Required Includes
#include "Game_Point_Vehicle.h"
#include "Game.h"

// Engine Includes
#include "Components/PrimitiveComponent.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "VH_COTUserIcons.h"

// Game Includes
#include "Game_COTComponent.h"
#include "Game_VehicleRepresentative.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Point_Vehicle::AGame_Point_Vehicle(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer)
{
	VehicleComponent = CreateDefaultSubobject<UChildActorComponent>(FName(TEXT("VehicleComponent")));
	VehicleComponent->SetupAttachment(RootComponent);
	
	COTType = FName(TEXT("u-d-v-m"));
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool AGame_Point_Vehicle::GetRotationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::XZ;

	return true;
}

bool AGame_Point_Vehicle::GetRotationDisabled_Implementation()
{
	return VehicleComponent == nullptr || VehicleComponent->GetChildActor() == nullptr;
}

void AGame_Point_Vehicle::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	if (AActor* vehicleActor = VehicleComponent->GetChildActor())
	{
		vehicleActor->SetActorEnableCollision(!bNewHidden);
	}
}

// todo ohg | use wintak icons when don't have a 3D model for a vehicle
// see https://git.takmaps.com/PAR-Government/wintak/-/blob/development/WinTak.CursorOnTarget/Placement/VehicleBlock.cs
// stored in .block files, which can be opened as text files; contain set of points that can be used to construct the icon at run-time
//		maybe generate bmp from block files pre-runtime using custom c# program
void AGame_Point_Vehicle::HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent)
{
	Super::HandleReceivedCOTUpdate(cotEvent);

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		FString vehicleModel = cotEvent->GetAttribute(TEXT("detail\tmodel\tname"));

		if (cotManager->GetUserIcons() == nullptr)
		{
			UE_LOG(Game, Warning, TEXT("-- AGame_Point_Vehicle::SetActorRepresentativeFromEvent | could not find cotmanager user icons"), *vehicleModel);
			return;
		}

		TMap<FString, TSubclassOf<AActor>> modelToBlueprints = cotManager->GetUserIcons()->ModelToBlueprint;
		if (TSubclassOf<AActor>* actorClass = modelToBlueprints.Find(vehicleModel))
		{
			SetActorRepresentative(actorClass->Get());
		}
		else
		{
			UE_LOG(Game, Log, TEXT("-- AGame_Point_Vehicle::SetActorRepresentativeFromEvent | could not find actor class for vehicle model for: %s"), *vehicleModel);
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Point_Vehicle::SetActorRepresentative(TSubclassOf<AGame_VehicleRepresentative> vehicleClass)
{
	UVH_COTEvent* cotEvent = COTComponent->GetCurrentCOTEvent();

	FString oldCallsign = TEXT("");
	FVector vehicleScale = FVector::OneVector;

	FString callsign = cotEvent->GetAttribute(TEXT("callsign"));

	if (AGame_VehicleRepresentative* vehicleActor = Cast<AGame_VehicleRepresentative>(VehicleComponent->GetChildActor()))
	{
		vehicleScale = vehicleActor->GetActorScale3D();

		if (!callsign.Equals(vehicleActor->FriendlyName))
		{
			oldCallsign = callsign;
		}

		VehicleComponent->DestroyChildActor();
	}
	else if (!callsign.IsEmpty())
	{
		oldCallsign = callsign;
	}

	if (vehicleClass != nullptr)
	{
		VehicleComponent->SetChildActorClass(vehicleClass);
		VehicleComponent->CreateChildActor();

		if (AGame_VehicleRepresentative* vehicleActor = Cast<AGame_VehicleRepresentative>(VehicleComponent->GetChildActor()))
		{
			vehicleActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true));

			vehicleActor->SetOwner(this);
			vehicleActor->SetActorScale3D(vehicleScale);

			// bind to mouse events
			vehicleActor->OnClicked.AddDynamic(this, &AGame_Point_Vehicle::HandleClickPressed);
			vehicleActor->OnReleased.AddDynamic(this, &AGame_Point_Vehicle::HandleClickReleased);
			vehicleActor->OnBeginCursorOver.AddDynamic(this, &AGame_Point_Vehicle::HandleBeginCursorOver);
			vehicleActor->OnEndCursorOver.AddDynamic(this, &AGame_Point_Vehicle::HandleEndCursorOver);

			cotEvent->SetAttribute(TEXT("type"), COTType);

			cotEvent->SetAttribute(TEXT("detail\tmodel\ttype"), TEXT("vehicle"));
			cotEvent->SetAttribute(TEXT("detail\tmodel\toutline"), TEXT("false"));
			cotEvent->SetAttribute(TEXT("detail\tmodel\tname"), vehicleActor->ModelName);
			cotEvent->SetAttribute(TEXT("strokeColor"), TEXT("-1"));
			cotEvent->SetAttribute(TEXT("fillColor"), TEXT("-1"));
			cotEvent->SetAttribute(TEXT("detail\tmodel\tcategory"), vehicleActor->ModelCategory);

			if (oldCallsign.IsEmpty())
			{
				cotEvent->SetAttribute(TEXT("callsign"), vehicleActor->FriendlyName);
			}
			else
			{
				cotEvent->SetAttribute(TEXT("callsign"), oldCallsign);
			}

			if (cotEvent->GetAttribute<int32>(TEXT("fillColor")) == 0)
			{
				cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), FColor(0, 255, 0, 255));
				cotEvent->SetAttribute<int32>(TEXT("fillColor"), 1073807104);
			}

			TArray<UActorComponent*> actorComponents;
			vehicleActor->GetComponents(actorComponents);

			for (UActorComponent* actorComponent : actorComponents)
			{
				if (UPrimitiveComponent* primitiveComponent = Cast<UPrimitiveComponent>(actorComponent))
				{
					primitiveComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);

					primitiveComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
					
					primitiveComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);
					primitiveComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

					primitiveComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
				}
			}
		}
	}

	SyncCallsignWidget();
}