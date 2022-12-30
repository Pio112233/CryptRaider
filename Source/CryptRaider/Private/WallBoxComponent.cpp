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

UPrimitiveComponent* UWallBoxComponent::GetSupportedActor()
{
	TArray<UPrimitiveComponent*> OutComponents;
	GetOverlappingComponents(OutComponents);

	if (OutComponents.Num() > 0)
	{
		if (!ComponentInside)
		{
			for (UPrimitiveComponent* Component : OutComponents)
			{
				if (Component->ComponentHasTag(OverlappableComponentTag) && !Component->ComponentTags.Contains("grabbed"))
				{
					Component->SetSimulatePhysics(false);
					Component->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
					Component->SetWorldLocation({Component->GetComponentLocation().X, Component->GetComponentLocation().Y, GetComponentLocation().Z - GetScaledBoxExtent().Z});
					Component->SetWorldRotation({0.0, Component->GetComponentRotation().Yaw, 0.0});
					OnSupportedCompOverlap.Broadcast(Component);
					ComponentInside = Component;
					break;
				}
			}
		}
	}
	else
	{
		ComponentInside = nullptr;
	}
	return ComponentInside;
}

