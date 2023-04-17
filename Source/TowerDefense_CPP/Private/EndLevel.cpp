// Fill out your copyright notice in the Description page of Project Settings.


#include "EndLevel.h"


// Sets default values
AEndLevel::AEndLevel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(BoxCollision);
}

// Called when the game starts or when spawned
void AEndLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEndLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

