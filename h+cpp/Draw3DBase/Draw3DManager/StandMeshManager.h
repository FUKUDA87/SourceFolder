#pragma once
#include"MeshManager.h"

class C_StandMeshManager :public C_MeshManager{
public:
	XFILE GetMesh(int MeshNo);
protected:
	//�X�^���h�̃��f�����T��
	bool GetMeshJudg(int MeshNo);
private:
	//�X�^���h�P
	bool GetStand1(int MeshNo);
	//�X�^���h�P01
	bool GetStand101(int MeshNo);
};