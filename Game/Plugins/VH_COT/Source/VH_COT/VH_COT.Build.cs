using UnrealBuildTool;
using System.IO;

public class VH_COT : ModuleRules
{
    public VH_COT(ReadOnlyTargetRules target) : base(target)
    {
        bEnableExceptions = true;

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
			{
				// UE4 engine modules
				"Core", 
				"CoreUObject", 
				"Engine",
                "HTTP",
                "ImageWrapper",
                "Json",
                "JsonUtilities",
                "Networking",
				"OpenCV",
                "RenderCore",
                "RHI",
                "Sockets",
                "UMG",
                "XmlParser",  

				// VH modules
				"VH_Database_Spatialite",
                "VH_Developer",
                "VH_FileIO",
                "VH_FileIO_Kml",
				"VH_FileIO_Network",
                "VH_Globe",
                "VH_GlobeMath",

				// ThirdParty Modules
				"commo",
                "gv2F"
            });
    }
}
