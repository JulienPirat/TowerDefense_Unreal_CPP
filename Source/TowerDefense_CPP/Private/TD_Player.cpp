// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_Player.h"

#include "DragAndDrop/DADObject.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATD_Player::ATD_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    isGrabMode = false;
}

// Called when the game starts or when spawned
void ATD_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATD_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(isGrabMode)
	{
		
	}
}

// Called to bind functionality to input
void ATD_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// You can bind to any of the trigger events here by changing the "ETriggerEvent" enum value
	Input->BindAction(IA_LeftClick, ETriggerEvent::Triggered, this, &ATD_Player::LeftClick);
	Input->BindAction(IA_G_GrabeMode, ETriggerEvent::Triggered, this, &ATD_Player::GrabMode);
}

void ATD_Player::LeftClick(const FInputActionInstance& Instance)
{
	if(isGrabMode)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Can Grab and Drop !"));
		auto playerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
		FVector CursorWorldLocation, CursorWorldDirection;
		playerController->DeprojectMousePositionToWorld(CursorWorldLocation, CursorWorldDirection);
		FVector CalcVector = FVector(1500.0f,1500.0f,1500.0f);
		FVector EndVector = CursorWorldLocation + (CursorWorldDirection*CalcVector);
		FHitResult OutResult;
		FCollisionQueryParams params;
		params.AddIgnoredActor(this);
		auto MainCamera = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
		params.AddIgnoredActor(MainCamera);
		
		if(GetWorld()->LineTraceSingleByChannel(OutResult, CursorWorldLocation,EndVector,ECollisionChannel::ECC_Vehicle, params, FCollisionResponseParams()))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("Hited !"));
			auto dist = OutResult.Location;
			EndVector.Z = OutResult.Location.Z+51; // Ne peut pas spawn un block dans un mesh qui a été hit. (A SUPPR QUAND ELEVATION DES DADOBJECT EN AJOUTANT UNE COLLISION BOX)
			auto spawned = GetWorld()->SpawnActor<ADADObject>(this->TestSpawnDADObject,EndVector, FRotator(0,0,0));
			if(IsValid(spawned))
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("Placed Block !"));
			}
			if(OutResult.Component->Mobility == EComponentMobility::Movable)
			{
				// Pour savoir si on peut le drag and drop
			}
			
		}
		DrawDebugLine(GetWorld(), CursorWorldLocation, EndVector,FColor::Red,false,5.0f,0,5.0f);
		
	}
} 

void ATD_Player::GrabMode(const FInputActionInstance& Instance)
{
	isGrabMode = !isGrabMode;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Change GrabeMode"));
} 