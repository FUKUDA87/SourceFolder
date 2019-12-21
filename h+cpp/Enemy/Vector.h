#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include"../GameSource/Countdown.h"

class Vector {
private:
	CHARA2D vector,vectorC;
	float f;
	D3DXMATRIX NowMat,NowTrans;
	float NowAng;
	Cou *cou;
	int NowCount,CountEnd;
public:
	void Init();
	Vector() { Init(); };
	~Vector();
	bool Update(D3DXVECTOR3 Pos, D3DXMATRIX mat);
	void Draw(bool b);
	//debug�p
	float GetAng(void) { return vector.Base.AngZ; };
};