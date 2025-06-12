#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// VH Plugin Includes
#include "Interface_Developer_Manipulation.h"

// Generated Includes
#include "Game_Subsystem_Gizmo.generated.h"

class AGame_TransformGizmo;
class UGame_Subsystem_Gizmo_Settings;

/*
* Example world subsystem that manages the transform gizmo automatically.
*/
UCLASS()
class GAME_API UGame_Subsystem_Gizmo : public UWorldSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_DELEGATE_RetVal_TwoParams(bool, FGetInputRay, FVector&, FVector&);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/*
	* The default gizmo class that the Gizmo subsystem will use to spawn a new gizmo.
	* Initialized by the settings loaded from UGame_Subsystem_Gizmo_Settings.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_TransformGizmo> DefaultGizmoClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> GizmoCollisionChannel;

	TArray<FGetInputRay> GetInputRayLambdas;

private:
	/*
	* A reference to the transform gizmo that is currently in use.
	*/
	UPROPERTY()
	AGame_TransformGizmo* TransformGizmo;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Subsystem_Gizmo();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_Gizmo* Get();

	UFUNCTION(BlueprintPure)
	static ETransformAxis AxisListToTransformAxis(EAxisListBlueprint axisList);

	static TSet<ETransformAxis> AxisListToTransformAxisSet(ETransformMode transformMode, EAxisListBlueprint axisList);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual bool ShouldCreateSubsystem(UObject* outer) const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* Returns the current transform gizmo reference, or nullptr
	* if there is no transform gizmo active.
	*/
	UFUNCTION(BlueprintPure)
	AGame_TransformGizmo* GetTransformGizmo() const;

	UFUNCTION(BlueprintCallable)
	void SetGizmoTo(AActor* actor, ETransformMode transformMode);

	UFUNCTION(BlueprintCallable)
	void SetGizmoToWithAllowed(AActor* actor, ETransformMode transformMode, const TSet<ETransformAxis>& allowedAxes);

	/*
	* \return true if gizmo is not null
	*/
	UFUNCTION(BlueprintCallable)
	bool DestroyGizmo();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	/*
	* Retrieves the settings from the given
	* UGame_Subsystem_Gizmo_Settings instance.
	*/
	void UpdateSettings(const UGame_Subsystem_Gizmo_Settings* settings);
};
