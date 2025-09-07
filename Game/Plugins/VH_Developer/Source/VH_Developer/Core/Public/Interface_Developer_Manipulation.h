#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_Developer_Manipulation.generated.h"

// similar to EAxisList::Type from Math/Axis.h but exposed to blueprint
UENUM(BlueprintType)
enum class EAxisListBlueprint : uint8
{
	None,
	X,
	Y,
	Z,
	XY,
	XZ,
	YZ,
	XYZ
};

UINTERFACE(Blueprintable)
class VH_DEVELOPER_API UInterface_Developer_Manipulation : public UInterface
{
    GENERATED_BODY()
};

class VH_DEVELOPER_API IInterface_Developer_Manipulation
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Sets axisList to enabled axes for translation
	* \return False to enable all axes; true to specify the axisList
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetTranslationAxisList(EAxisListBlueprint& axisList);

	/*
	* \brief Sets axisList to enabled axes for rotation
	* \return False to enable all axes; true to specify the axisList
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetRotationAxisList(EAxisListBlueprint& axisList);

	/*
	* \brief Returns true if rotation should be disabled
	* \return True to disable rotation
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetRotationDisabled();

	/*
	* \brief Sets axisList to enabled axes for scale
	* \return False to enable all axes; true to specify the axisList
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GetScaleAxisList(EAxisListBlueprint& axisList);

	/*
	* \brief Allows override for local-to-world transform of this object; defaults to GetActorTransform() if not implemented
	* \return true if override should occur
	*/
	UFUNCTION(BlueprintNativeEvent)
	bool GetWorldTransform(FTransform& localToWorld);

	/*
	* \brief Called when manipulation begins
	*/
	UFUNCTION(BlueprintNativeEvent)
	void ManipulationBegin();

	/*
	* \brief Called after each manipulation
	*/
	UFUNCTION(BlueprintNativeEvent)
	void ManipulationInProgress();

	/*
	* \brief Called when manipulation ends
	*/
	UFUNCTION(BlueprintNativeEvent)
	void ManipulationEnd();
};
