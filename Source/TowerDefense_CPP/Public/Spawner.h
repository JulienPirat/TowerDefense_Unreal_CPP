﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/Mignon.h"
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
	TSubclassOf<AMignon> MobToSpawn;

	UPROPERTY(EditAnywhere)
	int NbToSpawn;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SpawnMob();
};
