#pragma once
#include<d3dx9.h>
#include"../EnemyConst/PhaseConst.h"

class Speed {
public:
	virtual Speed* Action(int *NowSpeed,const int *TargetSpeed,const unsigned int *EneGroNo, const unsigned int *TarGroNo,int *NewPhase) = 0;//=0:�������z�֐��ɂ���i�K���p�����A�h���N���X���ŃI�[�o�[���C�h���Ȃ��Ƃ����Ȃ��֐�
protected:
	//�A�b�v�^�C�~���O
	int CountDown, CountDownNow;
	bool CountUpdate(void);
	int NowPhase;
};