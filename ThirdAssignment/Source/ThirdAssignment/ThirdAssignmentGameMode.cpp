// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdAssignmentGameMode.h"
#include "ThirdAssignmentCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdAssignmentGameMode::AThirdAssignmentGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
