// Required Includes
#include "Game_UserWidget_ContextMenu_Radial.h"
#include "Game.h"

// Engine Includes
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"
#include "Developer_Statics.h"
#include "VR_TraceComponent.h"

// Game Includes
#include "Game_ContextMenuOption.h"
#include "Game_Tool.h"
#include "Game_Pawn.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_ContextMenu_Radial::UGame_UserWidget_ContextMenu_Radial(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- IInterface_UI_ContextMenu
// ---------------------------------

void UGame_UserWidget_ContextMenu_Radial::SetContextMenuInformation_Implementation(AActor* instigator, UObject* source, const TSet<UObject*>& contextOptions)
{
	Source = source;

	Instigator = instigator;

	if (!bSkipSyncToGameTool)
	{
		if (AGame_Tool* gameTool = Cast<AGame_Tool>(instigator))
		{
			if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
			{
				if (AActor* sourceAsActor = Cast<AActor>(Source))
				{
					FVector dragLocation;
					if (!gameTool->GetInteractionHitLocation(dragLocation))
					{
						dragLocation = sourceAsActor->GetActorLocation();

						double distanceToolToDragLocation = FVector::Distance(gameTool->VRTrace->GetComponentLocation(), dragLocation);

						FTransform localToWorld = gameTool->VRTrace->GetComponentTransform();

						dragLocation = localToWorld.TransformPosition(FVector(distanceToolToDragLocation, 0, 0));
					}

					subsystem->MoveUserWidgetToWorldLocation(this, dragLocation);
				}
			}
		}

		bSkipSyncToGameTool = true;
	}

	CreateContextMenuOptions(contextOptions);

	FObjectSet objectSet;
	objectSet.Objects = contextOptions;
	OptionsHistory.Add(objectSet);

	ReceiveSetBackAvailable(OptionsHistory.Num() > 1);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_ContextMenu_Radial::NativeTick(const FGeometry& myGeometry, float deltaSeconds)
{
	Super::NativeTick(myGeometry, deltaSeconds);

	if (bTrackSource)
	{
		MoveToSourceLocation();
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_ContextMenu_Radial::LoadMostRecentPreviousOptions()
{
	// suppose option sets 0, 1, 2, 3; 3 are subclasses of 2, 2 are subclasses of 1, 1 are subclasses of 0
	// SetContextMenuInformation_Implementation add 0; new OptionsHistory is 0
	// SetContextMenuInformation_Implementation adds 1, than 2, than 3; new OptionsHistory is 0, 1, 2, 3
	// user chooses back, so load 2, remove 2, 3; new OptionsHistory is 0, 1
	// SetContextMenuInformation_Implementation adds 2; new OptionsHistory is 0, 1, 2
	// user chooses back, so load 1, remove 1, 2; new OptionsHistory is 0
	// SetContextMenuInformation_Implementation adds 1; new OptionsHistory is 0, 1
	// user chooses back, so load 0, remove 0, 1; new OptionsHistory is empty
	// SetContextMenuInformation_Implementation add 0; new OptionsHistory is 0
	if (OptionsHistory.Num() > 1)
	{
		int32 secondToLast = OptionsHistory.Num() - 2;
		TSet<UObject*> previousContextOptions = OptionsHistory[secondToLast].Objects;

		OptionsHistory.RemoveAt(secondToLast, 2);

		SetContextMenuInformation_Implementation(Instigator, Source, previousContextOptions);
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_ContextMenu_Radial::MoveToSourceLocation()
{
	if (AActor* sourceActor = Cast<AActor>(Source))
	{
		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			subsystem->MoveUserWidgetToWorldLocation(this, sourceActor->GetActorLocation());
		}
	}
}

void UGame_UserWidget_ContextMenu_Radial::CreateContextMenuOptions(const TSet<UObject*>& contextOptions)
{
	if (ContextMenuOptionClass == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_ContextMenu_Radial::CreateContextMenuOptions | ContextMenuOptionClass is nullptr | aborting"));

		return;
	}

	// handle context menu option visibility
	TSet<UObject*> visibleContextOptions;
	for (UObject* contextOption : contextOptions)
	{
		if (UGame_ContextMenuOption* gameOption = Cast<UGame_ContextMenuOption>(contextOption))
		{
			if (gameOption->GetVisible())
			{
				visibleContextOptions.Add(contextOption);
			}
		}
	}

	if (UCanvasPanel* canvasPanel = GetCanvasPanel())
	{
		// slot 0 is the close/back button; leave that
		for (int32 i = canvasPanel->GetChildrenCount() - 1; i > 0; i--)
		{
			canvasPanel->RemoveChildAt(i);
		}

		int32 index = 0;
		for (UObject* contextOption : visibleContextOptions)
		{
			UUserWidget* contextMenuOptionWidget = UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), ContextMenuOptionClass, FName(*FGuid::NewGuid().ToString()));
			
			canvasPanel->AddChild(contextMenuOptionWidget);

			if (UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(contextMenuOptionWidget->Slot))
			{
				if (FPositionsStruct* positionsPtr = ContextMenuOptionPositions.Find(visibleContextOptions.Num()))
				{
					slot->SetAlignment(FVector2D(0.5, 0.5));
					slot->SetAnchors(FAnchors(0.5, 0.5));

					slot->SetAutoSize(true);
					
					slot->SetPosition(positionsPtr->Positions[index]);
				}
			}

			ReceiveContextMenuOptionCreated(visibleContextOptions.Num(), index, contextMenuOptionWidget, contextOption);

			index++;
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_ContextMenu_Radial::GetCanvasPanel | CanvasPanel is nullptr | aborting"));
	}
}