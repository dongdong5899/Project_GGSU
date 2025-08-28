// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUResourceSubInstance.generated.h"

/**
 * 
 */
UCLASS()

class PROJECT_GGSU_API UGGSUResourceSubInstance : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	//GetGameInstance()->GetSubSystem<UGGSUResourceSubInstance>()

public:
	int GetGold() { return Gold; }
	void AddGold(int value) { Gold += value; }

private:
	int Gold;
};