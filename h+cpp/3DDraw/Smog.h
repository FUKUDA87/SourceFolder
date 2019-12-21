#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"

class C_Smog {
public:
	C_Smog(const D3DXVECTOR3 *Pos);
	~C_Smog();
	//������
	void Init();
	//�A�b�v�f�[�g
	virtual bool Update(void);
	//������
	bool CountUpdate(void);
	//�\��
	void Draw3D(void);
	virtual void Draw3D(D3DXVECTOR3 CamPos);
protected:
	Pol smog;
	//�����폜�p
	int NowCount;
	//�ړ��p
	float yUp;
	//�g��p
	float ScalSize;
private:

};