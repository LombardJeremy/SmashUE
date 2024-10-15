// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMultiplayerSubsystem.h"

#include "LocalMultiplayerSettings.h"
#include "Kismet/GameplayStatics.h"

void ULocalMultiplayerSubsystem::CreateAndInitPlayer(ELocalMultiplayerInputMappingType MappingType)
{
	const ULocalMultiplayerSettings* Settings = GetDefault<ULocalMultiplayerSettings>();

	for (int i = 0; i < Settings->KeyboardProfilesData.Num() + Settings->NbMaxGamepads; i++)
	{
		APlayerController* pc = UGameplayStatics::CreatePlayer(GetWorld(), i, true);
	}
}

/*int ULocalMultiplayerSubsystem::GetAssignedPlayerIndexFromKeyboardProfileIndex(int KeyboardProfileIndex)
{
	
}*/
