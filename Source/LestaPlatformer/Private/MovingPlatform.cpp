// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	timer = 0;
	mode = movimgMode::Forward;
}


void AMovingPlatform::setEndPosition(FVector v)
{
	endPosition = v;
}


void AMovingPlatform::setStartPosition(FVector v)
{
	startPosition = v;
}


void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	timer += DeltaTime;

	if (timer >= timeToMove)
	{
		timer -= timeToMove;

		if (mode == movimgMode::Forward)
		{
			mode = movimgMode::Backward;
			SetActorLocation(endPosition);
		}
		else
			if (mode == movimgMode::Backward)
			{
				mode = movimgMode::Forward;
				SetActorLocation(startPosition);
			}
	}


	if (mode == movimgMode::Forward)
	{
		moveVector = (endPosition - startPosition) / timeToMove;
	}

	if (mode == movimgMode::Backward)
	{
		moveVector = (startPosition - endPosition) / timeToMove ;
	}


	SetActorLocation(GetActorLocation() + moveVector * DeltaTime);

	movePawns(moveVector * DeltaTime);
}