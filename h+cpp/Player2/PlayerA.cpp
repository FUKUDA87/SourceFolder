#include "PlayerA.h"

C_PlayerA::C_PlayerA()
{
	BodyData.CarBodyNo = CarNo1;
	BodyData.TireNo = TireNo1;
	BodyData.StandNo = StandNo1;
	BodyData.GunNo = 1;
	InitPlayerA();
}

C_PlayerA::C_PlayerA(const BODYDATA * Data)
{
	SetBody(Data);

	//SaveCar();
}

C_PlayerA::~C_PlayerA()
{
}

void C_PlayerA::SetBody(const BODYDATA * Data)
{
	//���̃Z�b�g
	BodyData = *Data;
	//�p�[�c�̃Z�b�g
	InitPlayerA();
}

void C_PlayerA::SaveCar(void)
{
	//�p�[�c���̓ǂݍ���
	int DrawNum;
	DrawNum = CarDataManager.GetDrawNum(BodyData.CarBodyNo,true);
	for (int c = 0; c < DrawNum; c++) {
		CarDataManager.GetDrawSet(BodyData.CarBodyNo, &c,true);
	}
}

void C_PlayerA::InitPlayerA(void)
{

	//�ԏ�����
	SetMeshCar(BodyData.CarBodyNo);

	SetCarParts(&BodyData,true);

	
}

void C_PlayerA::InitPlayerAB(void)
{

	//�p�[�c�̍폜
	DeleteParts();

	//�ԏ�����
	SetMeshCar(BodyData.CarBodyNo);

	//�p�[�c���̓ǂݍ���
	int DrawNum;
	//�\�����̓ǂݍ���
	DrawNum = CarDataManager.GetDrawNum(BodyData.CarBodyNo, true);
	//�\�����̏�����
	//�\����
	for (int c = 0; c < DrawNum; c++) {
		//�\�����̓ǂݍ���
		PARTS P;
		CarDataManager.GetDrawSet(BodyData.CarBodyNo, &c, true);
	}
}
