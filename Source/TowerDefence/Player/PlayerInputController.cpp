// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerInputController.h"

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
		m_pCurrentTower = nullptr;
		return;
	}

	//Create tower object
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString("Spawning tower"));

	AActor* pTowerActor = GetWorld()->SpawnActor(m_pTowerType);
	m_pCurrentTower = Cast<ATower>(pTowerActor);
}

void APlayerInputController::Tick(float DeltaTime)
{
	if (m_pCurrentTower == nullptr)
		return;

	FHitResult pHitResult = FHitResult();
	GetHitResultUnderCursor(ECollisionChannel::ECC_GameTraceChannel1, false, pHitResult);

	if (pHitResult.Actor == nullptr)
		return;

	m_pCurrentTower->SetActorLocation(pHitResult.ImpactPoint);
}