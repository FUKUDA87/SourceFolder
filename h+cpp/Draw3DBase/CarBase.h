#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include<vector>
#include"../Ground/BillBase.h"
#include"../Draw3DBase/Draw3DManager/CarMeshManager.h"
#include"../GameSource/CharaBase.h"

class C_CarBase:public C_CharaBase {
public:
	C_CarBase();
	~C_CarBase();

	//������
	void InitCar(void);

	//�A�b�v�f�[�g
	virtual bool UpdateCar(void);
	//�O�i�A�b�v�f�[�g
	virtual bool UpdateCarFM(std::vector<BillBase*>ground);

	//3D�\��
	virtual void Draw3DCar(void);

	//�p�[�c�̈ʒu����
	virtual void SetParts(std::vector<BillBase*>ground);

	//==========================================
	//Get�ESet
	//==========================================
	//�ԑ̍s��n��
	D3DXMATRIX GetMatCar(void) {
		return Car.Base.Mat;
	}
	//�ԑ̍s�����
	void SetMatCar(const D3DXMATRIX *Mat) {
		Car.Base.Mat = *Mat;
	}
	//�Ԃ̕\���s��n��
	virtual D3DXMATRIX GetDrawMatCar(void) {
		return judg.GetDrawMat(&Car.Base.Mat, &Car.Base.Scal, &Car.Base.ScaPos);
	}
	//������n�ʂ�No����
	void SetGroNum(unsigned int GroundNo) {
		Car.Con.GroNum = GroundNo; 
	};
	//������n�ʂ�No�n��
	unsigned int GetGroNum(void) {
		return Car.Con.GroNum; 
	};
	////����Hp�n��
	//int GetHP(void) {
	//	return Car.Sta.NowHp; 
	//};
	//����Hp����
	virtual bool SetHP(int Damage);

	//����Hp����(�ǂƒe�̋�ʕt)
	virtual bool SetHP(int Damage,bool WallFlg);

	//�Ԃ̃��f���n��
	LPD3DXMESH GetMeshCar() {
		return Car.Mesh.lpMesh;
	}
	//�Ԃ̑���Flg�n��
	bool GetFlgCar(void) {
		return Car.Base.Flg;
	}
	//�Ԃ̑���Flg����
	void SetFlgCar(bool *Flg) {
		Car.Base.Flg=*Flg;
	}
	//�����蔻��̔��a�n��
	float GetBodRadCar(void) {
		return Car.Base.BodRad;
	}
	//�����蔻��p��Mat�n��
	D3DXMATRIX GetJudgMatCar() {
		return Car.Con.JudgMat;
	}
	//player��TransMat�n��
	D3DXMATRIX GetTransMatCar(void) {
		return Car.Base.Trans;
	}
	//player��TransMat����
	void SetTransMatCar(D3DXMATRIX *TransMat) {
		Car.Base.Trans = *TransMat;
	}
	//�R���W�������f���n��
	LPD3DXMESH GetColMod(void) {
		return Car.Con.ColModMesh.lpMesh;
	}
	//�ړ��̏��n��
	CONSTITUTION GetCon(void) {
		return Car.Con;
	}
	//�X�s�[�h�n��
	D3DXVECTOR3 GetSpeedCar(void) {
		return Car.Con.Speed;
	}
	//�X�s�[�h����
	void SetSpeedCar(D3DXVECTOR3 spe) {
		Car.Con.Speed = spe;
	}
	//�X�s�[�h�n��
	int GetNowSpeedCar(void) {
		return Car.Con.NowSpeed;
	}
	//�X�s�[�h����
	void SetNowSpeedCar(int spe) {
		Car.Con.NowSpeed = spe;
	}


	//�󒆂̓GFlg�n��
	bool GetSkyType(void) {
		return SkyType;
	}

	//�e�o��������
	void SetBPos(D3DXVECTOR3 RayPos, bool RayJudgFlg);

	//player���
	CHARAData GetData(void);

	//�g��n��
	D3DXVECTOR3 GetScalPosCar(void) {
		return Car.Base.ScaPos;
	}

	//�O�i����p�֐�-----------------------------------------------
	//�ړ��̏���n��
	QuaForMove GetQuaForMove(void);
	//�ړ��x�N�g���̒�������
	void SetQuaVecSize(float size) {
		Car.Con.SpeedMulJudg = size;
	}
	//�O�i����p�̈ړ��x�N�g���n��
	D3DXVECTOR3 GetForMoveVec(int i) {
		return ForMoveVec[i];
	}
	//�O�i����p�̈ړ��x�N�g������
	void SetForMoveVec(D3DXVECTOR3 Vec, int i) {
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

	//���G�A�b�v�f�[�g
	bool UpdateCountM(void);

	//���쐬�ɕK�v�ȏ��̎擾�ƃA�b�v�f�[�g
	virtual void GetPos2DSet(const D3DXMATRIX *mProj, const D3DXMATRIX *mView, const D3DVIEWPORT9 *Viewport) {};

protected:
	//�Ԃ̃��f������
	void SetMeshCar(int MeshNo);

	//�Ԃ̏��
	CHARA3D Car;

	//�_���[�W�t���O
	bool DamageFlg;

	QuaForMove CarFM;

	//�󒆂̓G������pFlg
	bool SkyType;

	D3DXMATRIX PlaMovMat;//player�̈ړ��O��Mat

	//�o���b�g�p
	BULLETRAYJUDG brj;

	Judg judg;


private:
	C_CarMeshManager carMeshManager;

	//�O�i�N�H�[�^�j�I���p
	D3DXMATRIX ForMoveEndMat;//�O�i��������Mat
	D3DXVECTOR3 ForMoveVec[3];//�ړ��O����ړ����Vec
	QuaForMove Q;//�O�i����p�N�H�[�^�j�I��

	//���G�^�C��
	int CountMNum,CountMStart;

};