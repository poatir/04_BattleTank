// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	

	public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	//Fuerza = masa x aceleración
	//aceleración = 10 m/(s x s)
	//400.000=40.000 kilos X 10 m/(s x s)
	//Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400.000;
};
