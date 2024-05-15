#include "GuideArrowActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Sound/SoundBase.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Kismet/GameplayStatics.h"
#include "FPSPlayerCharacter.h"

// Sets default values
AGuideArrowActor::AGuideArrowActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize SphereComponent
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(100.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Trigger"));

	// Initialize StaticMesh
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	// Bind overlap event
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AGuideArrowActor::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AGuideArrowActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGuideArrowActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGuideArrowActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor is Null"));
		return;
	}

	if (OtherActor == this) 
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor is this"));
		return;
	}

	if (!OverlapSound)
	{
		UE_LOG(LogTemp, Warning, TEXT("OverlapSound is Null"));
		return;
	}

	if (!OverlapEffect)
	{
		UE_LOG(LogTemp, Warning, TEXT("OverlapEffect is Null"));
		return;
	}

	if (OtherActor->IsA(AFPSPlayerCharacter::StaticClass())) {
		UGameplayStatics::PlaySoundAtLocation(this, OverlapSound, StaticMesh->GetComponentLocation());
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), OverlapEffect, StaticMesh->GetComponentLocation());
		// Destroy the StaticMesh
		Destroy();
	}
}
