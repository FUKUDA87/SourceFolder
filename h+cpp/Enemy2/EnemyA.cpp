#include "EnemyA.h"
#include"../Draw/Hp/Hp2DEnemy.h"
#include"../Draw/Hp/Hp3DEnemy.h"

C_EnemyA::C_EnemyA(D3DXMATRIX GroundMat, float * TransX)
{
	
	InitPos(GroundMat, TransX);

	EnemyA();
	InitBody();
	InitParts();
}

C_EnemyA::C_EnemyA(const int * EnemyNo, D3DXMATRIX GroundMat, float * TransX)
{
	InitPos(GroundMat, TransX);

	m_EnemyNo = *EnemyNo;
	C_EnemyDataManager e_DM;
	C_EnemyDataBase *e_DB=e_DM.GetEnemyData(&m_EnemyNo);
	//�Ԃ̏�����
	S_ENEMYBODYDATA l_EBD= e_DB->GetBodyData();
	SetCharaBase(&l_EBD.CharaBase);
	BodyData = l_EBD.Body;
	CarFM.BodyHeight = l_EBD.GroundHeight;
	Car.Base.ScaPos = l_EBD.ScalPos;
	SetMeshCar(BodyData.CarBodyNo);
	//�X�s�[�h�Z�b�g
	InitSpeedMove(e_DB->GetSpeed());
	//�p�[�c�̏�����
	int l_MaxHp = GetCharaBase().MaxHp;
	SetCarParts(&BodyData,EnemyNo,&l_MaxHp, false);

	//�e�̏�����
	int i = 0;
	for (unsigned int s = 0; s < Parts.size(); s++) {
		if (Parts[s]->GetParts().GunFlg>0)i++;
	}
	if (i <= 0)return;
	for (int g = 0; g < i; g++) {
		m_Gun.push_back(new C_EnemyGun(m_EnemyNo, g));
	}

	//Ai�̏�����
	m_Ai = e_DB->GetAiPhase();

	if (*EnemyNo > 100) {
		m_HpBase = new C_Hp2DEnemy(&D3DXVECTOR3(800.0f,30.0f,1.0f),&D3DXVECTOR3(1280.0f/2.0f,720.0f*0.1f,0.0f));
	}
	else {
		m_HpBase = new C_Hp3D(&D3DXVECTOR2(0.7f,0.1f));
	}
}

C_EnemyA::C_EnemyA(D3DXMATRIX GroundMat, float * TransX, const BODYDATA * IniteData)
{
	InitPos(GroundMat, TransX);

	//�ԏ�����
	BodyData = *IniteData;
	SetMeshCar(BodyData.CarBodyNo);

	SetCarParts(&BodyData, true);
}

C_EnemyA::C_EnemyA(D3DXMATRIX GroundMat, float * TransX, const BODYDATACar * IniteData, Speed* GetSpeed)
{
	InitPos(GroundMat, TransX);

	//�ԏ�����
	BodyData = IniteData->Body;
	Car.Base.ScaPos = IniteData->ScalPos;
	SetHp(&IniteData->MaxHp);
	SetMeshCar(BodyData.CarBodyNo);

	SetCarParts(&BodyData, true);

	//�X�s�[�h�Z�b�g
	InitSpeedMove(GetSpeed);

	if (BodyData.CarBodyNo == 101) {
		CarFM.BodyHeight = 0.75f;
	}

	/*GUNINITDATA InitGun;
	C_CharaBase c;
	InitGun.CharaBase = c.GetInitAll(1, true);
	InitGun.DrawNo.GunNo = 2;
	InitGun.InitGun = judg.InitSetPartsData(0.0f, 0.0f, 0.0f, &D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(1.0f, 1.0f, 1.0f), true);
	InitGun.LaserSize = 40.0f;
	InitSetGun(&InitGun);*/

	m_Gun.push_back(new C_EnemyGun(IniteData->EnemyNo,0));
}



void C_EnemyA::EnemyA(void)
{

}

void C_EnemyA::InitBody(void)
{
	SetMeshCar(CarNo101);
	CarFM.BodyHeight = 0.7f;
}

void C_EnemyA::InitParts(void)
{
	//�^�C���̏�����------------------------------------------------------------------------
	//�������p�ϐ�
	PARTS P;
	float AngXMaxUp = 35.0f;
	P.GunFlg = false;
	P.JudgFlg = false;
	P.MoveFlg = true;
	P.MeshDrawFlg = 1;
	P.Mesh.DrawMesh = TireMeshManager.GetMesh(TireNo101);
	//�����ʒu
	//����1�̏�����
	P.Base.AngX = 0.0f;
	D3DXVECTOR3 tPos = D3DXVECTOR3(0.65f, -0.5f, 0.55f);
	D3DXMatrixTranslation(&P.Base.Trans, -tPos.x, tPos.y, tPos.z);
	D3DXMatrixRotationY(&P.Base.RotY, D3DXToRadian(180.0f));
	P.Base.ScaPos = D3DXVECTOR3(0.75f, 1.0f, 1.0f);
	//�o��������
	Parts.push_back(new C_TireParts(&P, &AngXMaxUp));

	//����2�̏�����
	D3DXVECTOR3 ttPos = D3DXVECTOR3(0.65f, -0.5f, -0.75f);
	D3DXMatrixTranslation(&P.Base.Trans, -ttPos.x, ttPos.y, ttPos.z);
	//�o��������
	Parts.push_back(new C_TireParts(&P, &AngXMaxUp));

	//�E��1�̏�����
	D3DXMatrixTranslation(&P.Base.Trans, tPos.x, tPos.y, tPos.z);
	D3DXMatrixRotationY(&P.Base.RotY, D3DXToRadian(0.0f));
	AngXMaxUp *= -1.0f;
	//�o��������
	Parts.push_back(new C_TireParts(&P, &AngXMaxUp));

	//�E��2�̏�����
	D3DXMatrixTranslation(&P.Base.Trans, ttPos.x, ttPos.y, ttPos.z);
	//�o��������
	Parts.push_back(new C_TireParts(&P, &AngXMaxUp));


	//�X�^���h�̏�����---------------------------------------------------------
	P.GunFlg = true;
	P.Mesh.DrawMesh = StandMeshManager.GetMesh(StandNo101);
	//�����ʒu
	tPos = D3DXVECTOR3(0.0f, 0.72f, -0.2f);
	D3DXMatrixTranslation(&P.Base.Trans, tPos.x, tPos.y, tPos.z);
	P.Base.ScaPos = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	//�o��������
	Parts.push_back(new C_PartsBase(&P));

	//�e�̏�����-----------------------------------------------------------
}

void C_EnemyA::InitPos(D3DXMATRIX GroundMat, float * TransX)
{
	D3DXMATRIX tmp;
	D3DXMatrixTranslation(&Car.Base.Trans, *TransX, 0.0f, 0.0f);
	D3DXMatrixTranslation(&tmp, 0.0f, 0.5f, 0.0f);
	Car.Base.Mat = tmp * Car.Base.Trans*GroundMat;
}
