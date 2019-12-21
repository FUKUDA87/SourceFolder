#pragma once
#include<d3dx9.h>
#include<dsound.h>


class C_BulEmp{
public:
	C_BulEmp();
	~C_BulEmp();
	//������
	void Init(void);
	//�A�b�v�f�[�g
	virtual bool Update(const D3DXVECTOR3 *SoundPos, const D3DXVECTOR3 *CamPos, const D3DXVECTOR3 *CamLook, const D3DXVECTOR3 *CamHead);
	//�`�F���WBGM
	void ChangeBgm(int Noo);
protected:
	//�T�E���h��
	int SoundNum;
	//���̃T�E���h
	int NowSound;
	//�T�E���h�ϐ�
	LPDIRECTSOUNDBUFFER8 SoundE[3];
	LPDIRECTSOUND3DBUFFER8 Sound3DE[3];
	//����
	int SoundSize;

private:
};