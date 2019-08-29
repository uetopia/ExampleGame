// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExampleGame : ModuleRules
{
	public ExampleGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","Json",
                "JsonUtilities",
                "HTTP",
                "OnlineSubsystem",
                "OnlineSubsystemUtils",
                "LoginFlow",
                "UMG",
                "Slate",
                "SlateCore",
                "GameplayAbilities",
                "GameplayTasks",
	            "GameplayTags",
                "RamaSaveSystem"
         });

        PrivateDependencyModuleNames.AddRange(new string[] { "LoginFlow", "RamaSaveSystem", "Slate", "SlateCore" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "RamaSaveSystem" });

    }
}
