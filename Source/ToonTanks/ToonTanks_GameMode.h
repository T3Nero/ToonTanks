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

private:

	class ATank* Tank;
	class AToonTanks_PlayerController* ToonTanksPlayerController;
	void HandleGameStart();

	float StartGameDelay = 3.f;
};
