#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"

class C_Light {
public:
	C_Light();
	C_Light(const D3DXMATRIX *WallMat);
	~C_Light();
	//������
	void Init(void);
	//�A�b�v�f�[�g
	bool Update(void);
	//�\��
	void Draw3D(void);
	//�\��
	void Draw3D(const D3DXMATRIX *Mat);
	//�ʒu�s��n��
	D3DXMATRIX GetMat(void);
protected:

private:
	Object3D2 Light;
};
