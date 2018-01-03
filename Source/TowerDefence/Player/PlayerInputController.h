// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "./Towers/Tower.h"
#include "GameFramework/PlayerController.h"
#include "PlayerInputController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API APlayerInputController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ATower> m_pTowerType;

	FHitResult GetFloorHitUnderCursor();
	
protected:
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;
	
private:
	UFUNCTION()
	void onLeftClick();

	ATower* m_pCurrentTower;
	
};
