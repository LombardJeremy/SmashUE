// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMultiplayerSettings.h"

#include "InputMappingContext.h"

bool FLocalMultiplayerProfilData::ContainsKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const
{
	if(GetTypeHash(Key) == false) return false;
	UInputMappingContext* CurrentMappingContext = nullptr;
	CurrentMappingContext =	GetImcFromType(MappingType);
	for (FEnhancedActionKeyMapping Element : CurrentMappingContext->GetMappings())
	{
		if(Key == Element.Key)
		{
			return true;
		}
	}
	return false;
}

UInputMappingContext* FLocalMultiplayerProfilData::GetImcFromType(ELocalMultiplayerInputMappingType MappingType) const
{
	switch (MappingType)
	{
	case ELocalMultiplayerInputMappingType::InGame:
		return IMCInGame;
	case ELocalMultiplayerInputMappingType::Menu:
		return IMCMenu;
	}
	return nullptr;
}

int ULocalMultiplayerSettings::GetNbKeyboardProfiles() const
{
	return KeyboardProfilesData.Num();
}

int ULocalMultiplayerSettings::GetNbKeyboardProfileIndexFromKey(const FKey& Key,
	ELocalMultiplayerInputMappingType MappingType) const
{
	if(GetNbKeyboardProfiles() == 0) return -1;
	
	for (FLocalMultiplayerProfilData Element : KeyboardProfilesData)
	{
		if(Element.ContainsKey(Key, MappingType)) return true;		
	}
	return false;
}
