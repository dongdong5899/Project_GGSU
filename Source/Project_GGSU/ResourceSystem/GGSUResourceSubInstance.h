// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GGSUResourceSubInstance.generated.h"

UENUM()
enum EResourceType
{
	None,
	Wheat,
	
};

/**
 * 
 */
UCLASS()

class PROJECT_GGSU_API UGGSUResourceSubInstance : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	//GetGameInstance()->GetSubSystem<UGGSUResourceSubInstance>()

public:
	
	uint32 GetResource(EResourceType resourceType) { return ResourceTable[resourceType]; }
	void AddGold(EResourceType resourceType, uint32 value) { ResourceTable[resourceType] += value; }
	void Remove(EResourceType resourceType, uint32 value)
	{
		if (ResourceTable[resourceType] >= value)
			ResourceTable[resourceType] -= value;
		else
			ResourceTable[resourceType] = 0;
	}
	bool TryRemove(EResourceType resourceType, uint32 value)
	{
		if (ResourceTable[resourceType] >= value)
		{
			ResourceTable[resourceType] -= value;
			return true;
		}
		return false;
	}

private:
	int Gold;
	TMap<EResourceType, uint32> ResourceTable;
};