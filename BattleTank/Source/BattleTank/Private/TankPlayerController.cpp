// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tanque no poseido"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tanque poseido: %s"), *ControlledTank->GetName());
	}
}
void ATankPlayerController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller Tick"));
}
void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//HitLocation = FVector(1.0);
	int32 ViewportSizeX, ViewportSizeY;
	//Resolución de pantalla
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	//Posición de la mira basada en el tamaño del viewport
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXlocation, ViewportSizeY*CrosshairYlocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	//Convierte la posición 2d a posicion3d "world"
	//CameraWorldLocation no se necesita en este caso.
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation,ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

