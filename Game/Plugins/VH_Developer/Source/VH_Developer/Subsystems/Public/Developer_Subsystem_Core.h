#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Engine Includes
#include "Tickable.h"

// Generated Includes
#include "Developer_Subsystem_Core.generated.h"


// ---------------------------------
// --- Enums
// ---------------------------------

/*
 * This enum relates to the hardware-centric displays and input interfaces that the player uses.
 *   'Desktop' implies 2D displays with keyboard/mouse/gamepad/touchscreen interaction.
 *   'VR' implies a HMD (Head-Mounted Display) with hand controllers (or in some cases, hardware-tracked hands).
 *   'VREmulation' implies 2D displays, but using the keyboard/mouse/etc to manipulate emulated VR HMD and hand controllers.
 */
UENUM(BlueprintType)
enum class EHardwareInterfaceMode : uint8
{
	Unknown,
	Desktop,
	VR,
	VREmulation,
};

class UVH_GameSettings;
struct IConsoleCommand;

UCLASS()
class VH_DEVELOPER_API UDeveloper_Subsystem_Core : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHardwareInterfaceModeChanged, EHardwareInterfaceMode, newMode, EHardwareInterfaceMode, previousMode);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnHardwareInterfaceModeChanged OnHardwareInterfaceModeChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EHardwareInterfaceMode DefaultHardwareInterfaceMode;

private:
	EHardwareInterfaceMode HardwareInterfaceMode;

	TArray<IConsoleCommand*> ConsoleCommands;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Subsystem_Core();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UDeveloper_Subsystem_Core* Get(UWorld* world = nullptr);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetHardwareInterfaceMode(EHardwareInterfaceMode newMode);

	UFUNCTION(BlueprintPure)
	EHardwareInterfaceMode GetHardwareInterfaceMode() const;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

public:
	void ProcessCommandLineParams(const FString& commandLine, const TArray<FString>& tokens, const TArray<FString>& switches, const TArray<FString>& args);


	// ---------------------------------
	// --- Debug/Testing
	// ---------------------------------

public:
	UFUNCTION(Exec)
	void Test_SetHardwareInterfaceMode(const TArray<FString>& arguments);
};