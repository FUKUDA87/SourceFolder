#pragma once
#include"../Player2/PlayerA.h"
#include<d3dx9.h>

class StageCar:public C_PlayerA {
public:
	StageCar(const BODYDATA * Data);
	~StageCar() {};
	//�p��
	bool UpdateAll(void);
};