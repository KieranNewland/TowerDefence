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
	
	m_pSpawner = Cast<ATowerDefenceGameModeBase>(GetWorld()->GetAuthGameMode())->getSpawner();
	m_nTimeToShoot = 1;
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_nTimeToShoot -= DeltaTime;

	if (m_nTimeToShoot > 0)
		return;

	shoot();
}

void ATower::shoot()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red, TEXT("Shooting " + m_pSpawner->getBestEnemy()->GetName()));

	m_nTimeToShoot = 1;
}

