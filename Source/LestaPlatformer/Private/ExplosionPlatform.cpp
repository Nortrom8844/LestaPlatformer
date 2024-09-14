// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosionPlatform.h"


AExplosionPlatform::AExplosionPlatform()
{
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);
	PrimaryActorTick.bStartWithTickEnabled = true;

	timerIsOn = false;
	ready = true;
	exploded = false;
	timer = 0;

	explosionTime = 1;
	resetTime = 5;

	damage = 30;
}


bool AExplosionPlatform::isReady()
{
	return ready;
}

void AExplosionPlatform::startTimer()
{
	if (isReady())
	{
		timerIsOn = true;
		ready = false;
	}
}


int AExplosionPlatform::getDamage()
{
	return damage;
}

void AExplosionPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timerIsOn)
	{
		timer += DeltaTime;

		if ( (timer > explosionTime) && (!exploded) )
		{
			onExplode();
			ready = false;
			exploded = true;
		}

		if (timer > explosionTime + resetTime)
		{
			timerIsOn = false;
			ready = true;
			exploded = false;
			timer = 0;
		}
	}

}