#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// Engine Includes
#include "Tickable.h"

// Generated Includes
#include "Replication_Subsystem_Core.generated.h"


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FPriorityInfo
{
	GENERATED_BODY()

	double Priority;

	TSet<FString> IDs;

	FPriorityInfo()
	{
		Priority = 0;
	}
};

class AGameModeBase;
class APlayerController;
class AController;
class UReplication_DataChannel;
class UWorld;
class UNetConnection;

UCLASS()
class VH_REPLICATION_API UReplication_Subsystem_Core : public UWorldSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

	friend class UReplication_DataChannel;


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FDataReceived, const TArray<uint8>&, UReplication_DataChannel*);

	DECLARE_MULTICAST_DELEGATE_OneParam(FChannelCreated, UReplication_DataChannel*);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	FDataReceived OnDataReceived;

	FChannelCreated OnChannelCreated;

private:
	TMap<FString, TMap<APlayerController*, UReplication_DataChannel*>> IDToChannels;
	
	TArray<FPriorityInfo> SortedIDs;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UReplication_Subsystem_Core();


	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------

public:
	virtual TStatId GetStatId() const override;

	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
	
public:
	static UReplication_Subsystem_Core* Get(UWorld* world);
	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void AddChannels(const FString& id, double priority);

	TSet<UReplication_DataChannel*> GetChannels(const FString& id) const;

	bool IsSending(const FString& id) const;

	/*
	* \brief Sends data to channels of particular ID; thread-safe
	* \param id ID of channels 
	* \param data Data to send
	*/
	void SendData(const FString& id, const TArray<uint8>& data);

	/*
	* \brief Sends data to channels of particular ID; thread-safe
	* \param id ID of channels
	* \param data Data to send
	* \param onlySendTo Only send to channels of PlayerControllers in this set; empty means send to all
	* \param excludeFromSend Do not send to channels of PlayerControllers in this set; empty means send to all
	*/
	void SendData(const FString& id, const TArray<uint8> data, const TSet<APlayerController*>& onlySendTo, const TSet<APlayerController*>& excludeFromSend);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void AddSortedID(const FString& id, double priority);

	UReplication_DataChannel* CreateChannel(UNetConnection* netConnection, const FString& id, double priority);

	void AddClientChannel(UReplication_DataChannel* channel);

	double GetPriorityFromID(const FString& id) const;
	

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleGameModePostLogin(AGameModeBase* gameModeBase, APlayerController* playerController);

	void HandleGameModeLogout(AGameModeBase* gameModeBase, AController* controller);

	void HandleDataReceived(const TArray<uint8>& data, UReplication_DataChannel* channel);
};