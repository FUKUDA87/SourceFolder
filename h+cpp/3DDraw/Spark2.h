#pragma once
#include"Spark.h"

class C_Spark2 :public C_Spark {
public:
	//�o�[�W�����P
	C_Spark2(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos);
	//�o�[�W�����Q
	//C_Spark2(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos, const bool *LeftFlg);
	//�o�[�W����3�i�ǁj
	C_Spark2(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos, const bool *LeftFlg, const bool *InitFlg);
	//�o�[�W����4�i�ԁj
	C_Spark2(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos, const bool *InitFlg);
	bool Update(void);
};