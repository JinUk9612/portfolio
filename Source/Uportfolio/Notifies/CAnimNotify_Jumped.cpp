#include "CAnimNotify_Jumped.h"
#include "Global.h"
#include "Characters/CPlayer.h"

FString UCAnimNotify_Jumped::GetNotifyName_Implementation()const
{
	return "EndJump";
}

void UCAnimNotify_Jumped::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	CheckNull(MeshComp->GetOwner());

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	CheckNull(player);

	player->End_Jump();

}
