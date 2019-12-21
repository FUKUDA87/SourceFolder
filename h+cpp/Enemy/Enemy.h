#pragma once
#include<d3dx9.h>
#include"Vector.h"
#include"../3DDraw/Ball.h"
#include"../GameSource/Struct.h"
#include"HpEne.h"
#include"../Draw3DBase/CarBase.h"

#ifndef Enemy_H
#define Enemy_H


class Enemy :public C_CarBase{
private:
	Vector *vector;
	Ball *ball;
	//���ƃt���O
	bool backFlg;
	unsigned int GroNum;//�n��num
	HpEne *HpE;
	XFILE Dead;//����̎ԑ�
protected:
	Enemy3D enemy;
	D3DXVECTOR3 Pos2D;
public:
	void Init();
	Enemy();
	Enemy(D3DXMATRIX GroundMat, float *TransX);
	~Enemy();
	bool EneUpdate();
	void EneDraw();
	void Ene2Draw();

	//�����蔻��p�̍\����
	judgDeta GetJudgDate(void);
	//Hp
	int GetHp() {
		return enemy.CH.Sta.CharaBase.NowHp;
	}
	void SetHp(int hp);



	LPD3DXMESH GetMeshE(void) {
		return enemy.CH.Mesh.lpMesh;
	}

	virtual bool UpdateAll();
	bool VectorUpdate();
	//�A�b�v�f�[�gAll��̃A�b�v�f�[�g
	virtual bool UpdateEnd();
	virtual void DrawAll() {
		void EneDraw();
	};
	virtual bool GetFlgEA(){
		return GetFlgE();
	}
	bool GetFlgE(void);
	void SetFlgE(bool b) {
		enemy.CH.Base.Flg = b;
	}

	//------------------------------------------
	//�Q�b�g
	//------------------------------------------
	D3DXMATRIX GetMatEn(void) {
		return enemy.CH.Base.Mat;
	}
	void SetMatEn(D3DXMATRIX mat) {
		enemy.CH.Base.Mat = mat;
	}
	float GetRad(void) {
		return enemy.CH.Base.AttRad;
	}

	//------------------------------------------
	//�Z�b�g
	//------------------------------------------
	void SetSpeed(D3DXVECTOR3 speed) {
		enemy.CH.Con.Speed = speed;
	}
	//debug�p
	float GetAng(void) { return vector->GetAng(); };
	void SetPos2D(D3DXVECTOR3 p) { Pos2D = p;};

	//�X�s�[�h�Ǘ�//9.07
	void SetSize(float f) {
		enemy.EC.Size = f;
	};
	float GetSize(void) {
		return enemy.EC.Size;
	};
	void SetSiFlg(bool b) {
		enemy.EC.SiFlg = b;
	};
	bool GetSiFlg(void) {
		return enemy.EC.SiFlg;
	};
	//�n��num
	unsigned int GetGroNum() {
		return enemy.CH.Con.GroNum;
	}
	void SetGroNum(unsigned int i) {
		enemy.CH.Con.GroNum = i;
	}
	////�X�s�[�h�Ǘ�
	//void SetSpe(float f) {
	//	enemy.CH.Con.Speed = f;
	//}
	////�X�s�[�h�Ǘ�+=up
	//void SetSpeU(float up, float upEnd) {
	//	enemy.CH.Con.Speed += up;
	//	if (enemy.CH.Con.Speed > upEnd) enemy.CH.Con.Speed = upEnd;
	//}
	////�X�s�[�h�Ǘ�-=down
	//void SetSpeD(float dowe, float doEnd) {
	//	enemy.CH.Con.Speed -= dowe;
	//	if (enemy.CH.Con.Speed < doEnd) enemy.CH.Con.Speed = doEnd;
	//}

	//�����蔻��p�̊֐�--------------------------------
	//�ړ��̏��n��
	CONSTITUTION GetCon(void) {
		return enemy.CH.Con;
	}
	//player��TransMat�n��
	D3DXMATRIX GetTransMatEne(void) {
		return enemy.CH.Base.Trans;
	}
	//player��TransMat����
	void SetTransMatEne(D3DXMATRIX TransMat) {
		enemy.CH.Base.Trans = TransMat;
	}
	//--------------------------------------------------

	//�R���W�������f���n��
	LPD3DXMESH GetColMod(void) {
		return enemy.CH.Con.ColModMesh.lpMesh;
	}
};

#endif // !Enemy_H
