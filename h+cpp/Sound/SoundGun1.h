#pragma once
#include<d3dx9.h>
#include<dsound.h>
#include"../GameSource/Struct.h"


class C_SoundGun {
public:
	C_SoundGun();
	~C_SoundGun();
	//������
	void Init(void);
	//�A�b�v�f�[�g
	virtual bool Update(const D3DXVECTOR3 *SoundPos,const D3DXVECTOR3 *CamPos, const D3DXVECTOR3 *CamLook, const D3DXVECTOR3 *CamHead);
	bool Update(const bool *Flg);
	//�`�F���WBGM
	void ChangeBgm(int Noo);
	//��~
	void StopSound(const int *No);
protected:
	//�T�E���h��
	int SoundNum;
	//���̃T�E���h
	int NowSound;
	//�T�E���h�ϐ�
	SoundCol *soundCol;
	//����
	int SoundSize;
private:
};