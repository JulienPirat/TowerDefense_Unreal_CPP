// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Mignon.h"
#include "AI/TemplateEnemy.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawner();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ATemplateEnemy> MobToSpawn;

	UPROPERTY(EditAnywhere)
	int NbToSpawn;

	UPROPERTY(EditAnywhere)
	float DelayToSpawn;

	UFUNCTION(BlueprintCallable)
	void removeOneEnemyRemaining();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/**
	 * @brief Fonction récursive jusqu'au bon nombre de mob spawn.
	 */
	void SpawnMob();

	int NbEnemyRemaining = 0;
};
