// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cse389kylefeFinal : ModuleRules
{
	public cse389kylefeFinal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "UMG",
            "AIModule",
            "GameplayTasks",
            "Niagara",
            "GameplayAbilities",
            "GameplayTags",
            "NavigationSystem",
            "GameplayTasks" });
	}
}
