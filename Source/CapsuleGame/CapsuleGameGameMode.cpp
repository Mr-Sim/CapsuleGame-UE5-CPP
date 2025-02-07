// Copyright Epic Games, Inc. All Rights Reserved.

#include "CapsuleGameGameMode.h"
#include "CapsuleGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACapsuleGameGameMode::ACapsuleGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
