#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"


class C_EnemySelect {
public:
	BODYDATACar GetEnemy(const int EnemyNo);
protected:

private:
	//�p�[�c�f�[�^
	BODYDATACar eData;
	//��������p
	bool GetEnemyJudg(const int EnemyNo);

	//�G�P
	bool GetEnemy1(const int EnemyNo);
	//�G�P
	bool GetEnemyBoss1(const int EnemyNo);
};