// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DeliverySpot.h"
#include "Order.generated.h"

/**
 * 
 */
UCLASS()
class LUIGIS_PIZZA_API UOrder : public UObject
{
	GENERATED_BODY()

private:
	ADeliverySpot* DeliverySpot;

public:
	//Pizza[] pizzas; cuando se implementen las pizzas, se puede hacer un array de pizzas para que el pedido pueda tener varias pizzas
	float basePayment;
	float timeOrdered;


	UFUNCTION(BlueprintCallable, Category = "Order")
	void SetDeliverySpot(ADeliverySpot* NewDeliverySpot);
	UFUNCTION(BlueprintCallable, Category = "Order")
	float CalculateTotalPayment() const;
	
};
