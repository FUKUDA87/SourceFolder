#pragma once
#include<d3dx9.h>
#include"ground.h"
#include"../GameSource/Struct.h"
#include"../3DDraw/Light3D.h"
#include<vector>

const int WNum = 2;
class Wall :public C_Ground {
public:
	void InitW() ;
	Wall() ;
	Wall(int i);
	Wall(D3DXMATRIX Mat3, D3DXMATRIX Mat4, int gType, float Ang, float Length, bool LengthAuto);
	~Wall();
	bool WaUpdate();
	void WaDraw();
	//Light�̏�����
	void InitLight(const int *wNum);
	//�����O�A�E���P
	D3DXMATRIX GetWaMat(int i) {
		return Wall3D[i].Base.Mat;
	}

	//�\���̃|���S�����キ�������
	void SetDoawRadFlg(const bool *Flg) {
		DrawRadFlg=*Flg;
	}

	void SuperUpdate();
	void SuperDraw();
	//�ǂ̃R���W�������f���n��
	LPD3DXMESH GetColModWall(const bool *LeftFlg);
	//��3D�̍s��n��
	D3DXMATRIX GetWaMat(const bool *LeftFlg);
	//��3D�̍s��n��(�g�唲��)
	D3DXMATRIX GetWaMat(const bool *LeftFlg,int i);

	//�O���̕\�����n��
	unsigned int GetLightNum(void) {
		return light.size();
	}

protected:

private:
	//�\���p��Flg
	bool WallDrawFlg;
	//��3D�p
	Object3D2 Wall3D[2];
	//�O��3D�p
	std::vector<C_Light *>light;

	XFILE Wall3DS;
	bool DrawRadFlg;

	//���C�g---------------------------------
	//�Е������\��
	void InitLightOne(const int *wNum);
	//�T�C�h�o��
	void InitLightW(const int *wNum);
};