#pragma once
#include<d3dx9.h>
#include"StandE.h"
#include"../Gun/Bullet/EBulletManager.h"
#include"../Gun/GunDraw/GunEA.h"
#include"../Gun/Laser/LaserManager.h"
#include"../Key/Key.h"

class GunE :public StandE {
public:
	void InitGun();
	GunE() { InitGun(); };
	GunE(D3DXMATRIX GroundMat, float *TransX) : StandE(GroundMat,TransX) { InitGun();};
	~GunE() { delete bul; delete gunEA; delete laserMan; };
	virtual bool GunUpdate();
	virtual bool GunVec();
	void GunDraw();
	bool UpdateB();
	void DrawB();

	bool UpdateAll();
	void DrawAll();

	bool LaserUpdate();

	bool UpdateEnd();

	bool GetFlgEA(void);

	void SetTarget(D3DXVECTOR3 Pos) { targetPos = Pos; };

	D3DXMATRIX GetBulMat(int i) { return bul->GetBulMat(i); };
	void SetBulDel(unsigned int *i) { return bul->BulDelete(i); };
	unsigned int GetBulSiz(void) { return bul->GetBulSize(); };
	//Bullet�ړ��̒����n��
	float GetBulletMMoveDis(unsigned int i) { return bul->GetBulletMoveDis(i); }

	//���[�U�[�p
	D3DXVECTOR3 GetLasVec() {
		return laserMan->GetLVec();
	}
	D3DXMATRIX GetLasMat() {
		return laserMan->GetLMat();
	}
	void SetLasDis(float Dis, bool b);
	float GetLasDis() {
		return laserMan->GetLDis();
	}
protected:
	D3DXMATRIX StartMat, EndMat;
	//���[�U�[
	LaserManager *laserMan;
	float lDis;
	bool lFlg;
	EBulletManager *bul;
	GunEA* gunEA;
	Object3D gun;
	D3DXVECTOR3 targetPos;//player��pos�擾�p
	bool bat;//�U�����
	bool batF;

	float fAnim;

	//�L�[
	Key key;
private:

};