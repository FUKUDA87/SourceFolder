#pragma once
#include<d3dx9.h>
#include"../GameSource/Const.h"
#include"../GameSource/Struct.h"
#include<stdio.h>

class C_PlayerBody {
public:
	C_PlayerBody();
	~C_PlayerBody();

	//�쐬
	void Save(void);
	void Save2(void);


	//����
	void SetPData(const BODYDATA* Data);

	//�n��
	BODYDATA GetPData(void) {
		return pData;
	}
protected:

private:
	//�ԑ̏��
	BODYDATA pData;

	FILE* fp;
	FILE *fp_b;
};