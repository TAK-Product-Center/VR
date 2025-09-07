#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Engine Includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"

// Generated Includes
#include "UI_Subsystem_Core.generated.h"

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EUIType : uint8
{
	Viewport,
	World,
	PopoutWindow
};

UENUM(BlueprintType)
enum class ETabContainerType : uint8
{
	/* does not use tab containers */
	None,

	/* use an existing tab container if any exist; otherwise create new tab container */
	Existing,

	/* create a new tab container */
	New
};

// copied from SWindow.h to expose to blueprint; should be updated each Engine integration
UENUM(BlueprintType)
enum class EBlueprintWindowSizingRule : uint8
{
	/* The windows size fixed and cannot be resized */
	FixedSize,

	/* The window size is computed from its content and cannot be resized by users */
	Autosized,

	/* The window can be resized by users */
	UserSized,
};

// copied from SWindow.h to expose to blueprint; should be updated each Engine integration
UENUM(BlueprintType)
enum class EBlueprintWindowActivationPolicy : uint8
{
	/* Value indicating that a window never activates when it is shown */
	Never,

	/* Value indicating that a window always activates when it is shown */
	Always,

	/* Value indicating that a window only activates when it is first shown */
	FirstShown
};

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FOpenBehavior
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EHardwareInterfaceMode, EUIType> OpenBehavior;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAllowMultipleInstances;

	FOpenBehavior() :
		bAllowMultipleInstances(false)
	{
		
	}
};

USTRUCT(BlueprintType)
struct FOpenUserWidgetViewportSettings
{
	GENERATED_BODY()

	/* position in viewport; 0, 0 is top left */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D Position;

	/* pixel size */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D Size;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FAnchors Anchors;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D Alignment;

	FOpenUserWidgetViewportSettings() :
		Position(FVector2D(0, 0)),
		Size(FVector2D(1200, 800)),
		Alignment(FVector2D(0, 0))
	{

	}
};

USTRUCT(BlueprintType)
struct FOpenUserWidgetWorldSettings
{
	GENERATED_BODY()

	/* if WorldUIActor and WorldUIActorClass are nullptr, uses subsystem's DefaultWorldSettings */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> WorldUIActorClass;

	/* if WorldUIActor is nullptr, spawns actor using WorldUIActoClass */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* WorldUIActor;

	/* local offset from player camera to use if spawning WorldUIActor */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector LocalSpawnOffset;

	/* size of widget in WidgetComponent of WorldUIActor */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D Size;

	FOpenUserWidgetWorldSettings() :
		WorldUIActor(nullptr),
		LocalSpawnOffset(FVector(0, 0, 0)),
		Size(FVector2D(1200, 800))
	{

	}
};

// copied from SWindow.h to expose to blueprint; should be updated each Engine integration
USTRUCT(BlueprintType)
struct FOpenUserWidgetWindowSettings
{
	GENERATED_BODY()

	/* Title of the window */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Title;

	/* Does this window auto-center? If set to true, then the
		ScreenPosition value will be ignored */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool AutoCenter;

	/* Screen-space position where the window should be initially located. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D ScreenPosition;

	/* What the initial size of the window should be. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D ClientSize;

	/* Should this window support transparency */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool SupportsTransparency;

	/* The initial opacity of the window */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double InitialOpacity;

	/* Is the window initially maximized */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsInitiallyMaximized;

	/* Is the window initially minimized */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsInitiallyMinimized;

	/* How the window should be sized */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EBlueprintWindowSizingRule SizingRule;

	/* True if this window should always be on top of all other windows */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsTopmostWindow;

	/* Should this window be focused immediately after it is shown? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool FocusWhenFirstShown;

	/* When should this window be activated upon being shown? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EBlueprintWindowActivationPolicy ActivationPolicy;

	/* Use the default os look for the border of the window */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseOSWindowBorder;

	/* Does this window have a close button? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool HasCloseButton;
	
	/* Can this window be maximized? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool SupportsMaximize;
	
	/* Can this window be minimized? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool SupportsMinimize;
	
	/* Should this window preserve its aspect ratio when resized by user? */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldPreserveAspectRatio;
	
	/* The smallest width this window can be in Desktop Pixel Units. 0 means to ignore. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinWidth;

	/* The smallest height this window can be in Desktop Pixel Units. 0 means to ignore. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinHeight;

	/* The biggest width this window can be in Desktop Pixel Units. 0 means to ignore. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxWidth;

	/* The biggest height this window can be in Desktop Pixel Units. 0 means to ignore. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHeight;

	/* True if we should initially create a traditional title bar area.  If false, the user must embed the title
		area content into the window manually, taking into account platform-specific considerations!  Has no
		effect for certain types of windows (popups, tool-tips, etc.) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool CreateTitleBar;

	/* If the window appears off screen or is too large to safely fit this flag will force realistic
		constraints on the window and bring it back into view. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool SaneWindowPlacement;

	/* The padding around the edges of the window applied to it's content. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FMargin LayoutBorder;

	/* The margin around the edges of the window that will be detected as places the user can grab to resize the window. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FMargin UserResizeBorder;

	/* true if this window will self handle any eventual DPI adjustments */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bManualManageDPI;
	
	FOpenUserWidgetWindowSettings() :
		Title(TEXT("")),
		AutoCenter(true),
		ScreenPosition(FVector2D(0, 0)),
		ClientSize(FVector2D(1200, 800)),
		SupportsTransparency(false),
		InitialOpacity(1.0f),
		IsInitiallyMaximized(false),
		IsInitiallyMinimized(false),
		SizingRule(EBlueprintWindowSizingRule::UserSized),
		IsTopmostWindow(false),
		FocusWhenFirstShown(true),
		ActivationPolicy(EBlueprintWindowActivationPolicy::Always),
		UseOSWindowBorder(true),
		HasCloseButton(true),
		SupportsMaximize(true),
		SupportsMinimize(true),
		ShouldPreserveAspectRatio(false),
		MinWidth(0),
		MinHeight(0),
		MaxWidth(0),
		MaxHeight(0),
		CreateTitleBar(true),
		SaneWindowPlacement(true),
		UserResizeBorder(FMargin(5, 5, 5, 5)),
		bManualManageDPI(false)
	{
		
	}
};

USTRUCT(BlueprintType)
struct FTabContainerSettings
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ETabContainerType TabContainerType;

	/* if needs TabContainer and TabContainer and TabContainerClass are nullptr, uses subsystem's default TabContainerSettings */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> TabContainerClass;

	/* if needs TabContainer and TabContainer is nullptr, spawns tab container using TabContainerClass */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UUserWidget* TabContainer;

	FTabContainerSettings()
	{
		TabContainerType = ETabContainerType::None;
		TabContainer = nullptr;
	}
};

class UWidgetComponent;
class UI_Subsystem_Core_Settings;

UCLASS()
class VH_UI_API UUI_Subsystem_Core : public UGameInstanceSubsystem
{
	GENERATED_BODY()
		
	
	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserWidgetClosed, UUserWidget*, userWidget);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserWidgetOpened, UUserWidget*, userWidget);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnUserWidgetClosed OnUserWidgetClosed;

	UPROPERTY(BlueprintAssignable)
	FOnUserWidgetOpened OnUserWidgetOpened;

	/* default viewport settings; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FOpenUserWidgetViewportSettings DefaultViewportSettings;

	/* default world settings; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FOpenUserWidgetWorldSettings DefaultWorldSettings;

	/* default window settings; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FOpenUserWidgetWindowSettings DefaultWindowSettings;

	/* default tab settings; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTabContainerSettings DefaultTabContainerSettings;

	/* holds default opening behavior based on hardware interface mode; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EHardwareInterfaceMode, EUIType> DefaultOpenBehavior;

	/* if true, allows multiple instances of a widget from a particular class */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bDefaultAllowMultipleInstances;

	/* overrides DefaultViewportSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenUserWidgetViewportSettings> DefaultClassViewportSettings;
	
	/* overrides DefaultWorldSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenUserWidgetWorldSettings> DefaultClassWorldSettings;
	
	/* overrides DefaultWindowSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenUserWidgetWindowSettings> DefaultClassWindowSettings;
	
	/* overrides DefaultTabContainerSettings for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FTabContainerSettings> DefaultClassTabContainerSettings;
	
	/* overrides DefaultOpenBehavior for specific classes; used by the OpenWithDefaults functions */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<TSubclassOf<UUserWidget>, FOpenBehavior> DefaultClassOpenBehavior;

private:
	/* if value is nullptr, key is not in a container */
	TMap<UUserWidget*, UUserWidget*> UserWidgetToTabContainer;

	/* holds containers and non-containers */
	TMap<UUserWidget*, TSharedPtr<SWindow>> UserWidgetToWindow;

	/* holds containers and non-containers */
	TMap<UUserWidget*, AActor*> UserWidgetToWorldUIActor;

	/* holds non-containers */
	TMap<TSubclassOf<UUserWidget>, TSet<UUserWidget*>> UserWidgets;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UUI_Subsystem_Core();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;

	virtual void Deinitialize() override;
	

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UUI_Subsystem_Core* Get();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* \brief Convenience function to set class variables
	* \param settings Settings object to use to set class variables
	*/
	UFUNCTION(BlueprintCallable)
	void UpdateSettings(TSubclassOf<UUI_Subsystem_Core_Settings> settingsClass);

	/*
	* \brief Opens user widget using subsystem defaults
	*/
	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "userWidgetClass"))
	UUserWidget* OpenWithDefaultsByClass(TSubclassOf<UUserWidget> userWidgetClass);

	UFUNCTION(BlueprintCallable)
	bool OpenWithDefaults(UUserWidget* userWidget);

	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "userWidgetClass"))
	UUserWidget* OpenInViewportByClass(TSubclassOf<UUserWidget> userWidgetClass, const FTabContainerSettings& tabContainerSettings, const FOpenUserWidgetViewportSettings& viewportSettings);

	UFUNCTION(BlueprintCallable)
	bool OpenInViewport(UUserWidget* userWidget, const FTabContainerSettings& tabContainerSettings, const FOpenUserWidgetViewportSettings& viewportSettings);

	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "userWidgetClass"))
	UUserWidget* OpenInWorldByClass(TSubclassOf<UUserWidget> userWidgetClass, const FTabContainerSettings& tabContainerSettings, const FOpenUserWidgetWorldSettings& worldSettings);

	UFUNCTION(BlueprintCallable)
	bool OpenInWorld(UUserWidget* userWidget, const FTabContainerSettings& tabContainerSettings, const FOpenUserWidgetWorldSettings& worldSettings);

	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = "userWidgetClass"))
	UUserWidget* OpenInPopoutWindowByClass(TSubclassOf<UUserWidget> userWidgetClass, const FTabContainerSettings& tabContainerSettings, const FOpenUserWidgetWindowSettings& windowSettings);

	UFUNCTION(BlueprintCallable)
	bool OpenInPopoutWindow(UUserWidget* userWidget, const FTabContainerSettings& tabContainerSettings, const FOpenUserWidgetWindowSettings& windowSettings);

	UFUNCTION(BlueprintPure)
	EUIType GetUserWidgetUIType(UUserWidget* userWidget) const;

	UFUNCTION(BlueprintCallable)
	void CloseTabContainer(UUserWidget* tabContainer);

	UFUNCTION(BlueprintCallable)
	void CloseUserWidget(UUserWidget* userWidget);

	UFUNCTION(BlueprintCallable)
	void CloseAllWidgetsByClass(TSubclassOf<UUserWidget> userWidgetClass, bool bIncludeSubclasses);

	UFUNCTION(BlueprintCallable)
	void SetUserWidgetSize(UUserWidget* userWidget, const FVector2D& size);

	UFUNCTION(BlueprintCallable)
	FVector2D GetUserWidgetSize(UUserWidget* userWidget) const;

	UFUNCTION(BlueprintCallable)
	void SetUserWidgetPosition(UUserWidget* userWidget, const FVector2D& position);

	UFUNCTION(BlueprintPure)
	FVector2D GetUserWidgetPosition(UUserWidget* userWidget) const;

	UFUNCTION(BlueprintCallable)
	void MoveUserWidgetToWorldLocation(UUserWidget* userWidget, const FVector& worldLocation);

	UFUNCTION(BlueprintCallable)
	void SetUserWidgetScale(UUserWidget* userWidget, const FVector2D& scale);

	UFUNCTION(BlueprintPure)
	FVector2D GetUserWidgetScale(UUserWidget* userWidget) const;

	UFUNCTION(BlueprintPure)
	UUserWidget* GetUserWidgetTabContainer(UUserWidget* userWidget) const;

	UFUNCTION(BlueprintPure)
	TSet<UUserWidget*> GetTabsInTabContainer(UUserWidget* tabContainer) const;

	/* \brief Removes userWidget from it's tab container (if it's in a tab container)
	*  \param userWidget UserWidget to remove from it's tab container
	*  \note This calls userWidget->RemoveFromParent(), so keep a reference to it if you want to open later.  Otherwise it will be cleaned up by garbage collection.
	*/
	UFUNCTION(BlueprintCallable)
	void RemoveUserWidgetFromTabContainer(UUserWidget* userWidget);

	UFUNCTION(BlueprintCallable)
	void MoveWidgetToNewTabContainer(UUserWidget* userWidget);

	UFUNCTION(BlueprintCallable)
	void SetUserWidgetTabContainer(UUserWidget* userWidget, UUserWidget* tabContainer);

	template <class T>
	TSet<T*> GetUserWidgetsByClass(bool bIncludeSubclasses) const
	{
		TSet<T*> userWidgets;
		TSet<UUserWidget*> preCastWidgets;

		if (bIncludeSubclasses)
		{
			for (const TPair<TSubclassOf<UUserWidget>, TSet<UUserWidget*>>& entry : UserWidgets)
			{
				if (entry.Key->IsChildOf(T::StaticClass()))
				{
					preCastWidgets.Append(entry.Value);
				}
			}
		}
		else
		{
			if (TSet<UUserWidget*> const* userWidgetsPtr = UserWidgets.Find(T::StaticClass()))
			{
				preCastWidgets.Append(*userWidgetsPtr);
			}
		}

		for (UUserWidget* userWidget : preCastWidgets)
		{
			userWidgets.Add(Cast<T>(userWidget));
		}

		return userWidgets;
	}

	UFUNCTION(BlueprintPure)
	TSet<UUserWidget*> GetUserWidgetsByClass(TSubclassOf<UUserWidget> userWidgetClass, bool bIncludeSubclasses);

	/*
	* \brief Returns worldUIActor currently displaying userWidget (if any)
	* \param userWidget UserWidget to find
	* \return WorldUIActor currently displaying userWidget
	*/
	UFUNCTION(BlueprintPure)
	AActor* GetUserWidgetWorldUIActor(const UUserWidget* userWidget) const;

	UFUNCTION(BlueprintCallable)
	void SetUserWidgetDefaultWorldUIActor(UUserWidget* userWidget, AActor* worldUIActor);

	/// @brief returns DefaultWorldSettings if DefaultClassWorldSettings does not contain userWidgetClass
	UFUNCTION(BlueprintPure)
	FOpenUserWidgetWorldSettings GetUserWidgetClassWorldSettings(TSubclassOf<UUserWidget> userWidgetClass);

	/// @brief null userWidgetClass sets DefaultWorldSetttings to settings
	UFUNCTION(BlueprintCallable)
	void SetUserWidgetClassWorldSettings(TSubclassOf<UUserWidget> userWidgetClass, const FOpenUserWidgetWorldSettings& settings);

	void SyncUserWidgetsToApplicationScale();

	UFUNCTION(BlueprintPure)
	bool GetViewportMonitorIndex(int32& monitorIndex) const;
	
	UFUNCTION(BlueprintPure)
	bool GetViewportPosition(FVector2D& position) const;
	
	UFUNCTION(BlueprintPure)
	bool GetViewportSize(FVector2D& size) const;
	
	/* \brief Gets monitor index of window showing userWidget
	*  \param userWidget UserWidget to find monitor index
	*  \param monitorIndex Populated with monitorIndex if function returns true
	*  \return True if userWidget is shown in a window and no errors getting the monitor index
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	bool GetWindowMonitorIndex(UUserWidget* userWidget, int32& monitorIndex) const;
	
	/* \brief Moves window showing userWidget to monitor with specified monitorIndex
	*  \param userWidget UserWidget to move
	*  \param monitorIndex Index of monitor to move window showing userWidget
	*  \return True if userWidget is shown in a window and no errors moving window to monitor
	*/
	UFUNCTION(BlueprintCallable)
	bool MoveWindowToMonitor(UUserWidget* userWidget, int32 monitorIndex);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void Cleanup();

	void UpdateSettings(const UUI_Subsystem_Core_Settings* settings);

	UUserWidget* CreateWidget(TSubclassOf<UUserWidget> userWidgetClass) const;
	
	TSharedPtr<SWindow> CreateSWindow(UUserWidget* userWidget, const FOpenUserWidgetWindowSettings& windowSettings) const;

	AActor* GetWorldUIActor(const FOpenUserWidgetWorldSettings& worldSettings, UWidgetComponent*& widgetComponent) const;

	UUserWidget* GetTabContainer(EUIType uiType, const FTabContainerSettings& tabContainerSettings, bool& bCreatedTabContainer) const;

	void RegisterUserWidget(UUserWidget* userWidget, UUserWidget* tabContainer);

	TSharedPtr<SWindow> GetViewportWindow() const;

	bool GetWindowMonitorIndex(TSharedPtr<SWindow> window, int32& monitorIndex) const;

	FOpenUserWidgetViewportSettings GetDefaultViewportSettings(TSubclassOf<UUserWidget> userWidgetClass) const;

	FOpenUserWidgetWorldSettings GetDefaultWorldSettings(TSubclassOf<UUserWidget> userWidgetClass) const;

	FOpenUserWidgetWindowSettings GetDefaultWindowSettings(TSubclassOf<UUserWidget> userWidgetClass) const;

	FOpenBehavior GetOpenBehavior(TSubclassOf<UUserWidget> userWidgetClass) const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleWindowClosed(const TSharedRef<SWindow>& closedWindow);

	UFUNCTION()
	void HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode);

	void HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources);
};