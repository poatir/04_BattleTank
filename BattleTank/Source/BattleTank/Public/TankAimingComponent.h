// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
UENUM()
enum class EFiringState :uint8
{
	Reloading,
	Aiming,
	Locked
};
class UTankBarrel;  //Forward declaration
class UTankTurret;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	//UTankAimingComponent();

	// Called when the game starts
	//virtual void BeginPlay() override;
	
	// Called every frame
	//virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);

	//void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	//void SetBarrelReference(UTankBarrel* BarrelToSet);

	//void SetTurretReference(UStaticMeshComponent* TurretToSet);
	//void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;
private:
	UTankAimingComponent();
	//UStaticMeshComponent* Barrel = nullptr;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
