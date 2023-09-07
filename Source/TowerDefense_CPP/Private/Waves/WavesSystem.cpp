// Fill out your copyright notice in the Description page of Project Settings.


#include "Waves/WavesSystem.h"

#include "Kismet/GameplayStatics.h"
#include "Tasks/Task.h"
#include "Waves/SpawnerTemplate.h"


// Sets default values
AWavesSystem::AWavesSystem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AWavesSystem::GetMessageFromSpawner()
{
	if(AllSpawnersAreReady())
	{
		// Used to manage time
		FTimerHandle TimerHandle;

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle); //Clear le timer pour pas faire des pertes de mémoire.
			InitSpawners();
			StartAllSpawners();
		},  delayBetweenWaves, false);
	}
}

// Called when the game starts or when spawned
void AWavesSystem::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> ActorSpawners;
	UGameplayStatics::GetAllActorsOfClass(this,Spawner,ActorSpawners);

	for (auto ActorSpawner : ActorSpawners)
	{
		if (auto x = Cast<ASpawnerTemplate>(ActorSpawner)) {
			Spawners.Add(x);
		}
	}

	if(IsValid(DataTableForLevel))
		InitSpawners();
	
	if(AllSpawnersAreReady())
		StartAllSpawners();
}

bool AWavesSystem::AllSpawnersAreReady()
{
	int nbValide = Spawners.Num();
	for (auto sp : Spawners)
	{
		if(!sp->isEnable)
		{
			nbValide--;
		}
	}
	if(nbValide <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AWavesSystem::StartAllSpawners()
{
	for (auto sp : Spawners)
	{
		sp->StartSpawner();
	}
	idWave++;
}

void AWavesSystem::InitSpawners()
{
	TArray<FWavesDataTables*> res;
	DataTableForLevel->GetAllRows<FWavesDataTables>("",res);
	int nbSpawner = Spawners.Num();
	
	for (auto FromTable : res)
	{
		if(FromTable->WaveNumber == idWave)
		{
			Spawners[nbSpawner-1]->NbToSpawn = FromTable->nbMobs;
			Spawners[nbSpawner-1]->idMobIsSpawn = FromTable->mobToSpawn;
			nbSpawner--;
		}
	}
}

