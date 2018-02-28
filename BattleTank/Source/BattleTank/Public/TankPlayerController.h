// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
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
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXlocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYlocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;//Distancia en kilometros un millon de centimetros
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
