#pragma once
#include<d3dx9.h>
#include"Fade.h"

class Pause :public Fade {
public:
	Pause();
	~Pause() {};
	//�\��
	void Draw2DPau();
	//�A�b�v�f�[�g
	bool UpdatePau();
	//�\���̗L��Flg����
	void SetDFlg(bool Flg) {
		pau.Base.DrawFlg = Flg;
	}
	//�\���̗L��Flg�n��
	bool GetDFlg(void) {
		return pau.Base.DrawFlg;
	}

	//�X�e�[�W�Z�[�u�̗L��Flg����
	void SetStaSavFlg(bool Flg) {
		StageSaveFlg = Flg;
	}
	//�X�e�[�W�Z�[�u�̗L��Flg�n��
	bool GetStaSavFlg(void) {
		return StageSaveFlg;
	}
protected:
	CHARA2D pau;
private:
	//�X�e�[�W�̏��L�^�pFlg
	bool StageSaveFlg;
};