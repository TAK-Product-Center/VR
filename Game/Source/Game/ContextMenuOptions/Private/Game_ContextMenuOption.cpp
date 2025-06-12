// Required Includes
#include "Game_ContextMenuOption.h"
#include "Game.h"

// Engine Includes
#include "UObject/UObjectGlobals.h"
#include "UObject/Package.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "UI_Subsystem_Core.h"
#include "UI_Subsystem_ContextMenu.h"
#include "Interface_UI_ContextMenu.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ContextMenuOption::UGame_ContextMenuOption(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	bCloseAfterExecute(true)
{

}

// ---------------------------------
// --- FTickableObjectBase
// ---------------------------------

TStatId UGame_ContextMenuOption::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGame_ContextMenuOption, STATGROUP_Tickables);
}

bool UGame_ContextMenuOption::IsTickable() const
{
	return bShouldTick && !IsUnreachable();
}

void UGame_ContextMenuOption::Tick(float deltaSeconds)
{
	ReceiveTick(deltaSeconds);
}

// ---------------------------------
// --- Interface_UI_ContextMenuOption
// ---------------------------------

void UGame_ContextMenuOption::SetInstigatorAndSource_Implementation(AActor* instigatorParam, UObject* sourceParam)
{
	Instigator = instigatorParam;

	Source = sourceParam;
}

void UGame_ContextMenuOption::Execute_Implementation()
{
	OnExecuted.Broadcast(this);

	ReceiveExecute();

	PostExecute();

	if (UUI_Subsystem_ContextMenu* contextMenuSubsystem = UUI_Subsystem_ContextMenu::Get())
	{
		TSet<UObject*> subOptions;
		if (!GetSubOptions(subOptions))
		{
			TSet<TSubclassOf<UObject>> subOptionClasses = GetSubOptionClasses();
			if (subOptionClasses.Num() > 0)
			{
				for (const TSubclassOf<UObject>& contextOptionClass : subOptionClasses)
				{
					UObject* contextOption = NewObject<UObject>(GetTransientPackage(), contextOptionClass);

					subOptions.Add(contextOption);
				}
			}
		}

		if (subOptions.Num() > 0)
		{
			if (UUserWidget* contextMenu = contextMenuSubsystem->GetContextMenuFromSource(Source))
			{
				for (UObject* subOption : subOptions)
				{
					if (subOption->GetClass()->ImplementsInterface(UInterface_UI_ContextMenuOption::StaticClass()))
					{
						IInterface_UI_ContextMenuOption::Execute_SetInstigatorAndSource(subOption, Instigator, Source);
					}
				}

				IInterface_UI_ContextMenu::Execute_SetContextMenuInformation(contextMenu, Instigator, Source, subOptions);
			}
		}
		else if (bCloseAfterExecute)
		{
			CloseContextMenu();
		}
	}
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_ContextMenuOption* UGame_ContextMenuOption::CreateContextMenuOption(const FSlateBrush& icon, const FString& text, const FString& tooltip)
{
	UGame_ContextMenuOption* contextMenuOption = NewObject<UGame_ContextMenuOption>(GetTransientPackage(), UGame_ContextMenuOption::StaticClass());
	contextMenuOption->Icon = icon;
	contextMenuOption->Text = text;
	contextMenuOption->Tooltip = tooltip;

	return contextMenuOption;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

class UWorld* UGame_ContextMenuOption::GetWorld() const
{
	return UDeveloper_Statics::GetVHWorld();
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_ContextMenuOption::CloseContextMenu()
{
	UUI_Subsystem_ContextMenu* contextMenuSubsystem = UUI_Subsystem_ContextMenu::Get();
	UUI_Subsystem_Core* coreSubsystem = UUI_Subsystem_Core::Get();

	if (coreSubsystem != nullptr && contextMenuSubsystem != nullptr)
	{
		if (UUserWidget* contextMenu = contextMenuSubsystem->GetContextMenuFromSource(Source))
		{
			coreSubsystem->CloseUserWidget(contextMenu);
		}
	}
}

FSlateBrush UGame_ContextMenuOption::GetIcon_Implementation() const
{
	return Icon;
}

FString UGame_ContextMenuOption::GetText_Implementation() const
{
	return Text;
}

FString UGame_ContextMenuOption::GetTooltip_Implementation() const
{
	return Tooltip;
}

bool UGame_ContextMenuOption::GetSubOptions_Implementation(TSet<UObject*>& subOptions) const
{
	return false;
}

TSet<TSubclassOf<UObject>> UGame_ContextMenuOption::GetSubOptionClasses_Implementation() const
{
	return SubOptionClasses;
}

bool UGame_ContextMenuOption::GetVisible_Implementation() const
{
	return true;
}

bool UGame_ContextMenuOption::GetEnabled_Implementation() const
{
	return true;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_ContextMenuOption::PostExecute()
{

}