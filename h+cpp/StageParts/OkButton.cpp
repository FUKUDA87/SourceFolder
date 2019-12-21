#include "OkButton.h"
#include"../GameSource/TextureManager.h"

extern TextureManager textureManager;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g

C_OK::C_OK(const D3DXVECTOR3 * CharScal, const D3DXVECTOR3 * WindPos, const D3DXVECTOR3 * WindScal)
{
	//������
	InitOK();

	wind.Base.Pos = *WindPos;
	wind.Base.ScaPos.x *= WindScal->x;
	wind.Base.ScaPos.y *= WindScal->y;

	//�����̊g��
	OK.Base.ScaPos.x *= CharScal->x;
	OK.Base.ScaPos.y *= CharScal->y;

	OK.Base.Pos = wind.Base.Pos;
	
}

void C_OK::Draw2DOK(void)
{
	if (OK.Base.DrawFlg != true)return;

	Draw2D();

	//�����\��------------------------------------------------------------------------------------
	//�ʒu�̃Z�b�g
	D3DXMatrixScaling(&OK.Base.Scal, OK.Base.ScaPos.x, OK.Base.ScaPos.y, OK.Base.ScaPos.z);
	D3DXMATRIX tmp;
	tmp = OK.Base.Scal*wind.Base.Mat;

	//�\��
	//if (OK.Base.DrawFlg == false) {
		RECT rcH = { 0,0, OK.TEX.Width, OK.TEX.Height };
		lpSprite->SetTransform(&tmp);
		lpSprite->Draw(OK.TEX.Tex, &rcH, &D3DXVECTOR3((float)OK.TEX.Width / 2.0f, (float)OK.TEX.Height / 2.0f, 0.0f), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));//
	//}
	//else {
	//	RECT rcH = { 0,0, Stage.TEX2.Width, Stage.TEX2.Height };
	//	lpSprite->SetTransform(&tmp);
	//	lpSprite->Draw(Stage.TEX2.Tex, &rcH, &D3DXVECTOR3((float)Stage.TEX2.Width / 2.0f, (float)Stage.TEX2.Height / 2.0f, 0.0f), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));//
	//}
}

bool C_OK::Touch(void)
{
	if (OK.Base.DrawFlg != true)return false;
	//�^�b�`�m�F
	if (judg.PlaneCri(judg.SetMatP(wind.Base.Pos), wind.Base.ScaPos, wind.TEX.Width, wind.TEX.Height) == true)return true;

	return false;
}

void C_OK::InitOK(void)
{
	//�摜�̃��[�h
	OK.TEX = { NULL,163,81,NULL,NULL,NULL };
	OK.TEX.Tex = textureManager.GetTexture("../GameFolder/Material/Texture/CharOk1.png", OK.TEX.Width, OK.TEX.Height, NULL);

	//�����̏�����
	int CharNum = 2;
	OK.Base.ScaPos = D3DXVECTOR3(50.0f*(float)CharNum / (float)OK.TEX.Width, 50.0f / (float)OK.TEX.Height, 1.0f);

	OK.Base.DrawFlg = false;
}
