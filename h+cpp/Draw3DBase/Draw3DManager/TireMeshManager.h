#pragma once
#include"MeshManager.h"

class C_TireMeshManager :public C_MeshManager {
public:
	XFILE GetMesh(int MeshNo);
private:
	//����
	bool GetMeshJudg(int MeshNo);
	//�^�C���P
	bool GetTire1(int MeshNo);
	//�^�C���P01
	bool GetTire101(int MeshNo);
	//�^�C��201
	bool GetTire201(int MeshNo);
};