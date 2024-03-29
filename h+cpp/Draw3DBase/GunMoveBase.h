#pragma once
#include<d3dx9.h>
#include"../Gun/Bullet/BulletManager.h"
#include"../Gun/GunDraw/GunBase.h"
#include"Draw3DManager/GunManager.h"

class C_GunMoveBase :public BulletManager{
public:
	C_GunMoveBase();
	~C_GunMoveBase();
	//初期化
	virtual void InitGun(void);
	//車に継承した際にオーバーライド
	virtual bool UpdateGun();
	virtual bool UpdateGun(float AngX,float AngY);
	virtual bool UpdateGun(const D3DXMATRIX *CamMat);

	//弾を打つ
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ);
	//弾を打つ止める
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ,const bool *BirthFlg);
	//弾を撃つと音
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ,const bool *BirthFlg, const SoundCamera *sc);
	//弾を撃つと音とKey
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ,const bool *KeyFlg, const bool *BirthFlg, const SoundCamera *sc);
	//弾の移動
	virtual bool UpdateBulletMove(void);

	//表示
	void Draw3DGun();

	//表示用行列渡し
	//virtual D3DXMATRIX GetDrawMatGun(void);

	//銃の行列渡し
	D3DXMATRIX GetMatGun(void) {
		return gunBase->GetGMat();
	}

	//スタンドのMeshの入れ替え
	void SetGun(int GunNo);

protected:
	D3DXMATRIX ConnectGunMat;

	GunBase *gunBase;
private:
	C_GunManager gunManager;

	XFILE GunMesh;
};