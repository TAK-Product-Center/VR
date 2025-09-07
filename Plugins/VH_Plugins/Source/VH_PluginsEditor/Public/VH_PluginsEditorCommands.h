#pragma once

#include "Framework/Commands/Commands.h"
#include "VH_PluginsEditorStyle.h"

class FVH_PluginsEditorCommands : public TCommands<FVH_PluginsEditorCommands>
{
public:

	FVH_PluginsEditorCommands()
		: TCommands<FVH_PluginsEditorCommands>(TEXT("VH_PluginsEditor"), NSLOCTEXT("Contexts", "VH_PluginsEditor", "VH_PluginsEditor Plugin"), NAME_None, FVH_PluginsEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

	TArray<TSharedPtr<FUICommandInfo>> RegisterUGCCommands(const TArray<TSharedRef<class IPlugin>>& UGCList) const;
	void UnregisterUGCCommands(TArray<TSharedPtr<FUICommandInfo>>& UICommands) const;

public:
	TSharedPtr< FUICommandInfo > CreateUGCAction;
	TSharedPtr< FUICommandInfo > PackageUGCAction;
};