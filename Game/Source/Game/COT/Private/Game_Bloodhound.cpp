// Required Includes
#include "Game_Bloodhound.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

// VH Plugin Includes
#include "Interface_COTReceiver.h"
#include "VH_COTComponent.h"
#include "VH_COTEvent.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_Arrow.h"
#include "Game_UserWidget_Bloodhound.h"
#include "Game_EditPoint.h"
#include "Game_EntityDB.h"
#include "Game_EntityHandler_Bloodhound.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Bloodhound::AGame_Bloodhound()
{
	PrimaryActorTick.bCanEverTick = true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Bloodhound::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	if (ChaserToTargetArrow != nullptr)
	{
		ChaserToTargetArrow->Destroy();
	}

	if (InterceptArrow != nullptr)
	{
		InterceptArrow->Destroy();
	}

	if (InterceptActor != nullptr)
	{
		InterceptActor->Destroy();
	}
}

void AGame_Bloodhound::Tick(float deltaSec)
{
	Super::Tick(deltaSec);

	UpdateInterceptInfo();
}

void AGame_Bloodhound::SetActorScale3D(FVector newScale3D)
{
	Super::SetActorScale3D(newScale3D);

	if (ChaserToTargetArrow != nullptr)
	{
		ChaserToTargetArrow->SetActorScale3D(newScale3D);
	}

	if (InterceptActor != nullptr)
	{
		InterceptActor->SetActorScale3D(newScale3D);
	}
}

void AGame_Bloodhound::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	if (ChaserToTargetArrow != nullptr)
	{
		ChaserToTargetArrow->SetActorHiddenInGame(bNewHidden);
	}

	if (InterceptArrow != nullptr)
	{
		InterceptArrow->SetActorHiddenInGame(bNewHidden);
	}

	if (InterceptActor != nullptr)
	{
		InterceptActor->SetActorHiddenInGame(bNewHidden);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Bloodhound::SpawnActors(AGame_VirtualObjective* virtualObjective, const int32& detailStatus)
{
	SetActorScale3D(virtualObjective->GetActorScale3D());

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	spawnParams.Owner = this;

	InterceptActor = Cast<AActor>(GetWorld()->SpawnActor<AActor>(InterceptActorClass, spawnParams));
	InterceptActor->SetActorScale3D(GetActorScale3D());

	InterceptArrow = Cast<AGame_Arrow>(GetWorld()->SpawnActor<AGame_Arrow>(InterceptArrowClass, spawnParams));
	InterceptArrow->GetBaseEditPoint()->SetSelectionEnabled(false);
	InterceptArrow->GetArrowEditPoint()->SetSelectionEnabled(false);
	InterceptArrow->LinkedArrowActor = InterceptActor;
	InterceptArrow->bSyncLineToEditPoints = true;
	InterceptArrow->GetUIWidget()->VirtualObjective = virtualObjective;

	ChaserToTargetArrow = Cast<AGame_Arrow>(GetWorld()->SpawnActor<AGame_Arrow>(ChaserToTargetArrowClass, spawnParams));
	ChaserToTargetArrow->GetBaseEditPoint()->SetSelectionEnabled(false);
	ChaserToTargetArrow->GetArrowEditPoint()->SetSelectionEnabled(false);
	ChaserToTargetArrow->bSyncLineToEditPoints = true;
	ChaserToTargetArrow->GetUIWidget()->VirtualObjective = virtualObjective;

	ReceiveSpawnActors(virtualObjective, detailStatus);
}

void AGame_Bloodhound::SetChaser(const FString& inChaserUID)
{
	if (ChaserUID.IsEmpty())
	{
		ChaserUID = inChaserUID;
	}
	else
	{
		if (ChaserUID != inChaserUID && inChaserUID != TargetUID)
		{
			ChaserUID = inChaserUID;

			AActor* chaser = GetActor(ChaserUID);

			ChaserToTargetArrow->LinkedBaseActor = chaser;
			InterceptArrow->LinkedBaseActor = chaser;
		}
	}
}

void AGame_Bloodhound::SetTarget(const FString& inTargetUID)
{
	if (TargetUID.IsEmpty())
	{
		TargetUID = inTargetUID;
	}
	else
	{
		if (TargetUID != inTargetUID && inTargetUID != ChaserUID)
		{
			TargetUID = inTargetUID;

			AActor* target = GetActor(TargetUID);

			ChaserToTargetArrow->LinkedArrowActor = target;
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AActor* AGame_Bloodhound::GetActor(const FString& entityUID) const
{
	if (entityUID.IsEmpty())
	{
		return nullptr;
	}

	AGame_VirtualObjective* objectVO = UGame_VirtualObjectiveManager::GetObjectVO(this);
	if (objectVO == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_Bloodhound::GetChaser | Bloodhound Virtual Objective not found!"));
		return nullptr;
	}

	TSet<AActor*> actors;
	if (entityUID == UGame_EntityHandler_Bloodhound::StaticGetPlayerIdentifier())
	{
		actors.Add(UGame_Statics::GetVHPlayerPawn());
	}
	else
	{
		actors = objectVO->GetActorsForEntity(entityUID);
	}

	if (actors.Num() < 1)
	{
		return nullptr;
	}

	return actors.Array()[0];
}

AVH_GlobeReferenceActor* AGame_Bloodhound::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;
}

void AGame_Bloodhound::UpdateInterceptInfo()
{
	AActor* chaser = GetActor(ChaserUID);
	AActor* target = GetActor(TargetUID);

	if (chaser != nullptr && target != nullptr)
	{
		if (InterceptArrow->LinkedBaseActor != chaser)
		{
			InterceptArrow->LinkedBaseActor = chaser;
		}

		if (ChaserToTargetArrow->LinkedBaseActor != chaser)
		{
			ChaserToTargetArrow->LinkedBaseActor = chaser;
		}

		if (ChaserToTargetArrow->LinkedArrowActor != target)
		{
			ChaserToTargetArrow->LinkedArrowActor = target;
		}
		
		float interceptTime = 0;
		FVector interceptLocation = FVector(0, 0, 0);
		float interceptBearing = 0;

		if (GetInterceptData(interceptTime, interceptLocation, interceptBearing))
		{
			InterceptArrow->SetActorHiddenInGame(false);

			InterceptActor->SetActorLocation(interceptLocation);

			if (UGame_UserWidget_Bloodhound* widget = Cast<UGame_UserWidget_Bloodhound>(InterceptArrow->GetUIWidget()))
			{
				widget->SetSecondsToIntercept(interceptTime);
			}

			SetInterceptLineColor(interceptTime);
		}
		else
		{
			InterceptArrow->SetActorHiddenInGame(true);
		}

		InterceptActor->SetActorHiddenInGame(InterceptArrow->IsHidden());
	}
}

float AGame_Bloodhound::GetVelocitySize(AActor* actor) const
{
	if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
	{
		if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
		{
			if (AGame_VirtualObjective* activeVO = UGame_VirtualObjectiveManager::GetObjectVO(this))
			{
				return cotComponent->GetCurrentCOTEvent()->GetAttribute<double>(TEXT("detail\ttrack\tspeed")) * activeVO->GetUnrealUnitsPerMeter();
			}
		}
	}

	return actor->GetVelocity().Size();
}

FRotator AGame_Bloodhound::GetRotation(AActor* actor) const
{
	if (AVH_GlobeReferenceActor* globeReference = GetGlobeReference())
	{
		if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
		{
			if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
			{
				return globeReference->BearingToWorldRotation(cotComponent->GetCurrentCOTEvent()->GetAttribute<double>(TEXT("detail\tbearing\tvalue")));
			}
		}
	}

	return actor->GetActorForwardVector().Rotation();
}

// chaser and target keep current velocities; can chaser change bearing to intercept target?  if so return time/location/chaser bearing
bool AGame_Bloodhound::GetInterceptData(float& interceptTime, FVector& interceptLocation, float& interceptBearing)
{
	AVH_GlobeReferenceActor* globeRef = GetGlobeReference();

	AActor* chaser = GetActor(ChaserUID);
	AActor* target = GetActor(TargetUID);
	
	if (globeRef == nullptr || chaser == nullptr || target == nullptr)
	{
		return false;
	}

	// in unreal units / second
	float chaserSpeedUU = GetVelocitySize(chaser);
    float targetSpeedUU = GetVelocitySize(target);

	if (chaserSpeedUU == 0)
	{
		return false;
	}
    else if (targetSpeedUU == 0.f)
    {
		FVector chaserToTarget = target->GetActorLocation() - chaser->GetActorLocation();

		interceptBearing = globeRef->WorldRotationToBearing(chaserToTarget.Rotation());

        interceptTime = chaserToTarget.Size() / chaserSpeedUU;

		interceptLocation = target->GetActorLocation();

        return true;
    }
    else
    {
		FVector targetToChaser = chaser->GetActorLocation() - target->GetActorLocation();
		float targetToChaserSize = targetToChaser.Size();

        FRotator targetRotation = GetRotation(target);

        float a = chaserSpeedUU * chaserSpeedUU - targetSpeedUU * targetSpeedUU;
        float b = 2.f * FVector::DotProduct(targetToChaser, (targetRotation.Vector() * targetSpeedUU));
        float c = -targetToChaserSize * targetToChaserSize;

        // the two values to be solved by the Quadratic equation solution
        float time1 = 0.f;
        float time2 = 0.f;

        // QuadraticCalc returns false if it is unable to find a point
        if (QuadraticCalc(time1, time2, a, b, c))
        {
            // At least one of Time1 and Time2 have to be positive due to passing the QuadraticCalc check above if time1 and time2 are both positive, return
            // the smaller one to find the shortest amount of time to intercept
            if (time1 > 0.f && time2 > 0.f)
            {
                interceptTime = FMath::Min<float>(time1, time2);
            }
            // else if one of the two numbers is negative, return the positive one
            else
            {
                interceptTime = FMath::Max<float>(time1, time2);
            }

            interceptLocation = target->GetActorLocation() + ((targetRotation.Vector() * targetSpeedUU) * interceptTime);

            interceptBearing = globeRef->WorldRotationToBearing((interceptLocation - chaser->GetActorLocation()).Rotation());
        }
        else
        {
            // QuadraticCalc fails
            UE_LOG(Game, Warning, TEXT("-- AGame_Bloodhound::GetIntercept | QuadraticCalc failed"));
            return false;
        }
    }

    return true;
}

void AGame_Bloodhound::SetInterceptLineColor(float interceptTime)
{
	for (const TPair<FVector2D, FColor> entry : InterceptTimeToColor)
	{
		if ((entry.Key.X == -1 || entry.Key.X <= interceptTime) && (entry.Key.Y == -1 || entry.Key.Y >= interceptTime))
		{
			InterceptArrow->GetLine()->SetMaterialColor(entry.Value);
			return;
		}
	}
}

bool AGame_Bloodhound::QuadraticCalc(float& x1, float& x2, float a, float b, float c)
{
    // not quadratic because ax^2 is zero (ax^2 + bx + c = 0), which makes bx + c = 0 bx + c = 0 -> bx = -c -> x = -c / b
    if (a == 0.f)
    {
        // if b is also zero, then there is no solution, because the time to intercept is zero seconds and it causes a division by zero
        if (b == 0.f)
        {
            return false;
        }
        else
        {
            x1 = -c / b;
            x2 = x1;
        }
    }
    // if a is not 0, then carry onto the discriminant
    else
    {
        float discriminant = (b * b) - (4.f * a * c);

        if (discriminant > 0.f)
        {
            x1 = (-b + sqrt(discriminant)) / (2.f * a);
            x2 = (-b - sqrt(discriminant)) / (2.f * a);
        }
        else if (discriminant == 0.f)
        {
            x1 = -b / (2.f * a);
            // equation equals out to be (-b + 0) / 2a and (-b - 0) / 2a which just equals -b/2a, so both are the same.
            x2 = x1;
        }
        // discriminant is less than zero and sqrt of negative number is imaginary
        else
        {
            UE_LOG(Game, Warning, TEXT("-- AGame_Bloodhound::QuadraticCalc | discriminant is < 0"));
            return false;
        }
    }

    // if neither x1 or x2 is greater than zero, that means one or both intercepts occurred in the past or one or both of the intercepts are currently
    // intercepting, and an intercept in the past or an intercept that is currently being intercept is not a valid intercept
    if (x1 <= 0.f && x2 <= 0.f)
    {
        UE_LOG(Game, Warning, TEXT("-- AGame_Bloodhound::QuadraticCalc | intercept occurred in the past"));
        return false;
    }

    return true;
}