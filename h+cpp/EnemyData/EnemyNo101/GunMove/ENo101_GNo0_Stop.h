#pragma once
#include"ENo101_GNo0_MoveBase.h"

class C_ENo101_GNo0_Stop :public C_ENo101_GNo0_MoveBase {
public:
	C_ENo101_GNo0_Stop();
	C_E_GunMoveBase* Move(S_ENEMYGUNDATA* s_Data, int *NowPhase);
protected:

private:
	int Count, CountInit;
};