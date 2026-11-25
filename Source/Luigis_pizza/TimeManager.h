// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

class AGameManager;

UCLASS()
class LUIGIS_PIZZA_API ATimeManager : public AActor
{
	GENERATED_BODY()

public:
	ATimeManager();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reloj")
	float Seconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reloj")
	float SecondsPerDay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reloj")
	float NightStartSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reloj")
	bool IsNight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reloj")
	bool IsPaused;

	// Asignar el GameManager de la escena desde el panel Details
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conexiones")
	AGameManager* GameManager;

	UFUNCTION(BlueprintCallable, Category = "Reloj")
	void StartDay();

	UFUNCTION(BlueprintCallable, Category = "Reloj")
	void EndDay();
};