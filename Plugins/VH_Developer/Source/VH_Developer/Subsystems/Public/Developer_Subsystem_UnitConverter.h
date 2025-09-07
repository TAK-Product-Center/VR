#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Engine Includes
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Developer_Subsystem_UnitConverter.generated.h"

// Forward declarations
class UDeveloper_ConverterUnit;
class UDeveloper_Subsystem_UnitConverter_Settings;

/*
* To convert between two units you call the ConvertUnits function with the names(as strings) of the units you want to convert toand from.
*
* float valueInFeet = 123;
* float valueInMeters = UDeveloper_UnitConverter::Get()->ConvertUnits("feet", valueInFeet, "meters");
* The unit names come from the 'Name' field within UDeveloper_ConverterUnit.The format is the unit name in plural and lowercase.
*
* The converter can also format the result as a string.
*
* FString result = UDeveloper_UnitConverter::Get()->ConvertUnitsAndFormat("kilometers", 5.6, "meters", 1);
* In this example result ends with the value "5600.0m".The unit is converted, the unit abbreviation is appended, and it is displayed rounded to the number of decimal places specified in the last argument,
*/

UCLASS()
class VH_DEVELOPER_API UDeveloper_Subsystem_UnitConverter : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	TSet<TSubclassOf<UDeveloper_ConverterUnit>> DefaultConverters;

private:
	UPROPERTY()
	TMap<FString, UDeveloper_ConverterUnit*> Converters;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Subsystem_UnitConverter();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
	
public:
	static UDeveloper_Subsystem_UnitConverter* Get();


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
	UFUNCTION(BlueprintCallable)
	void UpdateSettings(TSubclassOf<UDeveloper_Subsystem_UnitConverter_Settings> settingsClass);

	UFUNCTION(BlueprintCallable)
	FString RegisterConverterUnitByClass(TSubclassOf<UDeveloper_ConverterUnit> unitClass);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	FString ConvertUnits(const FString& startConverterName, const FString& startValue, const FString& endConverterName) const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	FString ConvertUnitsAndFormat(const FString& startConverterName, const FString& startValue, const FString& endConverterName, int32 numDigits) const;

	UFUNCTION(BlueprintCallable)
	FString ConvertUnitsByClass(TSubclassOf<UDeveloper_ConverterUnit> startConverterClass, const FString& startValue, TSubclassOf<UDeveloper_ConverterUnit> endConverterClass);

	UFUNCTION(BlueprintCallable)
	FString ConvertUnitsAndFormatByClass(TSubclassOf<UDeveloper_ConverterUnit> startConverterClass, const FString& startValue, TSubclassOf<UDeveloper_ConverterUnit> endConverterClass, int32 numDigits);

	UFUNCTION(BlueprintPure)
	TSet<FString> GetUnitIDs() const;

	UFUNCTION(BlueprintPure)
	UDeveloper_ConverterUnit* GetUnit(const FString& unitID) const;
	
	UFUNCTION(BlueprintPure)
	FString GetAbbreviationFromName(const FString& unitID) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateSettings(const UDeveloper_Subsystem_UnitConverter_Settings* settings);
};