#pragma once

// Parent Includes
#include "Developer_PersistentSettings.h"

// Generated Includes
#include "Developer_PersistentSettings_XML.generated.h"

class FXmlNode;

UCLASS()
class VH_DEVELOPER_API UDeveloper_PersistentSettings_XML : public UDeveloper_PersistentSettings
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FString FullPathToXMLFile;

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


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	 * \brief Set the GameSettings filename.  If already exists, this will also initialize the settings to the file's contents.
	 * \param fullPathToXMLFile The full path to the GameSettings file.
	 */
	UFUNCTION(BlueprintCallable)
	void SetFilename(const FString& fullPathToXMLFile);

	UFUNCTION(BlueprintPure)
	FString GetFullPathToXMLFile() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	bool WriteToDisk() const;

private:
	void PopulateToXML(FXmlNode* rootNode) const;

	virtual void PostPopulateToXML(FXmlNode* rootNode) const;

	void PopulateFromXML(FXmlNode* rootNode);

	virtual void PostPopulateFromXML(FXmlNode* rootNode);
};
