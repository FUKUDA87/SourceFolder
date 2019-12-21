#pragma once
#include<d3dx9.h>
#include<stdio.h>
#include"../../GameSource/Struct.h"
#include"../../GameSource/Const.h"

class C_MeshDataManagerBase {
public:
	//�\�����̓ǂݍ���
	virtual int GetDrawNum(int CarNo,bool SaveFlg)=0;
	//�\���ݒ�̓ǂݍ���
	virtual PARTSBASE GetDrawSet(int CarNo,const int *DrawNo, bool SaveFlg) = 0;
protected:
	//�Z�[�u�E���[�h�p
	FILE* fp;
	FILE *fp_b;
	char FName[100];

	//�\����-----------------------------------------
	//�Z�[�u
	void SaveDN(int CarNo,int DrawNum);
	//���[�h
	int LoadDN(int CarNo);
	//txt���[�hdat�Z�[�u
	void LoadSaveDN(int CarNo);

	//�\�����----------------------------------------
	//�Z�[�u
	void SaveDS(int CarNo, const int *DrawNo,const PARTSBASE *Par);
	//���[�h
	PARTSBASE LoadDS(int CarNo, const int *DrawNo);
	//txt���[�hdat�Z�[�u
	void LoadSaveDS(int CarNo, const int *DrawNo);
	//�������p�[�c
	PARTSBASEINT InitPartsDS(void);

private:
	//�ϊ����|Int
	PARTSBASE ChangePB(const PARTSBASEINT *Par);
	//�ϊ��[��Int
	PARTSBASEINT ChangePBI(const PARTSBASE *Par);
};