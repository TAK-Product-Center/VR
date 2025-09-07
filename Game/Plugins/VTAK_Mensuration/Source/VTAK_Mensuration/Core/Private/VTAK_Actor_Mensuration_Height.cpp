// Required Includes
#include "VTAK_Actor_Mensuration_Height.h"
#include "VTAK_Mensuration.h"

// VH Plugin includes
#include "Developer_Subsystem_UnitConverter.h"

// Module Includes
#include "VTAK_EditPoint_Mensuration.h"

// Game Includes
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AVTAK_Actor_Mensuration_Height::AVTAK_Actor_Mensuration_Height()
{
	AllowedBaseTranslation = EAxisListBlueprint::Z;

	AllowedArrowTranslation = EAxisListBlueprint::Z;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AVTAK_Actor_Mensuration_Height::PostSpawnEditPoints()
{
	BaseEditPoint->OnManipulationBegin.AddDynamic(this, &AVTAK_Actor_Mensuration_Height::HandleManipulationBegin);
	ArrowEditPoint->OnManipulationBegin.AddDynamic(this, &AVTAK_Actor_Mensuration_Height::HandleManipulationBegin);

	BaseEditPoint->OnManipulationEnd.AddDynamic(this, &AVTAK_Actor_Mensuration_Height::HandleManipulationEnd);
	ArrowEditPoint->OnManipulationEnd.AddDynamic(this, &AVTAK_Actor_Mensuration_Height::HandleManipulationEnd);
}

// ---------------------------------
// --- API
// ---------------------------------

bool AVTAK_Actor_Mensuration_Height::SetLength_Implementation(float length, const FString& unit)
{
	if (!FMath::IsNearlyZero(length, 0.01f))
	{
		if (UDeveloper_Subsystem_UnitConverter* subsystem = UDeveloper_Subsystem_UnitConverter::Get())
		{
			float lengthInMeters = FCString::Atof(*subsystem->ConvertUnitsAndFormat(unit, FString::Printf(TEXT("%f"), length), TEXT("meters"), 2));

			if (BaseEditPoint && ArrowEditPoint)
			{
				FVector baseEditPointLoc = BaseEditPoint->GetActorLocation();
				FVector endEditPointLoc = ArrowEditPoint->GetActorLocation();

				FTransform transform = UGame_Statics::GetWorldTransformOverride(baseEditPointLoc);
				transform.SetLocation(FVector(0, 0, 0));

				FVector direction = FVector();
				if (endEditPointLoc.Z > baseEditPointLoc.Z)
				{
					direction = transform.TransformPosition(FVector::UpVector);
				}
				else if (baseEditPointLoc.Z > endEditPointLoc.Z)
				{
					direction = -transform.TransformPosition(FVector::UpVector);
				}

				FVector directionHeightScaled = direction * (lengthInMeters * 100.f);

				if (AVTAK_EditPoint_Mensuration* endPoint = Cast<AVTAK_EditPoint_Mensuration>(ArrowEditPoint))
				{
					endPoint->SetActorLocation(baseEditPointLoc + directionHeightScaled);

					endPoint->PersistWorldLocation();

					return true;
				}
			}
		}
	}

	return false;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AVTAK_Actor_Mensuration_Height::HandleManipulationBegin(AActor* manipulatedActor)
{
	if (AVTAK_EditPoint_Mensuration* mensurationEditPoint = Cast<AVTAK_EditPoint_Mensuration>(manipulatedActor))
	{
		mensurationEditPoint->ShowLevel(true);
	}
}

void AVTAK_Actor_Mensuration_Height::HandleManipulationEnd(AActor* manipulatedActor)
{
	if (AVTAK_EditPoint_Mensuration* mensurationEditPoint = Cast<AVTAK_EditPoint_Mensuration>(manipulatedActor))
	{
		mensurationEditPoint->ShowLevel(false);
	}
}