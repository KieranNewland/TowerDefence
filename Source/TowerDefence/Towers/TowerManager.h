// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "GameFramework/Actor.h"
#include "TowerManager.generated.h"

UCLASS()
class TOWERDEFENCE_API ATowerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Tower UI")
		void CreateTower(TSubclassOf<ATower> pTowerType);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	TArray<ATower*> m_aTowers;

	UPROPERTY()
	ATower* m_pCurrentTower;

	UFUNCTION()
		void UpdateTowerUnderCursor();
	
	
};
