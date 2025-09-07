#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_VR_Tool.generated.h"

class UVR_MotionControllerComponent;
struct FInputActionInstance;

UINTERFACE(Blueprintable)
class VH_VR_API UInterface_VR_Tool : public UInterface
{
    GENERATED_BODY()
};

class VH_VR_API IInterface_VR_Tool
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Called when self is added to motionControllerComponent's InputToolStack.  Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone.
	*/
	UFUNCTION(BlueprintNativeEvent) 
	void AddedToInputToolStack(UVR_MotionControllerComponent* motionControllerComponent);

	/*
	* \brief Called when self is removed from motionControllerComponent's InputToolStack.  Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone.
	*/
	UFUNCTION(BlueprintNativeEvent)
	void RemovedFromInputToolStack(UVR_MotionControllerComponent* motionControllerComponent);

	/*
	* \brief Called when self's index in motionControllerComponent's InputToolStack changes.  Tool receives input when at 0th index of motionControllerComponent's InputToolStack.  
	*        Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone.
	*/
	UFUNCTION(BlueprintNativeEvent)
	void InputToolStackIndexChanged(UVR_MotionControllerComponent* motionControllerComponent, int32 index);

	UFUNCTION(BlueprintNativeEvent)
	void ActionInput(const FInputActionInstance& inputActionInstance);

	/*
	* \brief VR_MotionControllerComponent will attempt to position itself to face the mouse position in desktop and VREmulation.
	*	     This gives the transform of the position to use as the origin location when determining that position.
	* \return False uses identity transform
	*/
	UFUNCTION(BlueprintNativeEvent)
	bool GetRelativeTransformForNonVRPositioning(FTransform& transform) const;
};
