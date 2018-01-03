// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerProjectile.h"


// Sets default values
ATowerProjectile::ATowerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_nProjectileSpeed = 300.0f;
}

// Called when the game starts or when spawned
void ATowerProjectile::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(5.0f);
	
	UStaticMeshComponent* pSphereComponent = FindComponentByClass<UStaticMeshComponent>();

	if (pSphereComponent == nullptr)
		return;

	pSphereComponent->OnComponentHit.AddDynamic(this, &ATowerProjectile::OnHit);
	pSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ATowerProjectile::OnOverlap);
}

// Called every frame
void ATowerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	updatePosition(DeltaTime);
}

void ATowerProjectile::updatePosition(float DeltaTime)
{
	FVector pDirection;
	FVector pOurPosition = GetActorLocation();

	if (m_pTargetEnemy == nullptr || m_pTargetEnemy->IsPendingKill() || m_pTargetEnemy->isDead())
	{
		pDirection = m_pLastDirection;
	}
	else
	{
		FVector pTargetPosition = m_pTargetEnemy->GetActorLocation();
		pDirection = (pTargetPosition - pOurPosition).GetSafeNormal();
		m_pLastDirection = pDirection;
	}

	FVector pMoveToLocation = pOurPosition + pDirection * m_nProjectileSpeed * DeltaTime;

	SetActorLocation(pMoveToLocation);
}

void ATowerProjectile::OnHit(UPrimitiveComponent* pComponent, AActor* pActor, UPrimitiveComponent* pOtherComponent, FVector NormalImpulse, const FHitResult &pHit)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Hit collision"));
}

void ATowerProjectile::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Overlap collision"));

	AEnemy* pEnemy = Cast<AEnemy>(OtherActor);

	if (pEnemy == nullptr)
		return;

	if (pEnemy->isDead())
		return;

	pEnemy->dealDamage(1);
	Destroy();
}