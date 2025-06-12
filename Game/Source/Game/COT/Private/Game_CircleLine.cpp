#include "Game_CircleLine.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_CircleLine::AGame_CircleLine(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	MajorRadiusInMeters(0.0f),
	MinorRadiusInMeters(0.0f)
{

}

void AGame_CircleLine::GenerateMesh()
{
	Super::GenerateMesh();
	OnEditPointsUpdated.Broadcast();
}

void AGame_CircleLine::SetMajorRadius(float InMajorRadius)
{
	MajorRadiusInMeters = InMajorRadius;
}

void AGame_CircleLine::SetMinorRadius(float InMinorRadius)
{
	MinorRadiusInMeters = InMinorRadius;
}

FVector AGame_CircleLine::GetSouthmostLocation() const
{
	FVector relativeLocation = FVector::ZeroVector;
	if(LinePoints.Num() > 0)
	{
		relativeLocation = LinePoints[0].Location;
		for (int editPointsIndex = 0; editPointsIndex < LinePoints.Num(); editPointsIndex++)
		{
			if (LinePoints[editPointsIndex].Location.Y < relativeLocation.Y)
			{
				relativeLocation = LinePoints[editPointsIndex].Location;
			}
		}
	}
	return relativeLocation;
}