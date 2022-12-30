// Fill out your copyright notice in the Description page of Project Settings.


#include "WeightSensitiveTrigger.h"

UPrimitiveComponent* UWeightSensitiveTrigger::GetSupportedActor()
{
	UWallBoxComponent::GetSupportedActor();
	if (ComponentInside && !ComponentInside->ComponentHasTag("grabbed"))
	{
		ComponentInside->SetSimulatePhysics(true);
		CurrentWeight = ComponentInside->GetMass();
		MoveAlpha = FMath::Clamp(CurrentWeight / TargetWeight, 0.0, 1.2);
		ComponentInside->SetSimulatePhysics(false);
	}
	else if (ComponentInside && !ComponentInside->IsSimulatingPhysics(NAME_None))
	{
	ComponentInside->SetSimulatePhysics(true);
	}
	else
	{
		MoveAlpha = 0.0;
		CurrentWeight = 0.0;
	}
	return ComponentInside;
}
