#pragma once
#include"MeshDataManagerBase.h"

class C_CarDataManager :public C_MeshDataManagerBase {
public:
	//�\�����̓ǂݍ���
	int GetDrawNum(int CarNo, bool SaveFlg);
	//�\���ݒ�̓ǂݍ���
	PARTSBASE GetDrawSet(int CarNo, const int *DrawNo, bool SaveFlg);
protected:
private:
	//�����\����
	bool DrawNumJudg(int CarNo);
	//�����ݒ�
	bool DrawSetJudg(int CarNo, const int *DrawNo);
};