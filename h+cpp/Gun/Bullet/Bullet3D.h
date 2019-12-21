#pragma once
#include<d3dx9.h>
#include"../../GameSource/Struct.h"

class C_Bullet3D {
public:
	C_Bullet3D();
	C_Bullet3D(const D3DXMATRIX *GunMat);
	~C_Bullet3D();
	//������
	void Init();
	//�A�b�v�f�[�g
	bool Update(void);
	bool Update(const D3DXVECTOR3 *MoveVec);
	//�\��
	void Draw3D(void);

	//�s��n��
	D3DXMATRIX GetMat(void) {
		return BulletMesh.Base.Scal*BulletMesh.Base.Mat;
	}
protected:
private:
	//�e�̃��b�V��
	Object3D BulletMesh;
	//���Ԃō폜
	int NowCount, MaxCount;
	//�ŏ�����MoveVec�𑫂��Ȃ�Flg
	bool IncFlg;
	//yUp
	float yUp;
};