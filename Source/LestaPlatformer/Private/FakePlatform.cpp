// Fill out your copyright notice in the Description page of Project Settings.


#include "FakePlatform.h"




void AFakePlatform::Activate()
{
	timer = 0;
	timerIsOn = true;
	Disappear();
}


void  AFakePlatform::Deactivate()
{
	timerIsOn = false;
	Appear();
}






void AFakePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timerIsOn)
	{
		timer += DeltaTime;
		if (timer > disapearTime)
		{
			Deactivate();
		}
	}

}