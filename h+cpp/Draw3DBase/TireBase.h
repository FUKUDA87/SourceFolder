#pragma once
#include"../GameSource/Struct.h"
#include"Draw3DManager/TireMeshManager.h"
#include"../GameSource/Judgment.h"

extern Judg judg;

class C_TireBase {
public:
	C_TireBase();
	//vector�^
	C_TireBase(const BASE3D *TireBase);
	~C_TireBase();
	//������
	void InitTire(void);
	//�A�b�v�f�[�g
	virtual bool UpdateTire(void);
	virtual bool UpdateTire(const D3DXMATRIX *CarMat);
	//�\��
	virtual void Draw3DTire(void);

	//�\���p�s��n��
	virtual D3DXMATRIX GetDrawMatTire(void) {
		return judg.GetDrawMat(&Tire.Mat, &Tire.Scal, &Tire.ScaPos);
	}
	//���b�V���̐؂�ւ�
	void SetMeshTire(int MeshNo);

	//��]Flg����
	void SetMoveTireFlg(const bool *Flg) {
		MoveTireFlg = *Flg;
	}

protected:
	BASE3D Tire;
private:
	XFILE TireMesh;

	C_TireMeshManager tireMeshManager;

	//��]�̗L��Flg
	bool MoveTireFlg;
};