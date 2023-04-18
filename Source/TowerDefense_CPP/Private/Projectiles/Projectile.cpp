// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/Projectile.h"

#include "AI/Mignon.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	EmptyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EmptyMesh"));
	RootComponent = EmptyMesh;
	
	// Configure la collision
	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SphereCollision->SetupAttachment(EmptyMesh);
	
	// Configure le Mesh Component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(SphereCollision);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	this->OnActorBeginOverlap.AddDynamic(this, &AProjectile::OnOverlap);

	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	UKismetSystemLibrary::MoveComponentTo(SphereCollision, FVector(900, 0, 0),
		FRotator(0.0f, 0.0f, 0.0f), false, false, 1.5f, false,EMoveComponentAction::Type::Move, LatentInfo);
}	

void AProjectile::OnOverlap(AActor* MyActor, AActor* OtherActor)
{
	if (auto Mignon = Cast<AMignon>(OtherActor)) {
		Mignon->Destroy();
		Destroy();
	}
}

