// Required includes
#include "Game.h"

// Engine Includes
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(Game);

class FVRTAKGameModuleImpl: public IModuleInterface
{
	virtual bool IsGameModule() const override
	{
		return true;
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, Game, "Game");