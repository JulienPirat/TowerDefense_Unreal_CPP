// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindEndLevel.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_CPP_API UBTTask_FindEndLevel : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	public:
    	UBTTask_FindEndLevel();
    
    private:
    	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    	virtual  FString GetStaticDescription() const override;
};
