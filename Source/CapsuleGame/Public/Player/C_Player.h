// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_Player.generated.h"

UCLASS()
class CAPSULEGAME_API AC_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	// CAMERA
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FirstPerson", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ThirdPerson", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* ThirdPersonCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ThirdPerson", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	// PHYSICS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CollisionComponent;

	// MESH
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Mesh", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* BodyMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Mesh", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* EyesMesh;	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Mesh", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* GlassesMesh;

	// MOVEMENT
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float WalkSpeed = 400.0f;
};
