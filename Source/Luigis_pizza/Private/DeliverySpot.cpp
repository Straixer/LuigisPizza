// Fill out your copyright notice in the Description page of Project Settings.


#include "DeliverySpot.h"

// Sets default values
ADeliverySpot::ADeliverySpot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ADeliverySpot::BeginPlay()
{
	Super::BeginPlay();
	this->OnActorBeginOverlap.AddDynamic(this, &ADeliverySpot::OnBeginOverlap);

}

// Called every frame
void ADeliverySpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeliverySpot::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{

}
