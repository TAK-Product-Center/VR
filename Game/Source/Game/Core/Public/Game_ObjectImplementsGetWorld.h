#pragma once

// VH Plugin Includes
#include "Developer_Statics.h"

// Generated Includes
#include "Game_ObjectImplementsGetWorld.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_ObjectImplementsGetWorld : public UObject
{
	GENERATED_BODY()

public:
	class UWorld* GetWorld() const { return UDeveloper_Statics::GetVHWorld(); }
};