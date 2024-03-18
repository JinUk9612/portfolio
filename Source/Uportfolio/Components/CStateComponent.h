#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"

UENUM(BlueprintType)
enum class EStateType : uint8
{
	Idle,Jump,TwoJump,Hitted,Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateTypeChangedSignature, EStateType, InPrevType, EStateType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPORTFOLIO_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStateComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsIdleMode() { return Type == EStateType::Idle; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsJumpMode() { return Type == EStateType::Jump; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsTwoJumpMode() { return Type == EStateType::TwoJump; }

public:
	void SetIdleMode();
	void SetJumpMode();
	void SetTwoJumpMode();
	void SetHittedMode();

private:
	void ChangeType(EStateType InNewType);

public:
	FORCEINLINE EStateType GetType() { return Type; }

public:
	UPROPERTY(BlueprintAssignable)
		FStateTypeChangedSignature OnStateTypeChanged;

public:
	EStateType Type;

		
};
