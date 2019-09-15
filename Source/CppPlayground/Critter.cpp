// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Initialize root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Initialize mesh and attach it to root
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	//Initialize camera and attach it to root
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());
	Camera->SetRelativeLocation(FVector(0.0f, 300.0f, 300.0f));
	Camera->SetRelativeRotation(FRotator(-45.0f, -90.0f, 0.0f));

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	MaxSpeed = 100.0f;
	CurrentVelocity = FVector(0.0f);
}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewPosition = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewPosition);
}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACritter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveSideward"), this, &ACritter::MoveSideward);
}

void ACritter::MoveForward(float value) 
{
	CurrentVelocity.Y = FMath::Clamp(value, -1.0f, 1.0f) * MaxSpeed;
}

void ACritter::MoveSideward(float value)
{
	CurrentVelocity.X = FMath::Clamp(value, -1.0f, 1.0f) * MaxSpeed;
}
