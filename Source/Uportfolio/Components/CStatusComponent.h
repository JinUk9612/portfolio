#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPORTFOLIO_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStatusComponent();

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE bool IsCanMove() { return bCanMove; }

	FORCEINLINE float GetWalk() { return Walk; }
	FORCEINLINE float GetFastWalk() { return FastWalk; }
	FORCEINLINE float GetRun() { return Run; }
	FORCEINLINE float GetFastRun() { return FastRun; }

	void SetMove();
	void SetStop();

private:
	UPROPERTY(EditAnywhere, Category = "Speed")
		float Walk = 200.f;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float FastWalk = 400.f;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float Run = 600.f;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float FastRun = 800.f;

private:
	bool bCanMove = true;
};
