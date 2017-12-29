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

	void loadPath(TArray<FVector> aPath);

private:
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* m_pSphereComponent;

	TArray<FVector> m_aPath;
	uint8 m_nCurrentPathIndex;
	
};