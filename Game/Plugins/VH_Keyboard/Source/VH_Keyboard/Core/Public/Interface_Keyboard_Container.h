#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_Keyboard_Container.generated.h"

UINTERFACE(Blueprintable)
class VH_KEYBOARD_API UInterface_Keyboard_Container : public UInterface
{
    GENERATED_BODY()
};

class VH_KEYBOARD_API IInterface_Keyboard_Container
{
	GENERATED_BODY()
	

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/* 
	* \brief Called to initialize keyboard at a given transform
	* \param transform Transform to initialize keyboard to
	*/
	UFUNCTION(BlueprintNativeEvent)
	void InitializeAtTransform(const FTransform& transform);

	/*
	* \brief Called to initialize keyboard for a given object
	* \param object Object to initialize keyboard to
	*/
	UFUNCTION(BlueprintNativeEvent)
	void InitializeForObject(UObject* object);
};
