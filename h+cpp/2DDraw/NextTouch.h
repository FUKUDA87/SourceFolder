#pragma once
#include"Window.h"
#include"../GameSource/Judgment.h"

class C_NextTouch:public Window {
public:
	C_NextTouch();
	~C_NextTouch();
	//������
	void InitTouch();
	//�A�b�v�f�[�g
	virtual bool UpdateAll(void);
	//�\��
	virtual void Draw2DAll(void);
	//�^�b�`�̊m�F
	virtual int TouchNow(void);

	//���̃��[�h�n��
	int GetMenuMode(void) {
		return MenuMode;
	}
	
	//�^�b�`���ɉ摜�̕ω�
	virtual int TouchNow2(void);

protected:
	//�����\����
	int DrawNum;

	//���̃��[�h
	int MenuMode;

	//�֗��֐�
	Judg judg;
private:

};