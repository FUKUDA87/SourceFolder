#include"Explosion.h"
#include"../GameSource/TextureManager.h"
#include"../Sound/BombSound1.h"

extern C_BombSound *BombSound;

extern LPDIRECT3DDEVICE9		lpD3DDevice;
extern TextureManager textureManager;

void Explo::Init()
{
	expl.TEX = { NULL,256,256,NULL,NULL,NULL };
	expl.TEX.Tex = textureManager.GetTexture("../GameFolder/Material/Texture/Smoke.png", expl.TEX.Width, expl.TEX.Height, NULL);
	cou = new Cou(0, 63, 1, false, false);
}

Explo::Explo() {
	Init();
}
Explo::Explo(D3DXMATRIX mat) {
	Init();
	expl.Base.Pos = D3DXVECTOR3(mat._41, mat._42, mat._43);
}
Explo::Explo(D3DXMATRIX mat, const SoundCamera * sc)
{
	Init();
	expl.Base.Pos = D3DXVECTOR3(mat._41, mat._42, mat._43);

	BombSound->Update(&expl.Base.Pos, &sc->CamPos, &sc->CamLook, &sc->CamHead);
}
Explo::~Explo() {
	delete cou;
}
bool Explo::ExplUpdate(float AngX,float AngY) {
	num = cou->GetNum();
	D3DXMatrixTranslation(&expl.Base.Trans, expl.Base.Pos.x, expl.Base.Pos.y, expl.Base.Pos.z);
	D3DXMatrixRotationX(&expl.Base.RotX, D3DXToRadian(AngX));
	D3DXMatrixRotationY(&expl.Base.RotY, D3DXToRadian(AngY));
	expl.Base.Mat = expl.Base.RotX * expl.Base.RotY*expl.Base.Trans;
	//���_�̐ݒ�
	D3DXVECTOR3 Pos(4.0f,4.0f,0.0f);
	expl.v[0].Pos = D3DXVECTOR3(-Pos.x, Pos.y, 0.0f);//x,y,z
	expl.v[1].Pos = D3DXVECTOR3(Pos.x, Pos.y, 0.0f);
	expl.v[2].Pos = D3DXVECTOR3(Pos.x, -Pos.y, 0.0f);
	expl.v[3].Pos = D3DXVECTOR3(-Pos.x, -Pos.y, 0.0f);

	expl.v[0].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	expl.v[1].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	expl.v[2].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	expl.v[3].Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	expl.v[0].Tex = D3DXVECTOR2(32.0f*(num % 8) / 256.0f, 32.0f*(num / 8) / 256.0f);
	expl.v[1].Tex = D3DXVECTOR2(32.0f*(num % 8 + 1) / 256.0f, 32.0f*(num / 8) / 256.0f);
	expl.v[2].Tex = D3DXVECTOR2(32.0f*(num % 8 + 1) / 256.0f, 32.0f*(num / 8 + 1) / 256.0f);
	expl.v[3].Tex = D3DXVECTOR2(32.0f*(num % 8) / 256.0f, 32.0f*(num / 8 + 1) / 256.0f);



	if (cou->CouJudge() == true) {
		return false;
	}
	else {
		cou->CouUpd();
	}
	return true;
}
bool Explo::ExplUpdate(const D3DXMATRIX * CamMat)
{
	num = cou->GetNum();
	D3DXMatrixTranslation(&expl.Base.Trans, expl.Base.Pos.x, expl.Base.Pos.y, expl.Base.Pos.z);
	//D3DXMatrixRotationX(&expl.Base.RotX, D3DXToRadian(AngX));
	//D3DXMatrixRotationY(&expl.Base.RotY, D3DXToRadian(AngY));
	expl.Base.Mat = *CamMat*expl.Base.Trans;
	//���_�̐ݒ�
	D3DXVECTOR3 Pos(4.0f, 4.0f, 0.0f);
	expl.v[0].Pos = D3DXVECTOR3(-Pos.x, Pos.y, 0.0f);//x,y,z
	expl.v[1].Pos = D3DXVECTOR3(Pos.x, Pos.y, 0.0f);
	expl.v[2].Pos = D3DXVECTOR3(Pos.x, -Pos.y, 0.0f);
	expl.v[3].Pos = D3DXVECTOR3(-Pos.x, -Pos.y, 0.0f);

	expl.v[0].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	expl.v[1].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	expl.v[2].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	expl.v[3].Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	expl.v[0].Tex = D3DXVECTOR2(32.0f*(num % 8) / 256.0f, 32.0f*(num / 8) / 256.0f);
	expl.v[1].Tex = D3DXVECTOR2(32.0f*(num % 8 + 1) / 256.0f, 32.0f*(num / 8) / 256.0f);
	expl.v[2].Tex = D3DXVECTOR2(32.0f*(num % 8 + 1) / 256.0f, 32.0f*(num / 8 + 1) / 256.0f);
	expl.v[3].Tex = D3DXVECTOR2(32.0f*(num % 8) / 256.0f, 32.0f*(num / 8 + 1) / 256.0f);

	if (cou->CouJudge() == true) {
		return false;
	}
	else {
		cou->CouUpd();
	}
	return true;
}
#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
void Explo::ExplDraw(void) {
	lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	lpD3DDevice->SetTexture(0, expl.TEX.Tex);
	lpD3DDevice->SetTransform(D3DTS_WORLD, &expl.Base.Mat);
	lpD3DDevice->SetFVF(FVF_VERTEX);//�o�O
	lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, expl.v, sizeof(VERTEX));//2�̓|���S����
	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
}