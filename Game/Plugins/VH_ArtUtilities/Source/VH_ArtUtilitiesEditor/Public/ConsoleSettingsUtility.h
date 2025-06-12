#pragma once

// Parent Includes
#include "Kismet/BlueprintFunctionLibrary.h"

// Engine Includes
#include "Blueprint/UserWidget.h"
#include "ConsoleSettingsUtility.generated.h"

class UConsoleCommandSave;


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FSettingsGroup
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayName;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

	FSettingsGroup();

	FSettingsGroup(int inID, FString inDisplayName);
};

USTRUCT(BlueprintType)
struct FConsoleCommand
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EditorName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CommandBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Tooltip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Value;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

	FConsoleCommand();

	FConsoleCommand(int inID, FString inDisplayName, FString inCommandBody, FString inTooltip, FString inValue);
};

// ---------------------------------
// --- Class
// ---------------------------------

UCLASS(BlueprintType)
class UConsoleCommandList : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	TArray<FConsoleCommand> Commands;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

	/*
	 * Default constructor, creates an empty set of commands.
	 */
	UConsoleCommandList();

	/*
	 * Constructor, copies in the argument commands.
	 */
	UConsoleCommandList(TArray<FConsoleCommand> inCommands);

	// ---------------------------------
	// --- API
	// ---------------------------------

	/*
	 * Returns a reference to a specific command
	 */
	UFUNCTION(BlueprintPure)
	bool GetByRef(int index, FConsoleCommand& foundCommand);

};



/*
 * Console Settings Utility allows users to create groups of console commands that are executed upon button press and beginning play.
 */
UCLASS(Blueprintable, BlueprintType)
class UConsoleSettingsUtilityFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:

	/*
	 * Authoritative source of the save slot name for the game.
	 * @return The string "ConsoleCommands"
	 */
	UFUNCTION(BlueprintPure)
	static FString GetSaveSlotName() { return "ConsoleCommands"; }

	/*
	 * Tries to access the current world and retun its name.
	 * @return Map name, empty if world is not found.
	 */
	UFUNCTION(BlueprintPure)
	static FString TryGetMapName();

	/*
	 * Saves the provided SaveGame in the predefined slot
	 * @return The SaveGameToSlot return value
	 */
	UFUNCTION(BlueprintCallable)
	static bool SaveCommands(UConsoleCommandSave* save);

	/*
	 * Saves the provided SaveGame in the predefined slot
	 * @return The SaveGameToSlot return value
	 */
	UFUNCTION(BlueprintCallable)
	static UConsoleCommandSave* LoadCurrentCommandsSave();
	
};
