#pragma once
#include"Hp.h"
#include<d3dx9.h>
#include"../GameSource/TextureManager.h"
#include"NumA.h"

extern TextureManager textureManager;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g

class HpD :public HP,NumA{
private:
protected:
	CHARA2D Slash;
	int Hp;
	int Maxhp;
public:
	void InitNum();
	HpD() { 
		InitNum();
	};
	~HpD() {};
	bool UpdateNum(int Max, int nowHp, bool disp);
	void DrawNum();

	bool UpdateAll(int Max, int nowHp, bool disp);
	void DrawAll();
};