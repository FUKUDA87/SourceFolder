#include "EnemyDataManager.h"

C_EnemyDataBase * C_EnemyDataManager::GetEnemyData(const int * EnemyNo)
{
	/*����*/
	if (*EnemyNo == EnemyNo1)return new C_EnemyDataNo1();
	if (*EnemyNo == EnemyBossNo101)return new C_EnemyDataNo101();

	//�����Ɉ���������Ȃ��ꍇ
	return new C_EnemyDataNo1();
}
