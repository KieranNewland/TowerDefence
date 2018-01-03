// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("EnemySphere"));
	m_pSphereComponent->InitSphereRadius(10.0f);
	m_pSphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = m_pSphereComponent;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	m_nCurrentHealth = m_nMaxHealth;
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Increment position towards next point
	FVector pCurrentPoint = m_aPath[m_nCurrentPathIndex];
	FVector pOurPosition = GetActorLocation();
	FVector pDirection = (pCurrentPoint - pOurPosition).GetSafeNormal();
	FVector pMovement = pDirection * DeltaTime * 100;
	FVector pTargetPosition = pOurPosition + pMovement;

	if (pMovement.Size() > (pCurrentPoint - pOurPosition).Size())
	{
		pTargetPosition = pCurrentPoint;
		m_nCurrentPathIndex = (m_nCurrentPathIndex + 1) % m_aPath.Num();
	}

	SetActorLocation(pTargetPosition);
}

void AEnemy::loadPath(TArray<FVector> aPath)
{
	m_aPath = TArray<FVector>(aPath);
}

void AEnemy::dealDamage(float nDamage)
{
	m_nCurrentHealth -= nDamage;

	if (m_nCurrentHealth > 0)
		return;

	destroyEnemy();
}

void AEnemy::destroyEnemy()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Enemy destroyed"));
	m_bDead = true;
	Destroy();
}

void AEnemy::Destroyed()
{
	Super::Destroyed();

	m_aPath.Empty();
}