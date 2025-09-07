#pragma once

// Parent includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "Interface_UI_Tab.h"

// Generated include
#include "VTAK_UmgWidget_MensurationDetail.generated.h"

// Forward declarations
class AVTAK_Actor_Mensuration;

UCLASS()
class VTAK_MENSURATION_API UVTAK_UmgWidget_MensurationDetail : public UUserWidget, public IInterface_UI_Tab
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Friend Classes
	// ---------------------------------

public:

	friend class AVTAK_Actor_Mensuration;


	// ---------------------------------
	// --- Members
	// ---------------------------------
protected:

	AVTAK_Actor_Mensuration* Mensuration;


	// ---------------------------------
	// --- Public
	// ---------------------------------
public:

	bool Init(AVTAK_Actor_Mensuration* const mensuration);

	UFUNCTION(BlueprintCallable)
	void UpdateUI();

	////// Getters //////

	UFUNCTION(BlueprintCallable)
	const float GetAngle(const FString& unit = TEXT("degrees")) const;

	UFUNCTION(BlueprintCallable)
	const FString GetAngleUnit() const;

	UFUNCTION(BlueprintCallable)
	bool GetAngleLock() const;

	UFUNCTION(BlueprintCallable)
	const float GetBearing(const FString& unit = TEXT("degrees")) const;

	UFUNCTION(BlueprintCallable)
	const FString GetBearingUnit() const;

	UFUNCTION(BlueprintCallable)
	bool GetBearingLock() const;

	UFUNCTION(BlueprintCallable)
	const float GetLength(const FString& unit = TEXT("meters")) const;

	UFUNCTION(BlueprintCallable)
	const FString GetLengthUnit() const;

	UFUNCTION(BlueprintCallable)
	bool GetLengthLock() const;

	UFUNCTION(BlueprintCallable)
	bool GetLock() const;

	UFUNCTION(BlueprintCallable)
	bool GetPointCollision() const;

	////// Setters //////

	UFUNCTION(BlueprintCallable)
	bool SetAngle(const float& angle, const FString& unit = TEXT("degrees"));

	UFUNCTION(BlueprintCallable)
	bool SetAngleLock(bool bLock);

	UFUNCTION(BlueprintCallable)
	bool SetAngleUnit(const FString& unit);

	UFUNCTION(BlueprintCallable)
	bool SetBearing(const float& bearing, const FString& unit = TEXT("degrees"));

	UFUNCTION(BlueprintCallable)
	bool SetBearingLock(bool bLock);

	UFUNCTION(BlueprintCallable)
	bool SetBearingUnit(const FString& unit);

	UFUNCTION(BlueprintCallable)
	bool SetLength(const float& length, const FString& unit = TEXT("feet"));

	UFUNCTION(BlueprintCallable)
	bool SetLengthLock(bool bLock);

	UFUNCTION(BlueprintCallable)
	bool SetLengthUnit(const FString& unit);

	UFUNCTION(BlueprintCallable)
	bool SetLock(bool bLock);

	UFUNCTION(BlueprintCallable)
	bool SetPointCollision(bool bEnableCollision);

	////// UI Updates //////

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateAngle(const float& angle);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateAngleLock(bool bLock);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateAngleUnit(const FString& unit);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBearing(const float& bearing);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBearingLock(bool bLock);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBearingUnit(const FString& unit);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLength(const float& length);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLengthLock(bool bLock);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLengthUnit(const FString& unit);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLock(bool bLock);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePointCollision(bool bEnableCollision);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleOnManipulationEnd(AActor* manipulatedActor);
};
