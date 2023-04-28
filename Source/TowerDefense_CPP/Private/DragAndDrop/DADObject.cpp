// Fill out your copyright notice in the Description page of Project Settings.


#include "DragAndDrop/DADObject.h"


#include "PlacingArea.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
ADADObject::ADADObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Configure le Corp de la tour Mesh Component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;

	// Configure le Tuyau Mesh Component
	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>("BarrelMesh");
	BarrelMesh->SetupAttachment(MeshComponent);

	// Configure la zone que peut attaquer	** Uniquement Visuel ! **
	AreaCanFire = CreateDefaultSubobject<UStaticMeshComponent>("AreaCanFire");
	AreaCanFire->SetupAttachment(MeshComponent);

	// Configure le Widget Interaction Component ** ICI Encore jamais Utilisé ! **
	WidgetInteraction = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetInteraction");
	WidgetInteraction->SetupAttachment(MeshComponent);

}

/**
 * @brief Tire un Projectile en direction du forward Vector de la tourelle
 */
void ADADObject::FireProjectile()
{
	if(!isActive)
		auto p = GetWorld()->SpawnActor<AProjectile>(this->Projectile,GetActorLocation(), GetActorRotation());
}

// Called when the game starts or when spawned
void ADADObject::BeginPlay()
{
	Super::BeginPlay();
	SetIsActive(true);
	playerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
}

// Called every frame
void ADADObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(isActive)
	{
		//Si la tour peut tirer.
		FHitResult OutResult;
		if(playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,true, OutResult))
		{
			if(auto PlaceArea = Cast<APlacingArea>(OutResult.GetActor()))
			{
				if(PlaceArea->CanPlaceDADObject)
				{
					//Si la zone est une zone ou la tourelle peut être posée.
					if(IsValid(CanPutTower_material))
					{
						// Si le matérial n'est pas vide.
						AreaCanFire->SetMaterial(0,CanPutTower_material); //Change le matériel de la zone de dégats
						ChangeTowerPosition(OutResult.Location);
						b_CanPutTower = true;
					}
				}else
				{
					//Si la zone est une zone ou la tourelle ne peut pas être posée.
					if(IsValid(CanNotPutTower_material))
					{
						// Si le matérial n'est pas vide.
						AreaCanFire->SetMaterial(0,CanNotPutTower_material); //Change le matériel de la zone de dégats
						ChangeTowerPosition(OutResult.Location);
						b_CanPutTower = false;
					}
				}
			}else
			{
				//SI le cast ne fonctionne pas donc pas une zone Placing Area
				if(IsValid(CanPutTower_material))
				{
					// Si le matérial n'est pas vide.
					AreaCanFire->SetMaterial(0,CanPutTower_material); //Change le matériel de la zone de dégats
					ChangeTowerPosition(OutResult.Location);
					b_CanPutTower = true;
				}
			}
		}
	}
}

// Called to bind functionality to input
void ADADObject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/**
 * @brief Permet de set si la tour est capable de tirer ou non. true = peut tier, false = peut pas tirer.
 * @param value Boolean qui active ou non la possibilité de tirer.
 */
void ADADObject::SetIsActive(bool value)
{
	isActive = value;
	AreaCanFire->SetVisibility(value); // Affiche la zone d'attaque de la tourelle.
}

/**
 * @brief Change la position de la tourelle
 * @param Position FVector qui indique la nouvelle position de la tourelle. 
 */
void ADADObject::ChangeTowerPosition(FVector Position)
{
	auto EndLocation = Position;
	EndLocation.Z += 50;
	SetActorLocation(EndLocation);
}