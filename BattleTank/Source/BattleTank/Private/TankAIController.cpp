// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (!PlayerTank) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is cm

	// Aim at the player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	//ControlledTank->Fire();
}
