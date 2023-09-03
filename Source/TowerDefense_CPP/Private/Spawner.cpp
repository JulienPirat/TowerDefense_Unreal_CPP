// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "AI/TemplateEnemy.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DelayToSpawn = 1.5f;
}

void ASpawner::removeOneEnemyRemaining()
{
	NbToSpawn--;
	if(NbToSpawn == 0)
	{
		SpawnMob();
		NbToSpawn = 9; // A MODIFIER ICI
	}
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnMob();
}

/**
 * @brief Fonction récursive jusqu'au bon nombre de mob spawn.
 */
void ASpawner::SpawnMob()
{
	// Used to manage time
	FTimerHandle TimerHandle;
	auto spawnedMob = GetWorld()->SpawnActor<ATemplateEnemy>(this->MobToSpawn,GetActorLocation(), FRotator(0,0,0));
	//spawnedMob->giveSpawner(this); OLD
	NbEnemyRemaining++;
	if(IsValid(spawnedMob))
	{
		NbToSpawn -=1;
	}
	if(NbToSpawn>0)
	{
		// This with execute a function after the specified Delay
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			if(NbToSpawn>0)
			{
				GetWorld()->GetTimerManager().ClearTimer(TimerHandle); //Clear le timer pour pas faire des pertes de mémoire.
				SpawnMob();
			}
		},  DelayToSpawn, false);
	}
}