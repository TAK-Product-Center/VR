#pragma once

#include "Globe_ConverterUnit_AltitudeRef_AGL.h"

#include "Game_Statics.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "VH_GlobeReferenceActor.h"

#include "Game_ConverterUnit_AltitudeRef_AGL.generated.h"

UCLASS(Blueprintable)
class GAME_API UGame_ConverterUnit_AltitudeRef_AGL : public UGlobe_ConverterUnit_AltitudeRef_AGL
{
	GENERATED_BODY()

public:
	virtual double GetGroundAltitude(const FGeodeticCoord2D& geoLocation2D) override
	{
		double groundHAE = 0;

		if (AGame_VirtualObjective* activeVO = UGame_Statics::GetVHPlayerController()->GetActiveVO())
		{
			if (activeVO->GetGlobeReference())
			{
				// NOTE: If trace fails, -999999 is returned here!
				groundHAE = activeVO->GetGlobeReference()->GetTerrainElevationDouble(geoLocation2D);
			}
		}

		return groundHAE;
	}
};
