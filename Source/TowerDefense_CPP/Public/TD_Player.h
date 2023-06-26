// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "DragAndDrop/DADObject.h"
#include "GameFramework/Pawn.h"
#include "TD_Player.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class TOWERDEFENSE_CPP_API ATD_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATD_Player();

	// Expose a mapping context as a property in your header file...
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* IA_LeftClick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* IA_LeftClick_Grabe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* IA_ShotcutMoveTower_M;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ADADObject> DADObjectToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stat")
	int Life;

	/**
	 * @brief Tourelle Sélectionnée.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ADADObject* TempTowerSelected;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void LeftClick(const FInputActionInstance& Instance);
	void LeftClickGrab(const FInputActionInstance& Instance);
	void ShortcutMoveTower_M(const FInputActionInstance& Instance);

	/**
	 * @brief Indique si peut poser une tourelle (Utilisé dans le UI)
	 */
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool canPutTower;

	/**
	 * @brief Création d'une tourelle (Utilisé en BP)
	 */
	UFUNCTION(BlueprintCallable)
	void CreateDADObject();

	/**
	 * @brief Destruction de la tourelle temporaire (Utilisé en BP)
	 */
	UFUNCTION(BlueprintCallable)
	void DestroyDADObject();

	UFUNCTION(BlueprintCallable)
	void TookDamage(int value);

	/**
	 * @brief Augmente les stats et la couleurs de la tourelle sélectionnée.
	 */
	UFUNCTION(BlueprintCallable)
	void UpgradeSelectedTower();

	/**
	 * @brief Supprime la tourelle sélectionnée.
	 */
	UFUNCTION(BlueprintCallable)
	void DeleteSelectedTower();
	
private:
	
	bool isLeftClickGrab; //Si déplacement de tourelle.

	/**
	 * @brief Tourelle créer ou grab.
	 */
	ADADObject* TempGrab;

	
};
