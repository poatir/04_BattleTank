#pragma once
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400.000;
private:
	UTankTrack();
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void ApplySidewaysForce();
	void DriveTrack();
	float CurrentThrottle = 0;
};