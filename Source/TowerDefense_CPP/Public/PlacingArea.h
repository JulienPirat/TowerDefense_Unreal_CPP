﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PlacingArea.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API APlacingArea : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlacingArea();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanPlaceDADObject;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
