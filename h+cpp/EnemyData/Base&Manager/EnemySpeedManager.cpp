#include "EnemySpeedManager.h"

Speed * C_EnemySpeedManager::GetEnemySpeed(int EnemyNo)
{
	//No1
	if (EnemyNo == EnemyNo1)return new SpeedUp1();
	//No101
	if (EnemyNo == EnemyBossNo101)return new C_EnemySpeedNo201();

	//検索に引っかからない時
	return new SpeedUp1();
}
