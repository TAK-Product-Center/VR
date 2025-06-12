#pragma once

#include "UObject/Interface.h"

#include "Interface_DetailMenu.generated.h"

UINTERFACE(Blueprintable)
class GAME_API UInterface_DetailMenu : public UInterface
{
    GENERATED_BODY()
};

class GAME_API IInterface_DetailMenu
{
    GENERATED_BODY()

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
    
	/*
	* \brief Sets entityUID for detail menu
	* \param entityUID UID of entity
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetEntityUID(const FString& entityUID);

	/*
	* \brief Sets actor for detail menu
	* \param actor passed to detail menu
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetActor(AActor* actor);
};
