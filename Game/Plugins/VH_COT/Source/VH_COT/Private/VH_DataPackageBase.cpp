#include "VH_DataPackageBase.h"
#include "VH_COTManager.h"
#include "VH_COTConnectionInfo.h"
#include "VH_COTEvent.h"
#include "VH_COTComponent.h"
#include "Interface_COTReceiver.h"
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "Database_Spatialite.h"

#include "Misc/Guid.h"
#include "XmlFile.h"

UVH_DataPackageBase::UVH_DataPackageBase() :
    Name(TEXT(""))
{
}

void UVH_DataPackageBase::AddUID(const FString& uid)
{
    UIDs.AddUnique(uid);

    OnUpdateContent.Broadcast();
}

void UVH_DataPackageBase::AddFile(const FString& fullPathToFile)
{
    FString modifiedPath = fullPathToFile.Replace(TEXT("\\"), TEXT("/"));

    Files.AddUnique(modifiedPath);

    OnUpdateContent.Broadcast();
}

void UVH_DataPackageBase::RemoveUID(const FString& uid)
{
    UIDs.Remove(uid);

    OnUpdateContent.Broadcast();
}

void UVH_DataPackageBase::RemoveFile(const FString& fullPathToFile)
{
    Files.Remove(fullPathToFile);

    OnUpdateContent.Broadcast();
}

void UVH_DataPackageBase::RemoveContent()
{
    UIDs.Empty();
    Files.Empty();

    OnUpdateContent.Broadcast();
}

FString UVH_DataPackageBase::CreateZipFile(const FString& fullPathToFile)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString zipRootPath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Temp") / Name;

        IFileManager& fileManager = IFileManager::Get();
        fileManager.MakeDirectory(*zipRootPath, true);

        // create files and add full list of files to filesToAdd
        TArray<FString> filesToAdd;

        for (const FString& uid : UIDs)
        {
            if (UVH_COTEvent* cotEvent = cotManager->GetCotEventFromUID(uid))
            {
                FString xml = cotEvent->ToXML();
                FString filePath = zipRootPath / uid + TEXT(".cot");
                FFileHelper::SaveStringToFile(xml, *filePath);

                filesToAdd.Add(filePath);
            }
            else
            {
                // see if it's in the cache
                FString cotFile = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Cache") / uid + TEXT(".cot");
                if (fileManager.FileExists(*cotFile))
                {
                    filesToAdd.Add(cotFile);
                }
                else
                {
                    UE_LOG(VH_COT, Verbose, TEXT("-- UVH_DataPackageBase::CreateZipFile | could not create file for uid: %s"), *uid);
                }
            }
        }

        filesToAdd.Append(Files);

        TMap<FString, FString> fullPathToNameInZip;
        for (const FString& fullPath : filesToAdd)
        {
            FString path = TEXT("");
            FString filename = TEXT("");
            FString extension = TEXT("");
            FPaths::Split(fullPath, path, filename, extension);

            fullPathToNameInZip.Add(fullPath, filename + TEXT(".") + extension);
        }

        // add manifest
        FString xml = TEXT("<MissionPackageManifest version=\"2\">");
        xml += TEXT("<Configuration>");
        xml += FString::Printf(TEXT("<Parameter name=\"name\" value=\"%s\"/>"), *Name);
        xml += FString::Printf(TEXT("<Parameter name=\"uid\" value=\"%s\"/>"), *FGuid::NewGuid().ToString());
        xml += TEXT("<Parameter name=\"onReceiveDelete\" value=\"false\"/>");
        xml += TEXT("<Parameter name=\"onReceiveImport\" value=\"true\"/>");
        xml += TEXT("</Configuration>");
        xml += TEXT("<Contents>");

        for (const auto& fileEntry : fullPathToNameInZip)
        {
            FString path = TEXT("");
            FString filename = TEXT("");
            FString extension = TEXT("");
            FPaths::Split(fileEntry.Key, path, filename, extension);

            bool bAddUID = extension.Equals(TEXT("cot"), ESearchCase::IgnoreCase);

            xml += FString::Printf(TEXT("<Content zipEntry=\"%s\" ignore=\"false\"%s>"), *fileEntry.Value, bAddUID ? TEXT("") : TEXT("/"));

            if (bAddUID)
            {
                xml += FString::Printf(TEXT("<Parameter name=\"uid\" value=\"%s\"/>"), *filename);
                xml += TEXT("</Content>");
            }
        }

        xml += TEXT("</Contents>");
        xml += TEXT("</MissionPackageManifest>");

        FString manifestFullPath = zipRootPath / TEXT("manifest.xml");

		FFileHelper::SaveStringToFile(xml, *manifestFullPath);
		 
        fullPathToNameInZip.Add(manifestFullPath, TEXT("MANIFEST/manifest.xml"));

        // create zip file
        FString zipFilePath = zipRootPath / Name + TEXT(".zip");
        UVH_FileIOStatics::ZipFile(zipFilePath, fullPathToNameInZip);

        // copy to VTAK/DataPackages so it will show up in DataPackages UI
        FString destination = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("DataPackages") / Name + TEXT(".zip");
        fileManager.Copy(*destination, *zipFilePath);

		if (!fullPathToFile.IsEmpty())
		{
			fileManager.Copy(*fullPathToFile, *zipFilePath);
		}

        // delete all created files
        fileManager.DeleteDirectory(*zipRootPath, false, true);

        return destination;
    }

    return TEXT("");
}