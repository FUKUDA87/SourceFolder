#pragma once
#include<d3dx9.h>

//#define TitleNo 1
//#define StageNo 2
//#define GameNo 3

class C_SceneSoundManager{
public:
	C_SceneSoundManager() {
		InitSSM();
	}
	~C_SceneSoundManager() {
		EndSSM();
	}
	//�T�E���h�̃A�b�v�f�[�g
	virtual bool UpdateSSM(void) {
		return false;
	}
protected:
	//�T�E���h�}�l�[�W���[�̊֐�
	//�T�E���h�̏�����
	virtual void InitSSM(void) {};
	//�T�E���h�̏I������
	virtual void EndSSM(void) {};
private:
	//�T�E���h�}�l�[�W���[�̕ϐ�

	//�T�E���h�̃N���X

};