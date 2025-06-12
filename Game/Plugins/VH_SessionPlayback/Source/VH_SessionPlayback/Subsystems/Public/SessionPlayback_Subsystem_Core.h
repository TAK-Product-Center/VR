#pragma once

#include "Subsystems/GameInstanceSubsystem.h"

#include "SessionPlayback_Subsystem_Core.generated.h"

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EPlaybackStatus : uint8
{
	EPS_Idle,
	EPS_PlaybackInProgress,
	EPS_PlaybackFinished,
	EPS_PlaybackRecording
};

class USessionPlayback_Impl;

UCLASS()
class VH_SESSIONPLAYBACK_API USessionPlayback_Subsystem_Core : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	USessionPlayback_Subsystem_Core();


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlaybackRateUpdated, float, playbackRate);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlaybackStatusUpdated, EPlaybackStatus, status);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FPlaybackRateUpdated OnPlaybackRateUpdated;

	UPROPERTY(BlueprintAssignable)
	FPlaybackStatusUpdated OnPlaybackStatusUpdated;

private:
	UPROPERTY()
	USessionPlayback_Impl* Implementation;

	UPROPERTY()
	TMap<FString, USessionPlayback_Impl*> Implementations;

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	 
public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Sets the implementation to use
	* \param implementationID ID of implementation; should be same ID used when registering the implementation
	* \return True if successfully set implementation
	*/
	UFUNCTION(BlueprintCallable)
	bool SetImplementation(const FString& implementationID);

	/*
	* \brief Returns currently used implementation or nullptr if no implementation is set
	* \return current implementation
	*/
	UFUNCTION(BlueprintPure)
	USessionPlayback_Impl* GetImplementation() const;

	/*
	* \brief Registers an implementation
	* \param implemenationID ID of implementation; used later when setting the implementation
	* \param implementation Pointer to implementation object
	*/
	void RegisterImplementation(const FString& implementationID, USessionPlayback_Impl* implementation);

	/*
	* \brief Loads playback file from disk
	* \param fullPathToFile Full path to playback file on disk
	* \param playbackDuration Populated with duration of playback in seconds
	* \param error Populated with error message when load fails
	* \return True on successful load
	*/
	UFUNCTION(BlueprintCallable)
	bool LoadPlayback(const FString& fullPathToFile, float& playbackDuration, FString& error);

	/*
	* \brief Unload and cleanup playback; call when user is finished with playback session
	*/
	UFUNCTION(BlueprintCallable)
	void UnloadPlayback();
	
	/*
	* \brief Sets the playback rate; ex: 2 means play at 2x speed, 0 means pause
	*		 Negative playback rates not allowed in most implementations
	* \param playbackRate Rate to set
	*/
	UFUNCTION(BlueprintCallable)
	void SetPlaybackRate(float playbackRate);

	/*
	* \brief Returns playback rate
	* \return Playback rate
	*/
	UFUNCTION(BlueprintPure)
	float GetPlaybackRate() const;

	/*
	* \brief Returns playback duration in seconds
	* \return Playback duration
	*/
	UFUNCTION(BlueprintPure)
	float GetPlaybackDuration() const;

	/*
	* \brief Sets the seconds passed in the session playback
	* \param secondsPassed Number of seconds passed
	*/
	UFUNCTION(BlueprintCallable)
	void SetSecondsPassed(float secondsPassed);

	/*
	* \brief Returns number of seconds passed in the session playback
	* \return Number of seconds passed
	*/
	UFUNCTION(BlueprintPure)
	float GetSecondsPassed() const;

	/*
	* \brief Starts recording playback
	* \param fullPathToFile Full path to local file to save playback
	* \return True if successfully started recording playback
	*/
	UFUNCTION(BlueprintCallable)
	bool StartRecord(const FString& fullPathToFile);

	/*
	* \brief Stops recording playback
	*/
	UFUNCTION(BlueprintCallable)
	void StopRecord();

	/*
	* \brief Returns status of playback
	* \return Playback status
	*/
	UFUNCTION(BlueprintPure)
	EPlaybackStatus GetPlaybackStatus() const;

	/*
	* \brief Returns if playback is occurring
	* \return True if playback is occurring
	*/
	UFUNCTION(BlueprintPure)
	bool IsPlaying() const;

	
	// ---------------------------------
	// --- Debug/Testing
	// ---------------------------------

private:
	UFUNCTION(Exec)
	void Test_LoadSessionPlayback(const FString& fullPathToFile);

	UFUNCTION(Exec)
	void Test_RecordSessionPlayback(const FString& fullPathToFile);

	UFUNCTION(Exec)
	void Test_StopRecordSessionPlayback();
};