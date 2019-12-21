#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include"../GameSource/Judgment.h"
#include"../GameSource/CharaBase.h"

class C_PartsBase:public C_CharaBase {
public:
	C_PartsBase(const PARTS *InitGetParts);
	~C_PartsBase();

	//�\��
	void Draw3DParts(void);

	//�A�b�v�f�[�g
	virtual bool UpdateParts(const D3DXMATRIX *Mat);
	//�A�b�v�f�[�g�{�g��̕ω�
	virtual bool UpdateParts(const D3DXMATRIX *Mat,const D3DXVECTOR3 *ScalPos);
	virtual bool UpdateParts(const D3DXMATRIX * Mat, const D3DXVECTOR3 * ScalPos, int *Phase) { return true; };

	//���n��
	PARTS GetParts(void) {
		return Parts;
	}
	//�\���p�s��n��
	D3DXMATRIX GetDrawMatParts(void);

	//�X�s�[�h�Z�b�g
	void SetSpeed(const int *GetNowSpeed, const int *GetMaxSpeed);

protected:
	PARTS Parts;

	Judg judg;

	//�\���P
	void Draw3DDrawMesh(void);
	//�\���Q
	void Draw3DDaedMesh(void);
	//�X�s�[�h(�J�[�̍��̃X�s�[�h�ƍő�X�s�[�h)
	int NowSpeed,MaxSpeed;

	//�ԑ̂̊g��s�񂢂�
	D3DXVECTOR3 ScalPosBody;

	//������
	void InitParts(void);
	//�g��ω�
	void ScalParts(const D3DXVECTOR3 *ScalPos);
private:

};