// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (!BeginPlaySoundCue)
	{
		UE_LOG(LogTemp, Warning, TEXT("BeginPlaySoundCue is Null"));
	}

	// Play the 2D sound at the beginning of the game
	UGameplayStatics::PlaySound2D(GetWorld(), BeginPlaySoundCue);
}
