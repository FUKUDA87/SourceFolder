#pragma once
#include<d3dx9.h>
#include<string>
#include"../GameSource/Judgment.h"

class C_Num2DBase {
public:

	//�ʒu�Ɗg��̃Z�b�g
	void SetNum(const D3DXVECTOR3 *Pos, const D3DXVECTOR3 *Scal);
	//�摜�̃Z�b�g
	void SetTex(std::string FileName,const int *Width, const int *Height);
	//�\��(�p��������)
	virtual void Draw2DNB(const int *TmpNum)=0;
	//�\���p�s��̍쐬
	virtual D3DXMATRIX GetDrawMatNDB(const D3DXMATRIX *Mat);
	//�摜�̏��n��
	CHARA2D GetTexNDB(void) {
		return Num;
	}
protected:
	Judg judg;
	CHARA2D Num;
private:
};