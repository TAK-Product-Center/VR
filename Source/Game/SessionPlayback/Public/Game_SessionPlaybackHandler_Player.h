#pragma once

#include "Interface_SessionPlaybackHandler.h"
#include "VH_GeodeticCoord.h"

#include "Game_SessionPlaybackHandler_Player.generated.h"

class UGame_SessionPlayback_Impl;
class AGame_Pawn;
class AGame_SessionPlaybackAvatar;

UCLASS()
class GAME_API UGame_SessionPlaybackHandler_Player : public UObject, public IInterface_SessionPlaybackHandler
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_SessionPlaybackHandler_Player();

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
private:
	UPROPERTY()
	UGame_SessionPlayback_Impl* Implementation;

	UPROPERTY()
	TMap<int32, AGame_SessionPlaybackAvatar*> Avatars;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static FString GetHandlerUIDStatic();
	 
	 
	// ---------------------------------
	// --- Interface_SessionPlaybackHandler
	// ---------------------------------

public:
	virtual FString GetHandlerUID_Implementation() const;

	virtual void SetImpl_Implementation(UGame_SessionPlayback_Impl* impl);

	virtual void ApplyEvent_Implementation(const FSpatialiteResult_BP& result);

	virtual void StartRecord_Implementation();

	virtual void StopRecord_Implementation();

	virtual void SetSecondsPassed_Implementation(float secondsPassed);

	virtual void UnloadPlayback_Implementation();

	virtual void FilterSetSecondsPassedResults_Implementation(FSpatialiteResults_BP& results);


	// ---------------------------------
	// --- API
	// ---------------------------------
	 
public:
	void AddPawnLocationEvent(const AGame_Pawn* pawn, const FGeodeticCoord3D& coordinate) const;
	
	void AddHeadPositionEvent(const AGame_Pawn* pawn, const FQuat& rotation) const;

	void AddControllerOffsetEvent(const AGame_Pawn* pawn, const FString& controllerName, const FTransform& transform) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void DestroyAvatars();

	AGame_SessionPlaybackAvatar* GetAvatar(int32 playerID);

	TSubclassOf<AGame_SessionPlaybackAvatar> GetPlaybackAvatarClass() const;

	bool GetPlayerInfoFromPawn(const AGame_Pawn* pawn, int32& playerID, FString& callsign) const;
};