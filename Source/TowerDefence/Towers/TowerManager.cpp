// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerManager.h"
#include "./Player/PlayerInputController.h"


// Sets default values
ATowerManager::ATowerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerManager::BeginPlay()
{
	Super::BeginPlay();

	m_aTowers = TArray<ATower*>();
}

// Called every frame
void ATowerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateTowerUnderCursor();
}

void ATowerManager::UpdateTowerUnderCursor()
{
	if (m_pCurrentTower == nullptr)
		return;

	FHitResult pHitResult = Cast<APlayerInputController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->GetFloorHitUnderCursor();

	if (pHitResult.Actor == nullptr)
		return;

	FVector pMousePos = pHitResult.ImpactPoint;
	float nRoundedX = roundf((pMousePos.X - 50) / 100) * 100 + 50;
	float nRoundedY = roundf((pMousePos.Y - 50) / 100) * 100 + 50;
	FVector pGetMapSquare = FVector(nRoundedX, nRoundedY, 0);
	m_pCurrentTower->SetActorLocation(pGetMapSquare);
}

void ATowerManager::CreateTower(TSubclassOf<ATower> pTowerType)
{
	if (m_pCurrentTower != nullptr)
		return;

	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Creating tower"));

	AActor* pTowerActor = GetWorld()->SpawnActor(pTowerType);
	m_pCurrentTower = Cast<ATower>(pTowerActor);
}