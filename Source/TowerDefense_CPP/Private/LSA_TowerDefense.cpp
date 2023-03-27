// Fill out your copyright notice in the Description page of Project Settings.


#include "LSA_TowerDefense.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void ALSA_TowerDefense::BeginPlay()
{
	Super::BeginPlay();

	if(IsValid(MainCamera))
	{
		//Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

		//Cut instantly to our actor on begin play.
		OurPlayerController->SetViewTarget(MainCamera);
		OurPlayerController->SetShowMouseCursor(true);
	}
}