#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_SendTo.generated.h"

class UVH_DataPackage;
class UVH_DataSync;

UCLASS()
class GAME_API UGame_UserWidget_SendTo : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
private:
	FString EntityUID;

	// when valid, means we're sending datapackage to contacts
	UPROPERTY()
	UVH_DataPackage* DataPackage;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_SendTo(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetEntityUID(const FString& entityUID);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetDataPackage(UVH_DataPackage* dataPackageArg);

	UFUNCTION(BlueprintCallable)
	void SetEntityUID(const FString& entityUID);

	UFUNCTION(BlueprintPure)
	FString GetEntityUID() const;

	UFUNCTION(BlueprintCallable)
	void SetDataPackage(UVH_DataPackage* dataPackageArg);

	UFUNCTION(BlueprintPure)
	UVH_DataPackage* GetDataPackage() const;

	UFUNCTION(BlueprintCallable)
	void Broadcast();

	UFUNCTION(BlueprintCallable)
	void Send(const TSet<FString>& contactUIDs, const TSet<UVH_DataPackage*>& dataPackages, const TSet<UVH_DataSync*>& dataSyncs);

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void InternalSend(bool bBroadcast, const TSet<FString>& contactUIDs, const TSet<UVH_DataPackage*>& dataPackages, const TSet<UVH_DataSync*>& dataSyncs);
};
