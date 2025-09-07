#pragma once

#include "UObject/Interface.h"

#include "Database_Spatialite.h"

#include "Interface_SessionPlaybackHandler.generated.h"

/*
* \brief Handles adding events to playback database and applying events from the playback database
*/

UINTERFACE(Blueprintable)
class GAME_API UInterface_SessionPlaybackHandler : public UInterface
{
    GENERATED_BODY()
};

class GAME_API IInterface_SessionPlaybackHandler
{
    GENERATED_BODY()

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	/*
	* \brief Returns handler UID
	* \return Handler UID FString
	*/
	UFUNCTION(BlueprintNativeEvent)
	FString GetHandlerUID() const;

	UFUNCTION(BlueprintNativeEvent)
	void SetImpl(UGame_SessionPlayback_Impl* impl);

	/*
	* \brief Applies event (row) from database
	*/
	UFUNCTION(BlueprintNativeEvent)
	void ApplyEvent(const FSpatialiteResult_BP& result);

	/*
	* \brief Called when start recording a session playback
	*/
	UFUNCTION(BlueprintNativeEvent)
	void StartRecord();

	/*
	* \brief Called when stop recording a session playback
	*/
	UFUNCTION(BlueprintNativeEvent)
	void StopRecord();

	/*
	* \brief Called when scrub occurs
	* \param secondsPassed Scrub set to secondsPassed
	*/
	UFUNCTION(BlueprintNativeEvent)
	void SetSecondsPassed(float secondsPassed);

	/*
	* \brief Called when playback is unloaded
	*/
	UFUNCTION(BlueprintNativeEvent)
	void UnloadPlayback();

	/*
	* \brief Called during SetSecondsPassed to allow handlers to filter results (for performance)
	* \param results Results for SetSecondsPassed query; 0th result is most recent based on PlaybackRate
	*/
	UFUNCTION(BlueprintNativeEvent)
	void FilterSetSecondsPassedResults(FSpatialiteResults_BP& results);

	UFUNCTION(BlueprintNativeEvent)
	void AlterTimeDilation(float dilation);
};
