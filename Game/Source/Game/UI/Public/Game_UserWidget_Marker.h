#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_UserWidget_Marker.generated.h"

class UVerticalBox;
class UImage;
class UGame_UserWidget_DisplayItem;
class AVH_GlobeReferenceActor;
class AGame_VirtualObjective;

UCLASS()
class GAME_API UGame_UserWidget_Marker : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, Category = "Vertical Box|Public", meta = (BindWidget))
	UVerticalBox* TopVerticalBox;

	UPROPERTY(BlueprintReadOnly, Category = "Vertical Box|Public", meta = (BindWidget))
	UVerticalBox* BottomVerticalBox;

	UPROPERTY(BlueprintReadOnly, Category = "Vertical Box|Public", meta = (BindWidget))
	UVerticalBox* RedXVerticalBox;

	UPROPERTY(BlueprintReadOnly, Category = "Images|Public", meta = (BindWidget))
	UImage* Separator;

	UPROPERTY(BlueprintReadOnly, Category = "Display Items|Public", meta = (BindWidget))
	UGame_UserWidget_DisplayItem* AltitudeItem;

	UPROPERTY(BlueprintReadOnly, Category = "Display Items|Public", meta = (BindWidget))
	UGame_UserWidget_DisplayItem* BearingItem;

	UPROPERTY(BlueprintReadOnly, Category = "Display Items|Public", meta = (BindWidget))
	UGame_UserWidget_DisplayItem* DistanceItem;

	UPROPERTY(BlueprintReadOnly, Category = "Display Items|Public", meta = (BindWidget))
	UGame_UserWidget_DisplayItem* ElevationItem;

	UPROPERTY(BlueprintReadOnly, Category = "Display Items|Public", meta = (BindWidget))
	UGame_UserWidget_DisplayItem* LatitudeItem;

	UPROPERTY(BlueprintReadOnly, Category = "Display Items|Public", meta = (BindWidget))
	UGame_UserWidget_DisplayItem* LongitudeItem;

	UPROPERTY(BlueprintReadOnly, Category = "Display Items|Public", meta = (BindWidget))
	UGame_UserWidget_DisplayItem* MGRSItem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display Units")
	int32 AltitudeNumDigits;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display Units")
	int32 DistanceNumDigits;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display Units")
	int32 BearingNumDigits;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display Units")
	int32 ElevationNumDigits;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_Marker(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void NativeConstruct() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetData(AGame_VirtualObjective* virtualObjective, const FVector& sourceLocation, const FVector& targetLocation);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void GetGlobeHAE(FGeodeticCoord3D& coordinate, bool& bInnerLoaded);

	virtual void BindToPlayerState();

	virtual void SetAltitude(const FGeodeticCoord3D& coordinate);

	virtual void SetBearing(AVH_GlobeReferenceActor* globeRef, const FVector& sourceLocation, const FVector& targetLocation);

	virtual void SetDistance(const FGeodeticCoord3D& sourceCoordinate, const FGeodeticCoord3D& targetCoordinate);

	virtual void SetElevation(AVH_GlobeReferenceActor* globeRef, const FVector& sourceLocation, const FVector& targetLocation);

	virtual void SetLatitude(double latitude);

	virtual void SetLongitude(double longitude);

	virtual void SetMGRS(AVH_GlobeReferenceActor* globeRef, const FVector& targetLocation);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION(BlueprintCallable)
	void HandleIsInTOCUpdated(bool bIsInTOC);

	UFUNCTION()
	void HandleWorldTransformOverrideUpdated(const FTransform& worldTransform);
};
