// Fill out your copyright notice in the Description page of Project Settings.


#include "OrderManager.h"

void UOrderManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	GetWorld()->GetTimerManager().SetTimer(OrderTimerHandle, this, &UOrderManager::TryGenerateOrder, OrderTimerInterval, true);
}

void UOrderManager::Deinitialize()
{
	GetWorld()->GetTimerManager().ClearTimer(OrderTimerHandle);
	Super::Deinitialize();
}

void UOrderManager::StartManagingOrders()
{
}

void UOrderManager::StopManagingOrders()
{
}

UOrder* UOrderManager::GenerateOrder()
{
	return nullptr;
}

void UOrderManager::TryGenerateOrder()
{
	if(isManagingOrders)
	{
		float RandomValue = FMath::FRand();
		if(Orders.Num()<maxOrders && RandomValue <= OrderSpawnChance)
		{
			UOrder* NewOrder = GenerateOrder();
			if(NewOrder)
			{
				Orders.Add(NewOrder);
			}
		}
	}
}

void UOrderManager::DeleteOrders()
{
}

void UOrderManager::payOrder(UOrder* Order)
{
}
