// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/ImpossibleCube.h"

#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
AImpossibleCube::AImpossibleCube()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	ImpossibleCubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("ImpossibleCubeMesh");
	ImpossibleCubeMesh->SetupAttachment(BoxCollision);
	
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	SphereMesh->SetupAttachment(ImpossibleCubeMesh);
	
}

// Called when the game starts or when spawned
void AImpossibleCube::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AImpossibleCube::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
