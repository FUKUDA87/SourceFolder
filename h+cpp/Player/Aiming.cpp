#include"Aiming.h"
#include"../GameSource/TextureManager.h"

extern TextureManager textureManager;
extern LPDIRECT3DDEVICE9 lpD3DDevice;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g

#define	SCRW		1280	// �E�B���h�E���iWidth
#define	SCRH		720		// �E�B���h�E�����iHeight

void Aiming::Init()
{
	//�摜�̃��[�h
	aim.TEX = { NULL,100,100,0,0,0 };
	aim.TEX.Tex= textureManager.GetTexture
	("../GameFolder/Material/Texture/Aiming1.png", aim.TEX.Width, aim.TEX.Height
		, D3DCOLOR_XRGB(aim.TEX.a, aim.TEX.g, aim.TEX.b));
	//������
	D3DXMatrixTranslation(&aim.Base.Mat, (float)(SCRW / 2 - aim.TEX.Width / 2), (float)(SCRH / 2 - aim.TEX.Height / 2), NULL);
	aim.Base.ScaPos = D3DXVECTOR3(0.2f, 0.2f,0.0f);
	D3DXMatrixScaling(&aim.Base.Scal, aim.Base.ScaPos.x,aim.Base.ScaPos.y, NULL);
	aim.Base.Flg = true;

	//���b�N�I����
	//�摜�̃��[�h
	aimR.TEX = { NULL,400,400,0,0,0 };
	aimR.TEX.Tex = textureManager.GetTexture
	("../GameFolder/Material/Texture/Aiming3.png", aimR.TEX.Width, aimR.TEX.Height
		, D3DCOLOR_XRGB(aimR.TEX.a, aimR.TEX.g, aimR.TEX.b));
	//������
	D3DXMatrixTranslation(&aimR.Base.Mat, (float)(SCRW / 2 - aimR.TEX.Width / 2), (float)(SCRH / 2 - aimR.TEX.Height / 2), NULL);
	aimR.Base.ScaPos = D3DXVECTOR3(0.2f, 0.2f, 0.0f);
	D3DXMatrixScaling(&aimR.Base.Scal, aimR.Base.ScaPos.x, aimR.Base.ScaPos.y, NULL);
	aimR.Base.Flg = false;
}

Aiming::Aiming() {
	Init();
}
Aiming::~Aiming() {

}
void Aiming::Draw(void) {
	if (aim.Base.Flg == true) {
		RECT rcAim = { 0,0,aim.TEX.Width, aim.TEX.Height };
		D3DXMatrixTranslation(&aim.Base.Mat, SCRW / 2, SCRH / 2, NULL);
		D3DXMATRIX tmp;
		tmp = aim.Base.Scal * aim.Base.Mat;
		lpSprite->SetTransform(&tmp);
		lpSprite->Draw(aim.TEX.Tex, &rcAim, &D3DXVECTOR3((float)(aim.TEX.Width / 2), (float)(aim.TEX.Height / 2), 0), NULL, D3DCOLOR_ARGB(100, 255, 255, 255));
	}
	else {
		if (aimR.Base.Flg == true) {
			RECT rcAim = { 0,0,aimR.TEX.Width, aimR.TEX.Height };
			D3DXMatrixTranslation(&aimR.Base.Mat, SCRW / 2, SCRH / 2, NULL);
			D3DXMATRIX tmp;
			tmp = aimR.Base.Scal * aimR.Base.Mat;
			lpSprite->SetTransform(&tmp);
			lpSprite->Draw(aimR.TEX.Tex, &rcAim, &D3DXVECTOR3((float)(aimR.TEX.Width / 2), (float)(aimR.TEX.Height / 2), 0), NULL, D3DCOLOR_ARGB(100, 255, 255, 255));
		}
	}
}

void Aiming::ChaFlg(void)
{
	if ((aim.Base.Flg == true) && (aimR.Base.Flg == false)) {
		aim.Base.Flg = false;
		aimR.Base.Flg = true;
	}
}

void Aiming::ResFlg(void)
{
	aim.Base.Flg = true;
	aimR.Base.Flg = false;
}
