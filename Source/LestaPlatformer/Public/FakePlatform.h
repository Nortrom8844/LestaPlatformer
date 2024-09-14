// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "FakePlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAPLATFORMER_API AFakePlatform : public APlatformBase
{
	GENERATED_BODY()
	
private:
	float timer = 0;
	float disapearTime = 4;
	bool timerIsOn = false;

public:


	UFUNCTION(BlueprintCallable)
	void Activate();

	UFUNCTION(BlueprintCallable)
	void Deactivate();

	UFUNCTION(BlueprintImplementableEvent)
	void Disappear();

	UFUNCTION(BlueprintImplementableEvent)
	void Appear();

	virtual void Tick(float DeltaTime) override;
};
