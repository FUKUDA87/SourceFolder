#include "Bullet3D.h"
#include"../../GameSource/XfileManager.h"
#include"../../GameSource/Judgment.h"

extern Judg judg;
extern XfileManager xfileManager;
extern LPDIRECT3DDEVICE9		lpD3DDevice;	// Direct3DDevice�C���^�[�t�F�C�X

void DrawMesh(XFILE *XFile);

C_Bullet3D::C_Bullet3D()
{
	Init();
}

C_Bullet3D::C_Bullet3D(const D3DXMATRIX *GunMat)
{
	Init();
	BulletMesh.Base.Mat = *GunMat;
	//x���v�Z
	judg.InitRotX(&BulletMesh.Base.Mat, &BulletMesh.Base.RotX);
	BulletMesh.Base.Mat = BulletMesh.Base.RotX*BulletMesh.Base.Mat;

}

C_Bullet3D::~C_Bullet3D()
{
}

void C_Bullet3D::Init()
{
	//���b�V���̓ǂݍ���
	xfileManager.GetXfile(&BulletMesh.Mesh, "../GameFolder/Material/XFile/Bullet1-3.x");
	//�ʒu�̏�����
	D3DXMatrixTranslation(&BulletMesh.Base.Mat, 0.0f, 0.0f, 0.0f);
	//�e�̎��Ԃ̏�����
	NowCount = 0;
	MaxCount = 1 * 60/2;
	//�g��s��̏�����
	BulletMesh.Base.ScaPos = D3DXVECTOR3(0.15f, 0.15f, 0.15f);
	judg.ScalingMat(&BulletMesh.Base.Scal, &BulletMesh.Base.ScaPos);

	IncFlg = false;

	int Big = 40, Small = -20;
	Big = Big - Small;
	yUp = 0.065f+ (float)(rand() % Big + Small) / 1000.0f;
}

bool C_Bullet3D::Update(void)
{
	NowCount += 1;
	if (NowCount > MaxCount) {
		NowCount = MaxCount;
		return false;
	}
	return true;
}

bool C_Bullet3D::Update(const D3DXVECTOR3 * MoveVec)
{
	if (IncFlg == true) {
		judg.VecMatIn(&BulletMesh.Base.Mat, *MoveVec);
	}
	else {
		IncFlg = true;
	}

	//�e�̉��ړ�
	D3DXMATRIX Tmp;
	D3DXMatrixTranslation(&Tmp, 0.07f, 0.0f, 0.0f);
	BulletMesh.Base.Mat = Tmp * BulletMesh.Base.Mat;

	//�e�̃W�����v����
	BulletMesh.Base.Mat._42 += yUp;
	yUp -= 0.01f;
	return Update();
}

void C_Bullet3D::Draw3D(void)
{
	lpD3DDevice->SetTransform(D3DTS_WORLD, &GetMat());
	DrawMesh(&BulletMesh.Mesh);
}
