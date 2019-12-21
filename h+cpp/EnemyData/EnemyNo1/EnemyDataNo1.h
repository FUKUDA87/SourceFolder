#pragma once
#include<d3dx9.h>
#include"../Base&Manager/EnemyDataBase.h"
#include"GunMove/EnemyNo1GunNo1_Attack.h"
#include"SpeedData/SpeedUp.h"
#include"EnemyAi/ENo1_AiPhase.h"


class C_EnemyDataNo1 :public C_EnemyDataBase {
public:
	//�ԏ��n���ƌ���
	S_ENEMYBODYDATA GetBodyData(void);
	//�W���p�[�c���n���ƌ���
	C_PartsMoveBase* GetPartsData(const int *PartsNo);
	//�W���p�[�c���n���ƌ���
	XFILE GetPartsMesh(const int *PartsNo);
	//�e�̏��n���ƌ���
	C_E_GunMoveBase* GetGunData(const int *GunNo, S_ENEMYGUNDATA *s_Data);
	//�Ԉړ��n��
	Speed* GetSpeed(void);
	//Ai�n��
	C_E_AiPhaseBase* GetAiPhase(void);
protected:

private:
	/*�p�[�c���*/

};