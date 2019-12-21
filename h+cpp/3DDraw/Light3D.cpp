#include "Light3D.h"
#include"../GameSource/XfileManager.h"
#include"../GameSource/Judgment.h"

extern Judg judg;
extern XfileManager xfileManager;
extern LPDIRECT3DDEVICE9		lpD3DDevice;	// Direct3DDevice�C���^�[�t�F�C�X


void DrawMesh(XFILE *XFile);

C_Light::C_Light()
{
	Init();
}

C_Light::C_Light(const D3DXMATRIX * WallMat)
{
	Init();
	//�ǂ̈ʒu�ɒu��
	D3DXMatrixRotationY(&Light.Base.RotY, D3DXToRadian(90.0f));
	Light.Base.Mat = Light.Base.RotY*Light.Base.Trans* *WallMat;
}

C_Light::~C_Light()
{
}

void C_Light::Init(void)
{
	//���b�V���̃��[�h
	xfileManager.GetXfile(&Light.Mesh, "../GameFolder/Material/XFile/LightWay2.x");
	//�ʒu�̏�����
	D3DXMatrixTranslation(&Light.Base.Mat, 0.0f, 0.0f, 0.0f);
	//�g��s��̏�����
	Light.Base.ScaPos = D3DXVECTOR3(5.0f, 5.0f, 5.0f);
	judg.ScalingMat(&Light.Base.Scal, &Light.Base.ScaPos);
	//�ړ��s��̏�����
	D3DXMatrixTranslation(&Light.Base.Trans, -1.0f, 5.0f, 0.0f);
}

bool C_Light::Update(void)
{
	return false;
}

void C_Light::Draw3D(void)
{
	lpD3DDevice->SetTransform(D3DTS_WORLD, &GetMat());
	DrawMesh(&Light.Mesh);
}

void C_Light::Draw3D(const D3DXMATRIX * Mat)
{
	Light.Base.Mat = Light.Base.RotY*Light.Base.Trans* *Mat;
	lpD3DDevice->SetTransform(D3DTS_WORLD, &GetMat());
	DrawMesh(&Light.Mesh);
}

D3DXMATRIX C_Light::GetMat(void)
{
	D3DXMATRIX Tmp;
	Tmp = Light.Base.Scal*Light.Base.Mat;
	return Tmp;
}
