// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalWeaponPickup.h"
#include "TP_WeaponComponent.h"
#include "GameFramework/Actor.h"
#include "FPSPlayerCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ANormalWeaponPickup::ANormalWeaponPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickUpSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("TP_PickUpComponent"));
	SetRootComponent(PickUpSphereComponent);

	GunMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMeshComponent"));
}

// Called when the game starts or when spawned
void ANormalWeaponPickup::BeginPlay()
{
	Super::BeginPlay();

	PickUpSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ANormalWeaponPickup::OnSphereBeginOverlaping);
}

// Called every frame
void ANormalWeaponPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANormalWeaponPickup::OnSphereBeginOverlaping(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AFPSPlayerCharacter* Character = Cast<AFPSPlayerCharacter>(OtherActor);
	if (Character != nullptr)
	{
		UActorComponent* ActorComponent = Character->AddComponentByClass(TP_WeaponComponentClass, false, FTransform(), false);
		UTP_WeaponComponent* TP_WeaponComponent = Cast<UTP_WeaponComponent>(ActorComponent);
		TP_WeaponComponent->AttachWeapon(Character);
		Destroy();
	}
}
