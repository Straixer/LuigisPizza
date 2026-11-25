// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "../TimeManager.h"

AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = false;
	Day = 1;
	CurrentState = EGameState::DayShift;
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	StartState(EGameState::DayShift);
}

void AGameManager::ChangeState(EGameState NewState)
{
	if (NewState == CurrentState)
	{
		return;
	}

	EndState(CurrentState);
	CurrentState = NewState;
	StartState(CurrentState);
}

void AGameManager::StartState(EGameState State)
{
	switch (State)
	{
	case EGameState::DayShift:
		UE_LOG(LogTemp, Warning, TEXT("Iniciando Turno de Dia. Dia: %d"), Day);
		if (TimeManager != nullptr && (TimeManager->IsNight || TimeManager->Seconds >= TimeManager->SecondsPerDay))
		{
			Day = Day + 1;
			TimeManager->StartDay();
		}
		// TODO: Activar aquí el OrderManager para que empiecen a entrar pedidos
		break;

	case EGameState::NightShift:
		UE_LOG(LogTemp, Warning, TEXT("Cambio a Turno de Noche"));
		// TODO: Cambiar iluminación a noche y subir dificultad/frecuencia de pedidos
		break;

	case EGameState::EndOfDay:
		UE_LOG(LogTemp, Warning, TEXT("Fin de jornada"));
		// TODO: Cortar nuevos pedidos y mostrar UI de ganancias del día
		break;

	case EGameState::Paused:
		UE_LOG(LogTemp, Warning, TEXT("Juego pausado"));
		if (TimeManager != nullptr)
		{
			TimeManager->IsPaused = true;
		}
		break;
	}
}

void AGameManager::EndState(EGameState State)
{
	switch (State)
	{
	case EGameState::Paused:
		if (TimeManager != nullptr)
		{
			TimeManager->IsPaused = false;
		}
		break;

	default:
		break;
	}
}

