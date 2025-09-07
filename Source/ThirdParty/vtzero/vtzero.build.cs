using UnrealBuildTool;
using System;
using System.IO;

public class vtzero : ModuleRules
{
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
	}

	public vtzero(ReadOnlyTargetRules target) : base(target)
	{
		Type = ModuleType.External;

		// Create vtzero path 
		string vtzeroPath = Path.Combine(ThirdPartyPath, "vtzero");

		// Add include paths
		PublicIncludePaths.AddRange(new string[] { Path.Combine(vtzeroPath, "vtzero/include") });
	}
}
