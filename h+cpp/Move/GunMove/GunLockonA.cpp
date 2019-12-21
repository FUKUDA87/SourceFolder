#include "GunLockonA.h"
#include"GunBulletA.h"

C_GunMove * C_GunLockonA::Action(GUNAI * GunAi)
{
	//Ai���@�\���Ă��邩
	if(GunAi->AIFlg==false)return nullptr;

	if ((GunAi->AIFlg == true) && (GunAi->RayJudgFlg == false)) {
		//���C����\
		GunAi->RayJudgFlg = true;
		//���C�̓���������
		GunAi->RayCountNow = GunAi->RayCountInit;
		//�˒�����
		GunAi->RayDis = 20.0f;
	}
	//���C�̔���񐔂ɂ���������
	if (GunAi->RayCountNow <= 0) {
		//�������s��
		GunAi->RayJudgFlg = false;
		return new C_GunBulletA();
	}

	GunAi->NowBase.Mat = GunAi->NowBase.Trans*GunAi->ConnectMat;

	D3DXMATRIX StartMat, EndMat,NowMat;
	StartMat = GunAi->Start.RotXMat*(GunAi->Start.RotYMat*GunAi->NowBase.Mat);
	EndMat = GunAi->End.RotXMat*(GunAi->End.RotYMat*GunAi->NowBase.Mat);

	//��]
	if (judg.Quaternion(&NowMat, StartMat, EndMat, &GunAi->NowAnime, GunAi->AnimeFrame, GunAi->GunMoveFlg) == false) {
		GunAi->GunMoveEndFlg = true;
	}
	D3DXVECTOR3 Pos;
	D3DXVec3TransformCoord(&Pos, &D3DXVECTOR3(0.0f, 0.0f, 1.0f), &NowMat);
	judg.TarEndMat(&NowMat, GunAi->NowBase.Mat, &GunAi->NowBase.RotX, &GunAi->NowBase.RotY, Pos, D3DXVECTOR3(0.0f, 0.0f, 1.0f));
	return nullptr;
}
