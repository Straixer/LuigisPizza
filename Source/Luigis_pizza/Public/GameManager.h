// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

class ATimeManager;

UENUM(BlueprintType)
enum class EGameState : uint8
{
	DayShift    UMETA(DisplayName = "Turno de Dia"),
	NightShift  UMETA(DisplayName = "Turno de Noche"),
	EndOfDay    UMETA(DisplayName = "Fin del Dia"),
	Paused      UMETA(DisplayName = "Pausado")
};

UCLASS()
class LUIGIS_PIZZA_API AGameManager : public AActor
{
	GENERATED_BODY()

public:
	AGameManager();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Estado")
	int32 Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Estado")
	EGameState CurrentState;

	// Asignar el TimeManager de la escena desde el panel Details
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conexiones")
	ATimeManager* TimeManager;

	// Usar siempre esta función para cambiar de estado, ya cierra el anterior y abre el nuevo
	UFUNCTION(BlueprintCallable, Category = "Estado")
	void ChangeState(EGameState NewState);

	UFUNCTION(BlueprintCallable, Category = "Estado")
	void StartState(EGameState State);

	UFUNCTION(BlueprintCallable, Category = "Estado")
	void EndState(EGameState State);
};