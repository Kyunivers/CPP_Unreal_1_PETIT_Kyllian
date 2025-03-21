// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPUnrealControle1GameMode.h"
#include "CPPUnrealControle1Character.h"
#include "UObject/ConstructorHelpers.h"

ACPPUnrealControle1GameMode::ACPPUnrealControle1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
