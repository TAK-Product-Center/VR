#pragma once

// Parent Includes
#include "UObject/Object.h"
#include "Tickable.h"

// Module Includes
#include "SessionPlayback_Subsystem_Core.h"

// Generated Includes
#include "SessionPlayback_Impl.generated.h"

UCLASS(Abstract)
class VH_SESSIONPLAYBACK_API USessionPlayback_Impl : public UObject, public FTickableGameObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	USessionPlayback_Impl();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	EPlaybackStatus PlaybackStatus;

	float PlaybackRate;

	float SecondsPassed;

	float PlaybackDuration;

	
	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------

public:
	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;

	virtual TStatId GetStatId() const override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Loads playback file from disk
	* \param fullPathToFile Full path to playback file on disk
	* \param playbackDuration Populated with duration of playback in seconds
	* \param error Populated with error message when load fails
	* \return True on successful load
	*/
	bool LoadPlayback(const FString& fullPathToFile, float& playbackDuration, FString& error);

	/*
	* \brief Unload and cleanup playback; call when user is finished with playback session
	*/
	void UnloadPlayback();
	
	/*
	* \brief Sets the playback rate; ex: -2 means play in reverse at 2x speed, 0 means pause
	* \param playbackRate Rate to set
	*/
	void SetPlaybackRate(float playbackRate);

	/*
	* \brief Returns playback rate
	* \return Playback rate
	*/
	float GetPlaybackRate() const;

	/*
	* \brief Returns playback duration in seconds
	* \return Playback duration
	*/
	float GetPlaybackDuration() const;

	/*
	* \brief Sets the seconds passed in the session playback
	* \param secondsPassed Number of seconds passed
	*/
	void SetSecondsPassed(float secondsPassed);

	/*
	* \brief Returns number of seconds passed in the session playback
	* \return Number of seconds passed
	*/
	float GetSecondsPassed() const;

	/*
	* \brief Starts recording playback
	* \param fullPathToFile Full path to local file to save playback
	* \return True if successfully started recording playback
	*/
	bool StartRecord(const FString& fullPathToFile);

	/*
	* \brief Stops recording playback
	*/
	void StopRecord();

	/*
	* \brief Returns status of playback
	* \return Playback status
	*/
	EPlaybackStatus GetPlaybackStatus() const;

	/*
	* \brief Called when SessionPlayback_Subsystem_Core is set to use this implementation
	*/
	void SetAsImplementation();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void SetPlaybackStatus(EPlaybackStatus status);

private:
	USessionPlayback_Subsystem_Core* GetPlaybackSubsystem() const;

	virtual bool PostLoadPlayback(const FString& fullPathToFile, float& playbackDuration, FString& error)  PURE_VIRTUAL(USessionPlayback_Impl, return false;);

	virtual void PostUnloadPlayback(); 

	virtual void PostTick(float deltaSeconds);

	virtual void PostSetSecondsPassed(float secondsPassed); 

	virtual void PostStartRecord(const FString & fullPathToFile);

	virtual void PostStopRecord();

	virtual void PostSetPlaybackRate(float playbackRate);

	virtual void PostSetAsImplementation();
};