// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "FakePlatform.h"
#include "DisapearPlatform.generated.h"

/**
 * 
 */
UCLASS()
class LESTAPLATFORMER_API ADisapearPlatform : public APlatformBase
{
	GENERATED_BODY()
	
private:
	float timer = 0;
	float reloadTime = 7;
	bool timerIsOn = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AFakePlatform* fakePlatform;

	UFUNCTION(BlueprintCallable)
	void Activate();

	virtual void Tick(float DeltaTime) override;
};
