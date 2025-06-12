// Fill out your copyright notice in the Description page of Project Settings.

#include "Game_Component_Talker.h"
#include "Game.h"


// ---------------------------------
// --- Constructor
// ---------------------------------

UGame_Component_Talker::UGame_Component_Talker(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
}


// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Component_Talker::OnTalkingBegin(UAudioComponent* audioComponent)
{
	Super::OnTalkingBegin(audioComponent);

	OnTalkingStatusChanged.Broadcast(true);
}

void UGame_Component_Talker::OnTalkingEnd()
{
	Super::OnTalkingEnd();

	OnTalkingStatusChanged.Broadcast(false);
}
