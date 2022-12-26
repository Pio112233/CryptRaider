// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"

class UPhysicsHandleComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	UPhysicsHandleComponent* GetPhysicsHandleComponent() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Grab();

	UFUNCTION(BlueprintCallable)
	void Release();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
	float MaxGrabDistance{250.0};

	UPROPERTY(EditAnywhere)
	float GrabRadius{100.0};

	UPROPERTY(EditAnywhere)
	float HoldDistance{120};

	UFUNCTION()
	bool GetGrabbableInRange(FHitResult& OutHitResult) const;

		
};
