#include "Game_WorldActor.h"
#include "Game.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"

#include "VH_GlobeReferenceActor.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_WorldActor::AGame_WorldActor(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	Root = CreateDefaultSubobject<USceneComponent>(FName(TEXT("Root")));
	RootComponent = Root;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_WorldActor::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	HandleSetActorHiddenInGame(bNewHidden);
}

void AGame_WorldActor::SetActorScale3D(FVector newScale3D)
{
	Super::SetActorScale3D(newScale3D);

	HandleSetActorScale3D(newScale3D);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AVH_GlobeReferenceActor* AGame_WorldActor::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(const_cast<AGame_WorldActor*>(this)))
	{
		if (AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference())
		{
			return globeRef;
		}
	}

	UE_LOG(Game, Warning, TEXT("AGame_WorldActor::GetGlobeReference | VO or GlobeRef are nullptr for %s | returning nullptr"), *GetName());

	return nullptr;
}