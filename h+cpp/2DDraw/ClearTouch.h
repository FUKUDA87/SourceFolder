#pragma once
#include"NextTouch.h"

class C_ClearTouch :public C_NextTouch {
public:
	C_ClearTouch(const D3DXVECTOR3 *WindPos, const D3DXVECTOR3 *WindScal, const D3DXVECTOR3 *CharScal, const float *yUp,const int *Mode);
	~C_ClearTouch();

	//�A�b�v�f�[�g
	bool UpdateAll(void);
	//�\��
	void Draw2DAll(void);
	//�^�b�`�̊m�F
	int TouchNow(void);

	//�\�����n��
	int GetDrawNum(void) {
		return DrawNum;
	}

	//�^�b�`���ɉ摜�̕ω�
	int TouchNow2(void);

protected:

	//�|�[�Y�ɖ߂�-------------------
	CHARA2D2 Title;
	//������
	void InitTitle(void);

	//�A�b�v�f�[�g
	bool UpdateTitle(void);

	//�\��
	void Draw2DTitle(void);

	//�X�e�[�W�I���ɖ߂�---------------
	CHARA2D2 Stage;
	//������
	void InitStage(void);

	//�A�b�v�f�[�g
	bool UpdateStage(void);

	//�\��
	void Draw2DStage(void);

private:
};