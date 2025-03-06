// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5WorkshopCppGameMode.h"
#include "UE5WorkshopCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5WorkshopCppGameMode::AUE5WorkshopCppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
