#pragma once

// Engine Includes
#include "IImageWrapper.h"
#include "PixelFormat.h"

// Generated Includes
#include "Developer_Statics.generated.h"

// ---------------------------------
// --- Macros
// ---------------------------------

#define VH_BEGIN_EXEC_TIMER(timerName) FDateTime _##timerName = FDateTime::UtcNow();

#define VH_END_EXEC_TIMER(timerName, logCategory) FTimespan elapsed_##timerName = FDateTime::UtcNow() - _##timerName;\
	UE_LOG(logCategory, Verbose, TEXT("%s took %.3f seconds"), TEXT(#timerName), elapsed_##timerName.GetTotalSeconds());

// TODO: Consider replacing PrintMessageLog() with macros to print to log, screen, etc -- but only if their log category is enabled for the specified verbosity.  
//		 Then use one "master" VH_LOG() to call them all!

/*
 * Invokes UE_LOG() in the specified color from UDeveloper_Statics.  For example, COLOR_WHITE will use UDeveloper_Statics::COLOR_WHITE.
 */
#define VH_LOG_COLOR(CategoryName, Verbosity, LogColor, Format, ...) \
	{ \
        SET_WARN_COLOR( UDeveloper_Statics::##LogColor ); \
		UE_LOG(CategoryName, Verbosity, Format, ##__VA_ARGS__); \
		CLEAR_WARN_COLOR(); \
	}

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class ELogMessageVerbosityLevel : uint8
{
    Log,
    Warning,
    Error
};

UENUM(BlueprintType)
enum class ELogMessageColor : uint8
{
    None,
    DarkRed,
    DarkGreen,
    DarkBlue,
    DarkYellow,
    DarkCyan,
    DarkPurple,
    Red,
    Green,
    Blue,
    Yellow,
    Cyan,
    Purple,
    White,
    Black,
    Gray,
};

UENUM(BlueprintType)
enum class EDriveType : uint8
{
    Unknown,
    NoRootDir,
    Removable,
    Fixed,
    Remote,
    CDRom,
    RamDisk,
};

// copied from Engine because ENetMode not blueprint accessible
UENUM(BlueprintType)
enum class EVH_NetMode : uint8
{
	/* Standalone: a game without networking, with one or more local players. Still considered a server because it has all server functionality. */
	NM_Standalone,

	/* Dedicated server: server with no local players. */
	NM_DedicatedServer,

	/* Listen server: a server that also has a local player who is hosting the game, available to other players on the network. */
	NM_ListenServer,

	/*
	 * Network client: client connected to a remote server.
	 * Note that every mode less than this value is a kind of server, so checking NetMode < NM_Client is always some variety of server.
	 */
	NM_Client,

	NM_MAX,
};

class APlayerController;

UCLASS()
class VH_DEVELOPER_API UDeveloper_Statics : public UObject
{
    GENERATED_BODY()


    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
    static const TCHAR* COLOR_NONE;
    static const TCHAR* COLOR_DARK_RED;
    static const TCHAR* COLOR_DARK_GREEN;
    static const TCHAR* COLOR_DARK_BLUE;
    static const TCHAR* COLOR_DARK_YELLOW;
    static const TCHAR* COLOR_DARK_CYAN;
    static const TCHAR* COLOR_DARK_PURPLE;
    static const TCHAR* COLOR_RED;
    static const TCHAR* COLOR_GREEN;
    static const TCHAR* COLOR_BLUE;
    static const TCHAR* COLOR_YELLOW;
    static const TCHAR* COLOR_CYAN;
    static const TCHAR* COLOR_PURPLE;
    static const TCHAR* COLOR_WHITE;
    static const TCHAR* COLOR_BLACK;
    static const TCHAR* COLOR_GRAY;


    // ---------------------------------
    // --- Static Functions
    // ---------------------------------

public:
    UFUNCTION(BlueprintPure, Category = "VhDeveloper", meta = (DisplayName = "VH Get World"))
    static UWorld* GetVHWorld();

	/* Returns whether this game instance is a Listen Server. */
	UFUNCTION(BlueprintPure, Category = "Networking", meta = (WorldContext = "WorldContextObject"))
	static bool IsListenServer(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "VhGame")
    static bool GetVHIsWithEditor();

    UFUNCTION(BlueprintPure, Category = "VhGame")
    static bool GetVHIsBuildShipping();

    UFUNCTION(BlueprintPure, Category = "VhGame")
    static bool GetVHIsBuildTest();

    UFUNCTION(BlueprintPure, Category = "VhDeveloper|Modes", meta = (DisplayName = "VH Is Play In Editor"))
	static bool IsPlayInEditor();

	UFUNCTION(BlueprintPure, Category = "VhDeveloper|Modes", meta = (DisplayName = "VH Is Play In Preview"))
	static bool IsPlayInPreview();

	UFUNCTION(BlueprintPure, Category = "VhDeveloper|Modes", meta = (DisplayName = "VH Is Play In Mobile Preview"))
	static bool IsPlayInMobilePreview();

	UFUNCTION(BlueprintPure, Category = "VhDeveloper|Modes", meta = (DisplayName = "VH Is Play In Vulkan Preview"))
	static bool IsPlayInVulkanPreview();


	////////////////////////////////////
	/////// Window Path Getters ////////
	////////////////////////////////////

	/*
	 * @brief	This static function is used to get the shared "AppData" folder on a Windows environment. This function will return the 
	 *			C:\ProgramData\ folder for all users.
	 *
	 * @return	static FString - The return will be the full path of the %PROGRAMDATA% folder in the Windows environment.
	 * @warning This function will only work in an Windows environment.
	 */
    UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Get Common AppData Path"))
    static FString GetCommonAppDataPath();

	/*
	 * @brief	This static function is used to get the user local "AppData" folder on a Windows environment. This function will return the
	 *			"C:/Users/[current user]/AppData/Local/" folder for the current user.
	 *
	 * @return	static FString - The return will be the full path of the %APPDATA% folder for the current user in the Windows environment.
	 * @warning This function will only work in an Windows environment.
	 */
    UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Get User AppData Path"))
    static FString GetUserAppDataPath();

	/*
	 * @brief	This static function is used to get the user profile folder on a Windows environment. This function will return the
	 *			"C:/Users/[current user]/" folder for the current user.  
	 *
	 * @return	static FString - The return will be the full path of the %USERPROFILE% folder for the current user in the Windows environment.
	 * @warning This function will only work in an Windows environment.
	 */
	UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Get User Profile Path"))
	static FString GetUserProfilePath();

	/*
	 * @brief	This static function is used to get the user "Pictures" folder on a Windows environment. This function will return the
	 *			"C:/Users/[current user]/Pictures/" folder for the current user.
	 *
	 * @return	static FString - The return will be the full path of the %USERPROFILE%/Pictures/ folder for the current user in the Windows environment.
	 * @warning This function will only work in an Windows environment.
	 */
	UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Get User Pictures Path"))
	static FString GetUserPicturesPath();

	/*
	 * @brief	This static function is used to get the user "Videos" folder on a Windows environment. This function will return the
	 *			"C:/Users/[current user]/Videos/" folder for the current user.
	 *
	 * @return	static FString - The return will be the full path of the %USERPROFILE%/Videos/ folder for the current user in the Windows environment.
	 * @warning This function will only work in an Windows environment.
	 */
	UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Get User Videos Path"))
	static FString GetUserVideosPath();

    UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Get Logical Drives"))
    static TArray<FString> GetLogicalDrives();

    UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Get Logical Drive Type"))
    static EDriveType GetLogicalDriveType(const FString& drive);

    /* Version of FPaths:CollapseRelativeDirectories() that correctly handles starting with "../" */
    static FString FixedCollapseRelativeDirectories(const FString& path);

    /* Version of FPaths:CollapseRelativeDirectories() that correctly handles starting with "../" */
    UFUNCTION(BlueprintPure, Category = "VhDeveloper|FileIO", meta = (DisplayName = "VH Collapse Relative Directories"))
    static void FixedCollapseRelativeDirectoriesInline(FString& path);

    UFUNCTION(BlueprintCallable, Category = "VhDeveloper|Debug", meta = (DisplayName = "VH Print Message"))
    static void PrintMessage(const FString& message, bool bPrintToScreen = false, bool bPrintToConsole = false, bool bPrintToLog = true, ELogMessageVerbosityLevel verbosityLevel = ELogMessageVerbosityLevel::Log, bool bShowStackTrace = false, ELogMessageColor logColor = ELogMessageColor::Gray);
    static void PrintMessageLog(const FString& message, bool bPrintToScreen = false, bool bPrintToConsole = false, bool bPrintToLog = true, bool bShowStackTrace = false, ELogMessageColor logColor = ELogMessageColor::Gray);
    static void PrintMessageWarning(const FString& message, bool bPrintToScreen = false, bool bPrintToConsole = false, bool bPrintToLog = true, bool bShowStackTrace = false, ELogMessageColor logColor = ELogMessageColor::Yellow);
    static void PrintMessageError(const FString& message, bool bPrintToScreen = false, bool bPrintToConsole = false, bool bPrintToLog = true, bool bShowStackTrace = false, ELogMessageColor logColor = ELogMessageColor::Red);

	/* Get the current stack trace (usually from an error).  Specify 'maxLines' value <= 0 to get ALL lines. */
    UFUNCTION(BlueprintCallable, Category = "VhDeveloper|Debug", meta = (DisplayName = "VH Get StackTrace"))
    static FString GetStackTrace(int32 maxLines = 8);

    static bool GetHardwareMemoryStats(double& totalVirtualMemory, double& usedVirtualMemory, double& totalPhysicalMemory, double& usedPhysicalMemory);
    
	static bool GetProcessMemoryStats(double& usedVirtualMemory, double& usedPhysicalMemory);
    
	static void LogAssetRegistryMemory();

    static bool KillProcessByName(const wchar_t* filename);
	
	static void FullRestart();
	
	static UTexture2D* CreateTextureWithWrapper(EImageFormat imageFormat, const TArray<uint8>& imageBytes);

	UFUNCTION(BlueprintCallable)
	static UTexture2D* CreateTextureFromPixels(int32 width, int32 height, const TArray<uint8>& pixelData);

    static void UpdateTexture2DPixels(UTexture2D* texture, const int32 mipIndex, const TArray<uint8>& pixelData);

    UFUNCTION(BlueprintPure, Category = "VhDeveloper|Format", meta = (DisplayName = "VH Format Float"))
    static FString FormatFloat(float inFloat, int32 numDecimals = 2);

	/*
	 * @brief	This function is used to convert a standard Unreal Engine path to the current operating system path. This is 
	 *			particularly useful when using Windows format and need the slashes to be '\' rather than '/'.
	 *
	 * @return	static FString - The return will be the full path in the format of the current operating system platform.
	 */
	UFUNCTION(BlueprintPure, Category = "VhDeveloper|Format", meta = (DisplayName = "VH Convert To Platform Path"))
	static FString ConvertToPlatformPath(const FString& unrealEnginePath);

    /*
	 * Generates a string of the binary representation of a variable's value. 
	 *
	 * usage: ToBinaryString(sizeof(var), &var)
	 */
    static FString ToBinaryString(size_t const size, void const* const ptr);

    /* Parses an ISO 8601 string (e.g. "2019-02-06T20:04:26Z") into a UE4 DateTime. See https://en.wikipedia.org/wiki/ISO_8601 for more details. */
    UFUNCTION(BlueprintCallable, Category = "VhDeveloper|Conversion", meta = (DisplayName = "VH DateTime From ISO8601"))
    static bool DateTimeFromISO8601(const FString& DateTimeISO8601, FDateTime& OutDateTime);

    /*
	* \brief Outputs string of DateTime based on passed in format
	* \param dateTime DateTime to generate string from
	* \param format Format of generated string (see notes below)
	* \return String generated from dateTime
	*
	*	Ex: %Y.%m.%d-%H.%M.%S
	*	case TCHAR('a'): Result += IsMorning() ? TEXT("am") : TEXT("pm"); break;
	*	case TCHAR('A'): Result += IsMorning() ? TEXT("AM") : TEXT("PM"); break;
	*	case TCHAR('d'): Result += FString::Printf(TEXT("%02i"), GetDay()); break;
	*	case TCHAR('D'): Result += FString::Printf(TEXT("%03i"), GetDayOfYear()); break;
	*	case TCHAR('m'): Result += FString::Printf(TEXT("%02i"), GetMonth()); break;
	*	case TCHAR('y'): Result += FString::Printf(TEXT("%02i"), GetYear() % 100); break;
	*	case TCHAR('Y'): Result += FString::Printf(TEXT("%04i"), GetYear()); break;
	*	case TCHAR('h'): Result += FString::Printf(TEXT("%02i"), GetHour12()); break;
	*	case TCHAR('H'): Result += FString::Printf(TEXT("%02i"), GetHour()); break;
	*	case TCHAR('M'): Result += FString::Printf(TEXT("%02i"), GetMinute()); break;
	*	case TCHAR('S'): Result += FString::Printf(TEXT("%02i"), GetSecond()); break;
	*	case TCHAR('s'): Result += FString::Printf(TEXT("%03i"), GetMillisecond()); break;
	*/
    UFUNCTION(BlueprintPure, Category = "VhDeveloper|Conversion", meta = (DisplayName = "VH DateTime To String"))
    static FString DateTimeToString(const FDateTime& dateTime, const FString& format);

    static inline double GetSeconds()
    {
#if PLATFORM_WINDOWS
        return FWindowsPlatformTime::Seconds();
#endif
#if PLATFORM_ANDROID
        return FGenericPlatformTime::Seconds();
#endif
    }

    //Get Class pointer from the path of that class
    UFUNCTION(BlueprintPure, Category = "VhDeveloper", meta = (DisplayName = "VH Get Class Object From Path"))
    static UClass* GetClassObjectFromPath(const FString& path);

    //Get class pointer from the full name of that class
    UFUNCTION(BlueprintPure, Category = "VhDeveloper", meta = (DisplayName = "VH Get Class Object From Full Name"))
    static UClass* GetClassObjectFromFullName(const FString& fullName);

	template<typename T, typename U>
	FORCEINLINE static T* DownCastUStruct(U* base)
	{
		static_assert(TIsDerivedFrom<T, U>::IsDerived, "Type T has to be derived from U.");
		return static_cast<T*>(base);
	}

	/*
	 * Solves a quadratic equation in double precision:  a(x^2) + bx + c = 0
	 * Returns the number of unique solutions. The solutions are returned in root0 and root1.
	 */
	static int32 SolveQuadratic(double a, double b, double c, double& outRoot0, double& outRoot1);

	/*
	 * Parses 'commandLine' into arrays of tokens, switches, and args.
	 * NOTE: If 'commandLine' is empty when called, it will be filled with the cached commandLine string.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper", meta = (DisplayName = "VH Parse Command Line Params"))
	static void ParseCommandLineParams(FString& commandLine, TArray<FString>& tokens, TArray<FString>& switches, TArray<FString>& args);

	/* Sets the clipboard contents to the specified string	 */
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper|Clipboard", meta = (DisplayName = "VH Send String to Clipboard"))
	static void SendToClipboard(const FString& inString);

	/* Gets a string containing the current contents of the clipboard	*/
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper|Clipboard", meta = (DisplayName = "VH Get String from Clipboard"))
	static FString GetFromClipboard();

	UFUNCTION(BlueprintPure, Category = "VhDeveloper")
	static EVH_NetMode GetActorNetMode(AActor* actor);

	/* Return true if the topmost owner of this actor is locally controlled */
	UFUNCTION(BlueprintPure, meta = (CallableWithoutWorldContext, DisplayName = "HasLocalNetOwner"))
	static bool K2_HasLocalNetOwner(AActor* actor);

	UFUNCTION(BlueprintCallable, Category = "VhDeveloper")
	static bool OpenFolderWithDefaultApp(const FString& fullPathToFolder);

	/*
	 * Attempts to open the file at the specified path using window's default application for that file type
	 * Returns whether the file was successfully opened
	 */
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper")
	static bool OpenFileWithDefaultApp(const FString& pathToFile);

	/*
	 * Attempts to execute the command at the specified file location.
	 * Returns whether the command was successfully executed
	 */
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper")
	static bool ExecuteFile(const FString& cmdCommand, const FString& cmdParams, bool bWaitForFinish = true);

	/*
	 * Opens a path in the OS (Windows) File Explorer.  If a file is specified, the Explorer window will initially find/highlight the file.
	 */
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper")
	static void ExploreFolderOrFile(const FString& folderOrFilePath);

	/*
	* Returns the IP address and network adapter of current connection
	*/
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper")
	static void GetNetInfo(FString& ipAddress, FString& netAdapter);

	/* if -multihome is specified, checks that IP maps to network adapter; returns true if -multihome is not specified */
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper")
	static bool VerifyMultihome();

	/* Returns DPI scale at given mouse location */
	UFUNCTION(BlueprintCallable, Category = "VhDeveloper")
	static float GetDPIScaleFactorAtPoint(float mouseX, float mouseY);

	/* Exposes the string compare function to blueprint*/
	UFUNCTION(BlueprintPure, Category = "VhDeveloper")
	static int32 CompareStringBP(FString stringA, FString stringB, bool isCaseSensitive);
	
	UFUNCTION(BlueprintPure)
	static void GetPlayerViewpoint(FTransform& localToWorld);

	/*
	* \brief Sends key down to current keyboard focus
	* \param key Key to press
	* \param bRepeat If true, press is sent as a repeating press
	*/
	UFUNCTION(BlueprintCallable)
	static void PressKey(const FKey& key, bool bRepeat);

	/*
	* \brief Sends key up to current keyboard focus
	* * \param key Key to release
	*/
	UFUNCTION(BlueprintCallable)
	static void ReleaseKey(const FKey& key);

	/*
	* \brief Sends key down, then key up to current keyboard focus
	* \param key Key to press and release
	*/
	UFUNCTION(BlueprintCallable)
	static void PressAndReleaseKey(const FKey& key);

	UFUNCTION(BlueprintCallable)
	static void SendKeyChar(const FString& keyString, bool bRepeat);

	static APlayerController* GetPlayerControllerFromPlayerID(int32 playerID);

	/*
	* \brief Deprojects the given UV coordinate to world space using the given SceneCaptureComponent2D
	* \param SceneCaptureComponent2D The target scene capture component 2d to use
	* \param TargetUV FVector2D of a screen space position (0 - 1 values)
	* \param WorldPosition out variable for the position in world space corresponding to the screen space position
	* \param WorldDirection out variable for the direction from the scene capture camera to the world space position
	*/
	UFUNCTION(BlueprintPure)
	static bool DeprojectSceneCaptureComponent2DToWorld(class USceneCaptureComponent2D* SceneCaptureComponent2D, const FVector2D& TargetUV, FVector& WorldPosition, FVector& WorldDirection);

	static bool TriangulatePolygon(const TArray<FVector2D>& Polygon, TArray<int32>& TriangulatedIndices, bool& OutWindsClockwise);

	/// @brief Generates triangular irregular network based on XY plan of passed in vertices
	static void Generate2DTin(const TArray<FVector>& vertices, TArray<int32>& triangles);
	
	static FString DecimalToHex(uint32 decimal);

	static uint32 HexToDecimal(const FString& hex);

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static bool IsClient(const UObject* worldContextObject);

private:
	static void GetKeyAndCharCodes(const FKey& key, bool& bHasKeyCode, uint32& keyCode, bool& bHasCharCode, uint32& charCode);

	/*
	* @brief	This is a helper function that takes in a CSIDL (Constant Special Item ID List), which is just a #define of an int, which is a reference
	*			to a particular Windows environment folder. This function will then return the full path to the folder of the given CSIDL reference.
	*
	* @return	static FString - The return will be the full path of the given CSIDL reference in the Windows environment.
	* @warning This function will only work in an Windows environment.
	*/
	static FString GetWindowsFolderPath(const int& csidlValue);

	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "->", BlueprintAutocast))
	static FString DoubleToString(double inValue, int32 numDecimalPlaces = 8);

	/*
	 * Convert this time span to its string representation.
	 *
	 * The following formatting codes are available:
	 *		%d - prints the days component
	 *		%D - prints the zero-padded days component (00000000..10675199)
	 *		%h - prints the zero-padded hours component (00..23)
	 *		%m - prints the zero-padded minutes component (00..59)
	 *		%s - prints the zero-padded seconds component (00..59)
	 *		%f - prints the zero-padded fractional seconds (000..999)
	 *		%u - prints the zero-padded fractional seconds (000000..999999)
	 *		%n - prints the zero-padded fractional seconds (000000000..999999999)
	 *
	 * Depending on whether the time span is positive or negative, a plus or minus
	 * sign character will always be added in front of the generated string.
	 */
	UFUNCTION(BlueprintPure)
	static FString TimeSpanToString(const FTimespan& timespan, const FString& format, bool bIncludePlusMinus);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "VH DateTime To Formatted String"))
	static FString DateTimeToFormattedString(const FDateTime& dateTime, const FString& format);

	static float Area(const TArray<FVector2D>& polygon);

	static bool Snip(const TArray<FVector2D>& polygon, int32 u, int32 v, int32 w, int32 pointCount, const TArray<int32>& vertexIndices);

	static bool IsPointInsideTriangle(const FVector2D& triangleA, const FVector2D& triangleB, const FVector2D& triangleC, const FVector2D& point);
};