#pragma once
#include"../Draw3DBase/Car.h"
#include"../2DDraw/HpD.h"

class C_PlayerBase :public C_Car {
public:
	C_PlayerBase();
	~C_PlayerBase();
	//������
	void InitPlayer(void);
	//�A�b�v�f�[�g
	virtual bool UpdatePlayer(void);
	//�p���̃A�b�v�f�[�g
	virtual bool UpdateAll(void);
	virtual bool UpdateAll(const D3DXMATRIX *CamMat);
	virtual bool UpdateEndAll(void);
	virtual bool UpdateDeadAll(void);

	//�p���̕\��
	virtual void Draw3DAll(void);
	virtual void Draw2DAll(void);

	float GetRadF(void) {
		return RadField;
	}
	void SetRadF(float rad) {
		RadField = rad;
	}

	//�J�[�u��Ang����
	void SetRodAngY(float Inc, bool KeyFlg);
	//CurEnd
	void SetCurRotMat(void);

	//�e�̏����ύX
	//�e�����Ɖ���Key
	bool UpdateBulPla(const bool *KeyFlg, const bool *BirthFlg, const SoundCamera *sc);

protected:

private:
	HpD *hp;
	FILE* fp;
	//�n�ʂ̕\���͈�
	float RadField;
	//�J�[�u�p�x
	float CurAng;
	D3DXMATRIX CurRotMatY;

};