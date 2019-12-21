#pragma once
#include<d3dx9.h>
#include"Struct.h"
#include"../Ground/BillBase.h"
#include<vector>
#include"Judgment.h"
#include"../Key/Key.h"
#include<math.h>

extern Key key;
extern bool FlgD;

extern D3DXMATRIX MatD;
extern Judg judg;

class Motion {
private:
	float CurSize = 0.0365f;//�x�W�F�Ȑ��̒����P�ɑ΂��Ă̒���
public:
	float CurveFloat(float A, float B, float C, float AnimeFlame);
	D3DXVECTOR3 CurvePos(D3DXMATRIX MatS, D3DXVECTOR3 PosV, D3DXMATRIX MatE, float AnimeFlame);
	//�G�x�W�F�Ȑ�
	//bool Formove(CONSTITUTION Con, D3DXMATRIX *Mat, float *Anime, std::vector<BillBase*>ground, bool *qGFlg, bool *qFlg, float *SpeB, D3DXMATRIX *StartMat, D3DXMATRIX *EndMat, D3DXVECTOR3 *WayVec, float *NowSpeed, D3DXVECTOR3 *CurVec, bool *CurFlg,float Y);
	//�����x�W�F�Ȑ�
	bool Formove(CONSTITUTION Con, D3DXMATRIX *Mat, float *Anime, std::vector<BillBase*>ground, bool *QuaInitFlg, bool *QuaMatInitFlg, float *SpeedMul,float SpeedMul2, D3DXMATRIX *StartMat, D3DXMATRIX *EndMat, D3DXVECTOR3 *WayVec, bool *CurFlg, D3DXVECTOR3 *CurVec,float BodyHeight);
	//�J�[�uMove
	bool CurveMove(D3DXMATRIX *TransMat, D3DXMATRIX StartMat, D3DXMATRIX EndMat, float *AnimeFarme, float Up);
	//player���X������
	bool CurveMove(D3DXMATRIX *TransMat, D3DXMATRIX StartMat, D3DXMATRIX RotMat, D3DXMATRIX EndMat, float *AnimeFarme, float Up, bool *Reverse);
};