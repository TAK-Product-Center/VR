#pragma once

// Parent includes
#include "Game_EditPoint.h"

// Generated includes
#include "Game_EditPoint_RectangleRotator.generated.h"


/**
 *  This class is for the rotator points on the rectangle tool which allows the user to rotate the rectangle entity
 */
UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_EditPoint_RectangleRotator : public AGame_EditPoint
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Members
	// ---------------------------------
protected:

	/*
	 *  This material will set the thickness of the rectangle rotator torus.
	 */ 
	UMaterialInstanceDynamic* MID;

	/*
	 *  This variable will hold an arbitrary value representing the thickness of the torus.
	 */
	float Thickness;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	
	/*
	 *  This will be used to initialize the variables above.
	 */
	AGame_EditPoint_RectangleRotator(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited Methods
	// ---------------------------------
protected:

	/*
	 *  We'll be overriding BeginPlay to instantiate the MID variable and setting the thickness scalar parameter of the MID.
	 */
	virtual void BeginPlay() override;


	// ---------------------------------
	// --- API
	// ---------------------------------
public:

	/*
	 *  This function will set the "ThicknessAmount" scalar parameter on the MaterialInstanceDynamic. The float parameter for this function is a multiplier
	 *  so passing 1.f would set the thickness to the default, .5f would set the thickness to half of the default, etc.
	 */
	virtual bool SetThickness(const float& thicknessMultiplier);

};
