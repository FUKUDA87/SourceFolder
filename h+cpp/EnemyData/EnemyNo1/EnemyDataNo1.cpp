#include "EnemyDataNo1.h"
#include"PartsMove/EnemyNo1_TireMove.h"
#include"PartsMove/EnemyNo1_StandMove.h"

S_ENEMYBODYDATA C_EnemyDataNo1::GetBodyData(void)
{
	S_ENEMYBODYDATA l_EBD;
	l_EBD.Body.CarBodyNo = CarNo101;
	l_EBD.Body.TireNo = TireNo101;
	l_EBD.Body.StandNo = StandNo101;
	l_EBD.Body.GunNo = 1;
	l_EBD.CharaBase.NowHp=l_EBD.CharaBase.MaxHp = 20;
	l_EBD.CharaBase.DamageSetFlg = true;
	l_EBD.ScalPos = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	l_EBD.GroundHeight = 0.75f;
	return l_EBD;
}

C_PartsMoveBase* C_EnemyDataNo1::GetPartsData(const int * PartsNo)
{
	//����
	if ((*PartsNo > -1) && (*PartsNo < 4))return new C_EnemyNo1_TireMove();
	if (*PartsNo > 3)return new C_EnemyNo1_StandMove();
	//�����Ɉ���������Ȃ��ꍇ
	return new C_EnemyNo1_TireMove();
}

XFILE C_EnemyDataNo1::GetPartsMesh(const int * PartsNo)
{
	//�^�C���}�l�[�W���[
	C_TireMeshManager TireMeshManager;
	//�X�^���h�}�l�[�W���[
	C_StandMeshManager StandMeshManager;
	//�p�[�c�}�l�[�W���[
	C_PartsMeshManager PartsMeshManager;
	if ((*PartsNo > -1) && (*PartsNo < 4))return TireMeshManager.GetMesh(TireNo101);
	if (*PartsNo > 3)return StandMeshManager.GetMesh(StandNo101);
	return TireMeshManager.GetMesh(TireNo101);
}

C_E_GunMoveBase* C_EnemyDataNo1::GetGunData(const int * GunNo, S_ENEMYGUNDATA *s_Data)
{
	//����
	if (*GunNo == co_E_DataNo0)return new C_ENo1_GNo1_Attack(s_Data);

	//�����Ɉ���������Ȃ��ꍇ
	return new C_ENo1_GNo1_Attack(s_Data);
}

Speed * C_EnemyDataNo1::GetSpeed(void)
{
	return new SpeedUp1();
}

C_E_AiPhaseBase * C_EnemyDataNo1::GetAiPhase(void)
{
	return new C_E_No1_AiPhase();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


