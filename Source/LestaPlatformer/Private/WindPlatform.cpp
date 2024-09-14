// Fill out your copyright notice in the Description page of Project Settings.


#include "WindPlatform.h"
#include "Math.h"




AWindPlatform::AWindPlatform()
{
	timer = 0;
	windChangeInterval = 2;
	windPower = 200;
	redirectWind();
}



void AWindPlatform::redirectWind()
{
	//FRandomStream stream;
	//stream.GenerateNewSeed();

	//wind = stream.GetUnitVector() * windPower;

	FVector SpawnVector;
	SpawnVector.X = FMath::FRandRange( (float)-100, (float)100 );
	SpawnVector.Y = FMath::FRandRange( (float)-100, (float)100 );
	SpawnVector.Z = 0;
	SpawnVector.Normalize(1);

	wind = SpawnVector * windPower;
}


void AWindPlatform::applyWind(APlatformerPawn* player, float DeltaTime)
{
	player->SetActorLocation(player->GetActorLocation() + wind * DeltaTime, true);
}


void AWindPlatform ::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	timer += DeltaTime;

	if (timer > windChangeInterval)
	{
		redirectWind();
		timer -= windChangeInterval;
	}

}