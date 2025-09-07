
#pragma once

// Depends on code from the plugin browser to work correctly
#include "IPluginWizardDefinition.h"

class FVH_PluginsPluginWizardDefinition : public IPluginWizardDefinition
{
public:
	FVH_PluginsPluginWizardDefinition();

	// Begin IPluginWizardDefinition interface
	virtual const TArray<TSharedRef<FPluginTemplateDescription>>& GetTemplatesSource() const override;
	virtual void OnTemplateSelectionChanged(TSharedPtr<FPluginTemplateDescription> InSelectedItem, ESelectInfo::Type SelectInfo) override;
	virtual bool HasValidTemplateSelection() const override;
	virtual TSharedPtr<FPluginTemplateDescription> GetSelectedTemplate() const override;
	virtual void ClearTemplateSelection() override;


	virtual bool CanShowOnStartup() const override { return true; }
	virtual bool HasModules() const override;

	/**
	* Whether or not this plugin is considered a mod
	* Setting this to false will generate the plugin in the "Mods" folder instead of the "Plugins" Folder.
	*/
	virtual bool IsMod() const override;
	virtual void OnShowOnStartupCheckboxChanged(ECheckBoxState CheckBoxState) override;
	virtual ECheckBoxState GetShowOnStartupCheckBoxState() const override;
	virtual TSharedPtr<class SWidget> GetCustomHeaderWidget() override;
	virtual FText GetInstructions() const override;

	virtual bool GetPluginIconPath(FString& OutIconPath) const override;
	virtual EHostType::Type GetPluginModuleDescriptor() const override;
	virtual ELoadingPhase::Type GetPluginLoadingPhase() const override;
	virtual bool GetTemplateIconPath(TSharedRef<FPluginTemplateDescription> InTemplate, FString& OutIconPath) const override;
	virtual FString GetPluginFolderPath() const override;
	virtual TArray<FString> GetFoldersForSelection() const override;
	virtual void PluginCreated(const FString& PluginName, bool bWasSuccessful) const override;

private:
	/** Creates the templates that can be used by the plugin manager to generate the plugin */
	void PopulateTemplatesSource();

	/** Gets the folder for the specified template. */
	FString GetFolderForTemplate(TSharedRef<FPluginTemplateDescription> InTemplate) const;

	// End IPluginWizardDefinition interface

private:

	///TODO These three are in interface, do they neeed to be here as well?  If so, there's some more properties in there we'll need here too.

	/** The available templates for the mod. They should function as mixins to the backing template */
	TArray<TSharedRef<FPluginTemplateDescription>> TemplateDefinitions;
	
	/** The currently selected template definition */
	TSharedPtr<FPluginTemplateDescription> CurrentTemplateDefinition;

	/** The content that will be used when creating the mod */
	TArray<TSharedRef<FPluginTemplateDescription>> SelectedTemplates;


	/** The base directory of this plugin. Used for accessing the templates used to create mods */
	FString PluginBaseDir;

	/**
	 * The path to the template that ultimately serves as the template that the mod will be based on. It's not intended to be
	 * selected directly, but rather other templates will act as mixins to define what content will exist in the plugin.
	 */
	FString BackingTemplatePath;

	/** The backing template definition for the mod. This should never be directly selectable */
	TSharedPtr<FPluginTemplateDescription> BackingTemplate;

	/** The base code template definition. Can be directly selectable to create an "empty" code mod, but should be included with any code mod selection */
	TSharedPtr<FPluginTemplateDescription> BaseCodeTemplate;

	/**
	 * Add per-project templates here
	 */
	 
	/** VTAK Example plugin	 */
	TSharedPtr<FPluginTemplateDescription> VTAK_ExampleTemplate;

	/** VTAK Example plugin	 */
	TSharedPtr<FPluginTemplateDescription> VTAK_BlankTemplate;

	/**
	* End per-project templates
	*/

	/** Maps a specific template to a specific icon file */
	TMap<FString, FString> TemplateToIconMap;

	/** Brush used for drawing the custom header widget */
	TSharedPtr<struct FSlateDynamicImageBrush> IconBrush;

	/** Custom header widget */
	TSharedPtr<class SWidget> CustomHeaderWidget;
};