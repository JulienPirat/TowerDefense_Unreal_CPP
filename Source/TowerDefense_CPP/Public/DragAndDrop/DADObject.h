// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AreaToFire.h"
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
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AAreaToFire> AreaCanFire;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BarrelMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SpawnProjectile_Empty;

	UPROPERTY(EditAnywhere)
	UWidgetInteractionComponent* WidgetInteraction;

	UPROPERTY(BlueprintReadOnly, Category="AI")
	AAIController* AIController;

	/**
	 * @brief Time to the tower for react
	 */
	UPROPERTY(EditAnywhere, Category="AI")
	float TimeToReact;
	
	/**
	 * @brief Indique si la tour peut tirer 
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isActive;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AProjectile>> Projectile;

	/**
	 * @brief Material lors de la sélection d'une tourelle
	 */
	UPROPERTY(EditAnywhere, Category="Glowing")
	UMaterialInterface* Glowing_material;

	/**
	 * @brief Material lors de la désélection d'une tourelle
	 */
	UPROPERTY(EditAnywhere, Category="Glowing")
	UMaterialInterface* Unglowing_material;

	/**
	 * @brief Material MiddleShield pour upgrade
	 */
	UPROPERTY(EditAnywhere, Category="Upgrade")
	TArray<UMaterialInterface*> MiddleShield_material;

	/**
	 * @brief Material Cable pour upgrade
	 */
	UPROPERTY(EditAnywhere, Category="Upgrade")
	TArray<UMaterialInterface*> Cable_material;

	UPROPERTY(EditAnywhere, Category="Sounds")
	USoundBase* DestroySound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	USoundBase* UpgradeSound;
	
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

	UFUNCTION(BlueprintCallable)
	void BeforeDestroy();

	UFUNCTION(BlueprintCallable)
	virtual void ChangeMaterialForGlowing(UMaterialInterface* material);

	UFUNCTION(BlueprintCallable)
	virtual void ChangeMaterialForUpgrade();

	UFUNCTION(BlueprintCallable)
	virtual void Upgrade();
	
	/**
	 * @brief Possibilité de poser une tourelle. Utilisé dans le player.
	 */
	bool b_CanPutTower;

	/**
	 * @brief Nombre de fois que la tower a été upgrade
	 */
	int NbUpgrade;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	
	/**
	 * @brief Change la position de la tourelle
	 * @param Position FVector qui indique la nouvelle position de la tourelle. 
	 */
	void ChangeTowerPosition(FVector Position);

	void UpdateAreaPosition(UMaterialInterface* material);
	
	AAreaToFire* TempArea;
	
	FVector InitialPosition;
	APlayerController* playerController;

	
};