#pragma once
#include"../../Base&Manager/EnemySpeed.h"

class SpeedUp1:public Speed {
public:
	SpeedUp1();
	virtual Speed* Action(int *NowSpeed, const int *TargetSpeed, const unsigned int *EneGroNo, const unsigned int *TarGroNo, int *NewPhase);
protected:
	//�ω���
	int SpeedUpNum;
};

class SpeedUp2 :public SpeedUp1 {
public:
	SpeedUp2();
	Speed* Action(int *NowSpeed, const int *TargetSpeed, const unsigned int *EneGroNo, const unsigned int *TarGroNo, int *NewPhase);
private:
};