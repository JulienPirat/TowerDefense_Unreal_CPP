// Fill out your copyright notice in the Description page of Project Settings.


#include "DragAndDrop/RailGun_Tower.h"


// Sets default values
ARailGun_Tower::ARailGun_Tower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Configure le MiddleBody Mesh Component
	MiddleBody = CreateDefaultSubobject<UStaticMeshComponent>("MiddleBody");
	MiddleBody->SetupAttachment(RootComponent);

	// Configure le MiddleShield Mesh Component
	MiddleShield = CreateDefaultSubobject<UStaticMeshComponent>("MiddleShield");
	MiddleShield->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARailGun_Tower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARailGun_Tower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

