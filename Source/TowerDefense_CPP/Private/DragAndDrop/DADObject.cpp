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
	
}

// Called every frame
void ADADObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (WidgetInteraction && WidgetInteraction->IsOverInteractableWidget())
	{
		// Convertit la position du curseur en un rayon dans l'espace 3D de la scène
		FVector2D MousePosition;
		UGameplayStatics::GetPlayerController(GetWorld(),0)->GetMousePosition(MousePosition.X, MousePosition.Y);
		FHitResult HitResult;
		UGameplayStatics::GetPlayerController(GetWorld(),0)->GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, false, HitResult);
		FVector WorldLocation = HitResult.Location;
		FVector WorldDirection = FVector::ZeroVector;

		// Convertit la position du curseur en un rayon dans l'espace 3D de la scène
		FVector ObjectForwardVector = GetActorForwardVector();
		FVector ObjectRightVector = GetActorRightVector();
		FVector ObjectUpVector = GetActorUpVector();

		FVector Offset = FVector(ObjectRightVector * GetActorLocation().X + ObjectForwardVector * GetActorLocation().Y + ObjectUpVector * GetActorLocation().Z);

		HitResult.Location += Offset;

		// Met à jour la position de l'objet pour qu'il suive le curseur
		SetActorLocation(HitResult.Location);
	}
}

// Called to bind functionality to input
void ADADObject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Configure les événements de clic gauche et de relâchement de clic gauche
	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &ADADObject::OnLeftClick);
	PlayerInputComponent->BindAction("LeftClick", IE_Released, this, &ADADObject::OnLeftClickReleased);
}

void ADADObject::OnLeftClick()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("ICI Click"));
	if (WidgetInteraction && WidgetInteraction->IsOverInteractableWidget())
	{
		// Stocke la position initiale de l'objet pour le drag and drop
		InitialPosition = GetActorLocation();
	}
}

void ADADObject::OnLeftClickReleased()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("ICI Realsee"));
	if (WidgetInteraction && WidgetInteraction->IsOverInteractableWidget())
	{
		// Réinitialise la position initiale de l'objet pour arrêter le drag and drop
		InitialPosition = FVector::ZeroVector;
	}
}