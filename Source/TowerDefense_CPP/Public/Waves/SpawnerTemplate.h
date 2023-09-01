// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI/TemplateEnemy.h"
#include "SpawnerTemplate.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API ASpawnerTemplate : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnerTemplate();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ATemplateEnemy> MobToSpawn;

	UPROPERTY(EditAnywhere)
	int NbToSpawn;

	UPROPERTY(EditAnywhere)
	float DelayToSpawn;

	UPROPERTY(BlueprintReadOnly)
	bool isEnable;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartSpawner();

private:
	/**
	 * @brief Fonction récursive jusqu'au bon nombre de mob spawn.
	 */
	void SpawnMob();
};