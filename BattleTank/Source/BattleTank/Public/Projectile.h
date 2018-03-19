#pragma once
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"
UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
public:	
	AProjectile();
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;
	void LaunchProjectile(float Speed);
private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;
};