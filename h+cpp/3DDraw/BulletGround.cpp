#include "BulletGround.h"
#include"../GameSource/TextureManager.h"
#include"../GameSource/Judgment.h"
#include"../GameSource/InvBi.h"
#include"../GameSource/XfileManager.h"

extern XfileManager xfileManager;
extern Inv inv;

extern Judg judg;
extern LPDIRECT3DDEVICE9		lpD3DDevice;
extern TextureManager textureManager;

#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
void DrawMesh(XFILE *XFile);

C_BulGro::C_BulGro(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos):C_Spark(Mat,Pos)
{
	InitBG();
	//�ʒu�̏�����
	Smoke.Base.Pos = *Pos;

	for (int s = 0; s < SmokeNum; s++) {
		SmokeS[s].Base.Pos = *Pos;
	}

	for (int a = 0; a < AspNum; a++) {
		AspMat[a].Pos = *Pos;
	}
}

C_BulGro::~C_BulGro()
{
	if (AspMat != nullptr) {
		delete[] AspMat;
	}
}

void C_BulGro::InitBG(void)
{
	//�摜�̃��[�h
	Smoke.TEX = { NULL,32,32,NULL,NULL,NULL };
	Smoke.TEX.Tex = textureManager.GetTexture("../GameFolder/Material/Texture/Smoke02.png", Smoke.TEX.Width, Smoke.TEX.Height, NULL);

	//
	D3DXMatrixIdentity(&Smoke.Base.Mat);

	//���
	SmokeNum = 2;
	for (int s = 0; s < SmokeNum; s++) {
		SmokeS[s] = Smoke;
	}

	Smoke.Base.TraPos = D3DXVECTOR3(0.0f, 2.0f, 0.0f);

	NowCount = 4;

	//���T�C�h�̏�����
	for (int s = 0; s < SmokeNum; s++) {
		SmokeS[s].Base.TraPos = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
	}

	//�j�Ђ̏�����
	//���b�V���̃��[�h
	xfileManager.GetXfile(&AspMesh, "../GameFolder/Material/XFile/AsphaltParts2-2.x");
	//�j�Ђ̐��̏�����
	AspNum = 5;
	AspMat = new BASE3D[AspNum];
	for (int a = 0; a < AspNum; a++) {
		//�ړ������̏�����
		AspMat[a].TraPos.x = (float)(rand() % (10+10) -10) / 100.0f;
		AspMat[a].TraPos.y = (float)(rand() % 5+2) / 10.0f;
		AspMat[a].TraPos.z = (float)(rand() % (10 + 10) - 10) / 100.0f;

		//�g��s��̏�����
		AspMat[a].ScaPos = D3DXVECTOR3(0.15f, 0.15f, 0.15f);
		judg.ScalingMat(&AspMat[a].Scal, &AspMat[a].ScaPos);
	}
	
	//����̏�����
	NowAlpha = 100;
	AlphaDown = 100/3;

	SmoUpY = 0.4f;

	ScaSmo = 1.0f;
}

bool C_BulGro::Update(void)
{
	return CountUpdate();
}

void C_BulGro::Draw3D(void)
{
	//���Q�̂��߂̉���Vec
	D3DXVECTOR3 sVec;

	//�����̕\��
	if (1) {
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		lpD3DDevice->SetFVF(FVF_VERTEX);//�o�O
		for (int c = 0; c < 4; c++) {
			Smoke.v[c].Color = D3DCOLOR_ARGB(NowAlpha, 100, 100, 100);
		}
		lpD3DDevice->SetTexture(0, Smoke.TEX.Tex);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &Smoke.Base.Mat);
		//�r���{�[�h
		D3DXVECTOR3 vec, oPos, nPos;
		oPos = Smoke.Base.Pos;
		nPos = Smoke.Base.Pos + Smoke.Base.TraPos*SmoUpY;
		vec = judg.Billboard(oPos, nPos, inv.GetcaPos(), 0.3f);
		sVec = vec;
		Smoke.v[0].Pos = nPos - vec;
		Smoke.v[1].Pos = nPos + vec;
		Smoke.v[2].Pos = oPos + vec * ScaSmo;
		Smoke.v[3].Pos = oPos - vec * ScaSmo;
		Smoke.v[0].Tex = D3DXVECTOR2(0.0f, 0.0f);
		Smoke.v[1].Tex = D3DXVECTOR2(1.0f, 0.0f);
		Smoke.v[2].Tex = D3DXVECTOR2(1.0f, 1.0f);
		Smoke.v[3].Tex = D3DXVECTOR2(0.0f, 1.0f);
		lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Smoke.v, sizeof(VERTEX));//2�̓|���S����
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	}

	//���T�C�h�̕\��
	if (1) {
		lpD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		lpD3DDevice->SetFVF(FVF_VERTEX);//�o�O
		D3DXVec3Normalize(&sVec, &sVec);
		sVec *= 0.7f;
		sVec *= SmoUpY;
		for (int s = 0; s < SmokeNum; s++) {

			for (int c = 0; c < 4; c++) {
				SmokeS[s].v[c].Color = D3DCOLOR_ARGB(NowAlpha-50, 100, 100, 100);
			}
			lpD3DDevice->SetTexture(0, SmokeS[s].TEX.Tex);
			lpD3DDevice->SetTransform(D3DTS_WORLD, &SmokeS[s].Base.Mat);
			//�r���{�[�h
			D3DXVECTOR3 vec, oPos, nPos;
			oPos = SmokeS[s].Base.Pos;
			nPos = oPos;
			nPos.y += SmokeS[s].Base.TraPos.y*0.5f;
			if (s == 0) {
				vec = sVec;
				SmokeS[s].v[1].Pos = nPos;
				SmokeS[s].v[2].Pos = oPos;
				SmokeS[s].v[0].Pos = SmokeS[s].v[3].Pos = oPos - vec;
				SmokeS[s].v[0].Pos.y += SmokeS[s].Base.TraPos.y * SmoUpY;
			}
			else {
				vec = -sVec;
				SmokeS[s].v[1].Pos = nPos;
				SmokeS[s].v[2].Pos = oPos;
				SmokeS[s].v[0].Pos = SmokeS[s].v[3].Pos = oPos - vec;
				SmokeS[s].v[0].Pos.y += SmokeS[s].Base.TraPos.y * SmoUpY;
			}

			SmokeS[s].v[0].Tex = D3DXVECTOR2(0.0f, 0.0f);
			SmokeS[s].v[1].Tex = D3DXVECTOR2(1.0f, 0.0f);
			SmokeS[s].v[2].Tex = D3DXVECTOR2(1.0f, 1.0f);
			SmokeS[s].v[3].Tex = D3DXVECTOR2(0.0f, 1.0f);
			lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, SmokeS[s].v, sizeof(VERTEX));//2�̓|���S����
		}
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		lpD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	}
	
	//�j�Ђ̕\��
	if (1) {
		for (int a = 0; a < AspNum; a++) {
			//�ړ�����
			AspMat[a].Pos += AspMat[a].TraPos;
			AspMat[a].TraPos.y -= 0.05f;
			D3DXMatrixTranslation(&AspMat[a].Mat, AspMat[a].Pos.x, AspMat[a].Pos.y, AspMat[a].Pos.z);
			//�\������
			D3DXMATRIX Tmp;
			Tmp = AspMat[a].Scal*AspMat[a].Mat;
			lpD3DDevice->SetTransform(D3DTS_WORLD, &Tmp);
			DrawMesh(&AspMesh);
		}

	}

	//���ꏈ��
	NowAlpha += AlphaDown;

	SmoUpY += 0.3f;
	if (SmoUpY > 1.0f)SmoUpY = 1.0f;
}
