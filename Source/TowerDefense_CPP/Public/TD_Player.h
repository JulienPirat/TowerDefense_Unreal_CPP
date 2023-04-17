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
    UInputAction* IA_G_GrabeMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* IA_LeftClick_Grabe;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ADADObject> TestSpawnDADObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stat")
	int Life;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void LeftClick(const FInputActionInstance& Instance);
	void LeftClickGrab(const FInputActionInstance& Instance);

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool canPutTower;

	UFUNCTION(BlueprintCallable)
	void CreateDADObject();

	UFUNCTION(BlueprintCallable)
	void DestroyDADObject();

	UFUNCTION(BlueprintCallable)
	void TookDamage(int value);
	
private:
	bool isLeftClickGrab;
	ADADObject* TempGrab;
};
