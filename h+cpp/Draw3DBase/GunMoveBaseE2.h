#pragma once
#include"GunMoveBaseE.h"
#include"../Gun/GunDraw/NewGun/GunLaser.h"
#include"../Gun/GunDraw/NewGun/EnemyGun.h"
#include<vector>

class C_GunMoveBaseE2 :public EBulletManager {
public:
	~C_GunMoveBaseE2();
	//������
	void InitSetGun(const GUNINITDATA* GunInitDataS);
	//�폜
	void DeleteGun(void);
	//�e�̕\�����n��
	unsigned int GetGunNum(void) {
		return m_Gun.size();
	}
	//�e�̏��n��
	GUNDATA GetGunData(unsigned int *No);
	//�p�[�c�̕\���s��n��
	D3DXMATRIX GetGunMat(unsigned int *No);
	//�p�[�c�̃_���[�W����
	bool SetDamageGun(const unsigned int *gNo, const int *Damage);
	//�p�[�c�̐����m�F(0�Ŏ��A�P�Ő��A�Q�͔��ʕs�\)
	int GunDeadFlg(unsigned int *gNo);

	void GetTargetPos(const D3DXVECTOR3 *Pos);

	S_ENEMYGUNDATA GetEnemyGunData(const unsigned int *gNo);

	void SetHitRayFlg(const unsigned int *gNo, const bool *Flg);

	bool UpdateBullet2(const D3DXVECTOR3 *mVec);

	void Draw3D_Laser(const D3DXVECTOR3 *CamPos);

	void GetRayHitDis(const unsigned int *gNo,const float *Dis);
protected:
	std::vector<C_GunLaser*>m_Gun;
private:

};