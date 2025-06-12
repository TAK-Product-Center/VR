#pragma once

// Parent Includes
#include "Components/ActorComponent.h"

// Engine Includes
#include "HAL/ThreadSafeCounter.h"

// Game Includes
#include "Database_Spatialite.h"

// Generated Includes
#include "Game_MUCComponent.generated.h"

class UVH_DataChannelManager;
class APlayerController;
class AGame_PlayerState;

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class EMUCDataType : uint8
{
	DT_Database,
	DT_InsertOrUpdate,
	DT_Delete,
	DT_RequestFileInfo,
	DT_FileInfo,
	DT_RequestFile,
	DT_PreFile,
	DT_File
};

struct FMD5Hash;

UCLASS(Blueprintable)
class GAME_API UGame_MUCComponent : public UActorComponent
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_MUCComponent();

	// ---------------------------------
	// --- Members
	// ---------------------------------
protected:
	FThreadSafeCounter DestroyCounter;

	UPROPERTY()
	UVH_DataChannelManager* DCM;

private:
	bool bChannelReady;

	TSet<FString> TaskIDs;

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	virtual bool IsReadyForFinishDestroy() override;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	UVH_DataChannelManager* GetDCM(int32 id);

	bool GetChannelReady();
	
	void SetChannelReady(bool bReady);

	virtual void CreateDCM(int32 id);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
protected:
	bool IsSafeToExecute();

	virtual FString GetTaskID(APlayerController* playerController, bool bSend) const;

	virtual FString GetTaskDescription(APlayerController* playerController, bool bSend) const;

private:
	void UpdateTasks(APlayerController* playerController, bool bSend, float pctComplete);

	virtual void PostServer_HandleChannelClosed(APlayerController* playerController) {}

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
private:
	UFUNCTION()
	virtual void HandleReceivedData(const TArray<uint8>& receivedData);

	UFUNCTION()
	void HandleClientSendProgress(float pctComplete);

	UFUNCTION()
	void HandleClientReceiveProgress(float pctComplete);

	UFUNCTION()
	void HandleServerSendProgress(APlayerController* playerController, float pctComplete);

	UFUNCTION()
	void HandleServerReceiveProgress(APlayerController* playerController, float pctComplete);

	UFUNCTION()
	void Server_HandleChannelClosed(APlayerController* playerController);
};
