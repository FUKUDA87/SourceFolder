#pragma once
#include"PartsBase.h"

class C_TireParts :public C_PartsBase {
public:
	C_TireParts(const PARTS *InitGetParts,const float *GetAngXMaxUp);
	bool UpdateParts(const D3DXMATRIX * Mat);
	//�A�b�v�f�[�g�{�g��̕ω�
	bool UpdateParts(const D3DXMATRIX *Mat, const D3DXVECTOR3 *ScalPos);
private:
	float AngXMaxUp;
};