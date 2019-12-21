#pragma once
#include"../GameSource/Judgment.h"
#include"../GameSource/Struct.h"
#include<d3dx9.h>
#include"../2DDraw/Num2DA.h"

class C_CarSelect {
public:
	C_CarSelect(const D3DXVECTOR3* PosA, const D3DXVECTOR3* ScalA, const D3DXVECTOR3* ArrScal, const D3DXVECTOR3* ArrTransPos,const D3DXVECTOR3 *ScalNum);
	~C_CarSelect();
	//�p���\��
	virtual void Draw2DAll(void);
	//�摜�̃^�b�`
	int Touch(void);
	//�A�b�v�f�[�g
	bool UpdateNo(const int *MeshNo);
	//No�n��
	int GetNo(void) {
		return No;
	}
protected:

	//������
	void InitCS(void);
	//�\��
	void Draw2DCS(void);


	//�摜�\����
	CHARA2D Back;
	BASE2D *Arr;
	TEXTURE ArrTex;

	Judg judg;

	//���̕\���p�N���X
	C_Num2DA *Num;
	//���b�V���̔ԍ�
	int No;
private:
	//���
	int ArrNum;
};