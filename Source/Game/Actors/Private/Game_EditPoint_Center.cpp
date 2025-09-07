// Required Includes
#include "Game_EditPoint_Center.h"
#include "Game.h"

// Game Includes
#include "Game_Subsystem_Core.h"
#include "Game_CameraScalingComponent.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_EditPoint_Center::AGame_EditPoint_Center(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_EditPoint_Center::BeginPlay()
{
	Super::BeginPlay();
		
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		CameraScalingComponent->AddDistanceThreshold(subsystem->GetCallsignShowDistanceMeters());
		CameraScalingComponent->OnThresholdCrossed.AddDynamic(this, &AGame_EditPoint_Center::HandleDistanceThresholdCrossed);

		PostEndHover(UGame_Statics::GetVHPlayerPawn());
	}
}

void AGame_EditPoint_Center::PostBeginHover(AActor* actor)
{
	Super::PostBeginHover(actor);

	ReceiveSetCallsignHidden(false);
}

void AGame_EditPoint_Center::PostEndHover(AActor* actor)
{
	Super::PostEndHover(actor);

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

	ReceiveSetCallsignHidden(bCallsignHidden);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_EditPoint_Center::SetCallsign(const FString& inCallsign)
{
	Callsign = inCallsign;

	ReceiveSetCallsign(inCallsign);
}

FString AGame_EditPoint_Center::GetCallsign() const
{
	return Callsign;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_EditPoint_Center::HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters)
{
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		ReceiveSetCallsignHidden(distanceMeters > subsystem->GetCallsignShowDistanceMeters());
	}
}