#include "TireParts.h"

C_TireParts::C_TireParts(const PARTS * InitGetParts, const float * GetAngXMaxUp):C_PartsBase(InitGetParts)
{
	AngXMaxUp = *GetAngXMaxUp;
}

bool C_TireParts::UpdateParts(const D3DXMATRIX * Mat)
{
	//������
	InitParts();
	//�X�s�[�h�̗��𒲂ׂ�
	if (Parts.MoveFlg == true) {
		float Size;
		Size = (float)NowSpeed / (float)MaxSpeed;
		//��]������
		Parts.Base.AngX += AngXMaxUp * Size;
		if (Parts.Base.AngX > 360.0f)Parts.Base.AngX -= 360.0f;
		if (Parts.Base.AngX < -360.0f)Parts.Base.AngX += 360.0f;

	}
	D3DXMatrixRotationX(&Parts.Base.RotX, D3DXToRadian((float)Parts.Base.AngX));

	Parts.Base.Mat = Parts.Base.RotX*Parts.Base.RotY*Parts.Base.Trans*(*Mat);
	return true;
}

bool C_TireParts::UpdateParts(const D3DXMATRIX * Mat, const D3DXVECTOR3 * ScalPos)
{
	ScalParts(ScalPos);

	//�X�s�[�h�̗��𒲂ׂ�
	if (Parts.MoveFlg == true) {
		float Size;
		Size = (float)NowSpeed / (float)MaxSpeed;
		//��]������
		Parts.Base.AngX += AngXMaxUp * Size;
		if (Parts.Base.AngX > 360.0f)Parts.Base.AngX -= 360.0f;
		if (Parts.Base.AngX < -360.0f)Parts.Base.AngX += 360.0f;

	}
	D3DXMatrixRotationX(&Parts.Base.RotX, D3DXToRadian((float)Parts.Base.AngX));

	Parts.Base.Mat = Parts.Base.RotX*Parts.Base.RotY*Parts.Base.Trans*(*Mat);
	return true;
}
