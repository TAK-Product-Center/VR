// Required Includes
#include "VH_COTComponent.h"
#include "VH_COT.h"

// Engine Includes
#include "Misc/Guid.h"
#include "GameFramework/Actor.h"

// Module Includes
#include "VH_COTManager.h"
#include "VH_COTEvent.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

UVH_COTComponent::UVH_COTComponent() :
    ActiveTime(FTimespan(24, 0, 0)),
	bGenerateCallsign(true)
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UVH_COTComponent::BeginPlay()
{
    Super::BeginPlay();

    UVH_COTEvent* cotEvent = GetCurrentCOTEvent();

    cotEvent->SetAttribute(TEXT("uid"), FGuid::NewGuid().ToString());
    cotEvent->SetAttribute(TEXT("type"), TEXT("a-u-g"));

    if (bGenerateCallsign)
    {
        CachedType = TEXT("a-u-g");
        cotEvent->SetAttribute(TEXT("callsign"), vh_cot::GenerateCallsign(cotEvent));
    }

    // populate time before calling register entity because it uses cotEvent->Time
    cotEvent->PopulateTime(ActiveTime);
}

void UVH_COTComponent::TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaSeconds, tickType, thisTickFunction);

	if (bReceivedCOTUpdate)
	{
		UVH_COTEvent* cotEvent = GetCurrentCOTEvent();

		// handle stale
		if (ShouldHandleStale())
		{
			if (cotEvent->GetAttribute<FDateTime>(TEXT("stale")) < FDateTime::UtcNow())
			{
				CleanupStaleEntity();
			}
		}

		// update callsign when CurrentCOTEvent->Type changes
		if (bGenerateCallsign && !bLockCallsign && !cotEvent->GetAttribute(TEXT("type")).Equals(CachedType))
		{
			cotEvent->SetAttribute(TEXT("callsign"), vh_cot::GenerateCallsign(cotEvent));
			CachedType = cotEvent->GetAttribute(TEXT("type"));
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UVH_COTComponent::SnapToGround()
{

}

TArray<FVector> UVH_COTComponent::PreModifyVOGlobeReference()
{
	TArray<FVector> positions = { GetOwner()->GetActorLocation() };
	return positions;
}

void UVH_COTComponent::PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions)
{
	GetOwner()->SetActorLocation(updatedPositions[0]);
}

UVH_COTEvent* UVH_COTComponent::GetCurrentCOTEvent()
{
	if (CurrentCOTEvent == nullptr)
	{
		CurrentCOTEvent = NewObject<UVH_COTEvent>();
	}

	return CurrentCOTEvent;
}

void UVH_COTComponent::PopulateCOT()
{
	bLockCallsign = true;

	UVH_COTEvent* cotEvent = GetCurrentCOTEvent();

	cotEvent->PopulateTime(ActiveTime);

	// create uid if needed
	if (cotEvent->GetAttribute(TEXT("uid")).IsEmpty())
	{
		cotEvent->SetAttribute(TEXT("uid"), FGuid::NewGuid().ToString());
	}

	// <point> node is required by commo library for valid send
	if (!cotEvent->HasNode(TEXT("point")))
	{
		cotEvent->SetPoint(FGeodeticCoord3D(0, 0, 0));
	}

	OnPopulateCOT.Broadcast();

	PopulateCOT_Virtual();
}

void UVH_COTComponent::BroadcastCOT()
{
	PopulateCOT();

	UVH_COTManager::Get()->BroadcastCOT(GetCurrentCOTEvent()->ToXML());
}

void UVH_COTComponent::SendCOT(const TArray<FName>& contactUIDs)
{
	PopulateCOT();

	UVH_COTManager::Get()->SendCOT(contactUIDs, GetCurrentCOTEvent()->ToXML());
}

void UVH_COTComponent::ReceiveCOTUpdate(UVH_COTEvent* cotEvent)
{
	// always update if <archive>, haven't received update yet, or incoming cotEvent's start is >= current cotEvent's start
	if (cotEvent->HasNode(TEXT("archive")) || !bReceivedCOTUpdate || cotEvent->GetAttribute<FDateTime>(TEXT("start")) >= GetCurrentCOTEvent()->GetAttribute<FDateTime>(TEXT("start")))
	{
		bReceivedCOTUpdate = true;

		bLockCallsign = true;

		CurrentCOTEvent = cotEvent;

		ReceiveCOTUpdate_Virtual(cotEvent);

		OnReceivedCOTUpdate.Broadcast(cotEvent);
	}
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void UVH_COTComponent::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{

}

void UVH_COTComponent::PopulateCOT_Virtual()
{

}

bool UVH_COTComponent::ShouldHandleStale_Virtual()
{
	return true;
}

bool UVH_COTComponent::ShouldHandleStale()
{
	return !GetCurrentCOTEvent()->HasNode(TEXT("archive")) && ShouldHandleStale_Virtual();
}

void UVH_COTComponent::CleanupStaleEntity()
{
	GetOwner()->Destroy();
}