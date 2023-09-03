// Fill out your copyright notice in the Description page of Project Settings.


#include "EndLevel.h"

#include "TD_Player.h"
#include "AI/Mignon.h"
#include "AI/TemplateEnemy.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEndLevel::AEndLevel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(BoxCollision);
}

// Called when the game starts or when spawned
void AEndLevel::BeginPlay()
{
	Super::BeginPlay();
	this->OnActorBeginOverlap.AddDynamic(this, &AEndLevel::OnOverlap);
}

void AEndLevel::OnOverlap(AActor* MyActor, AActor* OtherActor)
{
	if (auto Enemy = Cast<ATemplateEnemy>(OtherActor)) {
		auto APlayer = UGameplayStatics::GetActorOfClass(GetWorld(),ATD_Player::StaticClass());
		if(IsValid(APlayer))
		{
			if (auto Player = Cast<ATD_Player>(APlayer)) {
				Player->TookDamage(Enemy->Damage);
				Enemy->BeforeDestroy();
			}
		}
	}
}
