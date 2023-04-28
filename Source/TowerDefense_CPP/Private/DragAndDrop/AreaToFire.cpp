// Fill out your copyright notice in the Description page of Project Settings.


#include "DragAndDrop/AreaToFire.h"


// Sets default values
AAreaToFire::AAreaToFire()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Configure le Corp de la tour Mesh Component
	AreaCanFire = CreateDefaultSubobject<UStaticMeshComponent>("AreaCanFire");
	RootComponent = AreaCanFire;
}

/**
 * @brief Change le material de la zone d'attaque.
 * @param material 
 */
void AAreaToFire::ChangeMaterial(UMaterialInterface* material)
{
	AreaCanFire->SetMaterial(0, material); //Change le matériel de la zone de dégats
}

// Called when the game starts or when spawned
void AAreaToFire::BeginPlay()
{
	Super::BeginPlay();
	
}
