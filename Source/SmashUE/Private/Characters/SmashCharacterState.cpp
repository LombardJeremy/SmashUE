// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterState.h"
#include "Characters/SmashCharacterStateMachine.h"
#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterSettings.h"


// Sets default values for this component's properties
USmashCharacterState::USmashCharacterState()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

ESmashCharacterStateID USmashCharacterState::GetStateID()
{
	return ESmashCharacterStateID::None;
}

void USmashCharacterState::StateInit(USmashCharacterStateMachine* InStateMachine)
{
	CharacterSettings = GetDefault<USmashCharacterSettings>();
	StateMachine = InStateMachine;
	Character = InStateMachine->GetCharacter();
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Magenta,
		FString::Printf(TEXT("Init State %d"), GetStateID())
		);
}

void USmashCharacterState::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Character->PlayAnimMontage(AnimState);
}

void USmashCharacterState::StateExit(ESmashCharacterStateID NextStateID)
{
}

void USmashCharacterState::StateTick(float DeltaTime)
{
}

float USmashCharacterState::HaveInputMoveXTreshold()
{
	return Character->InputMoveXTreshold;
}

