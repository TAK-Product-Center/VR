
// Parent Includes
#include "Game_Tool.h"

// Generated Includes
#include "Game_Tool_DrumKeyboard.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Tool_DrumKeyboard : public AGame_Tool
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:

	virtual void TickUpdateBeam(float deltaSeconds) override;

	virtual void TickNonOwningBeamUpdate() override;
};