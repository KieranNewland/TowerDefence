// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerDefenceGameModeBase.h"

void ATowerDefenceGameModeBase::RegisterEnemySpawner(AEnemySpawner* pSpawner)
{
	m_pEnemySpawner = pSpawner;
}