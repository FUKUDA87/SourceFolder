#pragma once
#include<d3dx9.h>
#include<dsound.h>
#include"../GameSource/Struct.h"

class C_Bgm {
public:
	C_Bgm();
	~C_Bgm();
	//������
	void Init(void);
	//�A�b�v�f�[�g
	bool Update(const bool *Flg);

	bool Update(const bool *Flg,const SoundCamera *sc);

	//�X�g�b�v��
	void StopSound(void);
	//�X�^�[�g��
	void StartSound(void);
	//�`�F���WBGM
	void ChangeBgm(int Noo);

protected:
	//���̃T�E���h
	int NowSound;
private:
	//�T�E���h��
	int SoundNum;
	//�T�E���h�ϐ�
	LPDIRECTSOUNDBUFFER8 SoundB[3];
	LPDIRECTSOUND3DBUFFER8 Sound3DB[3];

	//����
	int *SoundSize;
	bool StopFlg;
};