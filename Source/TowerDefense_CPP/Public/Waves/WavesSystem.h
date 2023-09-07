// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utilities/WavesDataTables.h"
#include "WavesSystem.generated.h"

class ASpawnerTemplate;

UCLASS()
class TOWERDEFENSE_CPP_API AWavesSystem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWavesSystem();

	/**
	 * @brief List of all Spawners in the LVL
	 */
	UPROPERTY(BlueprintReadOnly)
	TArray<ASpawnerTemplate*> Spawners;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpawnerTemplate> Spawner;

	UPROPERTY(EditAnywhere)
	int delayBetweenWaves;

	UPROPERTY(EditAnywhere)
	UDataTable* DataTableForLevel;

	UPROPERTY(VisibleAnywhere)
	int idWave = 1;
	
	/**
	 * @brief Take message from spawner to indicate all of his mob was dead.
	 * Waves System check if all spawner are ready to launch next wave.
	 */
	void GetMessageFromSpawner();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	/**
	 * @brief request all spawners if they are ready to spawn Mobs
	 * @return true if all spawner is ready | false if one of them is not
	 */
	bool AllSpawnersAreReady();

	/**
	 * @brief Launch all Spawner and increase idWave.
	 */
	void StartAllSpawners();

	/**
	 * @brief Initialize Spawners (NbMob and idMob) with DataTable values.
	 */
	void InitSpawners();
};
