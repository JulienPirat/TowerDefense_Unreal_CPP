// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Waves/WavesSystem.h"
#include "GameFramework/Actor.h"
#include "SpawnerTemplate.generated.h"

class ATemplateEnemy;

UCLASS()
class TOWERDEFENSE_CPP_API ASpawnerTemplate : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnerTemplate();

	UPROPERTY(EditAnywhere)
	TMap<int,TSubclassOf<ATemplateEnemy>> MobsCanSpawn;

	/**
	 * @brief Number of Mob need to Spawn
	 */
	UPROPERTY(VisibleAnywhere)
	int NbToSpawn;

	UPROPERTY(EditAnywhere)
	float DelayToSpawn;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	bool isEnable;

	/**
	 * @brief Number of mobs that didn't die
	 */
	UPROPERTY(VisibleAnywhere)
	int NbEnemyRemaining = 0;

	UPROPERTY(VisibleAnywhere)
	int idMobIsSpawn;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AWavesSystem> WaveSystem;

	UFUNCTION(BlueprintCallable)
	void removeOneEnemyRemaining();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	void StartSpawner();

private:
	/**
	 * @brief Recursive function until the correct number of mob spawn
	 */
	void SpawnMob();

	void SendFinishToWavesSystem();
};
