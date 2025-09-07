// Required Includes
#include "VH_MilStd2525.h"
#include "VH_COT.h"

// Engine Includes
#include "XmlFile.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"

// Module Includes
#include "VH_COTStatics.h"

UVH_MilStd2525::UVH_MilStd2525() :
    PathToIconImages(TEXT("")),
	PathToXML(TEXT("")),
	PathToArchive(TEXT("")),
	bInitialized(false)
{

}

void UVH_MilStd2525::Initialize()
{
	if (!bInitialized)
	{
		if (!ReadFromXML())
		{
			// auto-extract zip, if needed
			if (AutoExtractArchive())
			{
				PopulateIcons();
				WriteToXML();
			}
			else
			{
				UE_LOG(VH_COT, Error, TEXT("-- UVH_MilStd2525::Initialize | could not extract icon files"));
				return;
			}
		}

		bInitialized = true;
	}
}

FName UVH_MilStd2525::ConvertCOTTypeToID(const FName& cotType)
{
    FString idString = cotType.ToString();

    // remove initial a-
    if (idString.StartsWith(TEXT("a-")))
    {
        idString = idString.Right(idString.Len() - 2);
    }

    return FName(*idString);
}

FSMilStd2525Icon UVH_MilStd2525::GetIconData(const FName& milStdID)
{
	Initialize();

    FName idFromCOT = ConvertCOTTypeToID(milStdID);

    if (const auto& entry = IDToIcon.Find(idFromCOT))
    {
        CreateTexture(entry->ID);
        return *entry;
    }

    FString id = milStdID.ToString();
    if (id.Len() > 1)
    {
        id = id.LeftChop(1);
        return GetIconData(FName(*id));
    }

    UE_LOG(VH_COT, Log, TEXT("-- UVH_MilStd2525::GetIconData | could not find | id: %s | cot: %s"), *milStdID.ToString(), *idFromCOT.ToString());

    return FSMilStd2525Icon();
}

TArray<FSMilStd2525Icon> UVH_MilStd2525::GetChildrenData(const FName& milStdID)
{
	Initialize();

    FName idFromCOT = ConvertCOTTypeToID(milStdID);

    TArray<FSMilStd2525Icon> childrenIcons;

    if (const auto& entry = IDToIcon.Find(idFromCOT))
    {
        for (const auto& id : entry->ChildrenIDs)
        {
            CreateTexture(id);
            childrenIcons.Add(GetIconData(id));
        }
    }

    return childrenIcons;
}

FSMilStd2525Icon UVH_MilStd2525::GetParentData(const FName& milStdID)
{
	Initialize();

    FName idFromCOT = ConvertCOTTypeToID(milStdID);

    if (const auto& entry = IDToIcon.Find(idFromCOT))
    {
        CreateTexture(entry->ID);
        return *entry;
    }

    return FSMilStd2525Icon();
}

void UVH_MilStd2525::CreateTexture(const FName& milStdID)
{
    if (auto entry = IDToIcon.Find(milStdID))
    {
        if (!entry->FilePath.IsEmpty() && !entry->bTextureInitialized)
        {
			//FString dataDir = FPaths::RootDir();
			FString dataDir = FPaths::Combine(UDeveloper_Statics::GetCommonAppDataPath(), TEXT("VRTAK"));

			TArray<uint8> imageData;
            if (!FFileHelper::LoadFileToArray(imageData, *FPaths::Combine(dataDir, entry->FilePath)))
            {
                UE_LOG(VH_COT, Warning, TEXT("-- UVH_MilStd2525::CreateTexture | unable to load icon image: %s"), *entry->FilePath);
            }

            if (UTexture2D* texture = UVH_COTStatics::CreateTexture(imageData, EImageFormat::PNG))
            {
                entry->Texture = texture;
                entry->bTextureInitialized = true;
            }
            else
            {
                UE_LOG(VH_COT, Warning, TEXT("-- UVH_MilStd2525::CreateTexture | could not create texture: %s"), *entry->FilePath);
                entry->bTextureInitialized = false;
            }
        }
    }
    else
    {
        UE_LOG(VH_COT, Warning, TEXT("-- UVH_MilStd2525::CreateTexture | couldn't find id: %s"), *milStdID.ToString());
    }
}

bool UVH_MilStd2525::AutoExtractArchive()
{
	IFileManager& fileManager = IFileManager::Get();
	//FString dataDir = FPaths::RootDir();
	FString dataDir = FPaths::Combine(UDeveloper_Statics::GetCommonAppDataPath(), TEXT("VRTAK"));

	FString fullPathToSymbolsFile = FPaths::Combine(dataDir, PathToSymbolsDat);
	// NOTE: If the symbols.dat file exists, then this assumes the archive was already extracted on a previous run!
	bool bSuccess = fileManager.FileExists(*fullPathToSymbolsFile);

	if (!bSuccess)
	{
		FString archiveFile = FPaths::Combine(FPaths::RootDir(), PathToArchive);
		if (fileManager.FileExists(*archiveFile))
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_MilStd2525::AutoExtractArchive | extracting icon files | archiveFile: \"%s\" | dataDir: \"%s\""), *archiveFile, *dataDir);

			// Ensure destination directory exists (before copying file)
			FString tempDir = FPaths::Combine(dataDir, FPaths::GetPath(PathToIconImages));
			if (!fileManager.DirectoryExists(*tempDir))
			{
				fileManager.MakeDirectory(*tempDir, true);
			}

			FString tempArchiveFile = FPaths::Combine(tempDir, FPaths::GetCleanFilename(archiveFile));
			fileManager.Copy(*tempArchiveFile, *archiveFile);
			UDeveloper_Statics::ExecuteFile(*tempArchiveFile, TEXT("-y"), true);
			fileManager.Delete(*tempArchiveFile, false, false);

			bSuccess = fileManager.FileExists(*fullPathToSymbolsFile);
		}
	}

	return bSuccess;
}

void UVH_MilStd2525::PopulateIcons()
{
	//FString dataDir = FPaths::RootDir();
	FString dataDir = FPaths::Combine(UDeveloper_Statics::GetCommonAppDataPath(), TEXT("VRTAK"));

	// helper lambdas
    auto findChildrenIcons = [& IDToIcon = IDToIcon](const FName& keyArg) {
        TArray<FName> children;

        FString keyArgString = keyArg.ToString();

        TArray<FName> keys;
        IDToIcon.GetKeys(keys);
        for (auto& key : keys)
        {
            FString keyString = key.ToString();
            if (keyString.Len() == keyArgString.Len() + 2 && keyString.StartsWith(keyArgString))
            {
                children.Add(key);
            }
        }

        return children;
    };

    auto idToCOTType = [](FString milStdID) {
        FString cotType = milStdID.Left(1);

        milStdID = milStdID.Right(milStdID.Len() - 1);
        milStdID.ToUpperInline();

        for (auto i = 0; i < milStdID.Len(); i++)
        {
            cotType += TEXT("-");
            cotType += milStdID.Mid(i, 1);
        }

        return FName(*cotType);
    };

    auto affiliationToDisplayName = [& AffiliationData = AffiliationData](const FString& affiliation) {
        if (auto entry = AffiliationData.Find(FName(*affiliation)))
        {
            return *entry;
        }

        return FString(TEXT("Unknown"));
    };
    // end helper lambdas

    // load symbols.dat
    TMap<FName, FString> idToDisplayName;

	TArray<FString> symbolLines;
	FFileHelper::LoadFileToStringArray(symbolLines, *FPaths::Combine(dataDir, PathToSymbolsDat));

    for (const auto& line : symbolLines)
    {
        if (!line.StartsWith(TEXT("#")) && !line.IsEmpty())
        {
            TArray<FString> splitLine;
            line.ParseIntoArray(splitLine, TEXT("/"));

            FString key = splitLine[1];
            FString value = splitLine[0];

            // remove .png
            key = key.Left(key.Len() - 4);

            // remove initial 's_'
            key = key.Right(key.Len() - 2);

            // special case for icons end with h----
            if (key.EndsWith(TEXT("h----")))
            {
                key = key.Left(key.Len() - 5);
            }

            // remove trailing -'s
            while (key.EndsWith(TEXT("-")))
            {
                key = key.Left(key.Len() - 1);
            }

            // remove p at 1st index
            key.RemoveAt(1, 1);

            idToDisplayName.Add(FName(*key), value);
        }
    }

    // add top nodes (affiliations) to IDToIcon (assumes not present in .pngs)
    for (auto entry : AffiliationData)
    {
        FSMilStd2525Icon iconData;
        iconData.ID = entry.Key;
        IDToIcon.Add(iconData.ID, iconData);
    }

    // populate IDToIcon from pngs
	FString iconPath = FPaths::Combine(dataDir, PathToIconImages);

    // get all image files
    TArray<FString> iconFiles;
    IFileManager::Get().FindFiles(iconFiles, *(iconPath / TEXT("*.png")), true, false);
    for (const auto& iconFile : iconFiles)
    {
        FString modifiedIconName = iconFile;

        // remove extension
        TArray<FString> splitFilename;
        modifiedIconName.ParseIntoArray(splitFilename, TEXT("."));
        modifiedIconName = splitFilename[0];

        // remove initial 's'
        modifiedIconName.RemoveAt(0, 1);

        // special case for icons end with h----
        if (modifiedIconName.EndsWith(TEXT("h----")))
        {
            modifiedIconName = modifiedIconName.Left(modifiedIconName.Len() - 5);
        }

        // remove trailing -'s
        while (modifiedIconName.EndsWith(TEXT("-")))
        {
            modifiedIconName = modifiedIconName.Left(modifiedIconName.Len() - 1);
        }

        // remove p at 2nd index
        modifiedIconName.RemoveAt(2, 1);

        FName cotType = idToCOTType(modifiedIconName);

        FSMilStd2525Icon icon;
        icon.ID = cotType;
        icon.FilePath = PathToIconImages / iconFile;
        icon.DisplayName = affiliationToDisplayName(modifiedIconName.Left(1));

        FName idWithoutAffiliation = FName(*modifiedIconName.Right(modifiedIconName.Len() - 1));
        if (auto entry = idToDisplayName.Find(idWithoutAffiliation))
        {
            icon.DisplayName += TEXT(" ") + *entry;
        }
        else
        {
            icon.DisplayName += idWithoutAffiliation.ToString();
        }

        IDToIcon.Add(cotType, icon);
    }

    // populate parent/child ids
    for (auto& entry : IDToIcon)
    {
        entry.Value.ChildrenIDs.Append(findChildrenIcons(entry.Key));

        FString keyString = entry.Key.ToString();
        entry.Value.ParentID = FName(*(keyString.Left(keyString.Len() - 2)));
    }
}

void UVH_MilStd2525::WriteToXML() const
{
    // helper lambda
    auto toXML = [](const TPair<FName, FSMilStd2525Icon>& entry) {
        FString xml = TEXT("<icon>\n");
        xml += FString::Printf(TEXT("<id>%s</id>\n"), *entry.Key.ToString());
        xml += FString::Printf(TEXT("<displayName>%s</displayName>\n"), *entry.Value.DisplayName);
        xml += FString::Printf(TEXT("<filePath>%s</filePath>\n"), *entry.Value.FilePath);
        xml += TEXT("<childrenIDs>\n");
        for (auto id : entry.Value.ChildrenIDs)
        {
            xml += FString::Printf(TEXT("<id>%s</id>\n"), *id.ToString());
        }
        xml += TEXT("</childrenIDs>\n");
        xml += FString::Printf(TEXT("<parentID>%s</parentID>\n"), *entry.Value.ParentID.ToString());
        xml += TEXT("</icon>\n");

        return xml;
    };
    // end helper lambda

    FString xml = TEXT("<icons>\n");
    for (const auto& entry : IDToIcon)
    {
        xml += toXML(entry);
    }
    xml += TEXT("</icons>");

	//FString dataDir = FPaths::RootDir();
	FString dataDir = FPaths::Combine(UDeveloper_Statics::GetCommonAppDataPath(), TEXT("VRTAK"));
	FFileHelper::SaveStringToFile(xml, *FPaths::Combine(dataDir, PathToXML));
}

bool UVH_MilStd2525::ReadFromXML()
{
	//FString dataDir = FPaths::RootDir();
	FString dataDir = FPaths::Combine(UDeveloper_Statics::GetCommonAppDataPath(), TEXT("VRTAK"));
	FString xmlPath = FPaths::Combine(dataDir, PathToXML);

    FXmlFile xmlFile(xmlPath);
    if (xmlFile.IsValid())
    {
        TArray<FXmlNode*> iconNodes = xmlFile.GetRootNode()->GetChildrenNodes();
        for (auto iconNode : iconNodes)
        {
            FSMilStd2525Icon icon;
            icon.ID = FName(*iconNode->FindChildNode(TEXT("id"))->GetContent());
            icon.DisplayName = iconNode->FindChildNode(TEXT("displayName"))->GetContent();
            icon.FilePath = iconNode->FindChildNode(TEXT("filePath"))->GetContent();

            FXmlNode* childrenIDNodes = iconNode->FindChildNode(TEXT("childrenIDs"));
            TArray<FXmlNode*> idNodes = childrenIDNodes->GetChildrenNodes();
            for (auto idNode : idNodes)
            {
                icon.ChildrenIDs.Add(FName(*idNode->GetContent()));
            }

            icon.ParentID = FName(*iconNode->FindChildNode(TEXT("parentID"))->GetContent());

            IDToIcon.Add(FName(*iconNode->FindChildNode(TEXT("id"))->GetContent()), icon);
        }

        return true;
    }

    return false;
}
