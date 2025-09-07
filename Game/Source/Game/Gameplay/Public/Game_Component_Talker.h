// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Net/VoiceConfig.h"
#include "Game_Component_Talker.generated.h"

/**
 *	DefaultToInstanced, BlueprintType, abstract, meta=(ShortTooltip="An ActorComponent is a reusable component that can be added to any actor.")

	BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent)
 */

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent, ShortTooltip = "The Game_Input is for controlling the input of the actor it is connected to."))
class GAME_API UGame_Component_Talker : public UVOIPTalker
{
    GENERATED_BODY()

public:
	UGame_Component_Talker(const FObjectInitializer& ObjectInitializer);


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	//Delegate for when the player begins and stops talking
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTalkingStatusChanged, bool, isTalking);

	UPROPERTY(BlueprintAssignable)
	FOnTalkingStatusChanged OnTalkingStatusChanged;

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	// Override this function to implement custom functionality when this player begins talking.
	virtual void OnTalkingBegin(UAudioComponent* audioComponent);

	// Override this function to implement custom functionality when this player stops talking.
	virtual void OnTalkingEnd();
};
