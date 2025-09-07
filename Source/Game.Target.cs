using UnrealBuildTool;

public class GameTarget : TargetRules
{

    public GameTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;

        bUseLoggingInShipping = true;

        bUseUnityBuild = false;
        bUsePCHFiles = false;

        bCompileISPC = false;

		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		// for VH_Database
		AdditionalCompilerArguments = "/wd4668";
	    
		LinkType = TargetLinkType.Modular;
		BuildEnvironment = TargetBuildEnvironment.Unique;

		ExtraModuleNames.AddRange(new string[] { "Game" });
    }
}
