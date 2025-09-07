#pragma once

// Parent Includes
#include "Game_Tool.h"

// Generated Includes
#include "Game_Tool_TOCBoard.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Tool_TOCBoard : public AGame_Tool
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> SpawnTOCBoardCollisionChannel;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Tool_TOCBoard(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void PostTriggerActionPressed() override;
};