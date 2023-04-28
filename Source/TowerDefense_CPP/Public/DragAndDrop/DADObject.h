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

	/**
	 * @brief Material pour l'areaDamage CanPutTower_material
	 */
	UPROPERTY(EditAnywhere)
	UMaterialInterface* CanPutTower_material;

	/**
	 * @brief Material pour l'areaDamage CanNotPutTower_material
	 */
	UPROPERTY(EditAnywhere)
	UMaterialInterface* CanNotPutTower_material;
	
public:
	// Sets default values for this pawn's properties
	ADADObject();

	/**
	 * @brief Indique si la tour peut tirer 
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isActive;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AProjectile> Projectile;

	/**
	 * @brief Tire un Projectile en direction du forward Vector de la tourelle
	 */
	UFUNCTION(BlueprintCallable)
	void FireProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
	 * @brief Permet de set si la tour est capable de tirer ou non. true = peut tier, false = peut pas tirer.
	 * @param value Boolean qui active ou non la possibilité de tirer.
	 */
	UFUNCTION(BlueprintCallable)
	void SetIsActive(bool value);

	/**
	 * @brief Possibilité de poser une tourelle. Utilisé dans le player.
	 */
	bool b_CanPutTower;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	
	/**
	 * @brief Change la position de la tourelle
	 * @param Position FVector qui indique la nouvelle position de la tourelle. 
	 */
	void ChangeTowerPosition(FVector Position);
	
	FVector InitialPosition;
	APlayerController* playerController;
};
