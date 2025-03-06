// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5WorkshopCpp : ModuleRules
{
	public UE5WorkshopCpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
