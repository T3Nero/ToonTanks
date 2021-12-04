// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanks_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanks_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	void ActorDied(AActor* DeadActor);

protected:

	virtual void BeginPlay() override;

	// Creates StartGame Event in Blueprint
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);


private:

	class ATank* Tank;
	class AToonTanks_PlayerController* ToonTanksPlayerController;
	void HandleGameStart();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float StartGameDelay = 3.f;

	int32 EnemyTowers = 0;
	int32 GetEnemyTowerCount();


};
