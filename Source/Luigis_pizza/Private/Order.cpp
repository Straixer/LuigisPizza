// Fill out your copyright notice in the Description page of Project Settings.


#include "Order.h"

void UOrder::SetDeliverySpot(ADeliverySpot* NewDeliverySpot)
{
	DeliverySpot = NewDeliverySpot;
}

float UOrder::CalculateTotalPayment() const
{
	// float timeElapsed = GetTime() - timeOrdered;
	// float multiplier = 2f;
	// if (timeElapsed > 30.0f){
	// multiplier = 1.5f;
	// } else if (timeElapsed > 60.0f){
	// multiplier = 1.0f;
	// }else if (timeElapsed > 90.0f){{
	// multiplier = 0.5f;
	// }
	// return basePayment * multiplier;
	return 10.0f;
}
