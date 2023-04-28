// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AreaToFire.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API AAreaToFire : public AActor
{
	GENERATED_BODY()
	

public:
	// Sets default values for this actor's properties
	AAreaToFire();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* AreaCanFire;

	UFUNCTION(BlueprintCallable)
	void ChangeMaterial(UMaterialInterface* material);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
