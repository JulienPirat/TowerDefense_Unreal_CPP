// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MignonController.h"
#include "TemplateEnemy.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ImpossibleCube.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API AImpossibleCube : public ATemplateEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AImpossibleCube();

	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollision;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ImpossibleCubeMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SphereMesh;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
