#pragma once
#include"Smog.h"
#include<vector>

class C_Smoke2 :public C_Smog {
public:
	C_Smoke2(const D3DXVECTOR3 *Pos);
	~C_Smoke2();
	//������
	void InitS(void);
	//�A�b�v�f�[�g
	bool Update(const int *NowHp,const int *MaxHp,const D3DXVECTOR3 *NowPos);
	//�A�b�v�f�[�g�N�H�[�^�j�I��
	bool UpdateQua(void);
	//�\��
	void Draw3D(const D3DXVECTOR3 *CamPos);

protected:

private:
	//�ʒu�̊i�[
	D3DXVECTOR3 *SmokePos;
	//�ʒu�̐�
	int SmokeNum;
	int SmokeNumDraw;
	//�X���b�N
	std::vector<PolQuaAni*>smoke;
};