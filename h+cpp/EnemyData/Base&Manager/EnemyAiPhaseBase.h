#pragma once
#include<d3dx9.h>
#include"../../GameSource/Struct.h"
#include"../EnemyConst/PhaseConst.h"

class C_E_AiPhaseBase {
public:
	virtual C_E_AiPhaseBase* Action(const CHARABASE *Chara,int *NewPhase) = 0;//=0:�������z�֐��ɂ���i�K���p�����A�h���N���X���ŃI�[�o�[���C�h���Ȃ��Ƃ����Ȃ��֐�
protected:
	int NowPhase;
};