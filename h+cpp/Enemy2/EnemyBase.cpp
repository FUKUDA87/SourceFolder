#include "EnemyBase.h"

C_EnemyBase::C_EnemyBase()
{
	InitEnemy();
}

C_EnemyBase::~C_EnemyBase()
{
	//���̍폜
	delete Vect;

	if (m_HpBase != nullptr) {
		delete m_HpBase;
	}
}

void C_EnemyBase::InitEnemy(void)
{
	int MaxHp = 50;// rand() % 10 + 45;
	SetHp(&MaxHp);
	Car.Con.DFlg = false;
	//�O�i�p�̃N�H�[�^�j�I���̏�����
	Car.Con.SpeedMulJudg = 1.0f;

	//���̏�����
	Vect = new Vector();

	
}

bool C_EnemyBase::UpdateCar(void)
{
	D3DXVECTOR3 pos, vec;
	judg.SetPosM(&pos, Car.Base.Mat);
	vec = D3DXVECTOR3(0.0f, 1.5f, 0.0f);
	CHARABASE c=GetCharaBase();
	
	return true;
}

void C_EnemyBase::Draw3DAll(void)
{
	//�{�X�ȊO�Ȃ�\��
	if (BodyData.CarBodyNo < 200) {
		CHARABASE c = GetCharaBase();
	}

	Draw3DCar();
	if (Car.Base.Flg == true) {
		if (Parts.size() > 0) {
			for (unsigned int p = 0; p < Parts.size(); p++) {
				Parts[p]->Draw3DParts();
			}
		}
		if (m_Gun.size() > 0) {
			for (unsigned int g = 0; g < m_Gun.size(); g++) {
				m_Gun[g]->Draw3D_Gun();
			}
		}
	}
		//DrawBM();
}

void C_EnemyBase::Draw3DAll(const D3DXVECTOR3 * CamPos)
{
	//�{�X�ȊO�Ȃ�\��
	if (BodyData.CarBodyNo < 200) {
		CHARABASE c = GetCharaBase();
		if (m_HpBase != nullptr) {
			CHARABASE l_c = GetCharaBase();
			m_HpBase->Draw3DAll(&l_c.NowHp, &l_c.MaxHp, CamPos, &Car.Base.Mat, 1.5f*Car.Base.ScaPos.y);
		}
	}

	Draw3DCar();
	if (Car.Base.Flg == true) {
		if (Parts.size() > 0) {
			for (unsigned int p = 0; p < Parts.size(); p++) {
				Parts[p]->Draw3DParts();
			}
		}
		if (m_Gun.size() > 0) {
			for (unsigned int g = 0; g < m_Gun.size(); g++) {
				m_Gun[g]->Draw3D_Gun();
			}
		}
	}
	DrawBM(CamPos);
}

void C_EnemyBase::Draw2DAll(void)
{
	Vect->Draw(Car.Base.Flg);
	if (m_HpBase != nullptr) {
		CHARABASE l_c = GetCharaBase();
		m_HpBase->Draw2DAll(&l_c.NowHp, &l_c.MaxHp);
	}
}

void C_EnemyBase::GetPos2DSet(const D3DXMATRIX *mProj, const D3DXMATRIX *mView, const D3DVIEWPORT9 *Viewport)
{
	judg.Pos2Dpvv(*mProj, *mView, *Viewport);
	D3DXMATRIX Pmat = judg.SetMatP(targetPos);
	Pos2D = judg.Pos2DPE(Car.Base.Mat, Pmat);//���Pos�쐬
	Vect->Update(Pos2D, Car.Base.Mat);
}

bool C_EnemyBase::GetDeleFlg(void)
{
	if (Car.Base.Flg == true)return true;
	if (BulletE.size() > 0)return true;
	return false;
}

void C_EnemyBase::SetParts(std::vector<BillBase*> ground)
{
	
}

void C_EnemyBase::UpdateBullet(void)
{
	//UpdateBME(brj.MoveVec, gunEA->GetBullet(), &gun.BulletFlg,0);
}
