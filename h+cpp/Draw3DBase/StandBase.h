#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include"Draw3DManager/StandMeshManager.h"

class C_StandBase{
public:
	C_StandBase();
	~C_StandBase();
	//������
	virtual void InitStand(void);
	//�ԂɌp�������ۂɃI�[�o�[���C�h
	virtual bool UpdateSta();
	void Draw3DSta();

	//�\���p�s��n��
	virtual D3DXMATRIX GetDrawMatSta(void);

	//�X�^���h��Mesh�̓���ւ�
	void SetMeshSta(int MeshNo);

protected:
	BASE3D Stand;
private:
	XFILE StandMesh;
	C_StandMeshManager standMeshManager;
	float x, y, z;
};

//class Stand1 :public C_Tire {
//private:
//	XFILE standMesh;
//	float x, y, z;
//protected:
//	D3DXMATRIX standMat;
//public:
//	Stand1();
//	~Stand1();
//	virtual bool SUpdate();
//	void SDraw();
//};
