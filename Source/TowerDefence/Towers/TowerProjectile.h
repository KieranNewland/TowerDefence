// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "./AI/Enemy.h"
#include "GameFramework/Actor.h"
#include "TowerProjectile.generated.h"

UCLASS()
class TOWERDEFENCE_API ATowerProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setTarget(AEnemy* pEnemy) { m_pTargetEnemy = pEnemy; }

	UFUNCTION()
		void OnHit(UPrimitiveComponent* pComponent, AActor* pActor, UPrimitiveComponent* pOtherComponent, FVector NormalImpulse, const FHitResult &pHit);

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditDefaultsOnly)
		float m_nProjectileSpeed = 1;
	
private:
	AEnemy* m_pTargetEnemy;
	FVector m_pLastDirection;

	void updatePosition(float DeltaTime);
};
