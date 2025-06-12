#pragma once

// Parent Includes
#include "VH_FileIO.h"

// Generated Includes
#include "VH_FileIOStatics.generated.h"

// Defines
#define MAX_STR_FILETYPES 4096	// length of buffer to hold all file types (description and extension)
#define MAX_STR_FILENAMES 65536	// length of buffer to hold all selected filenames (incl. path)


UCLASS()
class VH_FILEIO_API UVH_FileIOStatics : public UObject
{
    GENERATED_BODY()

    // ---------------------------------
    // --- API
    // ---------------------------------
public:
    /**
	 * Get list of all files in a directory (and optionally, in all subdirectories) that match an extension. All files are listed
	 * if 'fileExtension' is left blank. Can specify multiple extensions separated by ',' or ';' (e.g. "jpg,png").
	 * Relative directory paths are relative to the root dir. Found files are appended to 'files' array in order of extension list.
	 * Returns TRUE if any files are found and appended.
	 */
    UFUNCTION(BlueprintPure, Category = "VhFileIO", meta = (DisplayName = "VH Get Files In Path"))
    static bool GetFilesInPath(TArray<FString>& files, const FString& searchRootDir, const FString& fileExtensionPriority = TEXT(""), bool bIsRecursive = true, bool bIncludeRootPath = true, bool bAbsolutePaths = false);

    /**
	 * Get list of all directories (and optionally, in all subdirectories) in the specified 'searchRootDir'.
	 * Relative directory paths are relative to the project's Content dir. Returns FALSE if aborted.
	 */
    UFUNCTION(BlueprintPure, Category = "VhFileIO", meta = (DisplayName = "VH Get Directories In Path"))
    static bool GetDirectoriesInPath(TArray<FString>& directories, const FString& searchRootDir, bool bIsRecursive = true, bool bIncludeRootPath = true, bool bAbsolutePaths = false);

    /**
	 * Get list of all uassets in a directory (and optionally, in all subdirectories). This also loads the assets into memory.
	 * Relative directory paths are relative to the project's Content dir. Returns FALSE if aborted.
	 */
    UFUNCTION(BlueprintCallable, Category = "VhFileIO", meta = (DisplayName = "VH Load Assets In Path"))
    static bool LoadAssetsInPath(TArray<UObject*>& assets, const FString& searchRootDir, bool bIsRecursive = true);

    /** Zip fullPathToFiles to fullPathToZip */
    UFUNCTION(BlueprintCallable, Category = "VhFileIO|Archive", meta = (DisplayName = "VH Zip Files"))
    static void ZipFile(const FString& fullPathToZip, const TMap<FString, FString>& fullPathToNameInZip, bool bOverwrite = true);

    /** Unzip inFilename to outDirectory */
    UFUNCTION(BlueprintCallable, Category = "VhFileIO|Archive", meta = (DisplayName = "VH Unzip File"))
    static void UnzipFile(const FString& inFilename, const FString& outDirectory);

    /** Checks if directory or file exists at root level of zip file */
    UFUNCTION(BlueprintCallable, Category = "VhFileIO|Archive", meta = (DisplayName = "VH Directory Exists In Zip"))
    static bool DirectoryOrFileExistsInZip(const FString& fullPathToZip, const FString& targetName, bool isDir);

    /** Parses a string of extensions into an array while stripping extraneous characters -- e.g. passing in ".fbx;kml, *.xyz, .obj" yields { "fbx", "kml", "xyz", "obj" } */
    UFUNCTION(BlueprintCallable, Category = "VhFileIO|Archive", meta = (DisplayName = "VH Parse Extensions Into Array"))
    static TArray<FString> ParseExtensionsIntoArray(const FString& extensions);

	UFUNCTION(BlueprintCallable, Category = "VhFileIO|Archive")
	static bool IsZipArchive(const FString& fullPathToFile);

	UFUNCTION(BlueprintCallable, Category = "VhFileIO|FileBrowser")
	static bool OpenFileWithDefaultProgram(const FString& filepath);
};
