#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// Generated Includes
#include "Keyboard_Subsystem_Core.generated.h"

class UKeyboard_Subsystem_Core_Settings;

UCLASS()
class VH_KEYBOARD_API UKeyboard_Subsystem_Core : public UWorldSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FKeyboardSpawnDestroy, bool, bSpawn, AActor*, keyboardContainer);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> DefaultKeyboardClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, TSubclassOf<AActor>> KeyboardClassMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ECollisionChannel> KeyboardCollisionChannel;

	UPROPERTY(BlueprintAssignable)
	FKeyboardSpawnDestroy OnKeyboardSpawnDestroy;

private:
	UPROPERTY()
	AActor* Keyboard;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UKeyboard_Subsystem_Core();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UKeyboard_Subsystem_Core* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* outer) const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void UpdateSettings(TSubclassOf<UKeyboard_Subsystem_Core_Settings> settingsClass);

	UFUNCTION(BlueprintCallable)
	AActor* CreateKeyboardAtTransform(const FTransform& transform);

	UFUNCTION(BlueprintCallable)
	AActor* CreateKeyBoardForObject(UObject* object);

	UFUNCTION(BlueprintCallable)
	AActor* CreateKeyboardByClassAtTransform(UClass* keyboardClass, const FTransform& transform);

	UFUNCTION(BlueprintCallable)
	AActor* CreateKeyboardByClassForObject(UClass* keyboardClass, UObject* object);

	UFUNCTION(BlueprintPure)
	bool IsKeyboardOpen() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void UpdateSettings(const UKeyboard_Subsystem_Core_Settings* settings);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleKeyboardDestroyed(AActor* actor);
};