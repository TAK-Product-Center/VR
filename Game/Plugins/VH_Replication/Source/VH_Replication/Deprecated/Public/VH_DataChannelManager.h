#pragma once

#include "VH_DataChannel.h"
#include "VH_DataChannelManager.generated.h"

UCLASS()
class VH_REPLICATION_API UVH_DataChannelManager : public UObject
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Delegates 
	// ---------------------------------
private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDataReceived, const TArray<uint8>&, data);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerChannelCreated, APlayerController*, pc);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerChannelClosed, APlayerController*, pc);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClientTransferProgress, float, pctComplete);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FServerTransferProgress, APlayerController*, playerController, float, pctComplete);

	// ---------------------------------
	// --- Members
	// ---------------------------------
public:
	UPROPERTY()
	AActor* OwningActor;

	int32 ID;

	UPROPERTY()
	FDataReceived OnDataReceived;

	UPROPERTY()
	FServerChannelCreated OnServerChannelCreated;

	UPROPERTY()
	FServerChannelCreated OnServerChannelClosed;

	UPROPERTY()
	FClientTransferProgress OnClientSendProgress;

	UPROPERTY()
	FClientTransferProgress OnClientReceiveProgress;

	UPROPERTY()
	FServerTransferProgress OnServerSendProgress;

	UPROPERTY()
	FServerTransferProgress OnServerReceiveProgress;

	// only populated on client 
	UVH_DataChannel* Channel_ClientToServer;

protected:
	// only populated on server 
	TArray<UVH_DataChannel*> Channels_ServerToClient;

	TArray<APlayerController*> QueuedPCs;

private:
	/* if true, compress data before sending when original data is less than or equal to MaxCompressionBytes */
	bool bCompress;

	int32 MaxCompressionBytes;

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual class UWorld* GetWorld() const override;

	virtual void BeginDestroy() override;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	UVH_DataChannelManager(const FObjectInitializer& objectInitializer);

	virtual void Initialize(int32 id, AActor* owningActor);

	void SetCompression(bool bShouldCompress, int32 maxCompressionBytes);

	void SetPrioritizeVOIP(bool bShouldPrioritizeVOIP);

	virtual void PostLogin(APlayerController* pc);

	virtual void Logout(APlayerController* pc);

	virtual bool IsSendingClientToServer();

	virtual bool IsSendingServerToClient(APlayerController* pc);

	virtual void SendDataToServer(const TArray<uint8>& data);

	virtual void BroadcastDataToClients (const TArray<uint8>& data, int32 onlyPlayerID = -1, int32 excludePlayerID = -1);

	virtual void SetProgressDelegates(UVH_DataChannel* channel);

	bool ShouldCompress(int32 dataSizeInBytes) const;

	virtual bool HasChannelFor(APlayerController* pc);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
protected:
	virtual void HandlePeriodicChecks();

	virtual bool CreateChannel_ServerToClient(APlayerController* pc);

	bool ValidServerChannel(UVH_DataChannel* channel) const;

	void Compress(const TArray<uint8>& uncompressedData, TArray<uint8>& compressedData) const;

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	UFUNCTION()
	void HandleClientSendProgress(float pctComplete);

	UFUNCTION()
	void HandleClientReceiveProgress(float pctComplete);

	UFUNCTION()
	void HandleServerSendProgress(APlayerController* playerController, float pctComplete);

	UFUNCTION()
	void HandleServerReceiveProgress(APlayerController* playerController, float pctComplete);
};