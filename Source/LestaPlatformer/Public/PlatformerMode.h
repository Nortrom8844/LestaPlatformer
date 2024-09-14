// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformerPawn.h"
#include "StartPlatform.h"
#include "PlatformerMode.generated.h"

/**
 * 
 */
UCLASS()
class LESTAPLATFORMER_API APlatformerMode : public AGameModeBase
{
	GENERATED_BODY()

private:

	float time;
	bool timerIsOn;
	bool gameIsRunning;

public:
	APlatformerMode();

	UFUNCTION(BlueprintCallable)
	float getTime();

	UFUNCTION(BlueprintCallable)
	void startTimer();

	UFUNCTION(BlueprintCallable)
	void endTimer();

	UFUNCTION(BlueprintCallable)
	void startGame();

	UFUNCTION(BlueprintCallable)
	void victory();

	UFUNCTION(BlueprintCallable)
	void defeat();

	UFUNCTION(BlueprintCallable)
	bool getGameIsRunning();

	UFUNCTION(BlueprintImplementableEvent)
	void onStartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void onVictory();

	UFUNCTION(BlueprintImplementableEvent)
	void onDefeat();

	virtual void Tick(float DeltaTime) override;
};
