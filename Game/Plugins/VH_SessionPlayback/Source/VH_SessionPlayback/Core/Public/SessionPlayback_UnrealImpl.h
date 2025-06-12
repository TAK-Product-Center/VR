#pragma once

// Parent Includes
#include "SessionPlayback_Impl.h"

// Generated Includes
#include "SessionPlayback_UnrealImpl.generated.h"

class UReplaySubsystem;

UCLASS()
class VH_SESSIONPLAYBACK_API USessionPlayback_UnrealImpl : public USessionPlayback_Impl
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	USessionPlayback_UnrealImpl();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

private:
	virtual bool PostLoadPlayback(const FString& fullPathToFile, float& playbackDuration, FString& error) override;

	virtual void PostUnloadPlayback() override;

	virtual void PostTick(float deltaSeconds) override;

	virtual void PostSetSecondsPassed(float secondsPassed) override;

	virtual void PostStartRecord(const FString & fullPathToFile) override;

	virtual void PostStopRecord() override;

	virtual void PostSetPlaybackRate(float playbackRate) override;

	virtual void PostSetAsImplementation() override;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void SetPaused(bool bPaused) const;

	UReplaySubsystem* GetReplaySubsystem() const;
};
