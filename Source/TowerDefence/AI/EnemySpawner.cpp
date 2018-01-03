// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"
#include "TowerDefenceGameModeBase.h"


// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Cast<ATowerDefenceGameModeBase>(GetWorld()->GetAuthGameMode())->RegisterEnemySpawner(this);

	Super::BeginPlay();
	
	m_aEnemies = TArray<AEnemy*>();
	m_nAmtToSpawn = 10;
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	updateSpawnLoop(DeltaTime);
}

void AEnemySpawner::updateSpawnLoop(float nDelta)
{
	if (m_nAmtToSpawn == 0)
		return;

	m_nTimeSinceSpawn += nDelta;

	if (m_nTimeSinceSpawn < 1)
		return;

	m_nTimeSinceSpawn -= 1;

	spawnEnemy();

	m_nAmtToSpawn--;
}

void AEnemySpawner::spawnEnemy()
{
	FTransform pOurTransform = GetTransform();
	FVector pPosition = pOurTransform.GetLocation();
	FRotator pRotation = pOurTransform.GetRotation().Rotator();
	AActor* pEnemyActor = GetWorld()->SpawnActor(m_pEnemyType, &pPosition, &pRotation);

	AEnemy* pEnemy = Cast<AEnemy>(pEnemyActor);
	pEnemy->loadPath(m_aPathPoints);

	m_aEnemies.Add(pEnemy);
}

AEnemy* AEnemySpawner::getBestEnemy()
{
	for (AEnemy* pEnemy : m_aEnemies)
	{
		if (pEnemy == nullptr || pEnemy->isDead())
			continue;

		return pEnemy;
	}

	return nullptr;
}
