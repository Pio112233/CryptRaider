// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UPhysicsHandleComponent* UGrabber::GetPhysicsHandleComponent() const
{
	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
}

void UGrabber::Grab()
{
	UPhysicsHandleComponent* PhysicsHandle = GetPhysicsHandleComponent();
	if (PhysicsHandle)
	{
		FHitResult HitResult;
		GetGrabbableInRange(HitResult);
		if (HitResult.GetActor())
		{
			UPrimitiveComponent* HitComponent = HitResult.GetComponent();
			HitComponent->WakeAllRigidBodies();
			if (HitComponent->GetAttachParent())
			{
				HitComponent->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
				HitComponent->SetSimulatePhysics(true);
			}
			HitComponent->ComponentTags.Add("grabbed");
			GetPhysicsHandleComponent()->GrabComponentAtLocationWithRotation(HitComponent, NAME_None, HitResult.ImpactPoint, GetComponentRotation());
		}
	}
}


void UGrabber::Release()
{
	if (GetPhysicsHandleComponent() && GetPhysicsHandleComponent()->GetGrabbedComponent())
	{
		GetPhysicsHandleComponent()->GetGrabbedComponent()->ComponentTags.Remove("grabbed");
		GetPhysicsHandleComponent()->GetGrabbedComponent()->WakeAllRigidBodies();
		GetPhysicsHandleComponent()->ReleaseComponent();
	}
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (GetPhysicsHandleComponent() && GetPhysicsHandleComponent()->GrabbedComponent)
	{
		GetPhysicsHandleComponent()->SetTargetLocationAndRotation(GetComponentLocation() + GetForwardVector() * HoldDistance, GetComponentRotation());
	}
}

bool UGrabber::GetGrabbableInRange(FHitResult& OutHitResult) const
{
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	return GetWorld()->SweepSingleByChannel(OutHitResult, GetComponentLocation(), GetComponentLocation() + GetForwardVector() * MaxGrabDistance, FQuat::Identity, ECC_GameTraceChannel2, Sphere);
}

