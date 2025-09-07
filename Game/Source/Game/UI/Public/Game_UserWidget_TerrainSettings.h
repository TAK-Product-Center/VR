#pragma once

// Engine Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_TerrainSettings.generated.h"

class UCheckBox;
class UGame_UserWidget_TextInput;

UCLASS()
class GAME_API UGame_UserWidget_TerrainSettings : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UGame_UserWidget_TextInput* MinImageryZoomLevel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UGame_UserWidget_TextInput* MaxImageryZoomLevel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UGame_UserWidget_TextInput* MinHeightmapZoomLevel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UGame_UserWidget_TextInput* MaxHeightmapZoomLevel;
	
	UPROPERTY(BlueprintReadOnly, Category = "Check Boxs|Public", meta = (BindWidget))
	UCheckBox* EnableStreamingCheckBox;

	UPROPERTY(BlueprintReadWrite, Category = "User Widgets|Public")
	UUserWidget* ParentMenu;

protected:
	TMap<float, UCheckBox*> MenuSizeScales;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_TerrainSettings(const FObjectInitializer& ObjectInitializer);

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void NativeConstruct() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveImageryDirectoryUpdate(const FString& imageryDirectory);

	UFUNCTION(BlueprintCallable)
	void SetImageryDirectory(const FString& imageryDirectory);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveOfflineImageryDirectoryUpdate(const FString& offlineImageryDirectory);

	UFUNCTION(BlueprintCallable)
	void SetOfflineImageryDirectory(const FString& offlineImageryDirectory);

	UFUNCTION(BlueprintCallable)
	void SetStartingLocation(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintCallable)
	void ResetStartingLocation();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void BindDelegates();

	void InitWidgetsFromDatabase();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleMinImageryEdited(const FText& text, ETextCommit::Type commitMethod);

	UFUNCTION()
	void HandleMaxImageryEdited(const FText& text, ETextCommit::Type commitMethod);

	UFUNCTION()
	void HandleMinHeightmapEdited(const FText& text, ETextCommit::Type commitMethod);

	UFUNCTION()
	void HandleMaxHeightmapEdited(const FText& text, ETextCommit::Type commitMethod);

	UFUNCTION(BlueprintCallable, Category = "Events|Protected")
	void HandleEnableStreamingCheckStateChange(bool bIsChecked);

	UFUNCTION()
	void HandleStringSettingChanged(const FString& settingName, const FString& value);
};
