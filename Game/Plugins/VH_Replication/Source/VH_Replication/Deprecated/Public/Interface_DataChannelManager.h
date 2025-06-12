#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_DataChannelManager.generated.h"

class UVH_DataChannelManager;

UINTERFACE(Blueprintable)
class UInterface_DataChannelManager : public UInterface
{
    GENERATED_BODY()
};

class VH_REPLICATION_API IInterface_DataChannelManager
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------
public:
	virtual UVH_DataChannelManager* GetDCM(int32 id) = 0;

	virtual bool GetChannelReady(int32 id) = 0;

	virtual void SetChannelReady(int32 id, bool bReady) = 0;
};
