// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerMode.h"


APlatformerMode::APlatformerMode()
{
	timerIsOn = false;
	time = 0;

	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);
	PrimaryActorTick.bStartWithTickEnabled = true;

	gameIsRunning = true;
}


void APlatformerMode::startGame()
{
	gameIsRunning = true;
}

void APlatformerMode::victory()
{
	gameIsRunning = false;

	endTimer();
	onVictory();
}

void APlatformerMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (timerIsOn)
		time += DeltaTime;
}

void APlatformerMode::defeat()
{
	gameIsRunning = false;

	endTimer();
	onDefeat();
}

float APlatformerMode::getTime()
{
	return time;
}


void APlatformerMode::startTimer()
{
	time = 0;
	timerIsOn = true;
}


void APlatformerMode::endTimer()
{
	timerIsOn = false;
}

bool APlatformerMode::getGameIsRunning()
{
	return gameIsRunning;
}


