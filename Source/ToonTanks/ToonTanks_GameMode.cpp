// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanks_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanks_PlayerController.h"

void AToonTanks_GameMode::BeginPlay()
{
    Super::BeginPlay();
    HandleGameStart();

}

void AToonTanks_GameMode::ActorDied(AActor* DeadActor)
{
    if(DeadActor == Tank)
    {
        Tank->HandleDestruction();

        if(ToonTanksPlayerController)
        {
            ToonTanksPlayerController->SetPlayerEnabledState(false);
        }
        GameOver(false);
    }
    else if(ATower* DestroyedTower = Cast<ATower>(DeadActor))
    {
        DestroyedTower->HandleDestruction();
        EnemyTowers--;
        if(EnemyTowers == 0)
        {
            GameOver(true);
        }
    }
}

void AToonTanks_GameMode::HandleGameStart()
{
    EnemyTowers = GetEnemyTowerCount();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    ToonTanksPlayerController = Cast<AToonTanks_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    StartGame();

    if(ToonTanksPlayerController)
    {
        ToonTanksPlayerController->SetPlayerEnabledState(false);

        FTimerHandle PlayerEnableTimerHandle;
        FTimerDelegate PlayerEnabledTimerDelegate = FTimerDelegate::CreateUObject(
            ToonTanksPlayerController, 
            &AToonTanks_PlayerController::SetPlayerEnabledState,
            true);

        GetWorldTimerManager().SetTimer(
            PlayerEnableTimerHandle, 
            PlayerEnabledTimerDelegate, 
            StartGameDelay, 
            false);
    }
}

int32 AToonTanks_GameMode::GetEnemyTowerCount()
{
    TArray<AActor*> Towers;
    UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);
    return Towers.Num();
}