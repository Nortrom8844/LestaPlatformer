// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformBase.generated.h"

UCLASS()
class LESTAPLATFORMER_API APlatformBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh");
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, Category = "Scene");
	USceneComponent* scene;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
