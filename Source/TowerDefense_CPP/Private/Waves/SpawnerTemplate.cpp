// Fill out your copyright notice in the Description page of Project Settings.


#include "Waves/SpawnerTemplate.h"
#include "Kismet/GameplayStatics.h"
#include "AI/TemplateEnemy.h"
#include "Waves/WavesSystem.h"

// Sets default values
ASpawnerTemplate::ASpawnerTemplate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DelayToSpawn = 1.5f;
	isEnable = false;
}

// Called when the game starts or when spawned
void ASpawnerTemplate::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnerTemplate::StartSpawner()
{
	isEnable = true;
	NbEnemyRemaining = 0;
	SpawnMob();
}

/**
 * @brief Fonction récursive jusqu'au bon nombre de mob spawn.
 */
void ASpawnerTemplate::SpawnMob()
{
	if(NbToSpawn>0 && MobsCanSpawn.Num()>0)
	{
		//ICI Faire une vérif si le ID Existe ainsi que la liste est bien rempli
		// Used to manage time
		FTimerHandle TimerHandle;
		auto spawnedMob = GetWorld()->SpawnActor<ATemplateEnemy>(this->MobsCanSpawn[idMobIsSpawn],GetActorLocation(), FRotator(0,0,0));
		spawnedMob->giveSpawner(this);
		NbEnemyRemaining++;
		NbToSpawn--;
	
		// This with execute a function after the specified Delay
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
		{
			if(NbToSpawn>0)
			{
				//GetWorld()->GetTimerManager().ClearTimer(TimerHandle); //Clear le timer pour pas faire des pertes de mémoire. | UPD : Not working and clear the wrong timer when more than 1 spawner
				SpawnMob();
			}else
			{
				//GetWorld()->GetTimerManager().ClearTimer(TimerHandle); //Clear le timer pour pas faire des pertes de mémoire. | UPD : Not working and clear the wrong timer when more than 1 spawner
			}
		},  DelayToSpawn, false);
	}
}

void ASpawnerTemplate::SendFinishToWavesSystem()
{
	auto AWaveSys = UGameplayStatics::GetActorOfClass(this,WaveSystem);
	
	if (auto WaveSys = Cast<AWavesSystem>(AWaveSys)) {
		WaveSys->GetMessageFromSpawner();
	}

}

void ASpawnerTemplate::removeOneEnemyRemaining()
{
	NbEnemyRemaining--;
	if(NbEnemyRemaining <= 0)
	{
		NbEnemyRemaining = 0; // au cas ou
		isEnable = false;
		GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
		SendFinishToWavesSystem();
	}
}
