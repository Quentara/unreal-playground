// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class CPPPLAYGROUND_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(EditDefaultsOnly, BluePrintReadWrite, category = "Floater Variables")
	UStaticMeshComponent* FloaterMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Floater Variables")
	bool bIsFloating;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, category = "Floater Variables")
	FVector FloatingDirection;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, category = "Floater Variables")
	FRotator FloatingRotation;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, category = "Floater Variables")
	FVector ForceDirection;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
