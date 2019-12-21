#include "CarParts.h"

C_CarParts::~C_CarParts()
{
	DeleteParts();
}

void C_CarParts::DeleteParts(void)
{
	
	if (Parts.size() <= 0) return;

	//�W���p�[�c�̍폜
	for (unsigned int p = 0; p < Parts.size(); p++) {
		delete Parts[p];
		Parts.erase(Parts.begin() + p);
		p--;
	}
}

void C_CarParts::SetCarParts(const BODYDATA * Data,const bool SaveFlg)
{
	//SaveFlg�̓f�[�^�̕ύXFlg

	DeleteParts();

	int PartsNum;
	//�p�[�c���̓ǂݍ���
	PartsNum = CarDataManager.GetDrawNum(Data->CarBodyNo, SaveFlg);

	//�p�[�c�̏�����
	PARTSBASE PBase;
	for (int p = 0; p < PartsNum; p++) {
		//�p�[�c���̓ǂݍ���
		PBase=CarDataManager.GetDrawSet(Data->CarBodyNo, &p, SaveFlg);
		SetTireParts(Data, &PBase);
		SetStandParts(Data, &PBase);
		SetCarParts(Data, &PBase);
	}
}

PARTS C_CarParts::GetPartsData(unsigned int * No)
{
	if (Parts.size() <= 0)return PARTS();

	unsigned int pNo=*No;
	if (pNo <= 0)pNo = 0;
	if (pNo >= Parts.size())pNo = Parts.size() - 1;
	return Parts[pNo]->GetParts();
}

D3DXMATRIX C_CarParts::GetPartsMat(unsigned int * No)
{
	if (Parts.size() <= 0)return D3DXMATRIX();

	unsigned int pNo = *No;
	if (pNo <= 0)pNo = 0;
	if (pNo >= Parts.size())pNo = Parts.size() - 1;
	return Parts[pNo]->GetDrawMatParts();
}

bool C_CarParts::SetDamageParts(const unsigned int * pNo, const int * Damage)
{
	if (*pNo < 0)return false;
	if (*pNo > Parts.size() - 1)return false;

	if(Parts[*pNo]->HpDamage(Damage)!=true)return false;

	return true;
}

int C_CarParts::PartsDeadFlg(unsigned int * pNo)
{
	if (*pNo < 0)return 2;
	if (*pNo > Parts.size() - 1)return 2;

	if (Parts[*pNo]->Dead() == true)return 0;

	return 1;
}

void C_CarParts::SetCarParts(const BODYDATA * Data, const int * EnemyNo,const int *MaxHp, const bool SaveFlg)
{
	//SaveFlg�̓f�[�^�̕ύXFlg

	DeleteParts();

	int PartsNum;
	//�p�[�c���̓ǂݍ���
	PartsNum = CarDataManager.GetDrawNum(Data->CarBodyNo, SaveFlg);

	C_EnemyDataManager l_EDM;
	C_EnemyDataBase *l_EDB = l_EDM.GetEnemyData(EnemyNo);

	//�p�[�c�̏�����
	PARTSBASE PBase;
	for (int p = 0; p < PartsNum; p++) {
		//�p�[�c���̓ǂݍ���
		PBase = CarDataManager.GetDrawSet(Data->CarBodyNo, &p, SaveFlg);
		PARTS P = GetPartsData(&PBase);
		P.Mesh.DrawMesh = l_EDB->GetPartsMesh(&p);
		P.HpLinkFlg = false;
		P.PolFlg = false;
		Parts.push_back(new C_EnemyParts(&P,l_EDB->GetPartsData(&p),MaxHp));
	}
}

void C_CarParts::SetTireParts(const BODYDATA * Data, const PARTSBASE * PBase)
{
	if (PBase->MeshNo != MeshTireNo)return;

	PARTS P=GetPartsData(PBase);

	//�^�C���̏�����------------------------------------------------------------------------
	//�������p�ϐ�
	float AngXMaxUp = 28.0f;
	P.Mesh.DrawMesh = TireMeshManager.GetMesh(Data->TireNo);
	//�o��������
	Parts.push_back(new C_TireParts(&P, &AngXMaxUp));

}

void C_CarParts::SetStandParts(const BODYDATA * Data, const PARTSBASE * PBase)
{

	if (PBase->MeshNo != MeshStandNo)return;

	PARTS P = GetPartsData(PBase);

	//�X�^���h�̏�����---------------------------------------------------------
	P.Mesh.DrawMesh = StandMeshManager.GetMesh(Data->StandNo);
	//�o��������
	Parts.push_back(new C_PartsBase(&P));
}

void C_CarParts::SetCarParts(const BODYDATA * Data, const PARTSBASE * PBase)
{
	if (PBase->MeshNo != MeshCarPartsNo)return;

	PARTS P = GetPartsData(PBase);

	//������---------------------------------------------------------
	P.Mesh.DrawMesh = PartsMeshManager.GetMesh(PBase->MeshPartsNo);
	//�o��������
	Parts.push_back(new C_PartsBase(&P));
}

PARTS C_CarParts::GetPartsData(const PARTSBASE * PBase)
{
	PARTS P;

	P.GunFlg = PBase->GunFlg;
	P.JudgFlg = PBase->JudgFlg;
	P.MoveFlg = PBase->MoveFlg;
	P.MeshDrawFlg = PBase->MeshDrawFlg;
	P.MeshNo = PBase->MeshNo;
	//�����ʒu
	//����1�̏�����
	P.Base.AngX = PBase->AngX;
	P.Base.TraPos = PBase->TransPos;
	judgCP.SetTransMat(&P.Base.Trans, &P.Base.TraPos);
	P.Base.AngY = PBase->AngY;
	D3DXMatrixRotationY(&P.Base.RotY, D3DXToRadian((float)P.Base.AngY));
	P.Base.AngZ = PBase->AngZ;
	P.Base.ScaPos = PBase->ScalPos;
	//�o��������

	return P;
}
