#pragma once
#include"MeshManager.h"
//�e��
#include"../../Gun/GunDraw/GunData/GunDataBase.h"

class C_GunMeshManager :public C_MeshManager {
public:
	XFILE GetMesh(int MeshNo);
	//�e�̏e������Pos�̎擾
	C_GunDataBase* GetGunData(const int MeshNo);
private:
	//���f�����T��
	bool GetMeshJudg(int MeshNo);
	//No1
	bool GetGunNo1(int MeshNo);
	//No2
	bool GetGunNo2(int MeshNo);
	//No3
	bool GetGunNo3(int MeshNo);
};