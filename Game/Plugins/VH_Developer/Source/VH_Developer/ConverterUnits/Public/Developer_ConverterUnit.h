#pragma once

// Parent Includes
#include "UObject/Object.h"

// Generated Includes
#include "Developer_ConverterUnit.generated.h"

UCLASS(Blueprintable, Abstract)
class VH_DEVELOPER_API UDeveloper_ConverterUnit: public UObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	/*
	 * \brief The conversion ratio to the standard unit type.
	 */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
	double ToStandardUnitRatio;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
	FString Abbreviation;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
	FString ID;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
	FString BaseUnit;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_ConverterUnit(double ratio, const FString& abbreviation, const FString& id, const FString& baseUnit);

	UDeveloper_ConverterUnit();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Returns the abbreviation used by this unit, such as ft for feet or km for kilometers
	*/
	UFUNCTION(BlueprintPure)
	FString GetAbbreviation() const;

	/*
	* \brief Returns the name of the unit
	*/
	UFUNCTION(BlueprintPure)
	FString GetID() const;

	/*
	* \brief Returns the type of value this unit measures.
	*/
	UFUNCTION(BlueprintPure)
	FString GetStandardUnit() const;

	/*
	* \brief Converts from standard unit to this unit type.
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FString ConvertFromStandard(const FString& standardValue);

	/*
	* \brief Converts from this unit to the standard unit type.
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FString ConvertToStandard(const FString& unitValue);
	
	/*
	* \brief Takes a value that is already in this unit and formats it to display correctly
	*/
	UFUNCTION(BlueprintCallable)
	FString FormatText(const FString& unitValue, int32 numDigits);
};
