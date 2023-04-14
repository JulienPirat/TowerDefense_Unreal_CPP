// Fill out your copyright notice in the Description page of Project Settings.


#include "DragAndDrop/DADObject.h"

#include "Kismet/GameplayStatics.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
ADADObject::ADADObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Configure le Mesh Component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;

	// Configure le Widget Interaction Component
	WidgetInteraction = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteraction");
	WidgetInteraction->SetupAttachment(MeshComponent);

}

// Called when the game starts or when spawned
void ADADObject::BeginPlay()
{
	Super::BeginPlay();
	isActive = true;
}

// Called every frame
void ADADObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADADObject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}