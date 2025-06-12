#pragma once

// Parent Includes
#include "Developer_PersistentSettings.h"

// Generated Includes
#include "Developer_PersistentSettings_Config.generated.h"

UCLASS(Config="Game")
class VH_DEVELOPER_API UDeveloper_PersistentSettings_Config : public UDeveloper_PersistentSettings
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	UPROPERTY(Config)
	TMap<FString, FString> SettingsMap;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool HasSetting(const FString& settingName) const override;

protected:
	virtual FString GetSettingStringInternal(const FString& settingName) const override;

	virtual bool GetSettingBoolInternal(const FString& settingName) const override;

	virtual int32 GetSettingIntInternal(const FString& settingName) const override;
	
	virtual double GetSettingDoubleInternal(const FString& settingName) const override;

	virtual void StoreSettingStringInternal(const FString& settingName, const FString& settingValue) override;

	virtual void StoreSettingBoolInternal(const FString& settingName, bool settingValue) override;

	virtual void StoreSettingIntInternal(const FString& settingName, int32 settingValue) override;

	virtual void StoreSettingDoubleInternal(const FString& settingName, double settingValue) override;
};
