// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "TowerDefenceGameModeBase.h"


// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
	ATowerDefenceGameModeBase* pBaseMode = Cast<ATowerDefenceGameModeBase>(GetWorld()->GetAuthGameMode());
	m_pSpawner = pBaseMode->getSpawner();

	m_nTimeToShoot = 1;
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_nbPickedUp)
		return;

	m_nTimeToShoot -= DeltaTime;

	if (m_nTimeToShoot > 0)
		return;

	shoot();
}

void ATower::init()
{
	m_nbPickedUp = false;
}

void ATower::shoot()
{
	AEnemy* pChosenEnemy = m_pSpawner->getBestEnemy();

	if (pChosenEnemy == nullptr)
		return;

	FVector pOurPosition = GetActorLocation();
	AActor* pProjectileActor = GetWorld()->SpawnActor(m_pProjectile, &pOurPosition, &FRotator::ZeroRotator);
	Cast<ATowerProjectile>(pProjectileActor)->setTarget(pChosenEnemy);

	m_nTimeToShoot = 1;
}

