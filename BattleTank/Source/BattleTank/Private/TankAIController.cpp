#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	if (AimingComponent->GetFiringState()==EFiringState::Locked)
	{
		AimingComponent->Fire();
	}
}