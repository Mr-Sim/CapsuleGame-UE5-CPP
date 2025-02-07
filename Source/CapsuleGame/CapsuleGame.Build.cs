// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CapsuleGame : ModuleRules
{
	public CapsuleGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
