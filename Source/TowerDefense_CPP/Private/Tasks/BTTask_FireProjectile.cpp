// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/BTTask_FireProjectile.h"

#include "AIController.h"
#include "AI/Mignon.h"
#include "AI/TemplateEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DragAndDrop/DADObject.h"
#include "Kismet/KismetMathLibrary.h"

UBTTask_FireProjectile::UBTTask_FireProjectile()
{
	NodeName = TEXT("Fire Projectile");
}

EBTNodeResult::Type UBTTask_FireProjectile::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto Mob_ = OwnerComp.GetAIOwner()->GetBlackboardComponent()->GetValueAsObject(FName("Mob")); //Récupération du mob
	auto Tower_ = OwnerComp.GetAIOwner()->GetPawn();	//Récupération de la tourelle

	if (auto Tower = Cast<ADADObject>(Tower_))
	{
		if(IsValid(Mob_))
		{
			if (auto Mob = Cast<ATemplateEnemy>(Mob_))
			{
				auto TowerLocation = Tower->GetActorLocation();
				auto MobLocation = Mob->GetActorLocation();
				//Donne la rotation de la tourelle pour regarder le mob
				auto NewRotation = UKismetMathLibrary::FindLookAtRotation(TowerLocation,MobLocation); 
				Tower->SetActorRotation(NewRotation);
				Tower->FireProjectile();
			}
		}
	}
	return EBTNodeResult::Succeeded;
}

FString UBTTask_FireProjectile::GetStaticDescription() const
{
	return Super::GetStaticDescription();
}
