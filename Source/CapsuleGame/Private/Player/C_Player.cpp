// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/C_Player.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AC_GrappleComponent.h"

// Sets default values
AC_Player::AC_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GrappleComponent = CreateDefaultSubobject<UAC_GrappleComponent>(TEXT("GrappleComponent"));
}

// Called when the game starts or when spawned
void AC_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_Player::DisableMovement()
{
	GetCharacterMovement()->SetMovementMode(MOVE_None);
}

void AC_Player::EnableMovement()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}

void AC_Player::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AC_Player::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AC_Player::Jump()
{
	Super::Jump();
}

void AC_Player::Crouch(bool bClientSimulation)
{
	Super::Crouch(bClientSimulation);
}

void AC_Player::UseGrapple()
{
	GrappleComponent->UseGrapple();
}

void AC_Player::PullGrapple()
{
	GrappleComponent->PullGrapple();
}

void AC_Player::ReleaseGrapple()
{
	GrappleComponent->ReleaseGrapple();
}

// Called every frame
void AC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

