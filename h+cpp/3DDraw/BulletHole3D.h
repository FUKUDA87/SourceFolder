#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include"../GameSource/Judgment.h"

class C_BulHol3D {
public:
	C_BulHol3D(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos, int TypeNo);
	~C_BulHol3D();
	//������
	void InitHol3D(void);
	//�A�b�v�f�[�g
	bool UpdateHol3D(void);
	//�\��
	void Draw3DHol3D(void);
	//������
	bool CountUpdate(void);
protected:

private:
	Pol Hole;
	Judg judg;
	//����
	//�ǔ���
	void InitWall(int TypeNo);
	//�n�ʔ���
	void InitGround(int TypeNo);
	//����
	int NowCount;
};