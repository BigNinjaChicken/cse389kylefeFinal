// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Sound/SoundBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CSE389KYLEFEFINAL_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* BeginPlaySoundCue;
};
