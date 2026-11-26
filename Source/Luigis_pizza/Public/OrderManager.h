// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Order.h"
#include "OrderManager.generated.h"

/**
 * 
 */
UCLASS()
class LUIGIS_PIZZA_API UOrderManager : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "OrderManager")
	int maxOrders = 5;

private:
	FTimerHandle OrderTimerHandle;
	bool isManagingOrders = false;
	UPROPERTY()
	TArray<UOrder*> Orders;

	UPROPERTY(EditAnywhere, Category = "OrderManager")
	float OrderTimerInterval = 10.0f;
	UPROPERTY(EditAnywhere, Category = "OrderManager")
	float OrderSpawnChance = 0.5f;
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "OrderManager")
	void StartManagingOrders();
	UFUNCTION(BlueprintCallable, Category = "OrderManager")
	void StopManagingOrders();
private:
	UOrder* GenerateOrder();
	void TryGenerateOrder();
	void DeleteOrders();
	void payOrder(UOrder* Order);
};
