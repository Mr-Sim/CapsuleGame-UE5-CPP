// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_GrappleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAPSULEGAME_API UAC_GrappleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_GrappleComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetupGrappleInput(class UEnhancedInputComponent* EnhancedInput);

	void UseGrapple();
	void PullGrapple();
	void ReleaseGrapple();
	void QuickGrapple();
	
private:

	bool b_IsGrappling;
	FVector GrapplePoint;
	class ACharacter* OwnerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grapple", meta=(AllowPrivateAccess=true))
	float GrappleRange = 2000.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Grapple", meta=(AllowPrivateAccess=true))
	float GrappleRopeLength = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grapple", meta=(AllowPrivateAccess=true))
	float GrapplePullForce = 50.f;
	

	void PerformGrappleTrace();
	
		
};
