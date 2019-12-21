#include "CarBase.h"
#include"../GameSource/XfileManager.h"
#include"../GameSource/Judgment.h"
#include"../GameSource/Motion.h"

extern Judg judg;
extern XfileManager xfileManager;
extern LPDIRECT3DDEVICE9		lpD3DDevice;	// Direct3DDevice�C���^�[�t�F�C�X
extern Motion motion;

//void DrawMesh(XFILE *XFile);
void DrawMesh(XFILE *XFile, bool *Flg);


C_CarBase::C_CarBase()
{
	InitCar();
}

C_CarBase::~C_CarBase()
{

}

void C_CarBase::InitCar(void)
{
	//������Flg�̏�����
	Car.Base.Flg = true;

	//�_���[�WFlg�̏�����
	DamageFlg = false;

	//�s��̏�����
	judg.InitMatPos(&Car.Base.Mat, &Car.Base.TraPos, &Car.Base.ScaPos);
	judg.SetTransMat(&Car.Base.Trans, &Car.Base.TraPos);
	//���b�V���̏�����
	SetMeshCar(1);
	//�Ԃ̔���p

	//�o���b�g��񏉊���
	brj.JudgRayFlg = false;

	SkyType = false;

	//�O�i�N�H�[�^�j�I���̏�����
	CarFM.AnimeFrame = 0.0f;
	CarFM.QuaInitFlg= false;
	CarFM.QuaMatInitFlg = false;
	CarFM.CurFlg = false;
	Car.Con.SpeedMulJudg = 1.0f;
	CarFM.BodyHeight = 0.5f;

	//���G������
	CountMStart = 5;
	CountMNum = 0;

	//�Ԕ���
	bool Flg = true;
	SetDamageFlg(&Flg);
}

bool C_CarBase::UpdateCar(void)
{
	return false;
}

bool C_CarBase::UpdateCarFM(std::vector<BillBase*> ground)
{
	if (Car.Base.Flg == true) {
		PlaMovMat = Car.Base.Mat;
		//�O�i����
		CarFM.NowMat = Car.Base.Mat;
		motion.Formove(Car.Con, &CarFM.NowMat, &CarFM.AnimeFrame, ground, &CarFM.QuaInitFlg, &CarFM.QuaMatInitFlg, &Car.Con.SpeedMul, Car.Con.SpeedMulJudg, &CarFM.StartMat, &CarFM.EndMat, &CarFM.WayVec, &CarFM.CurFlg, &CarFM.CurVec, CarFM.BodyHeight);
		//�ԑ̂̕����𓾂邽�߂�Mat������
		Car.Con.JudgMat = CarFM.NowMat;
		Car.Base.Mat = Car.Base.Trans*CarFM.NowMat;

	}
	return true;
}

void C_CarBase::Draw3DCar(void)
{
	lpD3DDevice->SetTransform(D3DTS_WORLD, &GetDrawMatCar());
	if (Car.Base.Flg == true) {
		DrawMesh(&Car.Mesh, &DamageFlg);
	}
	else {
		DrawMesh(&Car.Con.DeadMesh, &DamageFlg);
	}
}

void C_CarBase::SetParts(std::vector<BillBase*> ground)
{
}

bool C_CarBase::SetHP(int Damage)
{
	if (CountMNum > 0)return false;

	int NowHp = GetHp();

	if (HpDamage(&Damage) != true)return false;

	if (Dead()==true) {
		Car.Base.Flg = false;
	}
	if (GetHp() < NowHp)DamageFlg = true;
	//���G�̏�����
	CountMNum = CountMStart;

	return true;
}

bool C_CarBase::SetHP(int Damage, bool WallFlg)
{
	if (CountMNum > 0)return false;

	int NowHp = GetHp();
	
	if (HpDamage(&Damage) != true)return false;

	if (Dead() == true) {
		Car.Base.Flg = false;
	}

	if (GetHp() < NowHp)DamageFlg = true;

	if (WallFlg == false)return true;
	//���G�̏�����
	CountMNum = CountMStart;

	return true;
}

void C_CarBase::SetBPos(D3DXVECTOR3 RayPos, bool RayJudgFlg)
{
	brj.RayPos = RayPos;
	brj.JudgRayFlg = RayJudgFlg;
}

CHARAData C_CarBase::GetData(void)
{
	CHARAData c;
	c.NowMat = Car.Base.Mat;
	c.Rad = Car.Base.AttRad;
	c.CurFlg = Car.Con.CurFlg;
	c.NowGround = Car.Con.GroNum;
	c.DrawFlg = Car.Base.Flg;
	c.Mesh = Car.Mesh.lpMesh;
	c.Speed = Car.Con.NowSpeed;
	return c;
}

QuaForMove C_CarBase::GetQuaForMove(void)
{
	Q.AnimeFrame = CarFM.AnimeFrame;
	Q.BodyHeight = CarFM.BodyHeight;
	Q.CurFlg = CarFM.CurFlg;
	Q.CurVec = CarFM.CurVec;
	Q.EndMat = CarFM.EndMat;
	Q.NowMat = Car.Base.Mat;
	Q.QuaInitFlg = CarFM.QuaInitFlg;
	Q.QuaMatInitFlg = CarFM.QuaMatInitFlg;
	Q.SpeedMul = Car.Con.SpeedMul;
	Q.SpeedMul2 = Car.Con.SpeedMulJudg;
	Q.StartMat = CarFM.StartMat;
	Q.WayVec = CarFM.WayVec;
	return Q;
}

bool C_CarBase::UpdateCountM(void)
{
	CountMNum -= 1;
	if (CountMNum <= 0) {
		CountMNum = 0;
		return false;
	}
	return true;
}

void C_CarBase::SetMeshCar(int MeshNo)
{
	XFILE3 X= carMeshManager.GetMesh(MeshNo);
	Car.Mesh = X.Mesh1;
	Car.Con.ColModMesh = X.Mesh2;
	Car.Con.DeadMesh = X.Mesh3;
	Car.Base.BodRad = judg.GetRad(&Car.Con.ColModMesh, &Car.Base.NumVertex, &Car.Con.PosBig, &Car.Con.PosSmall);
}
