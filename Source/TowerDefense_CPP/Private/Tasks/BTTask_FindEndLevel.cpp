// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/BTTask_FindEndLevel.h"

#include "AIController.h"
#include "EndLevel.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindEndLevel::UBTTask_FindEndLevel()
{
	NodeName = TEXT("Find End Level Location");

	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(
		UBTTask_FindEndLevel, BlackboardKey));
}

EBTNodeResult::Type UBTTask_FindEndLevel::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Coeur du joueur qui contient les pts de vie du joueur
	auto endLevel = UGameplayStatics::GetActorOfClass(GetWorld(),AEndLevel::StaticClass());

	if(IsValid(endLevel))
	{
		//Set la variable du BB avec la location du Coeur du Joueur.
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, endLevel->GetActorLocation());
	}

	return EBTNodeResult::Succeeded;
}

FString UBTTask_FindEndLevel::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector : %s"),*BlackboardKey.SelectedKeyName.ToString());
}