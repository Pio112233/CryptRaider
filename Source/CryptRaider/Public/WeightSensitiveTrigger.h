// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WallBoxComponent.h"
#include "WeightSensitiveTrigger.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UWeightSensitiveTrigger : public UWallBoxComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	float MoveAlpha{0.0};

protected:

	UPROPERTY(EditAnywhere)
	float TargetWeight{50.0};

	virtual UPrimitiveComponent* GetSupportedActor() override;

private:

	UPROPERTY()
	float CurrentWeight{0.0};
	
};
