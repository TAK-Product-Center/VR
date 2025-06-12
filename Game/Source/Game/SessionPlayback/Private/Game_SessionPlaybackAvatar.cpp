#include "Game_SessionPlaybackAvatar.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_SessionPlaybackAvatar::AGame_SessionPlaybackAvatar()
{
	SetActorTickEnabled(UseInterpolation);
}

void AGame_SessionPlaybackAvatar::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (UseInterpolation && InterpolationTime <= 1.0f)
	{
		InterpolationTime += deltaSeconds;

		float alpha = FMath::Clamp(InterpolationTime, 0.0f, 1.0f);

		FVector newPosition = FMath::Lerp(GetActorLocation(), TargetPosition, alpha);
		FRotator newRotation = FMath::Lerp(GetActorRotation(), TargetRotation, alpha);

		SetActorLocationAndRotation(newPosition, newRotation);
	}
}

void AGame_SessionPlaybackAvatar::SetTargetPosition(const FVector& position)
{
	if (UseInterpolation)
	{
		TargetPosition = position;
		InterpolationTime = 0.0f;
	}
	else
	{
		SetActorLocation(position);
	}
}

void AGame_SessionPlaybackAvatar::SetTargetRotation(const FRotator& rotation)
{
	if (UseInterpolation)
	{
		TargetRotation = rotation;
		InterpolationTime = 0.0f;
	}
	else
	{
		SetActorRotation(rotation);
	}
}
