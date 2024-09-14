// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Components/StaticMeshComponent.h"

#include "PlatformerPawn.generated.h"

UCLASS()
class LESTAPLATFORMER_API APlatformerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlatformerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity");
	bool onGround;

	FVector horizontalSpeed;
	FVector verticalSpeed;

	float forwardMoveAxis;
	float rightMoveAxis;

	float rotartionAxis;

	float moveSpeed;

	float jumpSpeed;
	FVector gravityAcceleration;

	void moveForward(float Axis);
	void moveStrafe(float Axis);
	void rotate(float Axis);
	void jump();

	int curHp;
	int maxHp;

	float looseZ;

	FVector initialPosition;

	bool blockedInputs;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	int getCurrentHP();

	UFUNCTION(BlueprintCallable)
	int getMaxHP();

	UFUNCTION(BlueprintCallable)
	void takeDamage(int damage);

	UFUNCTION(BlueprintCallable)
	void moveToInitialLocation();

	void die();

	UFUNCTION(BlueprintImplementableEvent)
	void onDie();

	UFUNCTION(BlueprintCallable)
	void blockInput();

	UFUNCTION(BlueprintCallable)
	void unblockInput();
};
