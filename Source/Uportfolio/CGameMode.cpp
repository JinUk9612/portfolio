#include "CGameMode.h"
#include "Global.h"


ACGameMode::ACGameMode()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/Character/BP_CPlayer.BP_CPlayer_C'");
}