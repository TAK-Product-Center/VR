#pragma once

#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"

#include "Game_TileComponent.h"
#include "Game_TileComponent_Mat.generated.h"

// ---------------------------------
// --- Delegates
// ---------------------------------
DECLARE_DELEGATE_OneParam(FGameLogicCompletedMat, UGame_TileComponent_Mat*);

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_TileComponent_Mat : public UGame_TileComponent
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	FGameLogicCompletedMat OnGameLogicCompleted;

	cv::Mat Mat;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UGame_TileComponent_Mat();

	virtual float GetAlpha();
};