#pragma once
#include<d3dx9.h>
#include"../../GameSource/TextureManager.h"
#include"../../GameSource/Judgment.h"
#include"../../GameSource/Struct.h"

extern Judg judg;
extern TextureManager textureManager;
extern LPDIRECT3DDEVICE9 lpD3DDevice;

#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

class BulletBase {
public:
	virtual void Init();
	BulletBase();
	~BulletBase() {};
	virtual void Draw3D() {};
	virtual bool Update() { return true; };
	virtual bool UpdateMove(D3DXVECTOR3 bVec) { return true; }
	D3DXMATRIX GetBulMat(void) {
		return bul.Base.Mat;
	}
	//移動のVce渡し
	virtual D3DXVECTOR3 GetMoveVec() {
		return MoveVec;
	}
	//移動のVceの長さ渡し
	virtual float GetMoVecDis();
	//時限式
	virtual bool UpdateTime(void);
	//レイFlg渡し
	virtual bool GetRayFlg(void);
	//レイFlg切り替え
	virtual void SetRayFlg(const bool *Flg);
protected:
	Pol bul;
	D3DXMATRIX *smokeMat;
	D3DXMATRIX IdenMat;
	int GNUM;
	bool MoBuFlg;
	//移動量のVec
	D3DXVECTOR3 MoveVec;
	//時間制限
	int NowCount;
	//弾のレイ判定可能Flg
	bool BulletRayFlg;
	float MoveSize;
};