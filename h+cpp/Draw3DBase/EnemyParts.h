#pragma once
#include"PartsBase.h"
#include"../EnemyData/Base&Manager/PartsMoveBase.h"

class C_EnemyParts :public C_PartsBase {
public:
	C_EnemyParts(const PARTS *InitGetParts,C_PartsMoveBase* GetMove,const int *MaxHp);
	~C_EnemyParts();
	//�A�b�v�f�[�g�{�g��̕ω�
	bool UpdateParts(const D3DXMATRIX *Mat, const D3DXVECTOR3 *ScalPos,int *Phase);
private:
	C_PartsMoveBase* Move;
	int m_MaxHp;
	bool InitHpFlg;
};