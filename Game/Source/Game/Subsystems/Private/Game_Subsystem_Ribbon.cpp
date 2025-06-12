// Required Includes
#include "Game_Subsystem_Ribbon.h"
#include "Game.h"

// Engine Includes
#include "UObject/UObjectGlobals.h"
#include "UObject/Package.h"
#include "TimerManager.h"
#include "Misc/CommandLine.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "UI_Subsystem_Core.h"
#include "UI_Subsystem_ContextMenu.h"

// Game Includes
#include "Interface_Game_RibbonButton.h"
#include "Interface_Game_RibbonMenu.h"
#include "Game_Subsystem_Ribbon_Settings.h"
#include "Game_Tool.h"
#include "Game_RibbonButtonRegistrar.h"
#include "Game_TutorialManager.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_Ribbon::UGame_Subsystem_Ribbon()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Subsystem_Ribbon* UGame_Subsystem_Ribbon::Get()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		return world->GetSubsystem<UGame_Subsystem_Ribbon>();
	}

	return nullptr;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Subsystem_Ribbon::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	if (const UGame_Subsystem_Ribbon_Settings* settings = GetDefault<UGame_Subsystem_Ribbon_Settings>())
	{
		ApplySettings(settings);
	}

	RibbonDB = NewObject<UGame_Database_Ribbon>();
	RibbonDB->Connect();

	//Reordering test
	/*
	TMap<FString, double> testOrder;
	testOrder.Add(TEXT("Home"), 15);
	RibbonDB->SaveLayout(
		testOrder,
		TMap<FString, TMap<FString, double>>(), 
		TMap<FString, FRibbonButtonLocation>());
		*/

	RibbonDB->LoadLayout(TabIndices, CategoryIndices, ButtonLocations);
}

void UGame_Subsystem_Ribbon::Deinitialize()
{
	RibbonDB->Disconnect();
	RibbonDB = nullptr;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_Subsystem_Ribbon::RegisterButton(UUserWidget* buttonWidget)
{
	if (!buttonWidget->GetClass()->ImplementsInterface(UInterface_Game_RibbonButton::StaticClass()))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Ribbon::RegisterButton | userWidget does not implement UGame_Interface_RibbonButton | aborting"));

		return;
	}

	FString id = IInterface_Game_RibbonButton::Execute_GetID(buttonWidget);

	if (UUserWidget* buttonWidgetTest = GetRibbonButtonByID(id))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Ribbon::RegisterButton | Ribbon Button ID failed unique assertion | aborting"));

		return;
	}

	RegisteredButtons.Add(id, buttonWidget);

	if (RibbonUserWidget != nullptr)
	{
		AddButton(buttonWidget);
		UpdateButtonEnabled(buttonWidget);
	}
}

void UGame_Subsystem_Ribbon::UnregisterButton(UUserWidget* buttonWidget)
{
	if (RibbonUserWidget != nullptr)
	{
		RemoveButton(buttonWidget);
	}

	FString id = IInterface_Game_RibbonButton::Execute_GetID(buttonWidget);

	RegisteredButtons.Remove(id);
}

void UGame_Subsystem_Ribbon::UnregisterButtonByID(const FString& id)
{
	if (RibbonUserWidget != nullptr)
	{
		if (UUserWidget* buttonWidget = GetRibbonButtonByID(id))
		{
			RemoveButton(buttonWidget);
		}
	}

	RegisteredButtons.Remove(id);
}

UUserWidget* UGame_Subsystem_Ribbon::GetRibbonButtonByID(const FString& id) const
{
	if (UUserWidget* const* userWidgetPtr = RegisteredButtons.Find(id))
	{
		return *userWidgetPtr;
	}

	return nullptr;
}

void UGame_Subsystem_Ribbon::ShowRibbon()
{
	if (RibbonButtonRegistrar == nullptr)
	{
		if (ButtonRegistrarClass != nullptr)
		{
			RibbonButtonRegistrar = NewObject<UGame_RibbonButtonRegistrar>(GetTransientPackage(), ButtonRegistrarClass);
			RibbonButtonRegistrar->RegisterRibbonButtons(GetWorld());
		}
	}

	UDeveloper_Subsystem_Core* subsystemDeveloper = UDeveloper_Subsystem_Core::Get();
	subsystemDeveloper->OnHardwareInterfaceModeChanged.AddUniqueDynamic(this, &UGame_Subsystem_Ribbon::HandleHardwareInterfaceModeChanged);

	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		if (!IsValid(RibbonUserWidget))
		{
			if (!RibbonMenuClass->ImplementsInterface(UInterface_Game_RibbonMenu::StaticClass()))
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Ribbon::ShowRibbon | RibbonMenuClass must implement Interface_Game_RibbonMenu | aborting"));

				return;
			}

			RibbonUserWidget = subsystem->OpenWithDefaultsByClass(RibbonMenuClass);

			if (subsystemDeveloper->GetHardwareInterfaceMode() == EHardwareInterfaceMode::VREmulation || subsystemDeveloper->GetHardwareInterfaceMode() == EHardwareInterfaceMode::VR)
			{
				RibbonWorldUIActor = subsystem->GetUserWidgetWorldUIActor(RibbonUserWidget);
			}

			PopulateRibbon();
		}

		if (!IsValid(RibbonWorldUIActor))
		{
			RibbonUserWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			RibbonWorldUIActor->SetActorHiddenInGame(false);
			RibbonWorldUIActor->SetActorEnableCollision(true);

			FTransform playerTransform;
			UDeveloper_Statics::GetPlayerViewpoint(playerTransform);

			FVector localSpawnOffset = subsystem->GetUserWidgetClassWorldSettings(RibbonMenuClass).LocalSpawnOffset;

			FVector worldLocation = playerTransform.TransformPosition(localSpawnOffset);
			RibbonWorldUIActor->SetActorLocation(worldLocation);
		}

		if (UGame_TutorialManager* tutorialManager = UGame_TutorialManager::Get())
		{
			tutorialManager->TutorialActionOccurred(RIBBON_VISIBLE_ACTION);
		}
	}

	OnRibbonVisibilityChanged.Broadcast(true);
}

void UGame_Subsystem_Ribbon::HideRibbon()
{
	if (RibbonWorldUIActor == nullptr)
	{
		if (RibbonUserWidget != nullptr)
		{
			RibbonUserWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
	else
	{
		RibbonWorldUIActor->SetActorHiddenInGame(true);
		RibbonWorldUIActor->SetActorEnableCollision(false);
	}

	if (UUI_Subsystem_ContextMenu* subsystem = UUI_Subsystem_ContextMenu::Get())
	{
		subsystem->CloseContextMenusForClass(AGame_Tool::StaticClass());
	}

	OnRibbonVisibilityChanged.Broadcast(false);
}

void UGame_Subsystem_Ribbon::ToggleRibbonVisibility()
{
	if (GetRibbonVisible())
	{
		/*
		 * Reordering Test
		 *
		for(const TPair<FString, double>& tab : TabIndices)
		{
			TabIndices[tab.Key] = TabIndices.Num() - (TabIndices[tab.Key] + 1);
		}
		
		RibbonDB->SaveLayout(
			TabIndices,
			CategoryIndices, 
			ButtonLocations);
	
		RegenerateRibbon();
		*/
		
		HideRibbon();
	}
	else
	{
		ShowRibbon();
	}
}

bool UGame_Subsystem_Ribbon::GetRibbonVisible() const
{
	bool bCurrentlyHidden = false;
	if (RibbonUserWidget == nullptr)
	{
		bCurrentlyHidden = true;
	}
	else
	{
		if (RibbonWorldUIActor == nullptr)
		{
			bCurrentlyHidden = RibbonUserWidget->GetVisibility() != ESlateVisibility::Visible;
		}
		else
		{
			bCurrentlyHidden = RibbonWorldUIActor->IsHidden();
		}
	}

	return !bCurrentlyHidden;
}

void UGame_Subsystem_Ribbon::CloseAllDropdownMenus()
{
	for (const TPair<FString, UUserWidget*>& registeredButton : RegisteredButtons)
	{
		if (UGame_UserWidget_RibbonButton* button = Cast< UGame_UserWidget_RibbonButton>(registeredButton.Value)) 
		{
			button->CloseDropdownMenu();
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_Subsystem_Ribbon::ApplySettings(const UGame_Subsystem_Ribbon_Settings* settings)
{
	RibbonMenuClass = settings->RibbonMenuClass;
	ButtonRegistrarClass = settings->ButtonRegistrarClass;
	TabIndices.Empty();
	TabIndices.Append(settings->TabIndices);
	CategoryIndices.Empty();
	for (const TPair<FString, FTabCategoryOrder>& catIndices : settings->CategoryIndices)
	{
		CategoryIndices.Add(catIndices.Key, catIndices.Value.CategoryIndices);
	}
}

void UGame_Subsystem_Ribbon::PopulateRibbon()
{
	for (const TPair<FString, UUserWidget*>& entry : RegisteredButtons)
	{
		AddButton(entry.Value);
	}

	if(IsValid(RibbonUserWidget))
	{
		IInterface_Game_RibbonMenu::Execute_UpdateContainerVisibility(RibbonUserWidget);
	}
}

void UGame_Subsystem_Ribbon::AddButton(UUserWidget* buttonWidget)
{
	if (IsValid(RibbonUserWidget))
	{
		FString id = IInterface_Game_RibbonButton::Execute_GetID(buttonWidget);

		FString tab = TEXT("");
		FString category = TEXT("");
		double buttonIndex = -1;

		if (FRibbonButtonLocation* buttonLoc = ButtonLocations.Find(id))
		{
			tab = buttonLoc->Tab;
			category = buttonLoc->Category;
			buttonIndex = buttonLoc->Index;
		}
		else
		{
			IInterface_Game_RibbonButton::Execute_GetDefaultTab(buttonWidget, tab);
			IInterface_Game_RibbonButton::Execute_GetDefaultCategory(buttonWidget, category);
			IInterface_Game_RibbonButton::Execute_GetDefaultIndexInCategory(buttonWidget, buttonIndex);
		}

		double tabIndex = -1;
		GetTabIndex(tab, tabIndex);

		double catIndex = -1;
		GetCategoryIndex(tab, category, catIndex);

		IInterface_Game_RibbonMenu::Execute_AddButton(RibbonUserWidget, buttonWidget, tab, tabIndex, category, catIndex, buttonIndex);
	}
}

void UGame_Subsystem_Ribbon::RemoveButton(UUserWidget* buttonWidget)
{
	if (IsValid(RibbonUserWidget))
	{
		FString id = IInterface_Game_RibbonButton::Execute_GetID(buttonWidget);

		FString tab = TEXT("");
		FString category = TEXT("");

		if (FRibbonButtonLocation* buttonLoc = ButtonLocations.Find(id))
		{
			tab = buttonLoc->Tab;
			category = buttonLoc->Category;
		}
		else
		{
			IInterface_Game_RibbonButton::Execute_GetDefaultTab(buttonWidget, tab);
			IInterface_Game_RibbonButton::Execute_GetDefaultCategory(buttonWidget, category);
		}

		IInterface_Game_RibbonMenu::Execute_RemoveButton(RibbonUserWidget, buttonWidget, tab, category);
	}
}

void UGame_Subsystem_Ribbon::SetButtonEnabledCondition(const FString& condition, const int32& newValue, bool bUpdateButtons)
{
	EnableConditionValues.Add(condition, newValue);

	if (bUpdateButtons)
	{
		bool updatedButtons = false;
		for (const TPair<FString, UUserWidget*>& button : RegisteredButtons)
		{
			updatedButtons |= UpdateButtonEnabled(button.Value);
		}

		if(updatedButtons && IsValid(RibbonUserWidget))
		{
			IInterface_Game_RibbonMenu::Execute_UpdateContainerVisibility(RibbonUserWidget);
		}
	}
}

void UGame_Subsystem_Ribbon::SyncToGameState()
{
	// Is in TOC?
	BindToPlayerState();	

	// VR vs Desktop
	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		subsystem->OnHardwareInterfaceModeChanged.AddUniqueDynamic(this, &UGame_Subsystem_Ribbon::HandleHardwareInterfaceModeChanged);
		HandleHardwareInterfaceModeChanged(subsystem->GetHardwareInterfaceMode(), subsystem->GetHardwareInterfaceMode());
	}

	// Is in Tutorial?
	if (UGame_TutorialManager* tutorial = UGame_TutorialManager::Get())
	{
		tutorial->OnTutorialStageChanged.AddUniqueDynamic(this, &UGame_Subsystem_Ribbon::HandleTutorialStageChanged);
		SetButtonEnabledCondition(TEXT("IsInTutorial"), tutorial->GetTutorialStage() != ETutorialStage::Inactive, false);
	}
	
	// MUC/NonMUC - Note MUC values will also be set via WBP_MUCMenu. Only checking if client is applicable here
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		SetButtonEnabledCondition(TEXT("IsInMUC"), 1, false);
		SetButtonEnabledCondition(TEXT("IsMUCClient"), 1, false);
		SetButtonEnabledCondition(TEXT("IsMUCHost"), 0, false);
	}
	else
	{
		// We cannot guarantee that just because we are NOT a client that we are in MUC or hosting it, so just set client to false
		SetButtonEnabledCondition(TEXT("IsMUCClient"), 0, false);

		// default IsInMUC to false; this is set to true for the host in the MUC UI
		SetButtonEnabledCondition(TEXT("IsInMUC"), 0, false);
	}
	
	// dev
	SetButtonEnabledCondition(TEXT("IsDev"), FParse::Param(FCommandLine::Get(), TEXT("dev")), false);

	SetButtonEnabledCondition(TEXT("MovementTypeDisabledWalk"), 0, false);
	SetButtonEnabledCondition(TEXT("MovementTypeDisabledFly"), 0, false);
	SetButtonEnabledCondition(TEXT("MovementTypeDisabledTP"), 0, false);

	SetButtonEnabledCondition(TEXT("IsPresentationOngoing"), 0, false);
	SetButtonEnabledCondition(TEXT("IsPresentationPresenter"), 0);
}

bool UGame_Subsystem_Ribbon::UpdateButtonEnabled(UUserWidget* button)
{
	TMap<FString, int32> conditions;

	//If there are no conditions then we don't control whether the button is enabled
	if (IInterface_Game_RibbonButton::Execute_GetEnableConditions(button, conditions))
	{
		bool shouldEnable = true;
		for (const TPair<FString, int32>& cond : conditions)
		{
			if (!EnableConditionValues.Contains(cond.Key) || EnableConditionValues[cond.Key] != cond.Value)
			{
				shouldEnable = false;
				break;
			}
		}

		bool wasEnabled = button->GetIsEnabled();
		if (!wasEnabled && shouldEnable)
		{
			button->SetVisibility(ESlateVisibility::Visible);
		}
		else if (wasEnabled && !shouldEnable)
		{
			bool bCollapse = IInterface_Game_RibbonButton::Execute_GetCollapseOnDisable(button);
			button->SetVisibility(bCollapse ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
		}
		else
		{
			return false;
		}
		
		button->SetIsEnabled(shouldEnable);
		return true;
	}
	return false;
}

bool UGame_Subsystem_Ribbon::GetTabIndex(const FString& tabName, double& index)
{
	if (double* tabIndex = TabIndices.Find(tabName))
	{
		index = *tabIndex;
		return true;
	}
	else
	{
		// create index for tab
		double maxIndex = -1;
		for (const TPair<FString, double>& entry : TabIndices)
		{
			if (entry.Value > maxIndex)
			{
				maxIndex = entry.Value;
			}
		}

		index = maxIndex + 1;
		TabIndices.Add(tabName, index);
	}
	return false;
}

bool UGame_Subsystem_Ribbon::GetCategoryIndex(const FString& tabName, const FString& categoryName, double& index)
{
	if (TMap<FString, double>* tabCats = CategoryIndices.Find(tabName))
	{
		if (double* categoryIndex = tabCats->Find(categoryName))
		{
			index = *categoryIndex;
			return true;
		}
		else
		{
			// create index for category
			double maxIndex = -1;
			for (const TPair<FString, double>& entry : *tabCats)
			{
				if (entry.Value > maxIndex)
				{
					maxIndex = entry.Value;
				}
			}

			index = maxIndex + 1;
			tabCats->Add(categoryName, index);
		}
	}
	else
	{
		CategoryIndices.Add(tabName, TMap<FString, double>());
		GetCategoryIndex(tabName, categoryName, index);
	}

	return false;
}

bool UGame_Subsystem_Ribbon::GetButtonLocationInfo(const FString& buttonID, FRibbonButtonLocation& buttonInfo)
{
	if (FRibbonButtonLocation* buttonLoc = ButtonLocations.Find(buttonID))
	{
		buttonInfo.Tab = buttonLoc->Tab;
		buttonInfo.Category = buttonLoc->Category;
		buttonInfo.Index = buttonLoc->Index;
		return true;
	}
	return false;
}

void UGame_Subsystem_Ribbon::RegenerateRibbon()
{
	HideRibbon();

	CloseAllDropdownMenus();

	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		subsystem->CloseUserWidget(RibbonUserWidget);
		RibbonUserWidget = nullptr;
	}
	
	TabIndices.Empty();
	CategoryIndices.Empty();
	ButtonLocations.Empty();

	RibbonDB->LoadLayout(TabIndices, CategoryIndices, ButtonLocations);

	ShowRibbon();
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_Subsystem_Ribbon::BindToPlayerState()
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_Subsystem_Ribbon::HandleIsInTOCUpdated);
		HandleIsInTOCUpdated(playerState->GetIsInTOC());
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_Subsystem_Ribbon::BindToPlayerState, 0.5);
	}
}

void UGame_Subsystem_Ribbon::HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode)
{
	if (RibbonUserWidget != nullptr)
	{
		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			CloseAllDropdownMenus();

			subsystem->CloseUserWidget(RibbonUserWidget);

			subsystem->OpenWithDefaults(RibbonUserWidget);

			if (newMode == EHardwareInterfaceMode::VREmulation || newMode == EHardwareInterfaceMode::VR)
			{
				RibbonUserWidget->SetVisibility(ESlateVisibility::Visible);

				RibbonWorldUIActor = subsystem->GetUserWidgetWorldUIActor(RibbonUserWidget);
			}
			else
			{
				RibbonWorldUIActor = nullptr;
			}
		}
	}

	bool isOnDesktop = newMode == EHardwareInterfaceMode::Desktop || newMode == EHardwareInterfaceMode::Unknown;
	
	SetButtonEnabledCondition(TEXT("HardwareInterfaceModeDesktop"), isOnDesktop, false);
	SetButtonEnabledCondition(TEXT("HardwareInterfaceModeVR"), !isOnDesktop, false);
	SetButtonEnabledCondition(TEXT("HardwareInterfaceModeUsingEmulation"), newMode == EHardwareInterfaceMode::VREmulation);
}

void UGame_Subsystem_Ribbon::HandleIsInTOCUpdated(bool bIsInTOC)
{
	SetButtonEnabledCondition(TEXT("IsInTOC"), bIsInTOC);

	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		if (subsystem->GetHardwareInterfaceMode() != EHardwareInterfaceMode::Desktop)
		{
			if (GetRibbonVisible())
			{
				HideRibbon();
		
				FTimerHandle timerHandle;
				GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_Subsystem_Ribbon::ShowRibbon, 0.5, false);
			}
		}
	}
}

void UGame_Subsystem_Ribbon::HandleTutorialStageChanged(ETutorialStage newStage)
{
	//NOTE: Does not handle starting at the middle of the tutorial
	if (newStage == ETutorialStage::Inactive)
	{
		SetButtonEnabledCondition(TEXT("IsInTutorial"), false);
	}
	else if (newStage == ETutorialStage::Initial)
	{
		SetButtonEnabledCondition(TEXT("IsInTutorial"), true);
	}
}
