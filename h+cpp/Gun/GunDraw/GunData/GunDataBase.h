#pragma once
#include<d3dx9.h>
#include"../../../GameSource/Const.h"


class C_GunDataBase {
public:
	~C_GunDataBase();
	int GetGunMouthNum(void);
	D3DXVECTOR3 GetGunMouthPos(const int *GunMouthNo);
protected:
	//��΂ɃR���X�g���N�^�ɏ���
	virtual void SetInitGun(void) = 0;
	//�������K�{
	void InitGun(const int Num);
	bool SetGunMouthPos(const int *No,const D3DXVECTOR3*Pos);
private:
	void SetInitGunMouthPos(void);
	void DeletePos(void);
	void SetGunMouthNum(const int Num);
	int GunMouthNum;
	D3DXVECTOR3 *MouthPos;
};