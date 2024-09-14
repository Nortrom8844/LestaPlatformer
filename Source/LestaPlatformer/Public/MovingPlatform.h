// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformBase.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */



enum class movimgMode{Forward, Backward, Stop};


UCLASS()
class LESTAPLATFORMER_API AMovingPlatform : public APlatformBase
{
	GENERATED_BODY()

private:
	float timer;
	FVector moveVector;

public:
	AMovingPlatform();

	UPROPERTY(EditAnywhere)
	FVector startPosition;

	UPROPERTY(EditAnywhere)
	FVector endPosition;

	UPROPERTY(EditAnywhere)
	float timeToMove;

	movimgMode mode;

	UFUNCTION(BlueprintCallable)
	void setEndPosition(FVector v);

	UFUNCTION(BlueprintCallable)
	void setStartPosition(FVector v);

	UFUNCTION(BlueprintImplementableEvent)
	void movePawns(FVector move);

	virtual void Tick(float DeltaTime) override;
};
