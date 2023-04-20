// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacingArea.h"


// Sets default values
APlacingArea::APlacingArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void APlacingArea::BeginPlay()
{
	Super::BeginPlay();
	
}
