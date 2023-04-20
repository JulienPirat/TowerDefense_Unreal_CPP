// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Pawn.h"
#include "Projectiles/Projectile.h"
#include "DADObject.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API ADADObject : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* AreaCanFire;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BarrelMesh;

	UPROPERTY(EditAnywhere)
	UWidgetInteractionComponent* WidgetInteraction;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* CanPutTower;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* CanNOTPutTower;
	
public:
	// Sets default values for this pawn's properties
	ADADObject();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isActive;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AProjectile> Projectile;

	UFUNCTION(BlueprintCallable)
	void FireProjectile();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetIsActive(bool value);
	
private:

	FVector InitialPosition;
	APlayerController* playerController;
};
