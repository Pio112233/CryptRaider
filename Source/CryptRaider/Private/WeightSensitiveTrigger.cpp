// Fill out your copyright notice in the Description page of Project Settings.


#include "WeightSensitiveTrigger.h"

UPrimitiveComponent* UWeightSensitiveTrigger::GetSupportedActor()
{
	UWallBoxComponent::GetSupportedActor();
	if (ComponentInside)
	{
		ComponentInside->SetSimulatePhysics(true);
		MoveAlpha = ComponentInside->GetMass() / TargetWeight;
	}
	else
	{
		MoveAlpha = 0.0;
	}
	return ComponentInside;
}
