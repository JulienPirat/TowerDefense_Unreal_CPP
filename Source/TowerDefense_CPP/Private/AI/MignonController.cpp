// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MignonController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AMignonController::AMignonController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackborad Component"));
}

void AMignonController::BeginPlay()
{
	Super::BeginPlay();
}

void AMignonController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(IsValid(Blackboard.Get()) && IsValid(BehaviorTree.Get()))
	{
		Blackboard->InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}
}