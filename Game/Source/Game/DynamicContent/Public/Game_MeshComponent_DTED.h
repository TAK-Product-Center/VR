#pragma once

// Parent Includes
#include "Game_TileComponent_Mesh.h"

// Engine Includes
#include "VH_GeodeticCoord.h"
#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"

// Generated Includes
#include "Game_MeshComponent_DTED.generated.h"

class AVH_GlobeReferenceActor;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MeshComponent_DTED : public UGame_TileComponent_Mesh
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MeshComponent_DTED();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	/*
	 * \brief Auto-extracts the default DTED archive, if needed.
	 * \param defaultDTEDPath Path to extracted DTED files.
	 * \return TRUE if successful.  FALSE if an error occurred.
	 */
	static bool StaticAutoExtractArchive(const FString& defaultDTEDPath);

	static bool GetHAE(const FGeodeticCoord2D& coordinate, double& hae);

	static bool GetHeightData(TArray<double>& haeValues, const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, double postSpacingMeters, int32& totalLongitudePosts, int32& totalLatitudePosts);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void ExecuteHelperThreadLogic() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	bool GetDTEDInfo(FGeodeticCoord2D coordinate, int32& dtedLevel) const;
};