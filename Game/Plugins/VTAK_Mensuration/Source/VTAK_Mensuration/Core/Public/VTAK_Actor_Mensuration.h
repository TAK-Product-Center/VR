#pragma once

// Parent Includes
#include "Game_Arrow.h"

// VH Plugin includes
#include "Interface_Developer_Manipulation.h"

// Module Includes
#include "VTAK_UmgWidget_MensurationDetail.h"

// Generated include
#include "VTAK_Actor_Mensuration.generated.h"

// Forward declarations
class UVH_UmgWidget_Mensuration;
class UWidgetComponent;
class UVH_ContextOption;

UCLASS(Blueprintable, BlueprintType)
class VTAK_MENSURATION_API AVTAK_Actor_Mensuration : public AGame_Arrow
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UVTAK_UmgWidget_MensurationDetail> MensurationDetailClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAxisListBlueprint AllowedLineRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAxisListBlueprint AllowedLineTranslation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAxisListBlueprint AllowedBaseRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAxisListBlueprint AllowedBaseTranslation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAxisListBlueprint AllowedArrowRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAxisListBlueprint AllowedArrowTranslation;

	UPROPERTY(BlueprintReadWrite)
	FString AngleUnit;

	UPROPERTY(BlueprintReadWrite)
	FString BearingUnit;

	UPROPERTY(BlueprintReadWrite)
	FString LengthUnit;

private:
	bool bIsAngleLocked;

	bool bIsBearingLocked;

	bool bIsLengthLocked;

	bool bIsAngleUnitManuallySet;

	bool bIsBearingUnitManuallySet;

	bool bIsLengthUnitManuallySet;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVTAK_Actor_Mensuration();


	// ---------------------------------
	// --- Friend Classes
	// ---------------------------------

public:
	friend class UVTAK_UmgWidget_MensurationDetail;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void BeginPlay() override;

	virtual void SpawnEditPointsAndLine() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	bool GetActive() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetAngle(const FString& unit) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetBearing(const FString& unit) const;

	/* Gets the edit points of the mensuration and returns it */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<AVTAK_EditPoint_Mensuration*> GetEditPoints() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetLength(const FString& unit) const;

	UFUNCTION(BlueprintCallable)
	bool GetPointCollision() const;

	UFUNCTION(BlueprintCallable)
	bool SetActive(bool bActive);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool SetAngle(float angle, const FString& unit = TEXT("degrees"));

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool SetBearing(float bearing, const FString& unit = TEXT("degrees"));

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool SetLength(float length, const FString& unit = TEXT("meters"));

	UFUNCTION(BlueprintCallable)
	bool SetPointCollision(bool bEnableCollision);

	/*
	 *	Called after EditPoints have been been spawn and line created.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void ReceivePostSpawnEditPoints();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	/*
	 *	Called after EditPoints have been been spawn and line created.
	 */
	virtual void PostSpawnEditPoints();

	/*
	 * Restores Manipulation widget to a state that was similar to before our specific manipulation context was requested
	 */
	bool RemoveEntityFromDB();

	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleStringSettingStored(const FString& settingName, const FString& settingValue);
};
