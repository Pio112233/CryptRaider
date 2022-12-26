// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "WallBoxComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSupportedCompOverlap, UPrimitiveComponent*, Component);

class UMover;
/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UWallBoxComponent : public UBoxComponent
{
	GENERATED_BODY()



public:

	UWallBoxComponent();

	UPROPERTY(BlueprintAssignable)
	FOnSupportedCompOverlap OnSupportedCompOverlap;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* MoverComp);

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName OverlappableComponentTag{};

	UPROPERTY(BlueprintReadOnly)
	bool bActorInside{false};

private:

	UFUNCTION()
	void GetSupportedActor();

	UPROPERTY()
	UMover* Mover{nullptr};
	
	
	
};
