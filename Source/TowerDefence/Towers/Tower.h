// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "./AI/EnemySpawner.h"
#include "TowerProjectile.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class TOWERDEFENCE_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ATowerProjectile> m_pProjectile;

	void init();

private:
	AEnemySpawner* m_pSpawner;
	float m_nTimeToShoot;
	bool m_nbPickedUp = true;;
	bool m_bActive;

	void shoot();
};
