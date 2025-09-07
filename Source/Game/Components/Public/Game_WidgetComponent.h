// Developed by Virtual Heroes, 2019-2020

#pragma once

#include "Components/WidgetComponent.h"
#include "Game_WidgetComponent.generated.h"

/**
 * Widget Component class that exposes the Lighting category that WidgetComponent normally hides, allowing us to control shadow magic once more
 */
UCLASS(Blueprintable, ShowCategories=(Lighting), meta = (BlueprintSpawnableComponent))
class GAME_API UGame_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_WidgetComponent();

	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	
	virtual void BeginPlay() override;
	
};

