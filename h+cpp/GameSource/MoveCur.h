#pragma once
#include<d3dx9.h>
#include"Struct.h"

class MoveCur {
public:
	//���[���ړ�
	void RailC(D3DXMATRIX *mat, float f);
	//�J�[�u
	void Curve(CHARA3D *chara);
};