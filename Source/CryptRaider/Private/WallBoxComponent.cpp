// Fill out your copyright notice in the Description page of Project Settings.


#include "WallBoxComponent.h"

UWallBoxComponent::UWallBoxComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UWallBoxComponent::SetMover(UMover* MoverComp)
{
	Mover = MoverComp;
}

void UWallBoxComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetSupportedActor();
}

void UWallBoxComponent::GetSupportedActor()
{
	TArray<UPrimitiveComponent*> OutComponents;
	GetOverlappingComponents(OutComponents);

	if (OutComponents.Num() > 0)
	{
		if (!bActorInside)
		{
			for (UPrimitiveComponent* Component : OutComponents)
			{
				if (Component->ComponentHasTag(OverlappableComponentTag))
				{
					OnSupportedCompOverlap.Broadcast(Component);
					bActorInside = true;
					break;
				}
			}
		}
	}
	else
	{
		bActorInside = false;
	}
}
