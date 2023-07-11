// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/ProjectileRailGun_LVL_01.h"


// Sets default values
AProjectileRailGun_LVL_01::AProjectileRailGun_LVL_01()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AProjectileRailGun_LVL_01::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileRailGun_LVL_01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

