// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Enemy.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TOWERDEFENCE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	FTransform m_pTransform;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AEnemy> m_pEnemyType;

	UPROPERTY(EditInstanceOnly)
	TArray<FVector> m_aPathPoints;

	TArray<AEnemy*> getEnemies() { return m_aEnemies; }

	AEnemy* getBestEnemy();

private:
	void updateSpawnLoop(float nDelta);
	void spawnEnemy();

	float m_nTimeSinceSpawn;
	int m_nAmtToSpawn;
	TArray<AEnemy*> m_aEnemies;
};
