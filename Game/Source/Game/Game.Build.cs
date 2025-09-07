using System.IO;
using UnrealBuildTool;

public class Game : ModuleRules
{
	public Game(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		bEnableExceptions = true;

		PublicIncludePaths.AddRange(new string[] 
		{
            Path.Combine(ModuleDirectory, "Actors/Public"),
            Path.Combine(ModuleDirectory, "Components/Public"),
            Path.Combine(ModuleDirectory, "ContextMenuOptions/Public"),
			Path.Combine(ModuleDirectory, "Core/Public"),
            Path.Combine(ModuleDirectory, "COT/Public"),
            Path.Combine(ModuleDirectory, "DynamicContent/Public"),
            Path.Combine(ModuleDirectory, "EntityHandlers/Public"),
            Path.Combine(ModuleDirectory, "Gameplay/Public"),
            Path.Combine(ModuleDirectory, "MultiuserCollaboration/Public"),
            Path.Combine(ModuleDirectory, "Operations/Public"),
            Path.Combine(ModuleDirectory, "SessionPlayback/Public"),
            Path.Combine(ModuleDirectory, "Tools/Public"),
            Path.Combine(ModuleDirectory, "UI/Public"),
            Path.Combine(ModuleDirectory, "UnitConverters/Public"),
			Path.Combine(ModuleDirectory, "Subsystems/Public"),
            Path.Combine(ModuleDirectory, "ThirdParty/Public"),
            Path.Combine(ModuleDirectory, "TransformGizmo/Public"),
		});

		PublicDependencyModuleNames.AddRange(new string[] 
		{
			// Engine
			"ApplicationCore",
			"AudioMixer",
			"Core",
			"CoreUObject",
			"DeveloperSettings",
			"Engine",
			"EnhancedInput",
			"HeadMountedDisplay",
			"HTTP",
			"InputCore",
			"Json",
			"JsonUtilities",
			"LidarPointCloudRuntime",
			"MediaAssets",
			"MoviePlayer",
			"NetCore",
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
			"OpenCV",
			"OpenCVHelper",
			"ProceduralMeshComponent",
			"RenderCore",
			"RHI",
			"Sockets",
			"UMG",
			"Voice",
			"XmlParser",
			"XRBase",
			
			// VH
			//"VH_Automation",
			"VH_COT",
			"VH_Database_Spatialite",
			"VH_Developer",
			"VH_FileIO",
			"VH_FileIO_Kml",
			"VH_FileIO_Network",
			"VH_Globe",
			"VH_GlobeMath",
			"VH_Keyboard",
			"VH_Plugins",
			"VH_Replication",
			"VH_SessionPlayback",
			"VH_UI",
			"VH_VR",
			
			// Game
			"fxGLTF",
			"gdal",
			"libVLC",
			"TAKKernel",
			"vtzero"
		});

		PrivateDependencyModuleNames.AddRange(new string[] 
		{
			"Launch",
			"AssetRegistry",
			"Slate",
			"SlateCore",
		});
		
		DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");
	}
}