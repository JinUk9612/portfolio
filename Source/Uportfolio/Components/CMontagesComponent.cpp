#include "CMontagesComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

UCMontagesComponent::UCMontagesComponent()
{
}


void UCMontagesComponent::BeginPlay()
{
	Super::BeginPlay();

	if (DataTable == nullptr)
	{
		CLog::Log("DataTable is not set!!");
		return;
	}

	TArray <FMontageData*> datas;

	DataTable->GetAllRows<FMontageData>("", datas);

	for (int32 i = 0; i < (int32)EStateType::Max; i++)
	{
		for (FMontageData* data : datas)
		{

			if (data->Type == (EStateType)i)
			{
				Datas[i] = data; 
				break;
			}

		}

	}

	
	
}



void UCMontagesComponent::PlayHitted()
{
	PlayAnimMontage(EStateType::Hitted);

}

void UCMontagesComponent::PlayJump()
{
	PlayAnimMontage(EStateType::Jump);

}

void UCMontagesComponent::PlayTwoJump()
{
	PlayAnimMontage(EStateType::TwoJump);

}



void UCMontagesComponent::PlayAnimMontage(EStateType InStateType)
{
	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());
	CheckNull(ownerCharacter);

	FMontageData* data = Datas[(int32)InStateType];

	if (!!data && !!data->AnimMontage)
	{
		ownerCharacter->PlayAnimMontage(data->AnimMontage, data->PlayRate, data->StartSection);
	}
}



