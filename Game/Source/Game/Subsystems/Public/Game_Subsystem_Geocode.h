#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Generated Includes
#include "Game_Subsystem_Geocode.generated.h"

struct FGeodeticCoord2D;

UCLASS()
class GAME_API UGame_Subsystem_Geocode : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnForwardGeocodeReceived, const FString&, id, const FGeodeticCoord2D&, coordinate);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReverseGeocodeReceived, const FString&, id, const FString&, result);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnForwardGeocodeReceived OnForwardGeocodeReceived;

	UPROPERTY(BlueprintAssignable)
	FOnReverseGeocodeReceived OnReverseGeocodeReceived;

private:
	FString Key;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
	
public:
	UGame_Subsystem_Geocode();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_Geocode* Get();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	FString ForwardGeocode(const FString& search);

	UFUNCTION(BlueprintCallable)
	FString ReverseGeocode(const FGeodeticCoord2D& coordinate);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

};
