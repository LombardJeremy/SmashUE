// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SmashCharacters.h"

// Sets default values
ASmashCharacters::ASmashCharacters()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASmashCharacters::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASmashCharacters::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASmashCharacters::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

