#include "TitleTex.h"
#include"../GameSource/TextureManager.h"

extern TextureManager textureManager;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g


TitleTex::TitleTex()
{
	title[0].TEX = { NULL,368,199,NULL,NULL };
	title[0].TEX.Tex = textureManager.GetTexture("../GameFolder/Material/Texture/Title1.png",title[0].TEX.Width , title[0].TEX.Height, NULL);
	D3DXMatrixScaling(&title[0].Base.Scal, 1.5f, 1.5f, 1);
	title[0].Base.Pos = D3DXVECTOR3(1280 / 2+10, 160, NULL);
}
TitleTex::~TitleTex()
{
}

void TitleTex::Draw()
{
	//�^�C�g���摜
	for (int i = 0; i < 1/*TITLE_NUM*/; i++) {
		RECT rcAim = { 0,0,500,300 };
		D3DXMatrixTranslation(&title[i].Base.Mat, title[i].Base.Pos.x, title[i].Base.Pos.y, NULL);
		D3DXMATRIX tmp;
		tmp = title[i].Base.Scal*title[i].Base.Mat;
		lpSprite->SetTransform(&tmp);
		lpSprite->Draw(title[i].TEX.Tex, &rcAim, &D3DXVECTOR3((float)(title[0].TEX.Width/2), (float)(title[0].TEX.Height/2), 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
}
