#pragma once

// Parent Includes
#include "HAL/RunnableThread.h"

// Engine Includes
#include "HAL/Runnable.h"
#include "HAL/ThreadSafeBool.h"
#include "HAL\CriticalSection.h"

#include "vlcpp/vlc.hpp"

class FGame_VideoPlayer_VLC_Thread : public FRunnable
{
    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
	bool bQueueVideoEndedDelegate;

	bool bQueueAspectDelegate;

	FCriticalSection* CritSection;

	TArray<uint8> FramePixels;

private:
    bool bStopping;

    bool bReceivedAspectRatio;

    float AspectRatio;

    FThreadSafeBool bPendingClean;

    FRunnableThread* Thread;

    FString URL;

	FString NewURL;

    libvlc_instance_t* VLC_Instance;

    libvlc_media_player_t* VLC_MediaPlayer;

	libvlc_event_manager_t* VLC_EventManager;

	int32 CachedVolume;

    double DurationSeconds;


    // ---------------------------------
    // --- Constructors
    // ---------------------------------

public:
    FGame_VideoPlayer_VLC_Thread();

    virtual ~FGame_VideoPlayer_VLC_Thread();


    // ---------------------------------
    // --- Inherited
    // ---------------------------------

public:
    virtual bool Init() override;

    virtual uint32 Run() override;

    virtual void Stop() override;

    virtual void Exit() override;


    // ---------------------------------
    // --- API
    // ---------------------------------

public:
    void SetURL(const FString& url);

    int32 GetVolume() const;

    void SetVolume(int32 volume);

    void SetPause(bool bPause);

    bool IsPaused() const;

    void PlayVideo();

	float GetAspectRatio() const;

	bool IsAspectRatioSet() const;

    double GetSecondsElapsed() const;

    void SetSecondsElapsed(double secondsElapsed);
   

    // ---------------------------------
    // --- Implementation
    // ---------------------------------

private:
	void CleanupVLC();
};