#pragma once
#include"MeshManager.h"

class C_CarMeshManager :public C_Mesh3Manager{
public:
	XFILE3 GetMesh(int MeshNo);
private:
	//���f�����T��
	bool GetMeshJudg(int MeshNo);

	//�J�[�P
	bool GetCar1(int MeshNo);
	//�J�[2
	bool GetCar2(int MeshNo);
	//��101
	bool GetCar101(int MeshNo);
	//��201
	bool GetCar201(int MeshNo);
};