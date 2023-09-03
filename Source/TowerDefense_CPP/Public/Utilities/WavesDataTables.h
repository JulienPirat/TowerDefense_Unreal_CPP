// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "WavesDataTables.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct FWavesDataTables : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int WaveNumber;

	UPROPERTY(EditAnywhere)
	FString mobToSpawn;
	
	UPROPERTY(EditAnywhere)
	int nbMobs;

	UPROPERTY(EditAnywhere)
	int SpawnerNumber;
};