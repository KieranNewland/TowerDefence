// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "AI/EnemySpawner.h"
#include "GameFramework/GameModeBase.h"
#include "TowerDefenceGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENCE_API ATowerDefenceGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void RegisterEnemySpawner(AEnemySpawner* pSpawner);
	AEnemySpawner* getSpawner() { return m_pEnemySpawner; }
	
private:
	AEnemySpawner* m_pEnemySpawner;
	
};
