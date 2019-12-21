#pragma once
#include"ClearTouch.h"

class C_OverTouch :public C_ClearTouch {
public:
	C_OverTouch(const D3DXVECTOR3 *WindPos, const D3DXVECTOR3 *WindScal, const D3DXVECTOR3 *CharScal, const float *yUp, const int *Mode);
	~C_OverTouch();

	//�\��
	void Draw2DAll(void);
	//�^�b�`�̊m�F
	int TouchNow(void);

	//�\��
	void Draw2DRetry(void);

	//�^�b�`���ɉ摜�̕ω�
	int TouchNow2(void);

protected:

private:
	//�|�[�Y�ɖ߂�-------------------
	CHARA2D2 Retry;
	//������
	void InitRetry(void);

	//�A�b�v�f�[�g
	bool UpdateRetry(void);
};