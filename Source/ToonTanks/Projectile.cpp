// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = InitialSpeed;
	ProjectileMovement->MaxSpeed = MaxSpeed;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* ActorHit, UPrimitiveComponent* ActorComp, FVector NormalImpulse, const FHitResult& Hit)
{
	auto ProjectileOwner = GetOwner();
	if(ProjectileOwner == nullptr) return;

	auto ProjectileInstigator = ProjectileOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();

	if(ActorHit && ActorHit != this && ActorHit != ProjectileOwner)
	{
		UGameplayStatics::ApplyDamage(ActorHit, Damage, ProjectileInstigator, this, DamageTypeClass);
		Destroy();
	}
}

