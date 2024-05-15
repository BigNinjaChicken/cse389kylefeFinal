// Fill out your copyright notice in the Description page of Project Settings.


#include "RoamInAreaBTTaskNode.h"
#include "AI/Navigation/NavigationTypes.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

URoamInAreaBTTaskNode::URoamInAreaBTTaskNode()
{
	NodeName = TEXT("Find Random Location");

	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(
		URoamInAreaBTTaskNode, BlackboardKey));
}

EBTNodeResult::Type URoamInAreaBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    FNavLocation Location{};

    // Get AI Pawn
    AAIController* AIController{ OwnerComp.GetAIOwner() };
    const APawn* AIPawn{ AIController->GetPawn() };

    // Get Pawn origin
    const FVector Origin{ AIPawn->GetActorLocation() };

    // Obtain Navigation System and find a random location
    const UNavigationSystemV1* NavSystem{ UNavigationSystemV1::GetCurrent(GetWorld()) };
    if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, Location))
    {
        AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Location.Location);
    }

    // Signal the BehaviorTreeComponent that the task finished with a Success!
    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}

FString URoamInAreaBTTaskNode::GetStaticDescription() const
{
    return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
