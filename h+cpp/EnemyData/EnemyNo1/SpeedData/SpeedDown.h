#pragma once
#include"../../Base&Manager/EnemySpeed.h"

class SpeedDown1 :public Speed {
public:
	SpeedDown1();
	Speed* Action(int *NowSpeed, const int *TargetSpeed, const unsigned int *EneGroNo, const unsigned int *TarGroNo, int *NewPhase);
protected:
	//�ω���
	int SpeedDownNum;
};

class SpeedDown2 :public SpeedDown1 {
public:
	SpeedDown2();
	Speed* Action(int *NowSpeed, const int *TargetSpeed, const unsigned int *EneGroNo, const unsigned int *TarGroNo, int *NewPhase);
private:
};