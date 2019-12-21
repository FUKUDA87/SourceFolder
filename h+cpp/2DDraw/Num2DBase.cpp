#include "Num2DBase.h"
#include"../GameSource/TextureManager.h"

extern TextureManager textureManager;

void C_Num2DBase::SetNum(const D3DXVECTOR3 * Pos, const D3DXVECTOR3 * Scal)
{
	Num.Base.Pos = *Pos;
	Num.Base.ScaPos = *Scal;
}

void C_Num2DBase::SetTex(std::string FileName, const int * Width, const int * Height)
{
	//�摜���̃Z�b�g
	Num.TEX.Width = *Width;
	Num.TEX.Height = *Height;
	//�摜�̃��[�h
	Num.TEX.Tex = textureManager.GetTexture(&FileName[0], Num.TEX.Width, Num.TEX.Height, NULL);
}

//void C_Num2DBase::Draw2DNB(const int * TmpNum)
//{
//	if (Num.TEX.Tex == nullptr)return;
//
//	//�\��
//
//}

D3DXMATRIX C_Num2DBase::GetDrawMatNDB(const D3DXMATRIX * Mat)
{
	D3DXMATRIX Tmp;
	//�s��̏���
	judg.ScalingMat(&Num.Base.Scal, &Num.Base.ScaPos);
	//�s��̍���
	Tmp = Num.Base.Scal**Mat;

	return Tmp;
}

