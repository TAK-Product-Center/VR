#pragma once

// Parent Includes
#include "Engine/Channel.h"

// Generated Includes
#include "VH_DataChannel.generated.h"

class UVH_DataChannelManager;

UCLASS(transient, customConstructor)
class VH_REPLICATION_API UVH_DataChannel : public UChannel
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UVH_DataChannel(const FObjectInitializer& objectInitializer = FObjectInitializer::Get());

	// ---------------------------------
	// --- Delegates 
	// ---------------------------------
private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClientTransferProgress, float, pctComplete);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FServerTransferProgress, APlayerController*, playerController, float, pctComplete);

	// ---------------------------------
	// --- Members
	// ---------------------------------
public:
	UPROPERTY()
	FClientTransferProgress OnClientSendProgress;

	UPROPERTY()
	FClientTransferProgress OnClientReceiveProgress;

	UPROPERTY()
	FServerTransferProgress OnServerSendProgress;

	UPROPERTY()
	FServerTransferProgress OnServerReceiveProgress;

	TArray<uint8> SendBuffer;

	TArray<uint8> ReceiveBuffer;
	
	UPROPERTY()
	APlayerController* PlayerControllerOwner;

	UPROPERTY()
	UVH_DataChannelManager* DCM;

	int32 ManagerID;

	float ProgressPercentDelta;

private:
	int32 PendingReceiveSize;

	int32 SendIndex;

	FCriticalSection SendBufferLock;

	float CachedSendPercent;

	float CachedReceivePercent;

	UPROPERTY()
	UObject* DataHandler;

	// ---------------------------------
	// --- Inherited Methods
	// ---------------------------------
public:
	virtual FString Describe() override;

	virtual void ReceivedBunch(FInBunch& bunch) override;

	virtual bool CanStopTicking() const override;

	virtual void Tick() override;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------
public:
	void SendData(const TArray<uint8>& data);

	float GetCachedSendPercent() const;

	float GetCachedReceivePercent() const;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	void HandleReceivedData();

	void SetDCMFromDataHandler();
};
