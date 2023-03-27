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

	UPROPERTY(EditAnywhere)
	TSubclassOf<ADADObject> TestSpawnDADObject;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void LeftClick(const FInputActionInstance& Instance);
	void GrabMode(const FInputActionInstance& Instance);
	
private:
    bool isGrabMode;
};
