#pragma once

// Parent Includes
#include "Game_Point.h"

// Generated Includes
#include "Game_Point_Icon.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Point_Icon : public AGame_Point
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleIconChanged);

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FHandleIconChanged OnIconChanged;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsXRay;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* PlaneStaticMeshComponent;

	UPROPERTY()
	UMaterialInstanceDynamic* IconMID;

	UPROPERTY()
	UTexture2D* IconTexture;

private:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	float CallsignRelativeHeight;


	// --------------------------------- 
	// --- Constructors
	// ---------------------------------

public:
	AGame_Point_Icon(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetIconTexture(UTexture2D* inIconTexture);

	UFUNCTION(BlueprintCallable)
	void SetIconColor(const FLinearColor& linearColor);

	UFUNCTION(BlueprintPure)
	UTexture2D* GetIconTexture() const;

	UFUNCTION(BlueprintPure)
	bool GetIsXRay() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

public:
	UFUNCTION()
	void HandleObjectAddedToVO(UObject* object, AGame_VirtualObjective* vo);
};
