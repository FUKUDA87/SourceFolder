#pragma once
#include"../../GameSource/Struct.h"
#include<stdio.h>
#include"../../GameSource/Const.h"

//�P�̃��b�V��
class C_MeshManager {
public:
	//���f�����n��
	virtual XFILE GetMesh(int MeshNo) = 0;
protected:
	//���f�����T��
	virtual bool GetMeshJudg(int MeshNo) = 0;

	char MeshName[100];
};
//�R�̃��b�V��
class C_Mesh3Manager {
public:
	//�X�^���h�̃��f�����n��
	virtual XFILE3 GetMesh(int MeshNo) = 0;
protected:
	//�X�^���h�̃��f�����T��
	virtual bool GetMeshJudg(int MeshNo) = 0;

	char MeshName[3][100];
};