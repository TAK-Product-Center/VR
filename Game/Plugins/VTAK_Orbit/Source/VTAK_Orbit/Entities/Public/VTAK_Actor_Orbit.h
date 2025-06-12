#pragma once

// Parent includes
#include "Game_EditPoint.h"

// Engine Includes
#include "InputKeyEventArgs.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"
#include "Interface_COTReceiver.h"

// Generated include
#include "VTAK_Actor_Orbit.generated.h"

class UVTAK_COTComponent_Orbit;
class UVTAK_DatabaseComponent_Orbit;
class UVTAK_UmgWidget_Menu_Orbit;
class UCameraComponent;

UCLASS()
class VTAK_ORBIT_API AVTAK_Actor_Orbit : public AGame_EditPoint, public IInterface_COTReceiver
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetOrbit, bool, bOrbit);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetPause, bool, bPause);
	
	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnSetOrbit OnSetOrbit;
	
	UPROPERTY(BlueprintAssignable)
	FOnSetPause OnSetPause;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UVTAK_COTComponent_Orbit* COTComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UVTAK_DatabaseComponent_Orbit* DatabaseComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* OrbitCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGeodeticCoord3D Coordinate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double RadiusMeters;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double SpeedMetersPerSecond;

private:
	bool bOrbit;

	bool bPause;

	bool bIgnoreRelease;

	double SecondsInOrbit;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_Actor_Orbit(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Interface_COTReceiver
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UVH_COTComponent* GetCOTComponent() const;

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void Tick(float deltaSeconds) override;

	virtual void SetActive(bool bActive) override;

	virtual bool GetRotationDisabled_Implementation() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void InsertIntoEntityDB();

	void RemoveFromEntityDB();

	UFUNCTION(BlueprintCallable)
	void SetOrbit(bool bShouldOrbit);
	
	UFUNCTION(BlueprintCallable)
	void SetPause(bool bShouldPause);

	UFUNCTION(BlueprintPure)
	bool GetOrbit() const;

	UFUNCTION(BlueprintPure)
	bool GetPause() const;
	

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleInputKey(const FInputKeyEventArgs& eventArgs);
};