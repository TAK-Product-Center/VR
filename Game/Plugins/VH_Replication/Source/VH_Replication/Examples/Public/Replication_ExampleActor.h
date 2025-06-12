#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Replication_ExampleActor.generated.h"

class UReplication_DataChannel;

UCLASS(Blueprintable, BlueprintType)
class VH_REPLICATION_API AReplication_ExampleActor : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	UPROPERTY(ReplicatedUsing = OnRep_ReplicationID)
	FString ReplicationID;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AReplication_ExampleActor(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_ReplicationID();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void CreateDataChannels();

	void SendData(const FString& stringToSend, int32 intToSend, double doubleToSend, const TSet<APlayerController*>& onlySendTo, const TSet<APlayerController*>& excludeFromSend);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleChannelCreated(UReplication_DataChannel* channel);

	void HandleDataReceived(const TArray<uint8>& data, UReplication_DataChannel* channel);
};