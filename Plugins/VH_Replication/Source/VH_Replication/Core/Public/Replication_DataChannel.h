#pragma once

// Parent Includes
#include "Engine/Channel.h"

// Generated Includes
#include "Replication_DataChannel.generated.h"

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class EReplicationDataType : uint8
{
	InitialParameters,
	Data
};

class UReplication_Subsystem_Core;

UCLASS(Transient, CustomConstructor)
class VH_REPLICATION_API UReplication_DataChannel : public UChannel
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Delegates 
	// ---------------------------------

private:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FDataReceived, const TArray<uint8>&, UReplication_DataChannel*);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	FDataReceived OnDataReceived;

	UReplication_Subsystem_Core* ReplicationSubsystem;

private:
	TArray<uint8> SendBuffer;

	TArray<uint8> ReceiveBuffer;
	
	int32 ExpectedReceiveSizeInBytes;

	int32 SendIndex;

	FCriticalSection SendBufferLock;

	/* ID from Replication_Subsystem_Core; multiple channels can have same OwnerID */
	FString OwnerID;

	/* Priority from Replication_Subsystem_Core; multiple channels can have same Priority */
	double Priority;
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UReplication_DataChannel(const FObjectInitializer& objectInitializer = FObjectInitializer::Get());


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual FString Describe() override;

	virtual void ReceivedBunch(FInBunch& bunch) override;

	virtual bool CanStopTicking() const override;

	virtual void Tick() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void SendData(const TArray<uint8>& data);

	bool IsSending() const;

	void ManualTick(float deltaSeconds);

	void SetInitialParameters(const FString& id, double priority);

	FString GetOwnerID() const;

	double GetPriority() const;

	FString ToString() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void SendDataInternal(EReplicationDataType dataType, const TArray<uint8>& data);

	void ProcessReceivedData();
};
