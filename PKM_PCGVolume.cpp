// Fill out your copyright notice in the Description page of Project Settings.


#include "PKM_PCGVolume.h"
#include "PCGComponent.h"

APKM_PCGVolume::APKM_PCGVolume(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	if (GetLevel())
	{
		if (GLevelEditorModeToolsIsValid())
		{
			GLevelEditorModeTools().OnEditorModeIDChanged().AddUObject(this, &APKM_PCGVolume::OnEditorModeChanged);
		}
	}
#endif
}

void APKM_PCGVolume::Destroyed()
{
#if WITH_EDITOR
	if (GetWorld())
	{
		GLevelEditorModeTools().OnEditorModeIDChanged().RemoveAll(this);
	}
#endif

	Super::Destroyed();
}

#if WITH_EDITOR
void APKM_PCGVolume::OnEditorModeChanged(const FEditorModeID& InID, bool bIsActive)
{
	if (bIsActive)
	{
		bool newDisableState = false;

		if (DisablePCGMode == EDisablePCGMode::DISABLEONLANDSCAPEMODE)
		{
			newDisableState = (InID == "EM_Landscape");
		}
		else if (DisablePCGMode == EDisablePCGMode::DISABLEONEVERYMODE)
		{
			newDisableState = !(InID == "EM_Default");
		}

		if (PCGComponent && newDisableState != bDisableState)
		{
			bDisableState = newDisableState;

			PCGComponent->bActivated = !bDisableState;
			if (bDisableState)
			{
				PCGComponent->CancelGeneration();
				if (CleanupOnDisable)
				{
					PCGComponent->Cleanup();
				}
			}
			else
			{
				PCGComponent->CancelGeneration();
				PCGComponent->CleanupLocalImmediate(true);
				PCGComponent->Generate();
			}
		}
	}
}
#endif