#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Engine Includes
#include "Blueprint/IUserObjectListEntry.h"

// VH Plugin Includes
#include "Database_Spatialite.h"

// Generate Include
#include "Game_ListEntry_Overlay_Base.generated.h"

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EMinimalDisplay : uint8
{
	EMD_Normal,
	EMD_Minimal,
	EMD_MinimalWithImage
};


UCLASS()
class GAME_API UGame_ListEntry_Overlay_Base : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSelectionToggled, const TArray<FString>&, UIDs);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Overlay List Entry|Delegates")
	FSelectionToggled OnSelectionToggled;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	FSpatialiteResult_BP Result;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	FString EntityUID;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	FString ClassUID;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	FString CategoryID;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	FString Latitude;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	FString Longitude;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	FString Height;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	bool bIsTransient;

	UPROPERTY(BlueprintReadWrite, Category = "Overlay List Entry|Variables")
	bool bIsVisible;

protected:
	EMinimalDisplay MinimalDisplayType;

	bool bHighlightOnSelection;

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void NativeConstruct() override;

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	bool GetHighlightOnSelection() const;

	UFUNCTION(BlueprintCallable)
	void SetHighlightOnSelection(bool bHighlight);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetHighlightOnSelection(bool bHighlight);

	UFUNCTION(BlueprintPure)
	EMinimalDisplay GetMinimalDisplayType() const;

	UFUNCTION(BlueprintCallable)
	void SetMinimalDisplayType(EMinimalDisplay displayType);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetMinimalDisplayType(EMinimalDisplay displayType);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Overlay List Entry|Events")
	TArray<FString> GetUIDs();

	UFUNCTION(BlueprintCallable, Category = "Overlay List Entry|Functions")
	void SetResult(const FSpatialiteResult_BP& inResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Overlay List Entry|Events")
	void HandleInsertOrUpdate(const FSpatialiteResult_BP& dbResult);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Overlay List Entry|Events")
	void SetSelectionCheckboxValue(bool bIsChecked);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Overlay List Entry|Events")
	void ShowSelectionCheckbox(bool bShouldShow);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Overlay List Entry|Events")
	void UpdateUI(const TMap<FString, FString>& overlayInfo);

	// ---------------------------------
	// --- Implementation Methods
	// ---------------------------------

protected:

	virtual TArray<FString> GetUIDs_Native();

	virtual void HandleInsertOrUpdate_Native(const FSpatialiteResult_BP& dbResult);

	virtual void SetSelectionCheckboxValue_Native(bool bIsChecked);

	virtual void ShowSelectionCheckbox_Native(bool bShouldShow);

	virtual void UpdateUI_Native(const TMap<FString, FString>& overlayInfo);

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:

	UFUNCTION(BlueprintCallable, Category = "Event Handlers|Public")
	void HandleDBInsertOrUpdate(const FSpatialiteResults_BP& dbResults);

};
