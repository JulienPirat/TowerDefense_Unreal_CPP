// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnerTemplate.h"
#include "GameFramework/Actor.h"
#include "WavesSystem.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API AWavesSystem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWavesSystem();
	
	UPROPERTY(BlueprintReadOnly)
	TArray<ASpawnerTemplate*> Spawners;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpawnerTemplate> Spawner;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	/**
	 * @brief request all spawners if they are ready to spawn Mobs
	 * @return true if all spawner is ready | false if one of them is not
	 */
	bool AllSpawnersAreReady();

	void StartAllSpawners();
};
