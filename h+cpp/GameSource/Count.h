#pragma once
#include<d3dx9.h>

class C_Count {
public:
	C_Count(const int *Start);
	//�J�E���g�_�E��
	bool Update(void);
	//�Ԋu�̒����p
	void UpCount(void);
protected:

private:
	//�����鐔
	int CountDownNow;
	//�n�܂�̐�
	int CountStart;
	//�؂�ւ�Flg
	bool StartFlg;
	//���
	void SetNow(void);
};