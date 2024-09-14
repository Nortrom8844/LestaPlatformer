// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerPawn.h"
#include "PlatformerMode.h"

// Sets default values
APlatformerPawn::APlatformerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	moveSpeed = 700;

	maxHp = 100;
	curHp = maxHp;

	jumpSpeed = 1200;

	looseZ = -400;

	horizontalSpeed = FVector(0, 0, 0);
	verticalSpeed = FVector(0, 0, 0);
	gravityAcceleration = FVector(0, 0, -20);

}

// Called when the game starts or when spawned
void APlatformerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	initialPosition = GetActorLocation();
}

// Called every frame
void APlatformerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (onGround)
	{
		if (verticalSpeed.Z < 0)
			verticalSpeed.Z = 0;

		FVector moveVector = GetActorForwardVector() * forwardMoveAxis + GetActorRightVector() * rightMoveAxis;

		moveVector.Normalize(1);
		moveVector *= moveSpeed;

		horizontalSpeed = moveVector;
	}
	else
	{
		verticalSpeed += gravityAcceleration;
	}

	//SetActorLocation(GetActorLocation() + verticalSpeed * DeltaTime + horizontalSpeed * DeltaTime, true,);

	if (GetActorLocation().Z < looseZ)
		die();

	AddMovementInput(verticalSpeed * DeltaTime + horizontalSpeed * DeltaTime);
}


void APlatformerPawn::moveForward(float Axis)
{
	if (!blockedInputs)
		forwardMoveAxis = Axis;
}

void APlatformerPawn::moveToInitialLocation()
{
	SetActorLocation(initialPosition);
}

void APlatformerPawn::moveStrafe(float Axis)
{
	if (!blockedInputs)
		rightMoveAxis = Axis;
}

void APlatformerPawn::rotate(float Axis)
{
	if (!blockedInputs)
	{
		FRotator rotationVector(0, Axis, 0);
		SetActorRotation(GetActorRotation() + rotationVector);
	}
}


int APlatformerPawn::getCurrentHP()
{
	return curHp;
}

int APlatformerPawn::getMaxHP()
{
	return maxHp;
}

void APlatformerPawn::die()
{
	APlatformerMode* mode = Cast<APlatformerMode>(GetWorld()->GetAuthGameMode());
	
	if ( mode->getGameIsRunning() )
		mode->defeat();
}


void APlatformerPawn::takeDamage(int damage)
{
	curHp -= damage;

	if (curHp <= 0)
		die();
}


void APlatformerPawn::jump()
{
	if (onGround)
		verticalSpeed = FVector(0, 0, jumpSpeed);
}

void APlatformerPawn::blockInput()
{
	horizontalSpeed = FVector(0, 0, 0);
	blockedInputs = true;
}


void APlatformerPawn::unblockInput()
{
	blockedInputs = false;
}


// Called to bind functionality to input
void APlatformerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlatformerPawn::moveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlatformerPawn::moveStrafe);
	PlayerInputComponent->BindAxis("Rotate", this, &APlatformerPawn::rotate);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlatformerPawn::jump);
}

