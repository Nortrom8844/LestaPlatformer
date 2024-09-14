// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "ExplosionPlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAPLATFORMER_API AExplosionPlatform : public APlatformBase
{
	GENERATED_BODY()

private:

	bool timerIsOn;
	bool ready;
	bool exploded;

	float timer;
	float explosionTime;
	float resetTime;

	int damage;

public:
	AExplosionPlatform();

	UFUNCTION(BlueprintCallable)
	bool isReady();

	UFUNCTION(BlueprintCallable)
	int getDamage();

	UFUNCTION(BlueprintCallable)
	void startTimer();

	UFUNCTION(BlueprintImplementableEvent)
	void onExplode();

	virtual void Tick(float DeltaTime) override;
};
