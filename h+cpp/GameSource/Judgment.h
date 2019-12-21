#pragma once
#include<d3dx9.h>
#include"Struct.h"

#ifndef Judgm_H
#define Judgm_H

extern LPDIRECT3DDEVICE9 lpD3DDevice;


class Judg {
private:
	//pos2D�p
	D3DXMATRIX SmProj;
	D3DXMATRIX SmView;
	D3DVIEWPORT9 SViewport;
	bool D2Flg;
public:
	void Init(){ D2Flg = false; }
	Judg() { Init(); };
	//��������
	bool ball(D3DXMATRIX mat1, D3DXMATRIX mat2,float rad);
	bool ball(D3DXVECTOR3 PosA, D3DXMATRIX MatB, float Rad);
	//��������+���Ƌ�
	bool ball(D3DXMATRIX mat1, D3DXMATRIX mat2, float rad, D3DXMATRIX *Trans1, D3DXMATRIX *Trans2);
	//��������+�����擾
	float ball(D3DXMATRIX mat1, D3DXMATRIX mat2);
	//��������+Hp
	bool ball(judgDeta *jd, D3DXMATRIX matB, float radB, int damB);
	//Hp�̏���
	bool HPj(int *NowHp, int *NowMaxHp);
	//���C�Ǝl�p�|���S������M
	bool RayPolM(D3DXMATRIX mat,D3DXVECTOR3 v0, D3DXVECTOR3 v1, D3DXVECTOR3 v2, D3DXVECTOR3 v3, D3DXMATRIX pmat, D3DXVECTOR3 ray, float *Dis);
	//���C�Ǝl�p�|���S������P
	bool RayPolP(D3DXVECTOR3 Pos, D3DXVECTOR3 v0, D3DXVECTOR3 v1, D3DXVECTOR3 v2, D3DXVECTOR3 v3, D3DXMATRIX pmat, D3DXVECTOR3 ray, float *Dis);
	bool RayPolP(D3DXVECTOR3 Pos, D3DXVECTOR3 v0, D3DXVECTOR3 v1, D3DXVECTOR3 v2, D3DXVECTOR3 v3, D3DXVECTOR3 ray, float *Dis);
	bool RayPolM(D3DXMATRIX Mat, D3DXVECTOR3 v0, D3DXVECTOR3 v1, D3DXVECTOR3 v2, D3DXVECTOR3 v3, D3DXVECTOR3 ray, float * Dis);
	//3D����2D�̍��W�擾
	D3DXVECTOR3 Pos2D(D3DXVECTOR3 pos3D);
	///3D����2D�̂���
	void Pos2Dpvv(D3DXMATRIX mProj, D3DXMATRIX mView, D3DVIEWPORT9 Viewport);
	//3D����2D�̍��W�擾+player��enemy�̋t�ʒu�쐬
	D3DXVECTOR3 Pos2DPE(D3DXMATRIX eMat,D3DXMATRIX pMat);
	//Ang�v�Z
	double Ang(D3DXVECTOR3 pla, D3DXVECTOR3 tar, D3DXVECTOR3 vec);
	//���CMesh
	bool Mesh(D3DXVECTOR3 pos, D3DXVECTOR3 vec, D3DXMATRIX mat,LPD3DXMESH mesh, float *Dis);
	//int Vec=�O�Ȃ�O�A���Ȃ�P�A���Ȃ�Q�A�E�Ȃ�R
	bool Mesh(D3DXMATRIX MatA,int VecNumA, float BodyRadA,D3DXMATRIX MatB, LPD3DXMESH MeshB);
	bool Mesh(D3DXVECTOR3 pos, D3DXVECTOR3 vec, D3DXMATRIX mat, LPD3DXMESH mesh, float *Dis, int m);
	//�O�ϓ���
	bool CroDot(D3DXMATRIX mat, D3DXMATRIX *rot, D3DXVECTOR3 targetPos, D3DXVECTOR3 FrontVec, double *Ang,double ang, bool angF);
	//tragetX��]�p(�~�T�C����])
	bool TarRotX(D3DXMATRIX mat, D3DXMATRIX * rotX, D3DXVECTOR3 targetPos, D3DXVECTOR3 FrontVec);
	//tragetY��]�p(�J�c�I��])
	bool TarRotY(D3DXMATRIX mat,D3DXMATRIX *rotY,  D3DXVECTOR3 targetPos, D3DXVECTOR3 FrontVec);
	//tragetEndMat�쐬
	bool TarEndMat(D3DXMATRIX *mat,D3DXMATRIX TransMat, D3DXMATRIX * RotXMat, D3DXMATRIX *RotYMat, D3DXVECTOR3 TargetPos, D3DXVECTOR3 FrontVec);
	//Pos<-Mat
	D3DXVECTOR3 SetPosM(D3DXMATRIX Mat);
	bool SetPosM(D3DXVECTOR3 *Pos,D3DXMATRIX Mat);
	//Mat<-Pos
	D3DXMATRIX SetMatP(D3DXVECTOR3 Pos);
	bool SetMatP(D3DXMATRIX *Mat, D3DXVECTOR3 Pos);
	//�N�H�[�^�j�I��==============================================================================================
	//�A�j���[�V����
	bool AnimeProc(D3DXMATRIX *NowMat, D3DXMATRIX StartMat, D3DXMATRIX EndMat, float AnimeFrame);
	bool AnimeProc(D3DXVECTOR3 *NowPos, D3DXVECTOR3 StartPos, D3DXVECTOR3 EndPos, float AnimeFrame);
	//AnimeFrame+=
	bool AnimeFrameInc(float *AnimeFrame, float up, bool upFlg);
	//�A�j���[�V����+AnimeFrame+=
	bool Quaternion(D3DXMATRIX *NowMat, D3DXMATRIX StartMat, D3DXMATRIX EndMat, float *AnimeFrame, float up, bool upFlg);
	bool Quaternion(D3DXVECTOR3 *NowPos, D3DXVECTOR3 StartPos, D3DXVECTOR3 EndPos, float *AnimeFrame, float up, bool upFlg);
	//���C�����Dis��Pos�ϊ�
	D3DXVECTOR3 DisPos(D3DXVECTOR3 PosA, D3DXVECTOR3 PosB, float Dis);
	//�r���{�[�h
	D3DXVECTOR3 Billboard(const D3DXVECTOR3 OldPos, const D3DXVECTOR3 NowPos, const D3DXVECTOR3 camPos, const float Size);
	//�r���{�[�h�{�|���Ή�
	D3DXVECTOR3 Billboard(const D3DXVECTOR3 OldPos, const D3DXVECTOR3 NowPos,const float Size,const bool Reverse);
	//���ƃ��C2D
	bool LineLine(const D3DXVECTOR2 PosA, const D3DXVECTOR2 VecA, const D3DXVECTOR2 PosB, const D3DXVECTOR2 VecB, float *Dis);
	//�摜�̔����T�C�Y
	D3DXVECTOR2 HalfSize(const D3DXVECTOR3 sPos, const int Width, const int Height);
	//2D�̉摜�̘g�v�Z
	bool PlaneP(RECT *rc, const D3DXVECTOR3 PosA, const D3DXVECTOR3 sPos, const int Width, const int Height);
	//2D�摜�N���b�N(�l�p�`)
	bool PlaneCri(const D3DXVECTOR3 PosA, const D3DXVECTOR3 sPos, const int Width, const int Height);
	bool PlaneCri(const D3DXMATRIX MatA, const D3DXVECTOR3 sPos, const int Width, const int Height);
	//�}�E�X�ʒu
	POINT GetPoint(void);
	//rayray3D
	bool LineLine3D(D3DXVECTOR3 *GetPos, D3DXVECTOR3 PosA1, D3DXVECTOR3 PosA2, D3DXVECTOR3 PosB1, D3DXVECTOR3 PosB2);
	//vectorPos
	D3DXVECTOR3 VecPos(D3DXMATRIX MatA, D3DXVECTOR3 PosB);
	//vectorTrans
	D3DXMATRIX VecTransMat(D3DXVECTOR3 VecA);
	//**Mat����
	bool SetppMat(D3DXMATRIX *Mat, D3DXVECTOR3 PosA, D3DXVECTOR3 PosB, D3DXVECTOR3 PosC, int RailNum, bool bc);
	//Vec=MatB-MatA
	bool MatMatVec(D3DXVECTOR3*Vec, D3DXMATRIX MatA, D3DXMATRIX MatB);
	D3DXVECTOR3 MatMatVec(D3DXMATRIX MatA, D3DXMATRIX MatB);
	bool VecMatIn(D3DXMATRIX *Mat, D3DXVECTOR3 Vec);
	//Speed�N�H�[�^�j�I���ϐ�
	bool SetFloatQ(float *f);
	bool SetFloatQ(D3DXVECTOR3 *Pos);
	float SlashFloat(float fA, float fB);
	//float�̑傫����r
	bool BigFloat(float *fA, float fB);
	//float�̏�������r
	bool SmallFloat(float *fA, float fB);
	//���a�����߂�
	float GetRad(XFILE *Mesh, DWORD *NumVertex, D3DXVECTOR3 *PosBig, D3DXVECTOR3 *PosSmall);
	float GetRad(XFILE *Mesh, DWORD *NumVertex, D3DXVECTOR3 *PosBig, D3DXVECTOR3 *PosSmall,bool a);
	//���o�[�XFlg
	void ReverseFlg(bool *Flg);
	//�X�P�C�����OMat����
	void ScalingMat(D3DXMATRIX *ScalMat, const D3DXVECTOR3 *Pos);
	//RotX�̏�����
	void InitRotX(const D3DXMATRIX * Mat,D3DXMATRIX*RotX);
	//�N�H�[�^�j�I���\���̂̏������֐�
	QuaAnimeC InitQuaAnime(const D3DXMATRIX *StartMat, const D3DXMATRIX *EndMat, const float *NowAnime, const float *AnimeFrame);
	//�������P
	void InitMatPos(D3DXMATRIX *Mat, D3DXVECTOR3 *TransPos, D3DXVECTOR3 *ScalPos);
	//�ړ��s��̃Z�b�g
	void SetTransMat(D3DXMATRIX *TransMat, const D3DXVECTOR3 *TransPos);
	//�\���p�̍s��쐬
	D3DXMATRIX GetDrawMat(const D3DXMATRIX *Mat,D3DXMATRIX *ScalMat, const D3DXVECTOR3 *ScalPos);
	//�������Q
	BASE3D GetInitBase3D(const D3DXVECTOR3 *InitPos, const D3DXVECTOR3 *TransPos, const D3DXVECTOR3 *ScalPos, const double * AngX, const  double * AngY, const  double * AngZ);
	//����p�̊g����܂߂��ړ��s��̍쐬
	D3DXMATRIX GetTransMatScal(const D3DXVECTOR3 *TransPos, const D3DXVECTOR3* ScalPos);
	//�s��̍���(MatA*MatB)
	D3DXMATRIX GetMatY(const D3DXMATRIX *MatA, const D3DXMATRIX *MatB);
	//�x�N�g���̊|���Z
	D3DXVECTOR3 GetVecVec(const D3DXVECTOR3 *VecA, const D3DXVECTOR3 *VecB);
	//�ʒu�̏�����(Gun�o�[�W����)
	BASE3D InitGunParts(const Object3DGun* Init);
	//�ʒu�̏�����(Gun�o�[�W����)
	Object3DGun InitSetPartsData(const float AngX,const float AngY,const float AngZ,const D3DXVECTOR3 *TransPos, const D3DXVECTOR3 *ScalPos,const bool DrawFlg);
	//�������\����
	GUNDRAWNOS GetInitGUNDRAWNOS(const int GunNo, const int BulletNo, const int MuzFlaNo, const int LaserNo);
};

#endif // !Judgm_H

/*
#include"Judgment.h"

extern Judg *judg;
*/