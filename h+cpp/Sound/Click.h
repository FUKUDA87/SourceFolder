#pragma once
#include"../GameSource/Struct.h"

class C_ClickSound {
public:
	C_ClickSound();
	~C_ClickSound();
	//������
	void InitCli(void);
	//�A�b�v�f�[�g
	bool UpdateCli(const bool *Flg);
	//��~
	void StopSoundCli(const int *No);
private:
	//�T�E���h��
	int SoundNum;
	//���̃T�E���h
	int NowSound;
	//�T�E���h�ϐ�
	SoundCol *soundCol;
	//����
	int SoundSize;
};