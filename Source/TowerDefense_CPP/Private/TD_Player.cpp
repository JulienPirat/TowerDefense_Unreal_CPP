// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Player.h"

#include "DragAndDrop/DADObject.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"

// Sets default values
ATD_Player::ATD_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATD_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATD_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// You can bind to any of the trigger events here by changing the "ETriggerEvent" enum value
	Input->BindAction(IA_LeftClick, ETriggerEvent::Triggered, this, &ATD_Player::LeftClick);
}

void ATD_Player::LeftClick(const FInputActionInstance& Instance)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("ICI 1"));
} 