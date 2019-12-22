#include "EnemyDataManager.h"

C_EnemyDataBase * C_EnemyDataManager::GetEnemyData(const int * EnemyNo)
{
	/*検索*/
	if (*EnemyNo == EnemyNo1)return new C_EnemyDataNo1();
	if (*EnemyNo == EnemyBossNo101)return new C_EnemyDataNo101();

	//検索に引っかからない場合
	return new C_EnemyDataNo1();
}
