// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "PlatformerPawn.h"

#include "WindPlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAPLATFORMER_API AWindPlatform : public APlatformBase
{
	GENERATED_BODY()
	
private:
	FVector wind;
	float windPower;

	void redirectWind();
	float timer;
	float windChangeInterval;

public:
	AWindPlatform();

	UFUNCTION(BlueprintCallable)
	void applyWind(APlatformerPawn* player, float DeltaTime);

	virtual void Tick(float DeltaTime) override;
};
