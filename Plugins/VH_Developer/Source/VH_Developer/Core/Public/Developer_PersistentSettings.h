#pragma once

// Parent Includes
#include "UObject/Object.h"

// Generated Includes
#include "Developer_PersistentSettings.generated.h"

UCLASS(Abstract, Blueprintable)
class VH_DEVELOPER_API UDeveloper_PersistentSettings : public UObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStringSettingStored, const FString&, settingName, const FString&, value);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBoolSettingStored, const FString&, settingName, bool, bValue);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIntSettingStored, const FString&, settingName, int32, value);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDoubleSettingStored, const FString&, settingName, double, value);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FStringSettingStored OnStringSettingStored;

	UPROPERTY(BlueprintAssignable)
	FBoolSettingStored OnBoolSettingStored;

	UPROPERTY(BlueprintAssignable)
	FIntSettingStored OnIntSettingStored;

	UPROPERTY(BlueprintAssignable)
	FDoubleSettingStored OnDoubleSettingStored;

	/* pattern to generate default setting key using {settingName}; ex: Default{settingName} */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FString DefaultSettingPattern;

	/* value returned when get missing string setting */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FString MissingSettingValueString;

	/* value returned when get missing bool setting */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool MissingSettingValueBool;

	/* value returned when get missing int setting */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 MissingSettingValueInt;

	/* value returned when get missing double setting */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	double MissingSettingValueDouble;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_PersistentSettings(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	virtual bool HasSetting(const FString& settingName) const;

	UFUNCTION(BlueprintCallable)
	bool HasDefaultSetting(const FString& settingName) const;

	/*
	 * \brief Get a string setting's value.
	 * \param settingName The setting's name.
	 * \return The setting's value. If not found, its "default" value is returned instead.
	 */
	UFUNCTION(BlueprintCallable)
	virtual FString GetSettingString(const FString& settingName, bool bFallbackToDefault = true) const;

	/*
	 * \brief Get a boolean setting's value.
	 * \param settingName The setting's name.
	 * \return The setting's value. If not found, its "default" value is returned instead.
	 */
	UFUNCTION(BlueprintCallable)
	virtual bool GetSettingBool(const FString& settingName, bool bFallbackToDefault = true) const;

	/*
	 * \brief Get a integer setting's value.
	 * \param settingName The setting's name.
	 * \return The setting's value. If not found, its "default" value is returned instead.
	 */
	UFUNCTION(BlueprintCallable)
	virtual int32 GetSettingInt(const FString& settingName, bool bFallbackToDefault = true) const;

	/*
	 * \brief Get a double setting's value.
	 * \param settingName The setting's name.
	 * \return The setting's value. If not found, its "default" value is returned instead.
	 */
	UFUNCTION(BlueprintCallable)
	virtual double GetSettingDouble(const FString& settingName, bool bFallbackToDefault = true) const;

	/*
	 * \brief Store/update a string setting's current value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreSettingString(const FString& settingName, const FString& settingValue);

	/*
	 * \brief Store/update a boolean setting's current value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreSettingBool(const FString& settingName, bool settingValue);

	/*
	 * \brief Store/update an integer setting's current value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreSettingInt(const FString& settingName, int32 settingValue);

	/*
	 * \brief Store/update a double setting's current value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreSettingDouble(const FString& settingName, double settingValue);

	/*
	 * \brief Get a string setting's default value.
	 * \param settingName The setting's name.
	 * \return The setting's default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual FString GetDefaultSettingString(const FString& settingName) const;

	/*
	 * \brief Get a boolean setting's default value.
	 * \param settingName The setting's name.
	 * \return The setting's default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual bool GetDefaultSettingBool(const FString& settingName) const;

	/*
	 * \brief Get an integer setting's default value.
	 * \param settingName The setting's name.
	 * \return The setting's default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual int32 GetDefaultSettingInt(const FString& settingName) const;

	/*
	 * \brief Get a double setting's default value.
	 * \param settingName The setting's name.
	 * \return The setting's default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual double GetDefaultSettingDouble(const FString& settingName) const;

	/*
	 * \brief Store/update a string setting's default value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreDefaultSettingString(const FString& settingName, const FString& settingValue);

	/*
	 * \brief Store/update a boolean setting's default value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreDefaultSettingBool(const FString& settingName, bool settingValue);

	/*
	 * \brief Store/update an integer setting's default value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreDefaultSettingInt(const FString& settingName, int32 settingValue);

	/*
	 * \brief Store/update a double setting's default value.
	 * \param settingName The setting's name.
	 * \param settingValue The setting's new default value.
	 */
	UFUNCTION(BlueprintCallable)
	virtual void StoreDefaultSettingDouble(const FString& settingName, double settingValue);

	/// @brief Removes setting with name equal to settingName
	UFUNCTION(BlueprintCallable)
	virtual void RemoveSetting(const FString& settingName);

	/// @brief Returns TSet with all setting names
	UFUNCTION(BlueprintCallable)
	virtual TSet<FString> GetAllSettings() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	/*
	 * \brief Generate the setting's default name.
	 * \param settingName The setting's root name.
	 * \return The setting's default name.
	 */
	FString GetDefaultSettingName(const FString& settingName) const;

	virtual FString GetSettingStringInternal(const FString& settingName) const;
	
	virtual bool GetSettingBoolInternal(const FString& settingName) const;
	
	virtual int32 GetSettingIntInternal(const FString& settingName) const;
	
	virtual double GetSettingDoubleInternal(const FString& settingName) const;

	virtual void StoreSettingStringInternal(const FString& settingName, const FString& settingValue);
	
	virtual void StoreSettingBoolInternal(const FString& settingName, bool settingValue);
	
	virtual void StoreSettingIntInternal(const FString& settingName, int32 settingValue);
	
	virtual void StoreSettingDoubleInternal(const FString& settingName, double settingValue);
};