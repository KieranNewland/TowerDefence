// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerInputController.h"

void APlayerInputController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI());
}

// Called to bind functionality to input
void APlayerInputController::SetupInputComponent()
{
	Super::SetupInputComponent();

	bShowMouseCursor = true;

	InputComponent->BindAction("SpawnTower", IE_Pressed, this, &APlayerInputController::onLeftClick);
}

void APlayerInputController::onLeftClick()
{
	if (m_pCurrentTower != nullptr)
	{
		m_pCurrentTower->init();
		m_pCurrentTower = nullptr;
		return;
	}
}

void APlayerInputController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FHitResult APlayerInputController::GetFloorHitUnderCursor()
{
	FHitResult pHitResult = FHitResult();
	GetHitResultUnderCursor(ECollisionChannel::ECC_GameTraceChannel1, false, pHitResult);

	return pHitResult;
}