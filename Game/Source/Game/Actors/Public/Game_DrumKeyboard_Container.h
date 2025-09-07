#pragma once

// Parent Includes
#include "Game_Keyboard_Container.h"

// Engine Includes
#include "Components/SplineComponent.h"

// Generated Includes
#include "Game_DrumKeyboard_Container.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_DrumKeyboard_Container : public AGame_Keyboard_Container
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "KeySpline"))
	USplineComponent* KeySpline;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_DrumKeyboard_Container(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditMove(bool bFinished) override;
#endif


	// ---------------------------------
	// --- Interface_Keyboard_Container
	// ---------------------------------

public:
	virtual void InitializeForObject_Implementation(UObject* object) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void EditorSplineChanged();

	UFUNCTION(BlueprintCallable)
	void RepositionToObject(UObject* object);
};