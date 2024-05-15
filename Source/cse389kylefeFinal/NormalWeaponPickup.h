// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP_WeaponComponent.h"
#include "NormalWeaponPickup.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class CSE389KYLEFEFINAL_API ANormalWeaponPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANormalWeaponPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USphereComponent* PickUpSphereComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	UStaticMeshComponent* GunMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnSphereBeginOverlaping(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	TSubclassOf<UTP_WeaponComponent> TP_WeaponComponentClass;
};
