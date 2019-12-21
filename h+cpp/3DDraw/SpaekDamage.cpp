#include "SpaekDamage.h"
#include"../GameSource/TextureManager.h"
#include"../GameSource/Judgment.h"
#include"../GameSource/InvBi.h"

extern Inv inv;


extern Judg judg;
extern TextureManager textureManager;

#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
C_SparkDamage::C_SparkDamage(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos):C_Spark(Mat,Pos)
{

}

C_SparkDamage::C_SparkDamage(const D3DXMATRIX * Mat, const D3DXVECTOR3 * Pos, const int * SparkFlg,const float *Ang) : C_Spark(Mat, Pos)
{
	DrawSDFlg = true;
	UpdateFlg = false;
	spark.Base.Mat = *Mat;
	judg.SetMatP(&spark.Base.Mat, *Pos);

	//�|���S���T�C�Y�̏�����
	PolSize = 0.03f;
	PolSizeSD = 0.025f;

	//�Փ˕��̔���
	SparkJudgGround(Mat, Pos, SparkFlg);
	SparkJudgWall(Mat, Pos, SparkFlg);
	SparkJudgCar(Mat, Pos, SparkFlg,Ang);

	//�X�p�[�N�̏�����
	//�t���b�V��
	Flash.TEX = { NULL,128,128,NULL,NULL,NULL };
	Flash.TEX.Tex = textureManager.GetTexture("../GameFolder/Material/Texture/MuzFla1T.png", Flash.TEX.Width, Flash.TEX.Height, NULL);
	Flash.Base.Mat = *Mat;
	judg.SetMatP(&Flash.Base.Mat, *Pos);
}

C_SparkDamage::~C_SparkDamage()
{
}

bool C_SparkDamage::UpdateSD(void)
{
	Flash.v[0].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	Flash.v[1].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	Flash.v[2].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	Flash.v[3].Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	Flash.v[0].Tex = D3DXVECTOR2(0.0f,0.0f);
	Flash.v[1].Tex = D3DXVECTOR2(1.0f,0.0f);
	Flash.v[2].Tex = D3DXVECTOR2(1.0f,1.0f);
	Flash.v[3].Tex = D3DXVECTOR2(0.0f,1.0f);
	return true;
}

bool C_SparkDamage::UpdateCar(void)
{
	spark.Base.Mat._42 += yUp;
	//��ړ��ƌ��ړ�
	judg.SetMatP(&spark.Base.Mat, judg.SetPosM(spark.Base.Mat) + spark.Base.Pos);
	//�s��̍X�V
	for (int i = (PNum - 1); i > 0; i--) {
		spark.PolMat[i] = spark.PolMat[i - 1];
	}
	//�擪�Ɉ�ԐV�����s��̑��
	spark.PolMat[0] = spark.Base.Mat;
	yUp += yDown;
	return CountUpdate();
}

bool C_SparkDamage::UpdateSuper(void)
{
	bool Flg;
	if (UpdateFlg == false) {
		Flg = Update();
	}
	else {
		Flg = UpdateCar();
	}
	return Flg;
}

void C_SparkDamage::DrawSD(void)
{
	if (DrawSDFlg == true) {
		UpdateSD();
		lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		lpD3DDevice->SetFVF(FVF_VERTEX);//�o�O
		lpD3DDevice->SetTexture(0, Flash.TEX.Tex);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &Flash.Base.Mat);
		lpD3DDevice->SetTransform(D3DTS_WORLD, &IdenMat);
		//�r���{�[�h
		D3DXVECTOR3 vec, oPos, nPos;
		D3DXMATRIX TransTmp;
		D3DXMatrixTranslation(&TransTmp, 0.0f, 1.0f*PolSizeSD, 0.0f);
		judg.SetPosM(&nPos, TransTmp*Flash.Base.Mat);
		D3DXMatrixTranslation(&TransTmp, 0.0f, -1.0f*PolSizeSD, 0.0f);
		judg.SetPosM(&oPos, TransTmp*Flash.Base.Mat);
		vec = judg.Billboard(oPos, nPos, inv.GetcaPos(), 3.0f*PolSizeSD);
		Flash.v[0].Pos = nPos - vec;
		Flash.v[1].Pos = nPos + vec;
		Flash.v[2].Pos = oPos + vec;
		Flash.v[3].Pos = oPos - vec;
		lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Flash.v, sizeof(VERTEX));//2�̓|���S����
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
		DrawSDFlg = false;
	}

}

void C_SparkDamage::Draw3DSuper(void)
{
	Draw3D();
	DrawSD();
}

void C_SparkDamage::SparkJudgGround(const D3DXMATRIX * Mat, const D3DXVECTOR3 * Pos, const int * SparkFlg)
{
	if (*SparkFlg != 0)return;
	//��]
	D3DXMATRIX RotYMat,TransMat;
	float AngY;
	AngY = (float)(rand() % 45);
	if ((rand() % 2) == 1)AngY *= -1.0f;
	D3DXMatrixRotationY(&RotYMat, D3DXToRadian(AngY));
	Flash.Base.Mat = spark.Base.Mat;
	spark.Base.Mat= RotYMat*spark.Base.Mat;
	//�����̏�����
	NowCount = 1 * 5;
}

void C_SparkDamage::SparkJudgWall(const D3DXMATRIX * Mat, const D3DXVECTOR3 * Pos, const int * SparkFlg)
{
	if (*SparkFlg != 1)return;
	PNum = 2;
	//�|���S���\���p��Mat�̏�����
	if (spark.PolMat != nullptr) {
		delete[] spark.PolMat;
	}
	spark.PolMat = new D3DXMATRIX[PNum];
	//��]
	//X��]�����߂�
	int Big = 7000, Small = -4000;
	Big = Big - Small;
	float Ang = (float)(rand() % Big + Small) / 100.0f;
	int Mul = (int)Ang;
	if (Mul <= 0)Mul = 1;
	yDown = -0.05f - 0.003f*(float)Mul;
	//�s��
	D3DXMATRIX RotYMat,TransMat,RotXMat;
	//�ǂ̖@���̕���
	D3DXMatrixRotationY(&RotYMat, D3DXToRadian(-90.0f));
	spark.Base.Mat = RotYMat * spark.Base.Mat;
	//�����ŏo��������ς���
	float AngY;
	AngY = (float)(rand() % 88);
	if ((rand() % 2) == 1)AngY *= -1.0f;
	D3DXMatrixRotationY(&RotYMat, D3DXToRadian(AngY));
	D3DXMatrixRotationX(&RotXMat, D3DXToRadian(Ang));
	spark.Base.Mat = RotXMat*RotYMat * spark.Base.Mat;

	yUp = 0.0f;
	zDown = -0.3f;

	PolSize = (float)(rand() % 3 + 3) / 100.0f;

	for (int i = 0; i <PNum; i++) {
		spark.PolMat[i] = spark.Base.Mat;
	}

	//�����̏�����
	NowCount = 1 * 5;
	DrawSDFlg = true;

}

void C_SparkDamage::SparkJudgCar(const D3DXMATRIX * Mat, const D3DXVECTOR3 * Pos, const int * SparkFlg, const float *Ang)
{
	if (*SparkFlg != 2)return;
	//DrawSDFlg = false;
	PNum = 3;
	//�|���S���\���p��Mat�̏�����
	if (spark.PolMat != nullptr) {
		delete[] spark.PolMat;
	}
	spark.PolMat = new D3DXMATRIX[PNum];
	//�����̏�����
	NowCount = 1 * 2;
	//��]�s��
	D3DXMATRIX RotZ,RotX;
	D3DXMatrixRotationZ(&RotZ, D3DXToRadian(*Ang));
	D3DXMatrixRotationX(&RotX, D3DXToRadian(30.0f));
	spark.Base.Mat = RotZ*RotX *spark.Base.Mat;

	yUp = 0.0f;
	zDown = (float)(rand()%20+10)/100.0f;
	yDown = -0.0f;

	//�x�N�g���v�Z
	D3DXVec3TransformNormal(&spark.Base.Pos, &D3DXVECTOR3(0.0f, -1.0f, 0.0f), &spark.Base.Mat);
	//spark.Base.Pos.y = 0.0f;
	D3DXVec3Normalize(&spark.Base.Pos, &spark.Base.Pos);
	spark.Base.Pos *= zDown;

	for (int i = 0; i < PNum; i++) {
		spark.PolMat[i] = spark.Base.Mat;
	}

	/*UpdateCar();
	NowCount += 1;*/

	UpdateFlg = true;
	PolSizeSD = 0.001f;

	PolSize = 0.03f;
}
