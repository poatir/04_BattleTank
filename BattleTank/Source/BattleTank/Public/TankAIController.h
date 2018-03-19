#pragma once
#include "AIController.h"
#include "TankAIController.generated.h"
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	float AcceptanceRadius = 3000;//asumiendo que es en centimetros
};