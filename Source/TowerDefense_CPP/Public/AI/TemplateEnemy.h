// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MignonController.h"
#include "UObject/Object.h"
#include "TemplateEnemy.generated.h"

class ASpawner;

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_CPP_API ATemplateEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATemplateEnemy();

	UPROPERTY(BlueprintReadOnly, Category="AI")
	AMignonController* AIController;
	
	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPawnMovementComponent> MovementComponent;

	/**
	 * @brief Dégat du mignon fait au joueur
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stat")
	int Damage;

	/**
	 * @brief Vie du mignon
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stat")
	int Life;

	/**
	 * @brief 
	 * @param damageTook Dégats reçu
	 */
	UFUNCTION(BlueprintCallable)
	void tookDamage(int damageTook);

	/**
	 * @brief Spawner were this Enemy was spawn.
	 */
	UFUNCTION(BlueprintCallable)
	void giveSpawner(ASpawner* spawner);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	
	/**
	 * @brief Spawner were this Enemy was spawn.
	 */
	ASpawner* _spawner;
};
