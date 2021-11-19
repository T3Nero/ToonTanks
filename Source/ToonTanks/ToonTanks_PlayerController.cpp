// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanks_PlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTanks_PlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
    if(bPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
    }
    else
    {
        GetPawn()->DisableInput(this);
    }
    bShowMouseCursor = bPlayerEnabled;
}