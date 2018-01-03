// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerDefenceGameModeBase.h"

void ATowerDefenceGameModeBase::StartPlay()
{
	Super::StartPlay();

	m_pTowerManager = GetWorld()->SpawnActor<ATowerManager>(FVector::ZeroVector, FRotator::ZeroRotator);

	if (m_pTowerUIClass != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Displaying tower UI"));
		m_pTowerUI = CreateWidget<UUserWidget>(GetWorld(), m_pTowerUIClass);
		m_pTowerUI->AddToViewport();
	}
}

void ATowerDefenceGameModeBase::RegisterEnemySpawner(AEnemySpawner* pSpawner)
{
	m_pEnemySpawner = pSpawner;
}