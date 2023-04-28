// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Mignon.h"

#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
AMignon::AMignon()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(BoxCollision);

	// Create Movement Component for the Mignon
	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void AMignon::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AMignon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

