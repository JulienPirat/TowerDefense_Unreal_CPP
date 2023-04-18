// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
ASpawner::ASpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnMob();
}

void ASpawner::SpawnMob()
{
	// Used to manage time
	FTimerHandle TimerHandle;
	auto spawnedMob = GetWorld()->SpawnActor<AMignon>(this->MobToSpawn,GetActorLocation(), FRotator(0,0,0));
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
				GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
				SpawnMob();
			}
		},  1.5f, false);
	}
}