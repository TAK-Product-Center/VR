// Required Includes
#include "Game_Tracking.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_COTComponent.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Point.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Tracking::AGame_Tracking(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer)
{
	Breadcrumbs = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(FName(TEXT("Breadcrumbs")));
	Breadcrumbs->SetupAttachment(RootComponent);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Tracking::AddBreadcrumb()
{
	if (CurrentTrackedPoint != nullptr)
	{
		if (AVH_GlobeReferenceActor* globeRef = UGame_VirtualObjectiveManager::GetObjectGlobeReference(this))
		{	
			FVector cotLocation = CurrentTrackedPoint->GetActorLocation();

			if (CurrentTrackedPoint->GetCOTComponent() && CurrentTrackedPoint->GetCOTComponent()->GetCurrentCOTEvent())
			{
				float cotCourse = CurrentTrackedPoint->GetCOTComponent()->GetCurrentCOTEvent()->GetAttribute<double>(TEXT("detail\ttrack\tcourse"));

				FRotator cotRotation = globeRef->BearingToWorldRotation(cotCourse);

				if (Breadcrumbs != nullptr)
				{
					Breadcrumbs->AddInstance(FTransform(cotRotation, cotLocation, ArrowScale * FVector(1.f, 1.f, 1.f)));
				}
			}
		}
	}
}

bool AGame_Tracking::IsLastBreadcrumbSimilar() const
{
	if (Breadcrumbs != nullptr)
	{
		int numBreadcrumbs = Breadcrumbs->GetInstanceCount();

		if (numBreadcrumbs == 0)
		{
			return false;
		}

		FTransform instanceTransform;

		bool bGotTransform = Breadcrumbs->GetInstanceTransform(numBreadcrumbs, instanceTransform, true);

		if (!bGotTransform)
		{
			return true;
		}

		if (CurrentTrackedPoint != nullptr)
		{
			return CurrentTrackedPoint->GetTransform().EqualsNoScale(instanceTransform, 0.0001f);
		}
	}

	return true;
}

bool AGame_Tracking::GetBreadcrumbStatus() const
{
	return bIsBreadcrumbsOn;
}

void AGame_Tracking::InitializeTrackingActor(AGame_Point* actorToTrack)
{
	if (actorToTrack != nullptr)
	{
		CurrentTrackedPoint = actorToTrack;

		CurrentTrackedPoint->GetCOTComponent()->OnReceivedCOTUpdate.AddDynamic(this, &ThisClass::OnCOTUpdate);

		bIsBreadcrumbsOn = true;
	}
}

void AGame_Tracking::ToggleBreadcrumbs()
{
	if (CurrentTrackedPoint != nullptr && CurrentTrackedPoint->GetCOTComponent())
	{
		if (bIsBreadcrumbsOn)
		{
			bIsBreadcrumbsOn = false;

			Breadcrumbs->SetVisibility(bIsBreadcrumbsOn, false);

			CurrentTrackedPoint->GetCOTComponent()->OnReceivedCOTUpdate.RemoveDynamic(this, &ThisClass::OnCOTUpdate);
		}
		else
		{
			bIsBreadcrumbsOn = true;

			Breadcrumbs->SetVisibility(bIsBreadcrumbsOn, false);

			CurrentTrackedPoint->GetCOTComponent()->OnReceivedCOTUpdate.AddDynamic(this, &ThisClass::OnCOTUpdate);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Tracking::OnCOTUpdate(UVH_COTEvent* cotEvent)
{
	if (!IsLastBreadcrumbSimilar())
	{
		AddBreadcrumb();
	}
}