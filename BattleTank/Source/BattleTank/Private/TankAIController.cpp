// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
//#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/*auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tanque AI no poseido"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tanque AI poseido: %s"), *ControlledTank->GetName());
	}*/

}
void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	/*auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());*/
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	//if (ensure(PlayerTank))
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	//{
	MoveToActor(PlayerTank, AcceptanceRadius);
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	//ControlledTank->AimAt(PlayerTank->GetActorLocation());
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//TODO Corregir disparo
	//ControlledTank->Fire();
	//}
}
/*ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
*/
/*ATank*  ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}*/

