#pragma once
#include<d3dx9.h>
#include"GunE.h"
#include"../Ground/BillBase.h"
#include<vector>
#include"../EnemyData/Base&Manager/EnemySpeed.h"

class MoveE:public GunE{
public:
	//Move�̊m�F
	void Move();
	void ChaFlg(bool *NowFlg, bool *NextFlg);
	//������
	void InitM();
	//EndFlg������
	void InitEndF();
	MoveE() { InitM(); };
	MoveE(D3DXMATRIX GroundMat, float *TransX);
	~MoveE();
	bool UpdateAI(CHARAData cd[], unsigned int NUM,std::vector<BillBase*>ground);
	//Enemy�J�[�u
	//Gun��]������
	void ResGunAng();
	//Gun��]
	D3DXMATRIX LocAMove();
	//enemy�ړ�
	D3DXMATRIX EneMove(std::vector<BillBase*>ground);
	//gun�Œ�
	D3DXMATRIX GunMove();
	//����
	bool UpdateBul(void);
	//bool SetParts(std::vector<BillBase*>ground);
	//�A�b�v�f�[�g
	bool UpdateAll(std::vector<BillBase*>ground);
	//�A�b�v�f�[�gEnd
	bool UpdateEnd();
	//�e�̈ړ�
	bool UpdateEndBullet();
	void SetPlaRayFlg(bool Flg) {
		plaJugFlg = Flg;
	}
	bool GetLaserFlg(void) {
		return laserMan->GetLFlg();
	}
	//�^�[�Q�b�g�̏�����
	void SetPlaEnd(bool Flg, D3DXVECTOR3 Speed);
	//�O�i����p�֐�-----------------------------------------------
	//�ړ��̏���n��
	QuaForMove GetQuaForMove(void);
	//�ړ��x�N�g���̒�������
	void SetQuaVecSize(float size) {
		enemy.CH.Con.SpeedMulJudg = size;
	}
	//�O�i����p�̈ړ��x�N�g���n��
	D3DXVECTOR3 GetForMoveVec(int i) {
		return ForMoveVec[i];
	}
	//�O�i����p�̈ړ��x�N�g������
	void SetForMoveVec(D3DXVECTOR3 Vec,int i) {
		ForMoveVec[i] = Vec;
	}
	//�O�i����p�̈ړ���Mat�n��
	D3DXMATRIX GetForMoveEndMat(void) {
		return ForMoveEndMat;
	}
	//�O�i����p�̈ړ���Mat����
	void SetForMoveEndMat(D3DXMATRIX Mat) {
		ForMoveEndMat = Mat;
	}
	//�U������
	bool AttaFlg(unsigned int PlaNo);

	//--------------------------------------------------------------
private:
	//Flg
	bool MoveFlg;//�����Ă��邩�ǂ���
	bool EneMovEndFlg;
	bool GunMovFlg;//�e�̈ړ�
	bool GunMovEndFlg;
	bool CurAFlg;//�Ԑ��ύX
	bool LocAFlg;//���b�N�I��
	bool LocAEndFlg;
	int CouLok;
	bool AttFlg;
	bool GunAFlg;
	bool AttAFlg;//�U������
	bool AttAEndFlg;
	int AttCount;
	bool GunRotFlg;

	int LocCouEnd;//
	int AttCouEnd;//

	bool plaJugFlg;//player�Ƀ��C���������Ă��邩�ǂ���
	int countRay;//plaRayFlg��true�̎��A�J�E���g
	D3DXMATRIX StartRotX, StartRotY, EndRotX, EndRotY;//GunA

	bool PlaEndFlg;//player�����񂾊m�F

	D3DXVECTOR3 NowGunVec;

	D3DXVECTOR3 NowMoveVec;

	//�N�H�[�^�j�I���O�i�p
	float Anime;
	D3DXMATRIX SqMat, EqMat;
	bool qFlg, qGFlg, cFlg;
	unsigned int GroNo;
	float NowSpeed;
	int Count;
	D3DXVECTOR3 qVec, cVec;
	D3DXMATRIX MoveMat;
	//�O�i����p--------------
	QuaForMove Q;//�O�i����p�N�H�[�^�j�I��
	D3DXMATRIX ForMoveEndMat;//�O�i��������Mat
	D3DXVECTOR3 ForMoveVec[3];//�ړ��O����ړ����Vec
	//------------------------
	//�X�s�[�h�Ǘ�
	//SpeedMove EneSpe;
	Speed *speed;
	float SpeedMul;
	int NowCount, MaxCount;
	//------------------------
};