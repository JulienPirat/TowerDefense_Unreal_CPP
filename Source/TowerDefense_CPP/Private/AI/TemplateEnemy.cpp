// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TemplateEnemy.h"

#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
ATemplateEnemy::ATemplateEnemy()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Movement Component for the Mignon
	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;
}

void ATemplateEnemy::tookDamage(int damageTook)
{
	this->Life -= damageTook;
	if(Life <= 0)
	{
		BeforeDestroy();
	}
}

void ATemplateEnemy::giveSpawner(ASpawnerTemplate* spawner)
{
	this->_spawner = spawner;
}

// Called when the game starts or when spawned
void ATemplateEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATemplateEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATemplateEnemy::BeforeDestroy()
{
	_spawner->removeOneEnemyRemaining();
	Destroy();
}
