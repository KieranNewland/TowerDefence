// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class TOWERDEFENCE_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;

	UPROPERTY(EditDefaultsOnly)
	float m_nMaxHealth = 1;

	void loadPath(TArray<FVector> aPath);
	void dealDamage(float nDamage);
	bool isDead() { return m_bDead; }

private:
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* m_pSphereComponent;

	TArray<FVector> m_aPath;
	uint8 m_nCurrentPathIndex;
	
	float m_nCurrentHealth;
	bool m_bDead;
	void destroyEnemy();
};
