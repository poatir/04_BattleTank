// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrosshairXlocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrosshairYlocation = 0.3333;


};
