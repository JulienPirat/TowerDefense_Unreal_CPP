// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Pawn.h"
#include "DADObject.generated.h"

UCLASS()
class TOWERDEFENSE_CPP_API ADADObject : public APawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	UWidgetInteractionComponent* WidgetInteraction;


	
public:
	// Sets default values for this pawn's properties
	ADADObject();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isActive;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	FVector InitialPosition;
	APlayerController* playerController;
};
