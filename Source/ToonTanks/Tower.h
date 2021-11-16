// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "Attack", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	float FireRange = 700.f;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;
	bool CheckInRange();
	void CheckFireCondition();
	
};
