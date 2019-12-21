#pragma once
#include<d3dx9.h>
#include"../Gun/Bullet/EBulletManager.h"
#include"../Gun/GunDraw/GunBase.h"
#include"Draw3DManager/GunManager.h"
#include"../Gun/GunDraw/GunEA.h"
#include"../Move/GunMove/GunLockonA.h"


class C_GunMoveBaseE{
public:
	C_GunMoveBaseE();
	~C_GunMoveBaseE();
	//������
	void InitGun(void);
	//�e�̉�]������
	void InitGunMove(void);

	//�e�̃A�b�v�f�[�g
	virtual bool UpdateGun(void);

	//�e�̍s��n��
	D3DXMATRIX GetGunMatB(void){
		return gunEA->GetGMat();
	}
	//�e�̏��n��
	GUNAI GetGunAi(void) {
		return gun;
	}

	//���C����̃J�E���g������
	void CountRay(const bool *JudgFlg);
	//
	
protected:
	//SetMat
	void SetGunMatT(const D3DXMATRIX *Mat);

	GunEA *gunEA;

	GUNAI gun;

	C_GunMove* GunMove;
private:
	C_GunManager gunManager;

	Judg judgg;

};