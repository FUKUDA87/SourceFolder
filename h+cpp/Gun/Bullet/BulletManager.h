#pragma once
#include<d3dx9.h>
#include"BulletBase.h"
#include"../Muz/MuzFlaBase.h"
#include<vector>
#include"Bullet3D.h"
#include"../../Key/Key.h"

#ifndef BulletManager_H
#define BulletManager_H

class BulletManager {
public:
	void InitBM();
	BulletManager();
	~BulletManager();
	virtual bool UpdateBM(D3DXVECTOR3 mVec,BulletBase* bulletBase,MuzFlaBase* muzFlaBase, const D3DXMATRIX *GunMat);
	virtual bool UpdateBM(const bool *BirthFlg, D3DXVECTOR3 mVec, BulletBase* bulletBase, MuzFlaBase* muzFlaBase, const D3DXMATRIX *GunMat);
	virtual bool UpdateBM(const bool *BirthFlg, D3DXVECTOR3 mVec, BulletBase* bulletBase, MuzFlaBase* muzFlaBase, const D3DXMATRIX *GunMat,const SoundCamera *sc);
	//�L�[�t���O�ǉ�
	virtual bool UpdateBM(const bool *KeyFlg,const bool *BirthFlg, D3DXVECTOR3 mVec, BulletBase* bulletBase, MuzFlaBase* muzFlaBase, const D3DXMATRIX *GunMat, const SoundCamera *sc);
	virtual bool UpdateBM(void);
	bool UpdateBM(D3DXMATRIX mat);
	void DrawBM();

	bool GetBulFlg(void) {
		return bulFlg;
	}

	//�o���b�gMat
	D3DXMATRIX GetBulMat(unsigned int i) {
		return bullet[i]->GetBulMat();
	}
	unsigned int GetBulSize(void) {
		return (unsigned int)bullet.size();
	}
	void BulDelete(unsigned int *i);
	//�ړ��̒����n��
	virtual float GetBulletMoveDis(unsigned int i) {
		return bullet[i]->GetMoVecDis();
	}
	//�e�̃��C���苖�n��
	virtual bool GetBulRayFlgM(const unsigned int *BNo) {
		return bullet[*BNo]->GetRayFlg();
	}
	//�e�̃��C���苖�؂�ւ�
	virtual void SetBulRayFlgM(const unsigned int *BNo,const bool *Flg) {
		bullet[*BNo]->SetRayFlg(Flg);
	}
	//�e�̒a��Flg�n��
	virtual bool GetBulBirFlgB(void) {
		return BulletBirthFlgB;
	}

protected:
	std::vector<BulletBase *>bullet;
	//��̒e
	std::vector<C_Bullet3D *>BulletOut;
	int bul1;
	int bulCnt;
	bool bulFlg;
	std::vector<MuzFlaBase*>mf;

	bool BulletBirthFlgB;
private:
	Key key;
};

#endif // !BulletManager_H
