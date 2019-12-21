#pragma once
#include<d3dx9.h>
#include"../GameSource/option.h"
#include"../GameSource/Enum.h"
#include"../GameSource/Struct.h"
#include"../3DDraw/Ball.h"
#include"../2DDraw/HpD.h"
#include"../3DDraw/Spear.h"
#include"../Ground/BillBase.h"
#include<vector>
#include"../Enemy/Vector.h"

class C_Player{
public:
	void Init();
	C_Player();
	~C_Player();
	 virtual bool Update();
	 virtual bool SuperUpdate(float AngX,float AngY,std::vector<BillBase*>ground);
	 void Draw();
	 void Draw2();
	 virtual void SuperDraw();
	D3DXMATRIX GetMat();
	void SetMat(D3DXMATRIX mat);
	float GetRad();

	//-------------------------------
	//�Q�b�g
	//-------------------------------
	D3DXVECTOR3 GetSpeed(void) {
		return player.Con.Speed;
	}
	void SetSpeed(D3DXVECTOR3 spe) {
		player.Con.Speed = spe;
	}
	float GetRadF(void) {
		return radF;
	}
	void SetRadF(float rad) {
		radF=rad;
	}
	void SetGroNum(unsigned int i) { player.Con.GroNum=i; };
	unsigned int GetGroNum(void) { return player.Con.GroNum; };
	//HP
	//int GetHP(void) { return player.Sta.NowHp; };
	void SetHP(int Damage);
	void SetHP(int *Hp);


	//�J�[�u�̃��o�[�X
	void CurReverse(bool b);

	//playerMesh
	LPD3DXMESH GetMesh() {
		return player.Mesh.lpMesh;
	}

	//player���
	CHARAData GetData(void);

	bool GetFlgP(void) {
		return player.Base.Flg;
	}
	float GetBodRad(void) {
		return player.Base.BodRad;
	}
	//�����蔻��p��Mat�n��
	D3DXMATRIX GetJudgMat() {
		return player.Con.JudgMat;
	}
	//player��TransMat�n��
	D3DXMATRIX GetTransMatPla(void) {
		return player.Base.Trans;
	}
	//player��TransMat����
	void SetTransMatPla(D3DXMATRIX TransMat) {
		player.Base.Trans = TransMat;
	}
	//�R���W�������f���n��
	LPD3DXMESH GetColMod(void) {
		return player.Con.ColModMesh.lpMesh;
	}
	//�ړ��̏��n��
	CONSTITUTION GetCon(void) {
		return player.Con;
	}
	//�J�[�u��Ang����
	void SetRodAngY(float Inc, bool KeyFlg);
	//CurEnd
	void SetCurRotMat(void);
	/*virtual QuaForMove GetQuaForMove(void) {
		QuaForMove q;
		q.AnimeFrame = Move.AnimeFrame;
		q.BodyHeight = 5.0f;
		return q;
	}*/
protected:
	QuaAnim cur;//�Ԑ��ύX�p
	QuaAnim Move;//�O�i�p
	QuaMove FMove;//�O�i�p�Q
	CHARA3D player;
	Vector* vector;
	Ball *ball;
	HpD *hp;
	Spear *spear;
private:
	float radF;
	//�_���[�W�t���O
	bool DFlg;

	FILE* fp;
	//�J�[�u�p�x
	float CurAng;
	D3DXMATRIX CurRotMatY;
};
