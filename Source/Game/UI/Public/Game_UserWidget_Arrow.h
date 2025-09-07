#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_Arrow.generated.h"

// Forward declarations
class AGame_EditPoint;
class AGame_VirtualObjective;

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class ERangeType : uint8
{
	Horizontal,
	Vertical,
	Both
};

UCLASS()
class GAME_API UGame_UserWidget_Arrow : public UUserWidget
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AGame_VirtualObjective* VirtualObjective;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ERangeType RangeType;

protected:
	FString RangeUnit;

	FString BearingUnit;

	float RangeMeters;

	float BearingDegrees;

	// determines if the user has specified a unit via a context option.
	// it will prevent updates from the settings menu
	bool bExplicitUnitSelected;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_Arrow(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool Initialize() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Runs on tick and updates the widget with changes in scale and changes in location of the baseEditPoint and arrowEditPoint
	*/
	void Update(const FVector& scale3D, const AGame_EditPoint* baseEditPoint, const AGame_EditPoint* arrowEditPoint);

	/*
	* \brief Returns the range in the unit which is specified in RangeUnit
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure = false)
    FString GetRangeString() const;

	/*
	* \brief Returns the bearing in the unit which is specified in BearingUnit
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	FString GetBearingString() const;

	/*
	* \brief Returns the abbreviation for the context sub option menu which is specified in RangeUnit
	*/
	UFUNCTION(BlueprintPure)
	FString GetRangeUnitString() const;

	/*
	* \brief Sets the Range explicitly, such as from a context option
	*/
	UFUNCTION(BlueprintCallable)
	void SetRangeUnit(FString rangeUnit);

	/*
	* \brief Sends the a Range string to blueprint for use on the UI
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRangeText(const FString& rangeText);

	/*
	* \brief Sends the a Bearing string to blueprint for use on the UI
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBearingText(const FString& bearingText);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:
	/*
	* \brief Sets the range or bearing if one of them are changed in the settings menu unless the user
	* has specified one in SetRangeUnits()
	*/
	UFUNCTION()
	virtual void HandleStringSettingChanged(const FString& settingName, const FString& value);
};
