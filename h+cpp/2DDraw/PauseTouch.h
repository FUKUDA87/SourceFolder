#pragma once
#include"NextTouch.h"

class C_PauseTouch :public C_NextTouch {
public:
	C_PauseTouch(const D3DXVECTOR3 *WindPos, const D3DXVECTOR3 *WindScal, const D3DXVECTOR3 *CharScal,const float *yUp,const int *Mode);
	~C_PauseTouch();

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
	//�\��
	void Draw2DPause(void);
	//�\��
	void Draw2DStage(void);

	//�^�b�`���ɉ摜�̕ω�
	int TouchNow2(void);

protected:

private:
	//�|�[�Y�ɖ߂�-------------------
	CHARA2D2 Pause;
	//������
	void InitPause(void);
	
	//�A�b�v�f�[�g
	bool UpdatePause(void);

	//�X�e�[�W�I���ɖ߂�---------------
	CHARA2D2 Stage;
	//������
	void InitStage(void);
	
	//�A�b�v�f�[�g
	bool UpdateStage(void);
};