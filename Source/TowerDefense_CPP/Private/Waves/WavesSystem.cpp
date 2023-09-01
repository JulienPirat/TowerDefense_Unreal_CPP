// Fill out your copyright notice in the Description page of Project Settings.


#include "Waves/WavesSystem.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AWavesSystem::AWavesSystem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
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

	if(AllSpawnersAreReady())
	{
		
	}
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

