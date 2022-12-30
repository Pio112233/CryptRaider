// Fill out your copyright notice in the Description page of Project Settings.


#include "CryptRaider/Public/Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetOwner()->GetActorLocation();
	
}

void UMover::MoveActor(float DeltaTime)
{
	FVector TargetLocation = OriginalLocation;
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	
	if (bShouldMove && MoveAlpha > 0.0)
	{
		TargetLocation = OriginalLocation + MoveOffset * MoveAlpha;
	}
	float Speed = MoveOffset.Length() / MoveTime;
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);

	GetOwner()->SetActorLocation(NewLocation);
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveActor(DeltaTime);
}

void UMover::SetShouldMove(bool ShouldMove)
{
	bShouldMove = ShouldMove;
}

void UMover::SetMoveAlpha(float NewMoveAlpha)
{
	MoveAlpha = NewMoveAlpha;
}

