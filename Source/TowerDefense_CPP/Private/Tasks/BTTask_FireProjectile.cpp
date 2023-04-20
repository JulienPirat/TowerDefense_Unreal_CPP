// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/BTTask_FireProjectile.h"

#include "AIController.h"
#include "AI/Mignon.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DragAndDrop/DADObject.h"
#include "Kismet/KismetMathLibrary.h"

UBTTask_FireProjectile::UBTTask_FireProjectile()
{
	NodeName = TEXT("Fire Projectile");
}

EBTNodeResult::Type UBTTask_FireProjectile::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto Mob_ = OwnerComp.GetAIOwner()->GetBlackboardComponent()->GetValueAsObject(FName("Mob"));
	auto Tower_ = OwnerComp.GetAIOwner()->GetPawn();

	if (auto Tower = Cast<ADADObject>(Tower_))
	{
		if(IsValid(Mob_))
		{
			if (auto Mob = Cast<AMignon>(Mob_))
			{
				auto TowerLocation = Tower->GetActorLocation();
				auto MobLocation = Mob->GetActorLocation();
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
