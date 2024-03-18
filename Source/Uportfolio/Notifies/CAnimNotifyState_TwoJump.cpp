#include "CAnimNotifyState_TwoJump.h"
#include "Global.h"
#include "Characters/CPlayer.h"

FString UCAnimNotifyState_TwoJump::GetNotifyName_Implementation() const
{
	return "TwoJump";
}

void UCAnimNotifyState_TwoJump::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	CheckNull(MeshComp->GetOwner());

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	CheckNull(player);

	player->OnTwo_Jump();

}

void UCAnimNotifyState_TwoJump::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{

	Super::NotifyEnd(MeshComp, Animation);

	CheckNull(MeshComp->GetOwner());

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	CheckNull(player);

	player->OffTwo_Jump();
}
