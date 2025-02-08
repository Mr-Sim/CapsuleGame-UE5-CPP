// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AC_GrappleComponent.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UAC_GrappleComponent::UAC_GrappleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_GrappleComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	
}


// Called every frame
void UAC_GrappleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UAC_GrappleComponent::UseGrapple()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "Using Grapple");
	if (!OwnerCharacter)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Grapple owner not found");
		return;
	}
	
	PerformGrappleTrace();
	if (GrapplePoint != FVector::ZeroVector)
	{
		b_IsGrappling = true;
	}
}

void UAC_GrappleComponent::PullGrapple()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "Pull Grapple");
	if (b_IsGrappling)
	{
		FVector Direction = (GrapplePoint - OwnerCharacter->GetActorLocation()).GetSafeNormal();
		OwnerCharacter->AddMovementInput(Direction, GrapplePullForce * GetWorld()->GetDeltaSeconds());
	}
}

void UAC_GrappleComponent::QuickGrapple()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "Quick Grapple");
}


void UAC_GrappleComponent::ReleaseGrapple()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "Release Grapple");
	if (b_IsGrappling)
	{
		GrapplePoint = FVector::ZeroVector;
		b_IsGrappling = false;
	}
}

void UAC_GrappleComponent::PerformGrappleTrace()
{
	if (!OwnerCharacter) return;
	
}
