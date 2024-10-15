// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "LocalMultiplayerSettings.generated.h"


class UInputMappingContext;
/**
 * 
 */

UENUM()
enum class ELocalMultiplayerInputMappingType
{
	InGame,
	Menu
};

USTRUCT()
struct FLocalMultiplayerProfilData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FName ProfileName;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> IMCInGame;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> IMCMenu;

	bool ContainsKey (const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const;

	UInputMappingContext* GetImcFromType(ELocalMultiplayerInputMappingType MappingType) const;
};

UCLASS(Config=Game, DefaultConfig, meta = (DisplayName="Local Multiplayer Settings"))
class LOCALMULTIPLAYER_API ULocalMultiplayerSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category="LocalMultiplayer")
	TArray<FLocalMultiplayerProfilData> KeyboardProfilesData;

	int GetNbKeyboardProfiles() const;

	int GetNbKeyboardProfileIndexFromKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const;

	UPROPERTY(Config, EditAnywhere, Category="LocalMultiplayer")
	FLocalMultiplayerProfilData GamepadProfilData;

	UPROPERTY(Config, EditAnywhere, Category="LocalMultiplayer")
	int NbMaxGamepads = 4;
};




