// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OverlappingActor.generated.h"

class UStaticMeshComponent;
class UWallBoxComponent;

UCLASS()
class CRYPTRAIDER_API AOverlappingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOverlappingActor();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UWallBoxComponent* GetCollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UWallBoxComponent* WallBoxComponent;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool CheckPuzzleProgress();
	
};
