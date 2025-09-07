// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class VH_FileIO_Network : ModuleRules
{
    public VH_FileIO_Network(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;

		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
			// ... add public include paths required here ...
        });
		
		PrivateIncludePaths.AddRange(new string[] {
			// ... add other private include paths required here ...
        });
		
		PublicDependencyModuleNames.AddRange(new string[] {
			// ... add other public dependencies that you statically link with here ...

			// UE4 engine modules
			"Core",
            "CoreUObject",
            "Engine",
            "HTTP",
            "XmlParser",

			// VH modules
            "VH_FileIO",

			// ThirdParty modules

        });

        PrivateDependencyModuleNames.AddRange(new string[] {
			// ... add private dependencies that you statically link with here ...

			// UE4 engine modules
            "Json",
            "JsonUtilities",

			// VH modules
            "VH_Developer",
            "VH_GlobeMath",

			// ThirdParty modules

        });
		
		DynamicallyLoadedModuleNames.AddRange(new string[] {
			// ... add any modules that your module loads dynamically here ...
        });

    }
}
