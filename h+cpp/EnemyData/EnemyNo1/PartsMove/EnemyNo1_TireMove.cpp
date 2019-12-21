#include "EnemyNo1_TireMove.h"

C_EnemyNo1_TireMove::C_EnemyNo1_TireMove()
{
	AngXMaxUp=28.0f;
}

C_PartsMoveBase * C_EnemyNo1_TireMove::Move(PARTS * Parts, const D3DXMATRIX * Mat, const int * Speed, const int * MaxSpeed, int *NowPhase)
{
	//�X�s�[�h�̗��𒲂ׂ�
	if (Parts->MoveFlg == true) {
		float Size;
		Size = (float)*Speed / (float)*MaxSpeed;
		//��]������
		Parts->Base.AngX += AngXMaxUp * Size;
		if (Parts->Base.AngX > 360.0f)Parts->Base.AngX -= 360.0f;
		if (Parts->Base.AngX < -360.0f)Parts->Base.AngX += 360.0f;

	}
	D3DXMatrixRotationX(&Parts->Base.RotX, D3DXToRadian((float)Parts->Base.AngX));

	Parts->Base.Mat = Parts->Base.RotX*Parts->Base.RotY*Parts->Base.Trans*(*Mat);
	return nullptr;
}
