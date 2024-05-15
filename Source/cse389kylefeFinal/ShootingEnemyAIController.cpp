// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingEnemyAIController.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

AShootingEnemyAIController::AShootingEnemyAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AShootingEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTree) {
		RunBehaviorTree(BehaviorTree);
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}
}

void AShootingEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (Blackboard && BehaviorTree) {
		Blackboard->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}
