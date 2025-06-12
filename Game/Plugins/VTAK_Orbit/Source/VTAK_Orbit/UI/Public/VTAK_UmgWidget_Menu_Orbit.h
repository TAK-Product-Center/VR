#pragma once

// Required includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "Interface_UI_Tab.h"

// Generated Includes
#include "VTAK_UmgWidget_Menu_Orbit.generated.h"

class AGame_VirtualObjective;
class AVTAK_Actor_Orbit;

UCLASS()
class VTAK_ORBIT_API UVTAK_UmgWidget_Menu_Orbit : public UUserWidget, public IInterface_UI_Tab
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVTAK_UmgWidget_Menu_Orbit(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool Initialize() override;

	virtual void NativeConstruct() override;
	

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCoordinate(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetRadius(const FString& radius, const FString& radiusUnit);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetSpeed(const FString& speed, const FString& speedUnit);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetPause(bool bPause);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetOrbit(bool bOrbit);

	UFUNCTION(BlueprintCallable)
	void SetRadius(const FString& radiusString);

	UFUNCTION(BlueprintCallable)
	void SetSpeed(const FString& speedString);

	UFUNCTION(BlueprintCallable)
	void ToggleOrbit();

	UFUNCTION(BlueprintCallable)
	void TogglePause();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	AVTAK_Actor_Orbit* GetOrbitActor() const;

	void PopulateFromDatabase();

	void BindToOrbitActor(bool bBind);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleStringSettingStored(const FString& settingName, const FString& value);

	UFUNCTION()
	void HandlePageIn(const FString& entityUID, AGame_VirtualObjective* virtualObjective);

	UFUNCTION()
	void HandlePageOut(const FString& entityUID, AGame_VirtualObjective* virtualObjective);

	UFUNCTION()
	void HandleDelete(const FSpatialiteResults_BP& results);
};