#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// VH Plugin Includes
#include "InputAction.h"

// Game Includes
#include "Game_TransformGizmo_Enum.h"

// Generated Includes
#include "Game_TransformGizmo.generated.h"

class UGame_TranslationComponent;
class UGame_RotationComponent;
class UGame_ScaleComponent;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_TransformGizmo : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	// The transform mode that the gizmo begins with.
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	ETransformMode DefaultTransformMode;

	// The transform origin that the gizmo begins with.
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	ETransformOrigin DefaultTransformOrigin;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Transform|Translation")
	float TranslationGizmoSensitivity;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Transform|Rotation")
	float RotationGizmoSensitivity;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Transform|Scale")
	float ScaleGizmoSensitivity;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Transform")
	float ScreenSize;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Transform")
	UInputAction* ToggleModeInputAction;

	/* Root components to compartmentalize the manipulation components */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* TranslationRoot;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* RotationRoot;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* ScaleRoot;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TMap<ETransformAxis, UGame_TranslationComponent*> TranslationComponents;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TMap<ETransformAxis, UGame_RotationComponent*> RotationComponents;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TMap<ETransformAxis, UGame_ScaleComponent*> ScaleComponents;

private:
	ETransformMode TransformMode;

	ETransformOrigin TransformOrigin;

	TSet<ETransformAxis> AllowedAxes;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_TransformGizmo(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void Tick(float deltaSeconds) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	ETransformMode GetTransformMode() const;

	UFUNCTION(BlueprintCallable)
	void SetTransformMode(ETransformMode mode, const TSet<ETransformAxis>& allowedAxes);

	UFUNCTION(BlueprintPure)
	ETransformOrigin GetTransformOrigin() const;

	UFUNCTION(BlueprintCallable)
	void SetTransformOrigin(ETransformOrigin origin);

	UFUNCTION(BlueprintPure)
	TSet<ETransformAxis> GetAllowedAxes() const;

	/*
	* \brief broadcasts OnClicked(source, EKeys::LeftMouseButton) on component based on mode and axis 
	* \returns Clicked component (if any)
	*/
	UFUNCTION(BlueprintCallable)
	UGame_TransformBaseComponent* SimulateMousePress(AActor* source, ETransformMode mode, ETransformAxis axis);

	/* resets LastRay in case mouse drag occurs but gizmo movement was not allowed */
	void ResetLastRay();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual FTransform GetSelectedActorTransform() const;

private:
	void UpdateComponentRotation();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	// Cycles the transform gizmo in the order translation -> rotation -> scale.
	UFUNCTION()
	void HandleToggleTransformMode();

	UFUNCTION()
	void HandleSelectionChanged(UObject* object, bool bSelected);
};