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
class UTankBarrel; 
class UTankTurret;
class AProjectile;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
public:	
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();
	EFiringState GetFiringState() const;
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
private:
	UTankAimingComponent();
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;
	virtual void BeginPlay()override;
	bool IsBarrelMoving();
	FVector AimDirection;
};
