// Fill out your copyright notice in the Description page of Project Settings.


#include "Waves/SpawnerTemplate.h"
#include "Kismet/GameplayStatics.h"
#include "AI/TemplateEnemy.h"

// Sets default values
ASpawnerTemplate::ASpawnerTemplate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DelayToSpawn = 1.5f;
	isEnable = false;
}

// Called when the game starts or when spawned
void ASpawnerTemplate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnerTemplate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawnerTemplate::StartSpawner()
{
	isEnable = true;
	SpawnMob();
}

/**
 * @brief Fonction récursive jusqu'au bon nombre de mob spawn.
 */
void ASpawnerTemplate::SpawnMob()
{
	// Used to manage time
	FTimerHandle TimerHandle;
	auto spawnedMob = GetWorld()->SpawnActor<ATemplateEnemy>(this->MobToSpawn,GetActorLocation(), FRotator(0,0,0));
	if(NbToSpawn>0)
	{
		// This with execute a function after the specified Delay
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			if(NbToSpawn>0)
			{
				GetWorld()->GetTimerManager().ClearTimer(TimerHandle); //Clear le timer pour pas faire des pertes de mémoire.
				SpawnMob();
			}else
			{
				isEnable = false;
			}
		},  DelayToSpawn, false);
	}
}