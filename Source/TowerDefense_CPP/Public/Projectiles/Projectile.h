// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* SphereCollision;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EmptyMesh;

	UFUNCTION(BlueprintCallable)
	void destroyProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnOverlap(AActor* MyActor, AActor* OtherActor);

	
};
