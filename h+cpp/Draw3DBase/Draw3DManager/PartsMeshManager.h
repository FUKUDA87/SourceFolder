#pragma once
#include"MeshManager.h"

class C_PartsMeshManager :public C_MeshManager {
public:
	XFILE GetMesh(int MeshNo);
private:
	//���f�����T��
	bool GetMeshJudg(int MeshNo);

	//�P
	bool GetParts1(int MeshNo);
	//2
	bool GetParts2(int MeshNo);
	//2
	bool GetParts3(int MeshNo);
};