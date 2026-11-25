// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"
#include "GameManager.h"

ATimeManager::ATimeManager()
{
	PrimaryActorTick.bCanEverTick = true;

	// Valores de prueba para testear el ciclo rápido
	Seconds = 0.0f;
	SecondsPerDay = 120.0f;
	NightStartSeconds = 60.0f;
	IsNight = false;
	IsPaused = false;
}

void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPaused == true)
	{
		return;
	}

	Seconds = Seconds + DeltaTime;

	// Aviso al GameManager cuando pasamos al turno de noche (solo lo lanza una vez)
	if (Seconds >= NightStartSeconds && IsNight == false)
	{
		IsNight = true;

		if (GameManager != nullptr)
		{
			GameManager->ChangeState(EGameState::NightShift);
		}
	}

	if (Seconds >= SecondsPerDay)
	{
		EndDay();
	}
}

void ATimeManager::StartDay()
{
	Seconds = 0.0f;
	IsNight = false;
	IsPaused = false;
}

void ATimeManager::EndDay()
{
	IsPaused = true;

	if (GameManager != nullptr)
	{
		GameManager->ChangeState(EGameState::EndOfDay);
	}
}

