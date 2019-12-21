#pragma once
#include<d3dx9.h>
#include"../Base&Manager/EnemyDataBase.h"
#include"../EnemyNo1/PartsMove/EnemyNo1_TireMove.h"
#include"../EnemyNo1/PartsMove/EnemyNo1_StandMove.h"
#include"SpeedMove/EnemySpeedNo201.h"
#include"EnemyAi/ENo101_AiPhase_1.h"
#include"PartsMove/ENo101_Judg1Move.h"


class C_EnemyDataNo101 :public C_EnemyDataBase {
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