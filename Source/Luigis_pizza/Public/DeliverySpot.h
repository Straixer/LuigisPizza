// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeliverySpot.generated.h"

UCLASS()
class LUIGIS_PIZZA_API ADeliverySpot : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ADeliverySpot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
