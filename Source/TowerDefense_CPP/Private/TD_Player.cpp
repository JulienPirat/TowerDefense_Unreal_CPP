// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Player.h"

#include "DragAndDrop/DADObject.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATD_Player::ATD_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    isLeftClickGrab = false;
	canPutTower = true;
}

// Called when the game starts or when spawned
void ATD_Player::BeginPlay()
{
	Super::BeginPlay();

	Life = 100;
}

// Called to bind functionality to input
void ATD_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(IA_LeftClick, ETriggerEvent::Triggered, this, &ATD_Player::LeftClick);
	Input->BindAction(IA_LeftClick_Grabe, ETriggerEvent::Triggered, this, &ATD_Player::LeftClickGrab);
}

void ATD_Player::LeftClick(const FInputActionInstance& Instance)
{
	if(!isLeftClickGrab)
	{
		if(!canPutTower)
		{
			if(IsValid(TempGrab))
			{
				if(TempGrab->b_CanPutTower)
				{
					//Si la tower est dans un zone valide
					TempGrab->SetIsActive(false);
					TempGrab = NULL;
					canPutTower = true;
				}
			}
		}
		//TODO SI touche un DADObject un menu apparait pour faire des actions
			
	}else
	{
		// SI GRAB
		if(TempGrab->b_CanPutTower)
		{
			TempGrab->SetIsActive(false);
			TempGrab = NULL;
			isLeftClickGrab = false;
			canPutTower = true;
		}
	}
		
}

/**
 * @brief Fonction de Clique long pour déplacer une tourelle
 * @param Instance 
 */
void ATD_Player::LeftClickGrab(const FInputActionInstance& Instance)
{
	auto playerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
	FHitResult OutResult;
	
			
	if(playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Vehicle,true, OutResult))
	{
		if(auto DADObj = Cast<ADADObject>(OutResult.GetActor()))
		{
			DADObj->SetIsActive(true);
			TempGrab = DADObj;
			isLeftClickGrab = true;
			canPutTower = false;
		}
	}
}

/**
 * @brief Spawn une tourelle.
 */
void ATD_Player::CreateDADObject()
{
	if(canPutTower)
	{
		auto spawned = GetWorld()->SpawnActor<ADADObject>(this->DADObjectToSpawn,FVector(10000,10000,10000), FRotator(0,0,0));
		if(IsValid(spawned))
		{
			TempGrab= spawned;
			canPutTower = false; // Ne peut pas faire spawn de tourelle.
		}
		//Ligne Pour débug
		//DrawDebugLine(GetWorld(), CursorWorldLocation, EndVector,FColor::Red,false,5.0f,0,5.0f);
	}
}

/**
 * @brief Détruit la tourelle temporaire qui a été spawn.
 */
void ATD_Player::DestroyDADObject()
{
	if(!isLeftClickGrab)
	{
		TempGrab->Destroy(); //Détruit la tourelle temporaire
		canPutTower = true; // Peut faire spawn une tourelle.
	}
}

/**
 * @brief Retire des HP au joueurs.
 * @param value HP a retirer
 */
void ATD_Player::TookDamage(int value)
{
	this->Life -= value;
	if(Life<= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("TODO : Player is Dead"));	
	}
} 