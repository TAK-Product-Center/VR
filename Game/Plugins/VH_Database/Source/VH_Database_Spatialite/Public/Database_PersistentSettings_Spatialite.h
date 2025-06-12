#pragma once

// Parent Includes
#include "Developer_PersistentSettings.h"

// Module Includes
#include "Database_Spatialite.h"

// Generated Includes
#include "Database_PersistentSettings_Spatialite.generated.h"

UCLASS()
class VH_DATABASE_SPATIALITE_API UDatabase_PersistentSettings_Spatialite : public UDeveloper_PersistentSettings
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FString FullPathToDatabase;

	UPROPERTY()
	UDatabase_Spatialite* SpatialiteDB;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDatabase_PersistentSettings_Spatialite(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginDestroy() override;

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

	virtual void RemoveSetting(const FString& settingName) override;

	virtual TSet<FString> GetAllSettings() const override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------
	 
public:
	void Connect(const FString& fullPathToDatabase);
	 

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool SyncQuery(const FString& query) const;
	bool SyncQuery(const FString& query, SpatialiteResults& results) const;

	SpatialiteResults FindSetting(const FString& settingName) const;

	void InsertOrUpdateSettingsDB(const FString& settingName, const FString& settingValue);
};