#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"

class C_Spark {
public:
	//Mat=�����p�x,Pos�����W
	C_Spark(const D3DXMATRIX *Mat,const D3DXVECTOR3 *Pos);
	~C_Spark();
	//������
	void Init();
	//�A�b�v�f�[�g
	virtual bool Update(void);
	//Vec=�ԑ̂̈ړ���
	bool Update(const D3DXVECTOR3 *CarMoveVec);
	//�p�����܂߂��A�b�v�f�[�g
	virtual bool UpdateSuper(void);
	//������
	bool CountUpdate(void);
	//�\��
	virtual void Draw3D(void);
	//�p�����܂߂�Draw3D
	virtual void Draw3DSuper(void);
protected:
	//�ŏ���Vec�𑫂��Ȃ�Flg
	bool CarMoveFlg;
	//�|���S���\���p�\����
	Pol spark;
	//�|���S����
	int PNum;
	//�W�����v�ړ��̕ϐ�
	float yUp, yDown;
	//�������Ɉړ�������
	float zDown;
	//�\���p�s��
	D3DXMATRIX IdenMat;
	//���Ԃō폜
	int NowCount;
	//�|���S���T�C�Y
	float PolSize;
private:
};