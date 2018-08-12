// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BuildingEscapeEditorTarget : TargetRules
{
	public BuildingEscapeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "BuildingEscape" } ); //This line must to be here on UnrealEngine4.17 or greater UE

        bUseUnityBuild = false;
        bUsePCHFiles = false;
    }
}
