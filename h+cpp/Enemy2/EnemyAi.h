#pragma once
#include"EnemyBase.h"
#include"../EnemyData/Base&Manager/EnemySpeed.h"
#include"../EnemyData/EnemyConst/PhaseConst.h"
#include"../EnemyData/Base&Manager/EnemyAiPhaseBase.h"

class C_EnemyAi :public C_EnemyBase {
public:
	C_EnemyAi();
	~C_EnemyAi();
	//�v�l
	bool UpdateAi(CHARAData cd[], unsigned int NUM, std::vector<BillBase*>ground);
	//�A�b�v�f�[�g
	bool UpdateAll(std::vector<BillBase*>ground);

	void SetParts(std::vector<BillBase*>ground);

	void SetPlaEnd(bool Flg);
	//Ai�̋N��
	bool StartAi(const unsigned int *GNo);

	bool GetDeadFlg(void) {
		return DeadFlg;
	}
	void SetDeadFlg(const bool Flg) {
		DeadFlg = Flg;
	}

protected:
	//�X�s�[�h�̏�����
	void InitSpeedMove(Speed* Initspeed);

	C_E_AiPhaseBase *m_Ai;
private:


	//------------------------
	//�X�s�[�h�Ǘ�
	//SpeedMove EneSpe;
	Speed *speed;
	float SpeedMul;
	int NowCount, MaxCount;
	//------------------------

	int NowPhase;

	bool DeadFlg;
};