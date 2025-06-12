#pragma once

#include "GameFramework/Actor.h"
#include "VH_PluginActor.generated.h"

/**
 * Use this actor to perform plugin-specific setup that relies on an actor
 * All children of this class found in plugins are intended to be spawned immediately when the game starts
 * Those children may contain their own logic to perform UI Setup, spawn other actors in the world, etc.
 */
UCLASS()
class VH_PLUGINS_API AVH_PluginActor : public AActor
{
    GENERATED_BODY()

public:
    AVH_PluginActor();

};
