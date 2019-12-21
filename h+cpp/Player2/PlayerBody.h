#pragma once
#include<d3dx9.h>
#include"../GameSource/Const.h"
#include"../GameSource/Struct.h"
#include<stdio.h>

class C_PlayerBody {
public:
	C_PlayerBody();
	~C_PlayerBody();

	//作成
	void Save(void);
	void Save2(void);


	//入れ
	void SetPData(const BODYDATA* Data);

	//渡し
	BODYDATA GetPData(void) {
		return pData;
	}
protected:

private:
	//車体情報
	BODYDATA pData;

	FILE* fp;
	FILE *fp_b;
};