// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "Speed", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float InitialSpeed = 1500.f;

	UPROPERTY(EditAnywhere, Category = "Speed", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MaxSpeed = 3000.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComp, AActor *ActorHit, UPrimitiveComponent *ActorComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* HitParticle;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	class UParticleSystemComponent* ParticleSystem;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound;

	// UE 4.26+ UMatineeCameraShake
	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UMatineeCameraShake> HitCameraShakeClass;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
