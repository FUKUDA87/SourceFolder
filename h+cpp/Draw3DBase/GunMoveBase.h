#pragma once
#include<d3dx9.h>
#include"../Gun/Bullet/BulletManager.h"
#include"../Gun/GunDraw/GunBase.h"
#include"Draw3DManager/GunManager.h"

class C_GunMoveBase :public BulletManager{
public:
	C_GunMoveBase();
	~C_GunMoveBase();
	//������
	virtual void InitGun(void);
	//�ԂɌp�������ۂɃI�[�o�[���C�h
	virtual bool UpdateGun();
	virtual bool UpdateGun(float AngX,float AngY);
	virtual bool UpdateGun(const D3DXMATRIX *CamMat);

	//�e��ł�
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ);
	//�e��ł~�߂�
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ,const bool *BirthFlg);
	//�e�����Ɖ�
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ,const bool *BirthFlg, const SoundCamera *sc);
	//�e�����Ɖ���Key
	virtual bool UpdateBullet(const BULLETRAYJUDG *BRJ,const bool *KeyFlg, const bool *BirthFlg, const SoundCamera *sc);
	//�e�̈ړ�
	virtual bool UpdateBulletMove(void);

	//�\��
	void Draw3DGun();

	//�\���p�s��n��
	//virtual D3DXMATRIX GetDrawMatGun(void);

	//�e�̍s��n��
	D3DXMATRIX GetMatGun(void) {
		return gunBase->GetGMat();
	}

	//�X�^���h��Mesh�̓���ւ�
	void SetGun(int GunNo);

protected:
	D3DXMATRIX ConnectGunMat;

	GunBase *gunBase;
private:
	C_GunManager gunManager;

	XFILE GunMesh;
};