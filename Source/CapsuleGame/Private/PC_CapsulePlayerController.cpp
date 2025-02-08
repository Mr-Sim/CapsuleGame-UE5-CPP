// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_CapsulePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/C_Player.h"

#pragma region INPUTS CONTEXT MANAGEMENT -------------------------------------------------------------------------------

void APC_CapsulePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(IA_Walk, ETriggerEvent::Triggered, this, &APC_CapsulePlayerController::Move);
		EnhancedInput->BindAction(IA_Look, ETriggerEvent::Triggered, this, &APC_CapsulePlayerController::Look);
		EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Started, this, &APC_CapsulePlayerController::Jump);
		
		EnhancedInput->BindAction(IA_GrappleUse, ETriggerEvent::Started, this, &APC_CapsulePlayerController::UseGrapple);
		EnhancedInput->BindAction(IA_GrapplePull, ETriggerEvent::Triggered, this, &APC_CapsulePlayerController::PullGrapple);
		EnhancedInput->BindAction(IA_GrappleRelease, ETriggerEvent::Completed, this, &APC_CapsulePlayerController::ReleaseGrapple);
	}
}

void APC_CapsulePlayerController::ActivateMovementContext()
{
	if (auto* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()); InputSubsystem && IMC_Movements)
    {
        InputSubsystem->AddMappingContext(IMC_Movements, 0);
    }
}
void APC_CapsulePlayerController::ActivateGrappleContext()
{
	if (auto* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()); InputSubsystem && IMC_Grapple)
    {
        InputSubsystem->AddMappingContext(IMC_Grapple, 1);
    }
}
void APC_CapsulePlayerController::DeactivateMovementContext()
{
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());
	if (InputSubsystem && IMC_Movements)
	{
		InputSubsystem->RemoveMappingContext(IMC_Movements);
	}
}
void APC_CapsulePlayerController::DeactivateGrappleContext()
{
	if (auto* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()); InputSubsystem && IMC_Grapple)
	{
		InputSubsystem->RemoveMappingContext(IMC_Movements);
	}
}

#pragma endregion	

void APC_CapsulePlayerController::Move(const FInputActionValue& Value)
{
	if (auto* Player = Cast<AC_Player>(GetPawn()))
	{
		Player->Move(Value);
	}
}

void APC_CapsulePlayerController::Look(const FInputActionValue& Value)
{
	if (auto* Player = Cast<AC_Player>(GetPawn()))
	{
		Player->Look(Value);
	}
}

void APC_CapsulePlayerController::Jump()
{
	if (auto* Player = Cast<AC_Player>(GetPawn()))
	{
		Player->Jump();
	}
}

void APC_CapsulePlayerController::Crouch()
{
	if (auto* Player = Cast<AC_Player>(GetPawn()))
	{
		Player->Crouch();
	}
}

void APC_CapsulePlayerController::UseGrapple()
{
	if (auto* Player = Cast<AC_Player>(GetPawn()); Player)
	{
		Player->UseGrapple();
	}
}

void APC_CapsulePlayerController::PullGrapple()
{
	if (auto* Player = Cast<AC_Player>(GetPawn()); Player)
	{
		Player->PullGrapple();
	}
}

void APC_CapsulePlayerController::ReleaseGrapple()
{
	if (auto* Player = Cast<AC_Player>(GetPawn()); Player)
	{
		Player->ReleaseGrapple();
	}
}

