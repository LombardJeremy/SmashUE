// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateRun.h"
#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterSettings.h"
#include "Characters/SmashCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"


ESmashCharacterStateID USmashCharacterStateRun::GetStateID()
{
	return ESmashCharacterStateID::Run;
}

void USmashCharacterStateRun::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	
	Character->GetCharacterMovement()->MaxWalkSpeed = MovementMaxSpeed;

	GEngine->AddOnScreenDebugMessage(
	-1,
	3.f,
	FColor::Cyan,
	TEXT("Enter StateWalk")
	);
}

void USmashCharacterStateRun::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);

	GEngine->AddOnScreenDebugMessage(
	-1,
	3.f,
	FColor::Red,
	TEXT("Exit StateWalk")
	);
}

void USmashCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);

	if(FMath::Abs(Character->GetInputMoveX()) < CharacterSettings->InputMoveXTreshold	)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Idle);
	}
	else
	{
		Character->SetOrientX(Character->GetInputMoveX());
		Character->AddMovementInput(FVector::ForwardVector, Character->GetOrientX());
	}	
}


