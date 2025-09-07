// Required Includes
#include "Game_EditPoint_Route.h"
#include "Game.h"

// Engine Includes
#include "Materials/MaterialInstanceDynamic.h"

// Game Includes
#include "Game_Subsystem_Core.h"
#include "Game_CameraScalingComponent.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_EditPoint_Route::AGame_EditPoint_Route(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_EditPoint_Route::SetActive(bool bActive)
{
	if (IsCheckpoint())
	{
		bActive = true;
	}

	Super::SetActive(bActive);
}

void AGame_EditPoint_Route::BeginPlay()
{
	Super::BeginPlay();
		
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		CameraScalingComponent->AddDistanceThreshold(subsystem->GetCallsignShowDistanceMeters());
		CameraScalingComponent->OnThresholdCrossed.AddDynamic(this, &AGame_EditPoint_Route::HandleDistanceThresholdCrossed);

		PostEndHover(UGame_Statics::GetVHPlayerPawn());
	}
}

void AGame_EditPoint_Route::PostBeginHover(AActor* actor)
{
	Super::PostBeginHover(actor);

	ReceiveSetCallsignHidden(false);
}

void AGame_EditPoint_Route::PostEndHover(AActor* actor)
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

void AGame_EditPoint_Route::UpdateMaterial()
{
	Super::UpdateMaterial();

	if (ShapeMID != nullptr && !IsCheckpoint())
	{
		ShapeMID->SetVectorParameterValue(FName(TEXT("Color")), FColor::White);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

bool AGame_EditPoint_Route::IsCheckpoint()
{
	return bIsCheckpoint;
}

void AGame_EditPoint_Route::SetIsCheckpoint(bool bCheckpoint)
{
	bUserCheckpoint = bCheckpoint;

	if (bIsCheckpoint != bCheckpoint)
	{
		bIsCheckpoint = bCheckpoint;

		if (!bIsCheckpoint)
		{
			SetUserCallsign(TEXT(""));
			
			bUserCheckpoint = false;
		}

		UpdateMaterial();

		OnCheckpointUpdated.Broadcast(bIsCheckpoint);
	}
}

void AGame_EditPoint_Route::SetUserCheckpoint(bool bInUserCheckpoint)
{
	if (bInUserCheckpoint != bUserCheckpoint)
	{
		bUserCheckpoint = bInUserCheckpoint;
	}
}

bool AGame_EditPoint_Route::GetUserCheckpoint() const
{
	return bUserCheckpoint;
}

void AGame_EditPoint_Route::SetUserCallsign(const FString& userCallsign)
{
	if (!UserCallsign.Equals(userCallsign))
	{
		UserCallsign = userCallsign;

		bUserCheckpoint = true;

		OnCallsignUpdated.Broadcast(GetCallsign());
	}
}

FString AGame_EditPoint_Route::GetUserCallsign() const
{
	return UserCallsign;
}

void AGame_EditPoint_Route::SetGeneratedCallsign(const FString& generatedCallsign)
{
	if (!GeneratedCallsign.Equals(generatedCallsign))
	{
		GeneratedCallsign = generatedCallsign;

		OnCallsignUpdated.Broadcast(GetCallsign());
	}
}

FString AGame_EditPoint_Route::GetCallsign() const
{
	return UserCallsign.IsEmpty() ? GeneratedCallsign : UserCallsign;
}

void AGame_EditPoint_Route::SetNavCue(const FString& navCue)
{
	if (!NavCue.Equals(navCue))
	{
		NavCue = navCue;

		bUserCheckpoint = true;

		OnNavCueUpdated.Broadcast(GetNavCue());
	}
}

FString AGame_EditPoint_Route::GetNavCue() const
{
	return NavCue;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_EditPoint_Route::HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters)
{
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		ReceiveSetCallsignHidden(distanceMeters > subsystem->GetCallsignShowDistanceMeters());
	}
}