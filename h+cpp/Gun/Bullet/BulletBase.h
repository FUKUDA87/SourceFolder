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
	//�ړ���Vce�n��
	virtual D3DXVECTOR3 GetMoveVec() {
		return MoveVec;
	}
	//�ړ���Vce�̒����n��
	virtual float GetMoVecDis();
	//������
	virtual bool UpdateTime(void);
	//���CFlg�n��
	virtual bool GetRayFlg(void);
	//���CFlg�؂�ւ�
	virtual void SetRayFlg(const bool *Flg);
protected:
	Pol bul;
	D3DXMATRIX *smokeMat;
	D3DXMATRIX IdenMat;
	int GNUM;
	bool MoBuFlg;
	//�ړ��ʂ�Vec
	D3DXVECTOR3 MoveVec;
	//���Ԑ���
	int NowCount;
	//�e�̃��C����\Flg
	bool BulletRayFlg;
	float MoveSize;
};