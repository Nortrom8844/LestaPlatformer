// Fill out your copyright notice in the Description page of Project Settings.


#include "DisapearPlatform.h"



void ADisapearPlatform::Activate()
{
	if (!timerIsOn)
	{
		timer = 0;
		timerIsOn = true;
		if (fakePlatform != NULL)
		{
			fakePlatform->Activate();
		}
	}
}




void ADisapearPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (timerIsOn)
	{
		timer += DeltaTime;
		if (timer >= reloadTime)
		{
			timerIsOn = false;
		}
	}
}