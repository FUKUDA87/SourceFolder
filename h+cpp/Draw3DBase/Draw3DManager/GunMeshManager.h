#pragma once
#include"MeshManager.h"
//銃口
#include"../../Gun/GunDraw/GunData/GunDataBase.h"

class C_GunMeshManager :public C_MeshManager {
public:
	XFILE GetMesh(int MeshNo);
	//銃の銃口数とPosの取得
	C_GunDataBase* GetGunData(const int MeshNo);
private:
	//モデル情報探し
	bool GetMeshJudg(int MeshNo);
	//No1
	bool GetGunNo1(int MeshNo);
	//No2
	bool GetGunNo2(int MeshNo);
	//No3
	bool GetGunNo3(int MeshNo);
};