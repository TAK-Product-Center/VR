// Required Includes
#include "Game_UserWidget_RibbonEditor.h"
#include "Game.h"

// Engine Includes
#include "filesystem"
#include "cmath"
#include "XmlFile.h"
#include "HAL/FileManager.h"
#include "Kismet/KismetStringLibrary.h"
#include "Windows/WindowsApplication.h"
#include "Components/PanelWidget.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Developer_Statics.h"

// Game Includes
#include "Game_DragDropOperation_RibbonEditor.h"
#include "Game_Subsystem_Ribbon.h"
#include "Game_UserWidget_RibbonButton.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonEditor::UGame_UserWidget_RibbonEditor(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	LayoutFolderPath = FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Layouts"));
	HoverTimer = -1;
}


// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_RibbonEditor::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if(IsDragging && CurrentHover != nullptr && HoverTimer >= 0)
	{
		if(UGame_UserWidget_RibbonEditor_TabButtonStandin* widget = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(CurrentHover))
		{
			HoverTimer += InDeltaTime;
			if(HoverTimer >= HoverTabSwapDelay)
			{
				SwitchToTab(widget);
				HoverTimer = -1;
			}
			widget->SetHoverBarPercent(FMath::Clamp(HoverTimer / HoverTabSwapDelay, 0.0f, 1.0f));
		}
	}
}


// ---------------------------------
// --- API
// ---------------------------------

FString UGame_UserWidget_RibbonEditor::AttemptRename(const FString& newName)
{
	//Names cannot be whitespace
	FString trimmedName(newName);
	trimmedName.RemoveSpacesInline();
	if(trimmedName.IsEmpty())
	{
		return TEXT("Name cannot be empty");
	}
	
	if(!newName.Equals(RenameTarget->Text, ESearchCase::IgnoreCase))
	{
		TArray<UWidget*> siblings = RenameTarget->Parent->GetAllChildren();
		for(int i = 0; i < siblings.Num(); i++)
		{
			if(UGame_UserWidget_RibbonEditor_DraggableWidget* widget = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(siblings[i]))
			{
				if(newName.Equals(widget->Text, ESearchCase::IgnoreCase))
				{
					return TEXT("Name in use");
				}
			}
		}
	}
	RenameTarget->SetText(newName);
	return TEXT("");
}

void UGame_UserWidget_RibbonEditor::InsertChild(UWidget* newChild, UPanelWidget* newParent, int newIndex)
{
	newChild->RemoveFromParent();
	TArray<UWidget*> children = newParent->GetAllChildren();
	newParent->ClearChildren();
	for(int i = 0; i < children.Num(); i++)
	{
		if(i == newIndex)
		{
			newParent->AddChild(newChild);
		}
		newParent->AddChild(children[i]);
	}

	//Special case if the child is at the end
	if(newIndex >= children.Num())
	{
		newParent->AddChild(newChild);
	}
}

void UGame_UserWidget_RibbonEditor::SetSpacerLocation(UPanelWidget* newParent, int newIndex)
{
	Spacer->SetVisibility(ESlateVisibility::Visible);
	if(newParent != SpacerParent || newIndex != SpacerIndex)
	{
		InsertChild(Spacer, newParent, newIndex);
		SpacerParent = newParent;
		SpacerIndex = newIndex;
	}
}

UGame_UserWidget_RibbonEditor_CategoryStandin* UGame_UserWidget_RibbonEditor::TabContainsCatOfName(UPanelWidget* containingTab, const FString& categoryName)
{
	TArray<UWidget*> children = containingTab->GetAllChildren();
	for(int i = 0; i < children.Num(); i++)
	{
		if(UGame_UserWidget_RibbonEditor_CategoryStandin* child = Cast<UGame_UserWidget_RibbonEditor_CategoryStandin>(children[i]))
		{
			if(child->Text.Equals(categoryName, ESearchCase::IgnoreCase))
			{
				return child;
			}
		}
	}
	return nullptr;
}

void UGame_UserWidget_RibbonEditor::EmplaceButton(UGame_UserWidget_RibbonEditor_ButtonStandin* ribbonButton, const FString& tabName, const FString& categoryName, int index)
{
	if(tabName.IsEmpty() && categoryName.Equals(TEXT("Trash")))
	{
		InsertChild(ribbonButton, Trash->GetPanelWidget(), index);
		ribbonButton->Parent = Trash->GetPanelWidget();
	}
	else
	{
		UGame_UserWidget_RibbonEditor_TabButtonStandin* tab;
		AddTab(tabName, tab);
	
		UGame_UserWidget_RibbonEditor_CategoryStandin* cat;
		AddCategory(categoryName, tab->LinkedContainer, cat);

		InsertChild(ribbonButton, cat->GetPanelWidget(), index);
		ribbonButton->Parent = cat->GetPanelWidget();
	}
}

bool UGame_UserWidget_RibbonEditor::AddTab(const FString& tabName, UGame_UserWidget_RibbonEditor_TabButtonStandin*& outNewTabButton)
{
	//Tab names cannot be whitespace
	FString trimmedName(tabName);
	trimmedName.RemoveSpacesInline();
	if(trimmedName.IsEmpty())
	{
		ShowError(TEXT("Add Tab Failed: Tab name cannot be empty"));
		return false;
	}
	
	//Tab names must be unique
	TArray<UWidget*> children = TabButtonList->GetAllChildren();
	for(int i = 0; i < children.Num(); i++)
	{
		if(UGame_UserWidget_RibbonEditor_TabButtonStandin* child = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(children[i]))
		{
			if(child->Text.Equals(tabName))
			{
				outNewTabButton = child;
				ShowError(TEXT("Add Tab Failed: Tab name must be unique"));
				return false;
			}
		}
	}

	UGame_UserWidget_RibbonEditor_DropTarget* tabContainer = Cast<UGame_UserWidget_RibbonEditor_DropTarget>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), TabWidgetClass, FName(*FGuid::NewGuid().ToString())));
	tabContainer->OnDragOverEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
	tabContainer->OnDropEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
	TabContainers->AddChild(tabContainer);
		
	UGame_UserWidget_RibbonEditor_TabButtonStandin* tabButton = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), TabButtonWidgetClass, FName(*FGuid::NewGuid().ToString())));
	tabButton->SetText(tabName);
	tabButton->Index = children.Num();
	tabButton->OnBeginDragEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleBeginWidgetDrag);
	tabButton->OnDragOverEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
	tabButton->OnDropEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
	tabButton->OnClick.AddDynamic(this, &UGame_UserWidget_RibbonEditor::SwitchToTab);
	tabButton->OnDoubleClick.AddDynamic(this, &UGame_UserWidget_RibbonEditor::ShowRename);
	tabButton->Parent = TabButtonList;
	tabButton->LinkedContainer = tabContainer;
	TabButtonList->AddChild(tabButton);

	outNewTabButton = tabButton;
	ShowError(TEXT(""));
	return true;
}

bool UGame_UserWidget_RibbonEditor::AddCategory(const FString& catName, UGame_UserWidget_RibbonEditor_DropTarget* containingTab, UGame_UserWidget_RibbonEditor_CategoryStandin*& outNewCategory)
{
	//Category names cannot be whitespace
	FString trimmedName(catName);
	trimmedName.RemoveSpacesInline();
	if(trimmedName.IsEmpty())
	{
		ShowError(TEXT("Add Category Failed: Category name cannot be empty"));
		return false;
	}

	
	//Category names must be unique within a tab
	outNewCategory = TabContainsCatOfName(containingTab->GetPanelWidget(), catName);
	if(outNewCategory)
	{
		ShowError(TEXT("Add Category Failed: Category name must be unique within a tab"));
		return false;
	}
	
	UPanelWidget* tabContainer = containingTab->GetPanelWidget();
	
	UGame_UserWidget_RibbonEditor_CategoryStandin* ribbonCategory = Cast<UGame_UserWidget_RibbonEditor_CategoryStandin>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), CategoryWidgetClass, FName(*FGuid::NewGuid().ToString())));
	ribbonCategory->SetText(catName);
	ribbonCategory->Index = tabContainer->GetChildrenCount();
	ribbonCategory->OnBeginDragEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleBeginWidgetDrag);
	ribbonCategory->OnDragOverEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
	ribbonCategory->OnDropEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
	ribbonCategory->OnDoubleClick.AddDynamic(this, &UGame_UserWidget_RibbonEditor::ShowRename);
	ribbonCategory->Parent = tabContainer;
	tabContainer->AddChild(ribbonCategory);

	outNewCategory = ribbonCategory;
	ShowError(TEXT(""));
	return true;
}

void UGame_UserWidget_RibbonEditor::LoadLayout(const FString& layoutName)
{
	if(!layoutName.IsEmpty())
	{
		if(layoutName.Equals(TEXT("default"), ESearchCase::IgnoreCase))
		{
			LoadDefaultLayout();
		}
		else if(!FPaths::ValidatePath(layoutName))
		{
			//Name contains invalid characters
			ShowError(TEXT("Load Failed: Name contains invalid characters"));
		}
		else
		{
			if(UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
			{
				FString path = GetPathForLayout(layoutName);
		
				FXmlFile xmlFile;
				xmlFile.LoadFile(path, EConstructMethod::ConstructFromFile);
	
				if (xmlFile.IsValid())
				{
					if (FXmlNode* node = xmlFile.GetRootNode())
					{
						CurrentLayout = layoutName;
						bool IsDev = ribbonSubsystem->EnableConditionValues[TEXT("IsDev")] > 0;
						
						TabButtonList->ClearChildren();
						TabContainers->ClearChildren();
						TabContainers->SetActiveWidgetIndex(0);
						Trash->GetPanelWidget()->ClearChildren();

						TArray<FString> keys;
						ribbonSubsystem->RegisteredButtons.GetKeys(keys);
				
						TArray<FXmlNode*> buttonList = node->FindChildNode(TEXT("Buttons"))->GetChildrenNodes();

						for(int i = 0; i < buttonList.Num(); i++)
						{
							FString ID = buttonList[i]->GetTag();
							if(UGame_UserWidget_RibbonButton* buttonWidget = Cast<UGame_UserWidget_RibbonButton>(ribbonSubsystem->GetRibbonButtonByID(ID)))
							{
								TMap<FString, int32> conditions;
								IInterface_Game_RibbonButton::Execute_GetEnableConditions(buttonWidget, conditions);
								if(IsDev || !conditions.Contains(TEXT("IsDev")))
								{
									UGame_UserWidget_RibbonEditor_ButtonStandin* ribbonButton = Cast<UGame_UserWidget_RibbonEditor_ButtonStandin>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), ButtonWidgetClass, FName(*FGuid::NewGuid().ToString())));
									ribbonButton->ID = buttonWidget->ID;
									ribbonButton->Index = UKismetStringLibrary::Conv_StringToInt(buttonList[i]->FindChildNode(TEXT("Index"))->GetContent());
									if(FRibbonButtonProxyOverride* visualOverride = VisualOverrides.Find(ribbonButton->ID))
									{
										ribbonButton->SetText(visualOverride->Text);
										ribbonButton->SetIcon(visualOverride->Icon);
									}
									else
									{
										ribbonButton->SetText(buttonWidget->Text);
										ribbonButton->SetIcon(buttonWidget->Icon);
									}
									ribbonButton->OnBeginDragEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleBeginWidgetDrag);
									ribbonButton->OnDragOverEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
									ribbonButton->OnDropEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
									EmplaceButton(ribbonButton, buttonList[i]->FindChildNode(TEXT("Tab"))->GetContent(), buttonList[i]->FindChildNode(TEXT("Category"))->GetContent(), ribbonButton->Index);
								}
								keys.Remove(ID);
							}
						}

						buttonList = node->FindChildNode(TEXT("Trash"))->GetChildrenNodes();

						for(int i = 0; i < buttonList.Num(); i++)
						{
							FString ID = buttonList[i]->GetTag();
							if(UGame_UserWidget_RibbonButton* buttonWidget = Cast<UGame_UserWidget_RibbonButton>(ribbonSubsystem->GetRibbonButtonByID(ID)))
							{
								TMap<FString, int32> conditions;
								IInterface_Game_RibbonButton::Execute_GetEnableConditions(buttonWidget, conditions);
								if(IsDev || !conditions.Contains(TEXT("IsDev")))
								{
									UGame_UserWidget_RibbonEditor_ButtonStandin* ribbonButton = Cast<UGame_UserWidget_RibbonEditor_ButtonStandin>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), ButtonWidgetClass, FName(*FGuid::NewGuid().ToString())));
									ribbonButton->ID = buttonWidget->ID;
									ribbonButton->Index = i;
									if(FRibbonButtonProxyOverride* visualOverride = VisualOverrides.Find(ribbonButton->ID))
									{
										ribbonButton->SetText(visualOverride->Text);
										ribbonButton->SetIcon(visualOverride->Icon);
									}
									else
									{
										ribbonButton->SetText(buttonWidget->Text);
										ribbonButton->SetIcon(buttonWidget->Icon);
									}
									ribbonButton->OnBeginDragEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleBeginWidgetDrag);
									ribbonButton->OnDragOverEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
									ribbonButton->OnDropEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
									ribbonButton->Parent = Trash->GetPanelWidget();
									Trash->GetPanelWidget()->AddChild(ribbonButton);
								}
								keys.Remove(ID);
							}
						}

						//For any buttons not specified by the loaded layout, grab the default
						FString tab = TEXT("");
						FString category = TEXT("");
						double buttonIndex = -1;

						for(const FString& key : keys)
						{
							if(UGame_UserWidget_RibbonButton* buttonWidget = Cast<UGame_UserWidget_RibbonButton>(ribbonSubsystem->GetRibbonButtonByID(key)))
							{
								TMap<FString, int32> conditions;
								IInterface_Game_RibbonButton::Execute_GetEnableConditions(buttonWidget, conditions);
								if(IsDev || !conditions.Contains(TEXT("IsDev")))
								{
									IInterface_Game_RibbonButton::Execute_GetDefaultTab(buttonWidget, tab);
									IInterface_Game_RibbonButton::Execute_GetDefaultCategory(buttonWidget, category);
									IInterface_Game_RibbonButton::Execute_GetDefaultIndexInCategory(buttonWidget, buttonIndex);
				
									UGame_UserWidget_RibbonEditor_ButtonStandin* ribbonButton = Cast<UGame_UserWidget_RibbonEditor_ButtonStandin>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), ButtonWidgetClass, FName(*FGuid::NewGuid().ToString())));
									ribbonButton->ID = buttonWidget->ID;
									ribbonButton->Index = buttonIndex;
									if(FRibbonButtonProxyOverride* visualOverride = VisualOverrides.Find(ribbonButton->ID))
									{
										ribbonButton->SetText(visualOverride->Text);
										ribbonButton->SetIcon(visualOverride->Icon);
									}
									else
									{
										ribbonButton->SetText(buttonWidget->Text);
										ribbonButton->SetIcon(buttonWidget->Icon);
									}
									ribbonButton->OnBeginDragEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleBeginWidgetDrag);
									ribbonButton->OnDragOverEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
									ribbonButton->OnDropEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
									EmplaceButton(ribbonButton, tab, category, buttonIndex);
								}
							}
						}
						ShowError(TEXT(""));
					}
				}
				else
				{
					LoadDefaultLayout();
				}
			}
		}
	}
	else
	{
		//Cannot have an empty name
		ShowError(TEXT("Load Failed: Name cannot be empty"));
	}
	
	Spacer->OnDragOverEvent.AddUniqueDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
	Spacer->OnDropEvent.AddUniqueDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
	
	Trash->OnDragOverEvent.AddUniqueDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
	Trash->OnDropEvent.AddUniqueDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
	Trash->SetText(TEXT("Removed Items"));
	
	Background->OnDragOverEvent.AddUniqueDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
	Background->OnDropEvent.AddUniqueDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
}

void UGame_UserWidget_RibbonEditor::LoadDefaultLayout()
{
	if(UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
	{
		CurrentLayout = TEXT("Default");
		
		TabButtonList->ClearChildren();
		TabContainers->ClearChildren();
		TabContainers->SetActiveWidgetIndex(0);
		Trash->GetPanelWidget()->ClearChildren();

		TArray<FString> tabs;
		ribbonSubsystem->TabIndices.GetKeys(tabs);
		TMap<FString, double>& tabIndices = ribbonSubsystem->TabIndices;

		tabs.Sort([tabIndices](const FString& tab1, const FString& tab2) {
				return tabIndices[tab1] <  tabIndices[tab2];
			});

		for(int i = 0; i < tabs.Num(); i++)
		{
			UGame_UserWidget_RibbonEditor_TabButtonStandin* newTab;
			AddTab(tabs[i], newTab);
			
			TArray<FString> cats;
			ribbonSubsystem->CategoryIndices[tabs[i]].GetKeys(cats);
			TMap<FString, double>& catIndices = ribbonSubsystem->CategoryIndices[tabs[i]];

			cats.Sort([catIndices](const FString& cat1, const FString& cat2) {
					return catIndices[cat1] <  catIndices[cat2];
				});
			
			for(int j = 0; j < cats.Num(); j++)
			{
				UGame_UserWidget_RibbonEditor_CategoryStandin* newCat;
				AddCategory(cats[j], newTab->LinkedContainer, newCat);
			}
		}

		TArray<FString> keys;
		ribbonSubsystem->RegisteredButtons.GetKeys(keys);
		
		FString tab = TEXT("");
		FString category = TEXT("");
		double buttonIndex = -1;
		
		for(const FString& key : keys)
		{
			if(UGame_UserWidget_RibbonButton* buttonWidget = Cast<UGame_UserWidget_RibbonButton>(ribbonSubsystem->GetRibbonButtonByID(key)))
			{
				IInterface_Game_RibbonButton::Execute_GetDefaultTab(buttonWidget, tab);
				IInterface_Game_RibbonButton::Execute_GetDefaultCategory(buttonWidget, category);
				IInterface_Game_RibbonButton::Execute_GetDefaultIndexInCategory(buttonWidget, buttonIndex);
				
				UGame_UserWidget_RibbonEditor_ButtonStandin* ribbonButton = Cast<UGame_UserWidget_RibbonEditor_ButtonStandin>(UUserWidget::CreateWidgetInstance(*UDeveloper_Statics::GetVHWorld(), ButtonWidgetClass, FName(*FGuid::NewGuid().ToString())));
				ribbonButton->ID = buttonWidget->ID;
				ribbonButton->Index = buttonIndex;
				if(FRibbonButtonProxyOverride* visualOverride = VisualOverrides.Find(ribbonButton->ID))
				{
					ribbonButton->SetText(visualOverride->Text);
					ribbonButton->SetIcon(visualOverride->Icon);
				}
				else
				{
					ribbonButton->SetText(buttonWidget->Text);
					ribbonButton->SetIcon(buttonWidget->Icon);
				}
				ribbonButton->OnBeginDragEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleBeginWidgetDrag);
				ribbonButton->OnDragOverEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetOver);
				ribbonButton->OnDropEvent.AddDynamic(this, &UGame_UserWidget_RibbonEditor::HandleWidgetDropped);
				EmplaceButton(ribbonButton, tab, category, buttonIndex);
			}
		}
		ShowError(TEXT(""));
	}
}

bool UGame_UserWidget_RibbonEditor::SaveLayout(const FString& layoutName)
{
	bool bSuccessfulSave = false;
	if(!layoutName.IsEmpty())
	{
		if(layoutName.Equals(TEXT("default"), ESearchCase::IgnoreCase))
		{
			//Default is a reserved name
			ShowError(TEXT("Save Failed: Default is a reserved name"));
		}
		else if(!FPaths::ValidatePath(layoutName))
		{
			//Name contains invalid characters
			ShowError(TEXT("Save Failed: Name contains invalid characters"));
		}
		else
		{
			FString path = GetPathForLayout(layoutName);
		
			FXmlFile xmlFile;
			xmlFile.LoadFile(TEXT("<Layout></Layout>"), EConstructMethod::ConstructFromBuffer);
	
			if (xmlFile.IsValid())
			{
				if (FXmlNode* node = xmlFile.GetRootNode())
				{
					bool bHasSettings = false;
					
					node->AppendChildNode(TEXT("Buttons"));
					FXmlNode* buttonListNode = node->FindChildNode(TEXT("Buttons"));
					
					node->AppendChildNode(TEXT("Tabs"));
					FXmlNode* tabListNode = node->FindChildNode(TEXT("Tabs"));
					
					TArray<UWidget*> tabList = TabButtonList->GetAllChildren();
					TArray<UWidget*> catList;
					TArray<UWidget*> buttonList;
					for(int i = 0; i < tabList.Num(); i++)
					{
						if(UGame_UserWidget_RibbonEditor_TabButtonStandin* tabWidget = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(tabList[i]))
						{
							tabListNode->AppendChildNode(tabWidget->Text);
							FXmlNode* catListNode = tabListNode->FindChildNode(tabWidget->Text);
							catList = tabWidget->LinkedContainer->GetPanelWidget()->GetAllChildren();
							for(int j = 0; j < catList.Num(); j++)
							{
								if(UGame_UserWidget_RibbonEditor_CategoryStandin* catWidget = Cast<UGame_UserWidget_RibbonEditor_CategoryStandin>(catList[j]))
								{
									catListNode->AppendChildNode(catWidget->Text);
									buttonList = catWidget->GetPanelWidget()->GetAllChildren();
									for(int k = 0; k < buttonList.Num(); k++)
									{
										if(UGame_UserWidget_RibbonEditor_ButtonStandin* widget = Cast<UGame_UserWidget_RibbonEditor_ButtonStandin>(buttonList[k]))
										{
											buttonListNode->AppendChildNode(widget->ID);
											FXmlNode* buttonNode = buttonListNode->FindChildNode(widget->ID);

											buttonNode->AppendChildNode(TEXT("Tab"),tabWidget->Text);
											buttonNode->AppendChildNode(TEXT("Category"),catWidget->Text);
											buttonNode->AppendChildNode(TEXT("Index"),FString::FromInt(widget->Index));

											bHasSettings |= widget->ID.Equals(TEXT("Settings"));
										}
									}
								}
							}
						}
					}
					
					node->AppendChildNode(TEXT("Trash"));
					FXmlNode* trashNode = node->FindChildNode(TEXT("Trash"));
					
					TArray<UWidget*> trashList = Trash->GetPanelWidget()->GetAllChildren();
					for(int i = 0; i < trashList.Num(); i++)
					{
						if(UGame_UserWidget_RibbonEditor_ButtonStandin* widget = Cast<UGame_UserWidget_RibbonEditor_ButtonStandin>(trashList[i]))
						{
							trashNode->AppendChildNode(widget->ID);
						}
					}
					if(bHasSettings)
					{
						CurrentLayout = layoutName;
						bSuccessfulSave = xmlFile.Save(path);
						ShowError(TEXT(""));
					}
					else
					{
						//Cannot save a layout with the settings button inaccessible
						ShowError(TEXT("Save Failed: Settings button must be accessible"));
					}
				}
			}
		}
	}
	else
	{
		//Cannot have an empty name
		ShowError(TEXT("Save Failed: Name cannot be empty"));
	}

	return bSuccessfulSave;
}

void UGame_UserWidget_RibbonEditor::SwitchToTab(UGame_UserWidget_RibbonEditor_TabButtonStandin* tabToLoad)
{
	tabToLoad->SetHoverBarPercent(0);
	TabContainers->SetActiveWidget(tabToLoad->LinkedContainer);
}

FString UGame_UserWidget_RibbonEditor::GetPathForLayout(const FString& layoutName)
{
	return FPaths::Combine(LayoutFolderPath, TEXT("" + layoutName + ".xml"));
}

void UGame_UserWidget_RibbonEditor::ImportLayout(const FString& layoutPath)
{
	IFileManager& fileManager = IFileManager::Get();
	FString newFilePath = FPaths::Combine(LayoutFolderPath, FPaths::GetCleanFilename(layoutPath));
	fileManager.Copy(ToCStr(newFilePath), ToCStr(layoutPath));
}

void UGame_UserWidget_RibbonEditor::ExportLayout(const FString& newPath)
{
	IFileManager& fileManager = IFileManager::Get();
	FString oldPath = FPaths::Combine(LayoutFolderPath, TEXT("" + CurrentLayout + ".xml"));
	fileManager.Copy(ToCStr(newPath), ToCStr(oldPath));
}

void UGame_UserWidget_RibbonEditor::DeleteLayout(const FString& layoutName)
{
	IFileManager& fileManager = IFileManager::Get();
	fileManager.Delete(ToCStr(GetPathForLayout(layoutName)));
}


// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_RibbonEditor::HandleBeginWidgetDrag(UGame_UserWidget_RibbonEditor_DraggableWidget* dragWidget,
                                                          const FGeometry& inGeometry, const FPointerEvent& inMouseEvent, UDragDropOperation* inOperation)
{
	//Remove dragged item from parent to begin movement, add spacer where it was
	SetSpacerSize(dragWidget->GetDesiredSize());
	dragWidget->RemoveFromParent();
	SetSpacerLocation(dragWidget->Parent, dragWidget->Index);
	IsDragging = true;
	ShowError("");
}

void UGame_UserWidget_RibbonEditor::HandleWidgetOver(UGame_UserWidget_RibbonEditor_DropTarget* overTarget,
	const FGeometry& inGeometry, const FVector2D& inDragDropLocation, UDragDropOperation* inOperation)
{
	if(inDragDropLocation != CurrentLocation)
	{
		CurrentLocation = inDragDropLocation;
		ErrorMessage = TEXT("");
		
		FGeometry OverridableGeometry = inGeometry;
		Spacer->SetVisibility(ESlateVisibility::Visible);
		if(overTarget != CurrentHover)
		{
			if(UGame_UserWidget_RibbonEditor_TabButtonStandin* widget = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(CurrentHover))
			{
				widget->SetHoverBarPercent(0);
				HoverTimer = -1;
			}
			CurrentHover = overTarget;
		}
	
		//Check if the spacer needs to be moved to a new location
		if(UGame_DragDropOperation_RibbonEditor* DragOperation = Cast<UGame_DragDropOperation_RibbonEditor>(inOperation))
		{
			if(DragOperation->DragTarget->Type == EDragDropTargetType::RibbonButton)
			{
				TArray<UWidget*> children;
				switch (overTarget->Type)
				{
				case EDragDropTargetType::RibbonButton:
					if(UGame_UserWidget_RibbonEditor_DraggableWidget* target = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(overTarget))
					{
						float percent = OverridableGeometry.AbsoluteToLocal(inDragDropLocation).X / OverridableGeometry.GetLocalSize().X;
						int index = target->Parent->GetChildIndex(target);
						if(index > SpacerIndex)
						{
							index--;
						}
						SetSpacerLocation(target->Parent, index + std::round(percent));
					}
					break;
				case EDragDropTargetType::Category:
				case EDragDropTargetType::Trash:
					//Put the spacer in the closest valid slot
					children = overTarget->GetPanelWidget()->GetAllChildren();
					for(int i = 0; i < children.Num(); i++)
					{
						OverridableGeometry = children[i]->GetCachedGeometry();
						if(OverridableGeometry.AbsoluteToLocal(inDragDropLocation).X / OverridableGeometry.GetLocalSize().X < 0.5)
						{
							SetSpacerLocation(overTarget->GetPanelWidget(), i);
							return;
						}
					}
					SetSpacerLocation(overTarget->GetPanelWidget(), children.Num());
					break;
				case EDragDropTargetType::TabButton:
					//Switch to linked tab if hovered long enough
					if(UGame_UserWidget_RibbonEditor_TabButtonStandin* widget = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(overTarget))
					{
						children = widget->LinkedContainer->GetPanelWidget()->GetAllChildren();
						if(children.Num() > 0)
						{
							if(UGame_UserWidget_RibbonEditor_DraggableWidget* newParent = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(children[children.Num() - 1]))
							{
								SetSpacerLocation(newParent->GetPanelWidget(), newParent->GetPanelWidget()->GetChildrenCount());
							}
						}
						else
						{
							if(UGame_UserWidget_RibbonEditor_DraggableWidget* draggedWidget = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(DragOperation->DragTarget))
							{
								//If there's no category to put the button in, return it to where it came from
								SetSpacerLocation(draggedWidget->Parent, draggedWidget->Index);
								ErrorMessage = TEXT("No valid category in target tab");
							}
						}

						//Start the timer
						if(TabContainers->GetActiveWidget() != widget->LinkedContainer && HoverTimer < 0)
						{
							HoverTimer = 0;
						}
					}
					break;
				case EDragDropTargetType::Spacer:
					//Do nothing
					break;
				case EDragDropTargetType::TabContainer:
				case EDragDropTargetType::Background:
					//Put the spacer where the widget started
					SetSpacerLocation(DragOperation->DragTarget->Parent, DragOperation->DragTarget->Index);
					break;
				}
			}
			else if(DragOperation->DragTarget->Type == EDragDropTargetType::Category)
			{
				if(overTarget->Type == EDragDropTargetType::RibbonButton)
				{
					//Actually use the category containing the hovered button
					overTarget = Cast<UGame_UserWidget_RibbonEditor_DropTarget>(overTarget->GetParent()->GetTypedOuter(UGame_UserWidget_RibbonEditor_DropTarget::StaticClass()));
					OverridableGeometry = overTarget->GetCachedGeometry();
				}
				switch (overTarget->Type)
				{
				case EDragDropTargetType::RibbonButton:
				case EDragDropTargetType::Category:
					if(UGame_UserWidget_RibbonEditor_DraggableWidget* target = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(overTarget))
					{
						if(TabContainsCatOfName(target->Parent, DragOperation->DragTarget->Text))
						{
							SetSpacerLocation(DragOperation->DragTarget->Parent, DragOperation->DragTarget->Index);
							ErrorMessage = TEXT("Target tab already contains a category of that name");
						}
						else
						{
							float percent = OverridableGeometry.AbsoluteToLocal(inDragDropLocation).X / OverridableGeometry.GetLocalSize().X;
							int index = target->Parent->GetChildIndex(target);
							if(index > SpacerIndex)
							{
								index--;
							}
							SetSpacerLocation(target->Parent, index + std::round(percent));
						}
					}
					break;
				case EDragDropTargetType::TabContainer:
					if(TabContainsCatOfName(overTarget->GetPanelWidget(), DragOperation->DragTarget->Text))
					{
						SetSpacerLocation(DragOperation->DragTarget->Parent, DragOperation->DragTarget->Index);
						ErrorMessage = TEXT("Target tab already contains a category of that name");
					}
					else
					{
						SetSpacerLocation(overTarget->GetPanelWidget(), overTarget->GetPanelWidget()->GetChildrenCount());
					}
					break;
				case EDragDropTargetType::Trash:
					Spacer->SetVisibility(ESlateVisibility::Collapsed);
					break;
				case EDragDropTargetType::TabButton:
					//Switch to linked tab if hovered long enough
					if(UGame_UserWidget_RibbonEditor_TabButtonStandin* widget = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(overTarget))
					{
						if(TabContainsCatOfName(widget->LinkedContainer->GetPanelWidget(), DragOperation->DragTarget->Text))
						{
							SetSpacerLocation(DragOperation->DragTarget->Parent, DragOperation->DragTarget->Index);
							ErrorMessage = TEXT("Target tab already contains a category of that name");
						}
						else
						{
							SetSpacerLocation(widget->LinkedContainer->GetPanelWidget(), widget->LinkedContainer->GetPanelWidget()->GetChildrenCount());
						}
							
						//Start the timer
						if(TabContainers->GetActiveWidget() != widget->LinkedContainer && HoverTimer < 0)
						{
							HoverTimer = 0;
						}
					}
					break;
				case EDragDropTargetType::Spacer:
					break;
				case EDragDropTargetType::Background:
					//Put the spacer where the widget started
					SetSpacerLocation(DragOperation->DragTarget->Parent, DragOperation->DragTarget->Index);
					break;
				}
			}
			else if(DragOperation->DragTarget->Type == EDragDropTargetType::TabButton)
			{
				if(overTarget->Type == EDragDropTargetType::RibbonButton)
				{
					//Actually use the category containing the hovered button
					overTarget = Cast<UGame_UserWidget_RibbonEditor_DropTarget>(overTarget->GetParent()->GetTypedOuter(UGame_UserWidget_RibbonEditor_DropTarget::StaticClass()));
					OverridableGeometry = overTarget->GetCachedGeometry();
				}
				switch (overTarget->Type)
				{
				case EDragDropTargetType::TabButton:
					if(UGame_UserWidget_RibbonEditor_DraggableWidget* target = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(overTarget))
					{
						float percent = OverridableGeometry.AbsoluteToLocal(inDragDropLocation).X / OverridableGeometry.GetLocalSize().X;
						int index = target->Parent->GetChildIndex(target);
						if(index > SpacerIndex)
						{
							index--;
						}
						SetSpacerLocation(target->Parent, index + std::round(percent));
					}
					break;
				case EDragDropTargetType::Background:
				case EDragDropTargetType::RibbonButton:
				case EDragDropTargetType::Category:
				case EDragDropTargetType::TabContainer:
					//Put the spacer where the widget started
					SetSpacerLocation(DragOperation->DragTarget->Parent, DragOperation->DragTarget->Index);
					break;
				case EDragDropTargetType::Trash:
					//Hide spacer
					Spacer->SetVisibility(ESlateVisibility::Collapsed);
					break;
				case EDragDropTargetType::Spacer:
					//Do nothing
					break;
				}
			}
		}
	}
}

void UGame_UserWidget_RibbonEditor::HandleWidgetDropped(UGame_UserWidget_RibbonEditor_DropTarget* dropTarget,
                                                        const FGeometry& inGeometry, const FVector2D& inDragDropLocation, UDragDropOperation* inOperation)
{
	if(IsDragging)
	{
		IsDragging = false;
		if(UGame_UserWidget_RibbonEditor_TabButtonStandin* widget = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(CurrentHover))
		{
			widget->SetHoverBarPercent(0);
			HoverTimer = -1;
		}
		CurrentHover = nullptr;
		if(UGame_DragDropOperation_RibbonEditor* DragOperation = Cast<UGame_DragDropOperation_RibbonEditor>(inOperation))
		{
			TArray<UWidget*> children;
			bool bMoveToSpacer = false;
		
			if(DragOperation->DragTarget->Type == EDragDropTargetType::RibbonButton)
			{
				bMoveToSpacer = true;
			}
			else if(DragOperation->DragTarget->Type == EDragDropTargetType::Category)
			{
				if(dropTarget->Type == EDragDropTargetType::RibbonButton)
				{
					//Actually use the category containing the hovered button
					dropTarget = Cast<UGame_UserWidget_RibbonEditor_DropTarget>(dropTarget->GetParent()->GetTypedOuter(UGame_UserWidget_RibbonEditor_DropTarget::StaticClass()));
				}
				
				switch (dropTarget->Type)
				{
					case EDragDropTargetType::RibbonButton:
					case EDragDropTargetType::Category:
					case EDragDropTargetType::Spacer:
					case EDragDropTargetType::Background:
					case EDragDropTargetType::TabButton:
					case EDragDropTargetType::TabContainer:
						bMoveToSpacer = true;
						break;
					case EDragDropTargetType::Trash:
						//Destroy and move contained buttons to the trash
						children = DragOperation->DragTarget->GetPanelWidget()->GetAllChildren();
						for(int i = 0; i < children.Num(); i++)
						{
							if(UGame_UserWidget_RibbonEditor_DraggableWidget* widget = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(children[i]))
							{
								dropTarget->GetPanelWidget()->AddChild(widget);
								widget->Parent = dropTarget->GetPanelWidget();
								widget->Index = dropTarget->GetPanelWidget()->GetChildrenCount();
							}
						}
						break;
				}
			}
			else if(DragOperation->DragTarget->Type == EDragDropTargetType::TabButton)
			{
				if(dropTarget->Type == EDragDropTargetType::RibbonButton)
				{
					//Actually use the category containing the hovered button
					dropTarget = Cast<UGame_UserWidget_RibbonEditor_DropTarget>(dropTarget->GetParent()->GetTypedOuter(UGame_UserWidget_RibbonEditor_DropTarget::StaticClass()));
				}
				
				switch (dropTarget->Type)
				{
					case EDragDropTargetType::RibbonButton:
					case EDragDropTargetType::Category:
					case EDragDropTargetType::TabButton:
					case EDragDropTargetType::Spacer:
					case EDragDropTargetType::Background:
					case EDragDropTargetType::TabContainer:
						bMoveToSpacer = true;
						break;
					case EDragDropTargetType::Trash:
						//Move all buttons to trash and destroy the tab and cats
						if(UGame_UserWidget_RibbonEditor_TabButtonStandin* tabWidget = Cast<UGame_UserWidget_RibbonEditor_TabButtonStandin>(DragOperation->DragTarget))
						{
							children = tabWidget->LinkedContainer->GetPanelWidget()->GetAllChildren();
							TArray<UWidget*> childrenChildren;
							for(int i = 0; i < children.Num(); i++)
							{
								if(UGame_UserWidget_RibbonEditor_DraggableWidget* catWidget = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(children[i]))
								{
									childrenChildren = catWidget->GetPanelWidget()->GetAllChildren();
									for(int j = 0; j < childrenChildren.Num(); j++)
									{
										if(UGame_UserWidget_RibbonEditor_DraggableWidget* widget = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(childrenChildren[j]))
										{
											dropTarget->GetPanelWidget()->AddChild(widget);
											widget->Parent = dropTarget->GetPanelWidget();
											widget->Index = dropTarget->GetPanelWidget()->GetChildrenCount();
										}
									}
									catWidget->RemoveFromParent();
								}
							}
							tabWidget->LinkedContainer->RemoveFromParent();
						}
						break;
				}
			}
			Spacer->RemoveFromParent();

			if(bMoveToSpacer)
			{
				//Put it where the spacer is
				InsertChild(DragOperation->DragTarget, SpacerParent, SpacerIndex);
				children = SpacerParent->GetAllChildren();
				for(int i = 0; i < children.Num(); i++)
				{
					if(UGame_UserWidget_RibbonEditor_DraggableWidget* widget = Cast<UGame_UserWidget_RibbonEditor_DraggableWidget>(children[i]))
					{
						widget->Parent = SpacerParent;
						widget->Index = i;
					}
				}
			}

			SetSpacerSize(FVector2D::Zero());
			SpacerParent = nullptr;
			Trash->GetPanelWidget()->AddChild(Spacer);

			DragOperation->DragTarget->SetVisibility(ESlateVisibility::Visible);
			ShowError(ErrorMessage);
		}
	}
}
