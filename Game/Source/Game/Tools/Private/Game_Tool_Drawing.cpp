// Required Includes
#include "Game_Tool_Drawing.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_COTComponent.h"
#include "Interface_COTReceiver.h"

// Game Includes
#include "Game_DrawContainer.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_COTComponent_Draw.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"
#include "Game_COTComponent.h"
#include "Game_GameInstance.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Tool_Drawing::AGame_Tool_Drawing(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	bRegisterToDatabaseOnRelease(true)
{

}
// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Tool_Drawing::EndPlay(EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	SetDrawContainer(nullptr);
}

void AGame_Tool_Drawing::PostTriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults)
{
	Super::PostTriggerPressed(traceChannel, hitResults);

	SpawnDrawContainer();
}

void AGame_Tool_Drawing::PostTriggerReleased()
{
	Super::PostTriggerReleased();

	if (bRegisterToDatabaseOnRelease)
	{
		if (DrawContainer != nullptr)
		{
			if (UGame_COTComponent* cotComponent = Cast<UGame_COTComponent>(IInterface_COTReceiver::Execute_GetCOTComponent(DrawContainer)))
			{
				cotComponent->RegisterWithDatabase();

				if (UGame_GameInstance* gameInstance = UGame_Statics::GetVHGameInstance())
				{
					gameInstance->MUC_AddCreatedEntityUID(FName(*cotComponent->GetCurrentCOTEvent()->GetAttribute(TEXT("uid"))));
				}
			}
		}
	}
}


// ---------------------------------
// --- API
// ---------------------------------

void AGame_Tool_Drawing::SpawnDrawContainer()
{
	if (!IsValid(DrawContainer))
	{
		FActorSpawnParameters spawnParams;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		DrawContainer = GetWorld()->SpawnActor<AGame_DrawContainer>(DrawContainerClass, spawnParams);
		
		if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
		{
			DrawContainer->SetActorScale3D(virtualObjective->GetActorScale3D());

			virtualObjective->AddObjectToEntity(GetDrawComponent()->GetCurrentCOTEvent()->GetAttribute(TEXT("uid")), DrawContainer);
		}
	}
}

UGame_COTComponent_Draw* AGame_Tool_Drawing::GetDrawComponent() const
{
	if (DrawContainer != nullptr)
	{
		return DrawContainer->GetDrawComponent();
	}

	return nullptr;
}

void AGame_Tool_Drawing::SetDrawContainer(AGame_DrawContainer* drawContainerArg)
{
	if (DrawContainer != nullptr)
	{
		if (UGame_COTComponent_Draw* drawComponent = DrawContainer->GetDrawComponent())
		{
			drawComponent->SetEditPointsActive(nullptr, false);
		}

		DrawContainer->SetInEditMode(false);
	}

	DrawContainer = drawContainerArg;

	if (DrawContainer != nullptr)
	{
		DrawContainer->GetDrawComponent()->SetEditPointsActive(nullptr, true);

		DrawContainer->SetInEditMode(true);
	}
}

AGame_DrawContainer* AGame_Tool_Drawing::GetDrawContainer() const
{
	return DrawContainer;
}