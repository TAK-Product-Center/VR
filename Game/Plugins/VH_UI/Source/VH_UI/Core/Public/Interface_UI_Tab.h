#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_UI_Tab.generated.h"

class UTexture2D;


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FTabInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Title;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* Icon;

	FTabInfo()
	{
		Title = TEXT("");
		Icon = nullptr;
	}
};

UINTERFACE(Blueprintable)
class VH_UI_API UInterface_UI_Tab : public UInterface
{
    GENERATED_BODY()
};

class VH_UI_API IInterface_UI_Tab
{
	GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Gives information about the tab
	* \param tabInfo FTabInfo struct to populate
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void GetTabInfo(FTabInfo& tabInfo) const;
};
