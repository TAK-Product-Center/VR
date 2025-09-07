
#pragma once

#include "GameFramework/SaveGame.h"
#include "ConsoleSettingsUtility.h"
#include "ConsoleCommandSave.generated.h"

// ---------------------------------
// --- Structs
// ---------------------------------

/*
 * Substitute for UConsoleCommandList whose data can be saved more easily.
 */
USTRUCT()
struct FSavedCommandsStruct
{
	GENERATED_BODY()
		
	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	/*
	 * FConsoleCommand datas to save.
	 */
	UPROPERTY()
	TArray<FConsoleCommand> Commands;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

	/*
	 * Default constructor, creates an empty set of commands.
	 */
	FSavedCommandsStruct();

	/*
	 * Constructor, copies in the argument commands.
	 */
	FSavedCommandsStruct(const TArray<FConsoleCommand>& inCommands);
};

	// ---------------------------------
	// --- Class
	// ---------------------------------

/**
 * Describes a save for the console commands for each setting and level
 */
UCLASS(Blueprintable, BlueprintType)
class UConsoleCommandSave : public USaveGame
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:

	/*
	 * Groups of commands
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FSettingsGroup> SettingGroups;

	/*
	 * Commands found in all groups
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FConsoleCommand> GeneralCommands;

	/*
	 * The ID of the most recently made group
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrentGroupID;

	/*
	 * The ID of the most recently made command
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrentCommandID;


private:
	/*
	 * The values of the commands found in each group.
	 */
	UPROPERTY(SaveGame)
	TMap<int32, FSavedCommandsStruct> PrivateGroupToGeneralCommands;
	/*
	 * The values of the commands found in specific groups.
	 */
	UPROPERTY(SaveGame)
	TMap<int32, FSavedCommandsStruct> PrivateGroupToSpecificCommands;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	/*
	 * Loads the provided SaveGame in the predefined slot
	 * @param InSettingGroups - The groups of commands to save.
	 * @param InGeneralCommands - The commands found in every group.
	 * @param InGroupToGeneralCommands - The values of the commands found in each group.
	 * @param InGroupToSpecificCommands - The specific commands in each group and their values.
	 * @param InCurrentGroupID - The ID of the most recently made group.
	 * @param InCurrentCommandID - The ID of the most recently made command.
	 */
	UFUNCTION(BlueprintCallable)
	void PopulateSaveGameVariables( TArray<FSettingsGroup> InSettingGroups,
									TArray<FConsoleCommand> InGeneralCommands,
									TMap<int32, UConsoleCommandList*> InGroupToGeneralCommands,
									TMap<int32, UConsoleCommandList*> InGroupToSpecificCommands,
									int32 InCurrentGroupID,
									int32 InCurrentCommandID);


	/*
	 * Saves the provided SaveGame in the predefined slot
	 * @param InSettingGroups - The groups of commands to save.
	 * @param InGeneralCommands - The commands cound in each group.
	 * @param InGroupToGeneralCommands - The values of the commands found in each group.
	 * @param InGroupToSpecificCommands - The specific commands in each group and their values.
	 * @param InCurrentGroupID - The ID of the most recently made group.
	 * @param InCurrentCommandID - The ID of the most recently made command.
	 */
	UFUNCTION(BlueprintCallable)
	void RetrieveSaveGameVariables( TArray<FSettingsGroup>& InSettingGroups,
									TArray<FConsoleCommand>& InGeneralCommands,
									TMap<int32, UConsoleCommandList*>& InGroupToGeneralCommands,
									TMap<int32, UConsoleCommandList*>& InGroupToSpecificCommands,
									int32& InCurrentGroupID,
									int32& InCurrentCommandID);
};
