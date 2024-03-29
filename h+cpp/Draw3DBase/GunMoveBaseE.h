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
	//初期化
	void InitGun(void);
	//銃の回転初期化
	void InitGunMove(void);

	//銃のアップデート
	virtual bool UpdateGun(void);

	//銃の行列渡し
	D3DXMATRIX GetGunMatB(void){
		return gunEA->GetGMat();
	}
	//銃の情報渡し
	GUNAI GetGunAi(void) {
		return gun;
	}

	//レイ判定のカウントをする
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