#pragma once
#include"Spark.h"

class C_SparkDamage :public C_Spark{
public:
	C_SparkDamage(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos);
	//�n��(0)�ƕ�(1,2)�Ǝ�(3)�ɒe�������������̉Ή�
	C_SparkDamage(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos,const int *SparkFlg,const float *Ang);
	~C_SparkDamage();
	//�A�b�v�f�[�g
	bool UpdateSD(void);
	bool UpdateCar(void);
	bool UpdateSuper(void);
	//�\��
	void DrawSD(void);
	void Draw3DSuper(void);
protected:

private:
	//�ϐ�----------------------------------------------------------------------------------
	Pol Flash;
	//�ŏ������\��Flg
	bool DrawSDFlg;
	//�|���S���T�C�YSD
	float PolSizeSD;
	//Update�̎d��Flg
	bool UpdateFlg;
	//�֐�----------------------------------------------------------------------------------
	//�n�ʔ���
	void SparkJudgGround(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos, const int *SparkFlg);
	//�ǔ���
	void SparkJudgWall(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos, const int *SparkFlg);
	//�Ԕ���
	void SparkJudgCar(const D3DXMATRIX *Mat, const D3DXVECTOR3 *Pos, const int *SparkFlg,const float *Ang);
};