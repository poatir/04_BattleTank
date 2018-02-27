// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
//Forward declarations
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	void AimAt(FVector HitLocation);

	UFUNCTION (BlueprintCallable, Category = Setup)
	//void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	//void SetTurretReference(UStaticMeshComponent* TurretToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000; //1000 m/s
	
	UPROPERTY(EditAnywhere, Category = Setup)
	//UClass* ProjectileBlueprint;  genera BLOQUEO DE UE
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//referecia local para spawn projectile
	UTankBarrel* Barrel = nullptr;
};
