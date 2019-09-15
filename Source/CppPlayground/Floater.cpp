// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create default mesh component
	FloaterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloaterStaticMesh"));

	// Deactivates floating of the object by default
	bIsFloating = false;

	// Set initial floating direction, force direction and rotation
	FloatingDirection = FVector(1.0f, 0.0f, 0.0f);
	FloatingRotation = FRotator(0.0f, 0.0f, 1.0f);
	ForceDirection = FVector(8000000.0f, 0.0f, 0.0f);
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	if (!bIsFloating)
	{
		FloaterMesh->AddForce(ForceDirection);
	}
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Declare variable to save hit results on collision
	FHitResult HitResult;

	if (bIsFloating)
	{
		AddActorWorldOffset(FloatingDirection, true, &HitResult);	// Moves actor unless there is a collision
		AddActorLocalRotation(FloatingRotation);
	}

	// Change the direction of the actor when it collides with something
	if (HitResult.bBlockingHit == 1)
	{
		FloatingDirection.X *= -1;
	}
}
