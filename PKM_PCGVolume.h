// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PCGVolume.h"
#if WITH_EDITOR
#include "Editor.h"
#include "EditorModeManager.h"
#endif


#include "PKM_PCGVolume.generated.h"

UENUM(BlueprintType)
enum class EDisablePCGMode : uint8
{
	DISABLEONLANDSCAPEMODE = 0 UMETA(DisplayName = "Disable on LandscapeMode"),
	DISABLEONEVERYMODE = 1 UMETA(DisplayName = "Disable on every modes"),
	DONTDISABLE = 2 UMETA(DisplayName = "Dont disable"),
};

UCLASS(BlueprintType)
class POKEMONGAME_API APKM_PCGVolume : public APCGVolume
{
	GENERATED_BODY()
	
public:

	APKM_PCGVolume(const FObjectInitializer& ObjectInitializer);

	virtual void Destroyed() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EDisablePCGMode DisablePCGMode = EDisablePCGMode::DISABLEONLANDSCAPEMODE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CleanupOnDisable = true;

#if WITH_EDITOR
		bool bDisableState = true;
		void OnEditorModeChanged(const FEditorModeID& InID, bool bIsActive);
#endif

};
