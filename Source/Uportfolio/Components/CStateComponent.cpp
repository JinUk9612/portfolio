#include "CStateComponent.h"

UCStateComponent::UCStateComponent()
{

}


void UCStateComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCStateComponent::SetIdleMode()
{
	ChangeType(EStateType::Idle);

}

void UCStateComponent::SetJumpMode()
{
	ChangeType(EStateType::Jump);

}

void UCStateComponent::SetBackstepMode()
{
	ChangeType(EStateType::Backstep);

}

void UCStateComponent::SetHittedMode()
{
	ChangeType(EStateType::Hitted);

}

void UCStateComponent::ChangeType(EStateType InNewType)
{
	EStateType prev = Type;

	Type = InNewType;

	if (OnStateTypeChanged.IsBound())
		OnStateTypeChanged.Broadcast(prev, InNewType);
}



