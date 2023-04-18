// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TowerAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

ATowerAIController::ATowerAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackborad Component"));
}

void ATowerAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATowerAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(IsValid(Blackboard.Get()) && IsValid(BehaviorTree.Get()))
	{
		Blackboard->InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}
}