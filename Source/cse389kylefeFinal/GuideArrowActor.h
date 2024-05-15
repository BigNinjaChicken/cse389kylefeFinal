#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GuideArrowActor.generated.h"

UCLASS()
class CSE389KYLEFEFINAL_API AGuideArrowActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGuideArrowActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Function to handle overlap event
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
						class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Sphere component for detecting overlaps
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USphereComponent* SphereComponent;

	// Static mesh component
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* StaticMesh;

	// Sound to play on overlap
	UPROPERTY(EditAnywhere, Category = "Sound")
	class USoundBase* OverlapSound;

	// Niagara particle system to play on overlap
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UNiagaraSystem* OverlapEffect;
};
