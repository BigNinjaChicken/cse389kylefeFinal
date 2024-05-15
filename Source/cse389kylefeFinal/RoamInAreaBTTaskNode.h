// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RoamInAreaBTTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class CSE389KYLEFEFINAL_API URoamInAreaBTTaskNode : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	URoamInAreaBTTaskNode();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	float SearchRadius = 500.0f;
};
