#pragma once

#include "Game_MUCComponent.h"
#include "Game_MUCComponent_Database.generated.h"

class UGame_MUCTransferLog;

UCLASS(Blueprintable)
class GAME_API UGame_MUCComponent_Database : public UGame_MUCComponent
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_MUCComponent_Database();

	// ---------------------------------
	// --- Delegates
	// ---------------------------------
private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMUCInsertOrUpdate, const FSpatialiteResults_BP&, results);

	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	UPROPERTY(BlueprintAssignable)
	FMUCInsertOrUpdate OnMUCInsertOrUpdateReceived;

	UPROPERTY(BlueprintAssignable)
	FMUCInsertOrUpdate OnMUCInsertOrUpdateSent;

private:
	UPROPERTY()
	TArray<UGame_MUCTransferLog*> SendLog;

	UPROPERTY()
	TArray<UGame_MUCTransferLog*> ReceiveLog;

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get MUCComponent Database ID"))
	static const int32 GetDataChannelManagerID();

	UFUNCTION(BlueprintPure)
	static bool AllowGlobalDelete(const FName& entityUID);

	UFUNCTION(BlueprintCallable)
	static void MUCDelete(const FName& entityUID, bool bGlobal);

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual void InitializeComponent() override;

	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	virtual void HandleReceivedData(const TArray<uint8>& receivedData) override;

	virtual FString GetTaskID(APlayerController* playerController, bool bSend) const override;

	virtual FString GetTaskDescription(APlayerController* playerController, bool bSend) const override;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	void SendDBUpdateToClients(const FSpatialiteResults_BP& results);

	void SendDBDeleteToClients(const FSpatialiteResults_BP& results);

	void AddSendLog(const SpatialiteResult& result);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<UGame_MUCTransferLog*> GetSendLog() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<UGame_MUCTransferLog*> GetReceiveLog() const;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	bool AllowGlobalDelete_Internal(const FName& entityUID);

	void SetReplicatesUpdates(bool shouldReplicateUpdates);

	void SendData(const FSpatialiteResults_BP& results, bool bToServer, EMUCDataType dataType);

	void PushUpdateToOtherClients(const FSpatialiteResults_BP& results, EMUCDataType dataType, int32 excludePlayerID);

	void DeleteMUCEntityDB() const;

	void DeleteStaleDBs() const;

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	UFUNCTION()
	void SendDBUpdateToServer(const FSpatialiteResults_BP& results);
};

