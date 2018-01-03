// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Blueprint/UserWidget.h"
#include "AI/EnemySpawner.h"
#include "Towers/Tower.h"
#include "Towers/TowerManager.h"
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
	virtual void StartPlay() override;

	void RegisterEnemySpawner(AEnemySpawner* pSpawner);
	AEnemySpawner* getSpawner() { return m_pEnemySpawner; }

	UPROPERTY(EditDefaultsOnly, Category = "Tower UI")
		TSubclassOf<UUserWidget> m_pTowerUIClass;
	
private:
	AEnemySpawner* m_pEnemySpawner;

	UUserWidget* m_pTowerUI;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Tower UI")
	ATowerManager* m_pTowerManager;
};
