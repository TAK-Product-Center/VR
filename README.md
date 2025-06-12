# VR-TAK Plugin SDK
1. Download Unreal Engine 5.3.2 from [github](https://github.com/EpicGames/UnrealEngine)
   - This readme will refer to the Unreal Engine root directory as [root]. Run [root]/Setup.bat to download Unreal Engine dependencies
2. Download the VR-TAK plugin SDK from [github](https://github.com/TAK-Product-Center/VR)
   - This readme will refer to the plugin SDK root directory as [sdkRoot]. Copy [root]/Engine into [sdkRoot] such that afterward you see [sdkRoot]/Engine
   - Copy the contents of [sdkRoot]/EnginePatch into [sdkRoot]/Engine and replace all files
3. Run [sdkRoot]/GenerateProjectFiles.bat
4. Open [sdkRoot]/UE5.sln in Visual Studio 2022
5. Build Engine/UE5 and Games/Game projects
