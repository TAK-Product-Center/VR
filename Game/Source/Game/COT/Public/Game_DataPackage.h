#pragma once

#include "Game.h"
#include "VH_DataPackage.h"
#include "Game_DataPackage.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_DataPackage : public UVH_DataPackage
{
    GENERATED_BODY()

public:
    UGame_DataPackage();

    virtual void SetVisibility(bool bVisibleArg) override;
};