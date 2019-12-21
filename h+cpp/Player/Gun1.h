#pragma once
#include<d3dx9.h>
#include"Stand1.h"
#include"../Gun/Bullet/BulletManager.h"
#include"../Gun/GunDraw/GunBase.h"

#ifndef Gun1_H
#define Gun1_H

class Gun1 :public Stand1,public BulletManager{
public:
	void Init();
	Gun1();
	~Gun1();
	virtual bool GUpdate(float AngX, float AngY);
	virtual bool GUpdate(const D3DXMATRIX *CamMat);
	virtual bool GUpdate(void);
	//�e��ł�
	virtual bool GUpdateB(void);
	//�e��ł~�߂�
	virtual bool GUpdateB(const bool *BirthFlg);
	//�e�����Ɖ�
	virtual bool GUpdateB(const bool *BirthFlg,const SoundCamera *sc);
	//�e�����Ɖ���Key
	virtual bool GUpdateB(const bool *KeyFlg, const bool *BirthFlg, const SoundCamera *sc);
	//�e�̈ړ�
	virtual bool GUpdateBEnd(void);
	bool MoveUpdate(std::vector<BillBase*>ground);
	bool SuperUpdate(float AngX, float AngY) ;
	bool SetParts(float AngX, float AngY);
	bool SuperUpdate(const D3DXMATRIX *CamMat);
	bool SetParts(const D3DXMATRIX *CamMat);
	void GDraw();
	void SuperDraw();
	D3DXMATRIX GetGMat();

	//�e�p�����o�[�֐�---------------------------------------------
	//�e
	void SetBPos(D3DXVECTOR3 pos, bool b);
	//D3DXMATRIX GetBulMat(int i) { return bulletM->GetBulMat(i); };
	//void SetBulDel(unsigned int *i) { return bulletM->BulDelete(i); };
	//unsigned int GetBulSiz(void) { return bulletM->GetBulSize(); };
	////Bullet�̈ړ�����
	//float GetBulletMMoveDis(unsigned int i) { return bulletM->GetBulletMoveDis(i); }
	////�e�̃��C���苖��Flg�n��
	//bool GetBulRayFlgG(const unsigned int *BNo) {
	//	return bulletM->GetBulRayFlgM(BNo);
	//}
	////�e�̃��C���苖��Flg�؂�ւ�
	//void SetBulRayFlgG(const unsigned int *BNo,const bool *Flg) {
	//	bulletM->SetBulRayFlgM(BNo, Flg);
	//}

	//-------------------------------------------------------------

	//�O�i����p�֐�-----------------------------------------------
	//�ړ��̏���n��
	QuaForMove GetQuaForMove(void);
	//�ړ��x�N�g���̒�������
	void SetQuaVecSize(float size) {
		player.Con.SpeedMulJudg = size;
	}
	//�O�i����p�̈ړ��x�N�g���n��
	D3DXVECTOR3 GetForMoveVec(int i) {
		return ForMoveVec[i];
	}
	//�O�i����p�̈ړ��x�N�g������
	void SetForMoveVec(D3DXVECTOR3 Vec,int i) {
		ForMoveVec[i] = Vec;
	}
	//�O�i����p�̈ړ���Mat�n��
	D3DXMATRIX GetForMoveEndMat(void) {
		return ForMoveEndMat;
	}
	//�O�i����p�̈ړ���Mat����
	void SetForMoveEndMat(D3DXMATRIX Mat) {
		ForMoveEndMat = Mat;
	}
protected:
	Object3D gun;
	GunBase *gunBase;
	//BulletManager *bulletM;
	bool B;
	D3DXVECTOR3 Pos;
	
	int Count;
	D3DXVECTOR3 qVec;
private:
	float x, y, z;
	D3DXVECTOR3 bVec, cVec;//�o���b�g�ړ��p
	D3DXMATRIX PlaMovMat;//player�̈ړ��O��Mat
	QuaForMove Q;//�O�i����p�N�H�[�^�j�I��
	D3DXMATRIX ForMoveEndMat;//�O�i��������Mat
	D3DXVECTOR3 ForMoveVec[3];//�ړ��O����ړ����Vec
};

#endif // !Gun1_H
