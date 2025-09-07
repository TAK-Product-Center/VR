using UnrealBuildTool;
using System.IO;

public class VH_Vehicle : ModuleRules
{
	public VH_Vehicle(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;

		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(ModuleDirectory, "AI/Public"),
				Path.Combine(ModuleDirectory, "Core/Public"),
				Path.Combine(ModuleDirectory, "Data/Public"),
				Path.Combine(ModuleDirectory, "WheeledVehicle/Public")
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"AIModule",
				"ChaosVehicles",
				"Core",
				"Engine",
				"GameplayTasks",
				"InputCore",
				"NavigationSystem",
				"Navmesh",
				"PhysicsCore",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{

			}
			);
	}
}
