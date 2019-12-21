#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"

class C_Score {
public:
	C_Score();
	~C_Score();
	//������
	void Init(void);
	//�A�b�v�f�[�g
	bool Update(void);
	//�\��
	void Draw2D(void);
	//�X�R�A�̃C���N�������g
	void ScoreUp(const int *UpNum);

protected:

private:
	//�X�R�A�����摜�E�X�R�A���摜�E�X�R�A�̃|�C���g
	CHARA2D score, snum,sPoint;
	//�X�R�A��
	int ScoreNum,ScoreNumNow;
	//�X�R�A�̏オ�艺����l
	int ScoreNumUD;
	//������̃A�j���[�V����
	float Anime, AnimeFrame;
	D3DXMATRIX StartMat, EndMat;
	int DrawCount;
	int alphaP;
};