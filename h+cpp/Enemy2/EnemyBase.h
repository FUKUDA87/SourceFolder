#pragma once
#include"../Draw3DBase/CarE.h"
#include"../Enemy/Vector.h"
#include"../Enemy/HpEne.h"
#include"../Draw/Hp/HpBase.h"

class C_EnemyBase :public C_CarE {
public:
	C_EnemyBase();
	~C_EnemyBase();
	//������
	void InitEnemy(void);
	//�A�b�v�f�[�g
	bool UpdateCar(void);
	//�\��
	void Draw3DAll(void);
	void Draw3DAll(const D3DXVECTOR3 *CamPos);
	void Draw2DAll(void);
	//���쐬�ɕK�v�ȏ��̎擾�ƃA�b�v�f�[�g
	void GetPos2DSet(const D3DXMATRIX *mProj, const D3DXMATRIX *mView, const D3DVIEWPORT9 *Viewport);

	//�G�l�~�[�̑��ݍ폜�n��
	bool GetDeleFlg(void);

	//�p�[�c�̈ʒu����
	void SetParts(std::vector<BillBase*>ground);

	void UpdateBullet(void);

protected:
	//���
	Vector *Vect;

	C_HpBase* m_HpBase;

	D3DXVECTOR3 Pos2D;
	D3DXVECTOR3 targetPos;//player��pos�擾�p

	int m_EnemyNo;
private:
	
};