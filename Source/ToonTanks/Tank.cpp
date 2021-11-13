// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Comp"));
    SpringArm->SetupAttachment(RootComponent);

    // SetupAttachment - Attaching the Camera to the SpringArm (child of spring arm)
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Comp"));
    Camera->SetupAttachment(SpringArm);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);

}

void ATank::Move(float Value)
{
    if(Value != 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Value = %f"), Value);
    }
}
