#pragma once
#include"PlayerBase.h"
#include"../GameSource/PartsTrans.h"


class C_PlayerA :public C_PlayerBase {
public:
	C_PlayerA();
	C_PlayerA(const BODYDATA *Data);
	~C_PlayerA();

	//�Ԃ̃{�f�B�̍X�V
	void SetBody(const BODYDATA *Data);
protected:
	//������
	virtual void InitPlayerA(void);

	



	void SaveCar(void);
private:
	//�p�[�c�̏��������[�h����������肵�ăp�[�c���\��
	virtual void InitPlayerAB(void);
};