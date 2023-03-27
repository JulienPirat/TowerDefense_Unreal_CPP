// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LSA_TowerDefense.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_CPP_API ALSA_TowerDefense : public ALevelScriptActor
{
	GENERATED_BODY()
	
	public:
    	UPROPERTY(EditAnywhere, Category = "Camera")
    	ACameraActor* MainCamera;
    
    protected:
    	virtual void BeginPlay() override;
};
