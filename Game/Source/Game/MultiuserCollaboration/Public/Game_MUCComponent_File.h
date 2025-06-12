#pragma once

#include "Game_MUCComponent.h"
#include "Game_MUCComponent_File.generated.h"

struct FMD5Hash;

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT()
struct FPendingSend
{
	GENERATED_BODY()

	EMUCDataType DataType;

	UPROPERTY()
	APlayerController* PlayerController;

	FMD5Hash MD5Hash;

	FString FullPathToFile;
};

USTRUCT(BlueprintType)
struct FTransferInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FString FullPathToFile;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FString FileSize;
};

UCLASS(Blueprintable)
class GAME_API UGame_MUCComponent_File : public UGame_MUCComponent
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_MUCComponent_File();

	// ---------------------------------
	// --- Delegates
	// ---------------------------------
private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFileRequest, const FString&, hash, const FString&, filename, const FString&, fileSize);

	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	UPROPERTY(BlueprintAssignable)
	FFileRequest OnFileRequest;

private:
	TSet<FString> ClientRequestedFiles;

	UPROPERTY()
	TArray<FPendingSend> PendingSends;

	UPROPERTY()
	TMap<APlayerController*, FTransferInfo> SendInfos;

	UPROPERTY()
	TMap<FString, FTransferInfo> ReceiveInfos;

	FString ClientReceivingHash;

	TArray<FString> SentFiles;

	TArray<FString> ReceivedFiles;

	FThreadSafeCounter DestroyCounter;

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get MUCComponent File ID"))
	static const int32 GetDataChannelManagerID();

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual bool IsReadyForFinishDestroy() override;

	virtual void TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

	virtual FString GetTaskID(APlayerController* playerController, bool bSend) const override;

	virtual FString GetTaskDescription(APlayerController* playerController, bool bSend) const override;

	virtual void PostServer_HandleChannelClosed(APlayerController* playerController) override;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	UFUNCTION(BlueprintCallable)
	void ClientBeginTransfer(const FString& hash);

	UFUNCTION(BlueprintPure)
	TMap<FString, FTransferInfo> ClientGetReceiveInfos() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<FString> GetSentFiles() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<FString> GetReceivedFiles() const;

	void MUCInsertOrUpdateReceived(const SpatialiteResults& results);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	void SendFileInfoRequest(const FMD5Hash& md5Hash, const FString& fullPathToFile);

	void SendFileInfo(const FMD5Hash& md5Hash, int32 onlyPlayerID, const FString& fullPathToFile);

	void SendFileRequest(const FMD5Hash& md5Hash);

	void SendFile(const FMD5Hash& md5Hash, int32 onlyPlayerID, const FString& fullPathToFile);

	APlayerController* GetPlayerControllerFromPlayerID(int32 playerID) const;

	bool IsSafeToExecute();

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	virtual void HandleReceivedData(const TArray<uint8>& receivedData) override;
};
