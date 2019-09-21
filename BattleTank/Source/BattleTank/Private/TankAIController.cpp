// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank =GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	// TODO Move toward the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm 

	// Aim towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// TODO Fix firing
	//ControlledTank->Fire(); // TODO limit firing rate
}

