#pragma once
#include"GunLaser.h"

class C_EnemyGun :public C_GunLaser {
public:
	C_EnemyGun(const int EnemyNo,const int GunNo);//��œG���x���������ė���
	//C_BulletDraw3DBase* GetBullet();
	////�p���\��
	//virtual bool Update_Gun(const D3DXMATRIX *Mat, int *NowPhase, const D3DXVECTOR3*CamPos);
protected:

private:
	int Phase;//�G�l�~�[�̏�ԁi�t�F�[�Y�j
};