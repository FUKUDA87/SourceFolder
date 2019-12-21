#include "GunBulletStopA.h"
#include"GunLockonA.h"

C_GunBulletStopA::C_GunBulletStopA()
{
	InitFlg = true;
}

C_GunMove * C_GunBulletStopA::Action(GUNAI * GunAi)
{
	//Ai���@�\���Ă��邩
	if (GunAi->AIFlg == false)return nullptr;
	//������
	if (InitFlg == true) {
		GunAi->BulletCount = 120;

		InitFlg = false;
	}

	if (GunAi->BulletCount > 0)GunAi->BulletCount -= 1;
	if (GunAi->BulletCount <= 0) {
		GunAi->EndFlg = true;
		GunAi->AIFlg = false;
		return new C_GunLockonA();
	}

	return nullptr;
}
