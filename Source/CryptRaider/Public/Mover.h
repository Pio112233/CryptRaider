// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetShouldMove(bool ShouldMove);
	
	UFUNCTION(BlueprintCallable)
    void SetShouldRotate(bool ShouldRotate);

	UFUNCTION(BlueprintCallable)
	void SetMoveAlpha(float NewMoveAlpha);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	bool bMovementEnabled{true};

	UPROPERTY(EditAnywhere)
	bool bRotationEnabled{};

	UPROPERTY(EditAnywhere, Category = Movement)
	FVector MoveOffset{};

	UPROPERTY()
	float MoveAlpha{1.0};

	FVector OriginalLocation{};

	UPROPERTY(EditAnywhere, Category = Movement)
	float MoveTime{4.0};

	UPROPERTY(EditAnywhere, Category = Movement)
	bool bShouldMove{};

	UPROPERTY(EditAnywhere, Category = Rotation)
	bool bShouldRotate{};

	UPROPERTY(EditAnywhere, Category = Rotation)
	FRotator RotationOffset{};

	UPROPERTY(EditAnywhere, Category = Rotation)
	float RotationSpeed{2.0};

	FRotator OriginalRotation{};

	UFUNCTION()
	void MoveActor(float DeltaTime);

	UFUNCTION()
	void RotateActor(float DeltaTime);

		
};
