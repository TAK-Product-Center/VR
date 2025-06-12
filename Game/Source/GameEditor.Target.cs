using UnrealBuildTool;

public class GameEditorTarget : TargetRules
{
	public GameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        bUseUnityBuild = false;
        bUsePCHFiles = false;

        DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		// for VH_Database
		bOverrideBuildEnvironment = true;  
		AdditionalCompilerArguments = "/wd4668";

		ExtraModuleNames.AddRange( new string[] { "Game" } );
	}
}
