// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManifest.h"
#include "Misc/FileHelper.h"
#include "Misc/App.h"
#include "Misc/StringBuilder.h"
#include "Modules/ModuleManager.h"
#include "Modules/SimpleParse.h"

DEFINE_LOG_CATEGORY_STATIC(LogModuleManifest, Log, All); // WITH_VH || add log category for module manifest.

FModuleManifest::FModuleManifest()
{
}

FString FModuleManifest::GetFileName(const FString& DirectoryName, bool bIsGameFolder)
{
#if UE_BUILD_DEVELOPMENT
	return DirectoryName / ((FApp::GetBuildConfiguration() == EBuildConfiguration::DebugGame && bIsGameFolder)? TEXT(UBT_MODULE_MANIFEST_DEBUGGAME) : TEXT(UBT_MODULE_MANIFEST));
#else
	return DirectoryName / TEXT(UBT_MODULE_MANIFEST);
#endif
}

// Assumes GetTypeHash(AltKeyType) matches GetTypeHash(KeyType)
template<class KeyType, class ValueType, class AltKeyType, class AltValueType>
ValueType& FindOrAddHeterogeneous(TMap<KeyType, ValueType>& Map, const AltKeyType& Key, const AltValueType& Value) 
{
	checkSlow(GetTypeHash(KeyType(Key)) == GetTypeHash(Key));
	ValueType* Existing = Map.FindByHash(GetTypeHash(Key), Key);
	return Existing ? *Existing : Map.Emplace(KeyType(Key), AltValueType(Value));
}

bool FModuleManifest::TryRead(const FString& FileName, FModuleManifest& OutManifest)
{
	// WITH_VH || if we're looking into an external plugin module manifest, enable log messages.
	bool isExternalManifest = FModuleManager::Get().IsExternalModulePath(FileName);

	// Read the file to a string
	FString Text;
	if (!FFileHelper::LoadFileToString(Text, *FileName))
	{
		if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Unable to parse manifest in path: %s."), *FileName); } // WITH_VH
		return false;
	}

	const TCHAR* Ptr = *Text;
	if (!FSimpleParse::MatchZeroOrMoreWhitespace(Ptr) || !FSimpleParse::MatchChar(Ptr, TEXT('{')) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr) || FSimpleParse::MatchChar(Ptr, TEXT('}')))
	{
		if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Missing manifest initial bracket in path: %s."), *FileName); } // WITH_VH
		return false;
	}

	for (;;)
	{
		TStringBuilder<64> Field;
		if (!FSimpleParse::ParseString(Ptr, Field))
		{
			if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Unable to parse field in path: %s."), *FileName); } // WITH_VH
			return false;
		}

		if (!FSimpleParse::MatchZeroOrMoreWhitespace(Ptr) || !FSimpleParse::MatchChar(Ptr, TEXT(':')) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr))
		{
			if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Missing field colon in path: %s."), *FileName); } // WITH_VH
			return false;
		}

		if (Field.ToView() == TEXTVIEW("BuildId"))
		{
			if (!FSimpleParse::ParseString(Ptr, OutManifest.BuildId))
			{
				if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Unable to parse BuildID field in path: %s."), *FileName); } // WITH_VH
				return false;
			}
		}
		else if (Field.ToView() == TEXTVIEW("Modules"))
		{
			if (!FSimpleParse::MatchZeroOrMoreWhitespace(Ptr) || !FSimpleParse::MatchChar(Ptr, TEXT('{')) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr))
			{
				if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Unable to parse Modules field in path: %s."), *FileName); } // WITH_VH
				return false;
			}

			if (!FSimpleParse::MatchChar(Ptr, TEXT('}')))
			{
				for (;;)
				{
					TStringBuilder<64> ModuleName;
					TStringBuilder<80> ModulePath;
					if (!FSimpleParse::ParseString(Ptr, ModuleName) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr) || !FSimpleParse::MatchChar(Ptr, TEXT(':')) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr) || !FSimpleParse::ParseString(Ptr, ModulePath) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr))
					{
						if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Incomplete Modules entry or missing colon for a Modules entry: %s."), *FileName); } // WITH_VH
						return false;
					}

					FindOrAddHeterogeneous(OutManifest.ModuleNameToFileName, ModuleName.ToView(), ModulePath.ToView());

					if (FSimpleParse::MatchChar(Ptr, TEXT('}')))
					{
						break;
					}

					if (!FSimpleParse::MatchChar(Ptr, TEXT(',')) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr))
					{
						if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Missing a comma to end one Modules entry and start another in path: %s."), *FileName); } // WITH_VH
						return false;
					}
				}
			}
		}
		else
		{
			if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Non-valid field name in path: %s."), *FileName); } // WITH_VH
			return false;
		}

		if (!FSimpleParse::MatchZeroOrMoreWhitespace(Ptr))
		{
			return false;
		}

		if (FSimpleParse::MatchChar(Ptr, TEXT('}')))
		{
			return true;
		}

		if (!FSimpleParse::MatchChar(Ptr, TEXT(',')) || !FSimpleParse::MatchZeroOrMoreWhitespace(Ptr))
		{
			if (isExternalManifest) { UE_LOG(LogModuleManifest, Warning, TEXT("TryRead() - Missing an end bracket to end the module manifest or a comma to signify a new field in path: %s."), *FileName); } // WITH_VH
			return false;
		}
	}
}
