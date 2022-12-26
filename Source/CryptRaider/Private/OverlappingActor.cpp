// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlappingActor.h"

#include "WallBoxComponent.h"

// Sets default values
AOverlappingActor::AOverlappingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(RootComponent);

	WallBoxComponent = CreateDefaultSubobject<UWallBoxComponent>("Collider");
	WallBoxComponent->SetupAttachment(MeshComponent);
	
}

UWallBoxComponent* AOverlappingActor::GetCollider()
{
	return WallBoxComponent;
}

// Called when the game starts or when spawned
void AOverlappingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

