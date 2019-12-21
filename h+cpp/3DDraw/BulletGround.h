#pragma once
#include"Spark.h"

class C_BulGro :public C_Spark {
public:
	C_BulGro(const D3DXMATRIX *Mat,const D3DXVECTOR3 *Pos);
	~C_BulGro();
	//������
	void InitBG(void);
	//�A�b�v�f�[�g
	bool Update(void);
	//�\��
	void Draw3D(void);
protected:

private:
	//�����̕\��
	Pol Smoke;
	float SmoUpY;
	//���T�C�h�̕\��
	Pol SmokeS[2];
	int SmokeNum;
	//�A�X�t�@���g�̌���
	XFILE AspMesh;
	BASE3D *AspMat;
	int AspNum;

	//�\���̔���
	int NowAlpha,AlphaDown;
	//�X���[�N�̊g��
	float ScaSmo;
};