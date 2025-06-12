#pragma once

#include "Game.h"
#include "VH_DataSync.h"
#include "Game_EntityDB.h"
#include "Game_DataSync.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_DataSync : public UVH_DataSync
{
    GENERATED_BODY()

public:
    UGame_DataSync();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnChangesReceived);

	UPROPERTY(BlueprintAssignable)
	FOnChangesReceived OnChangesReceived;

    // destroys actors and delete entries from database that are a part of this datasync
    virtual void Unload() override;

	/**
	 * Calls OnChangesReceived delegate if any functions have been bounds
	 */
	virtual void ChangesReceived() override;

protected:
	virtual void RegisterFile(const FString& fullPathToFile) override;

    virtual void Notify(const FString& message, float duration) const override;

    virtual bool IsFileRegistered(const FString& fullPathToFile) const override;

	virtual void DeleteFromDatabase(const FString& entityUID, const FString& classUID) override;
};