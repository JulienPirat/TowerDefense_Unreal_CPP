// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DADObject.h"
#include "GameFramework/Actor.h"
#include "RailGun_Tower.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API ARailGun_Tower : public ADADObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MiddleBody;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MiddleShield;
	
public:
	// Sets default values for this actor's properties
	ARailGun_Tower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
