#include "BulletEmpty1.h"
#include"../GameSource/SoundManager.h"

extern SoundManager soundManager;
extern LPDIRECTSOUNDBUFFER lpSPrimary;

extern LPDIRECTSOUND8 lpDSound;	//DirectSound�I�u�W�F�N�g

extern LPDIRECTSOUND3DLISTENER8 lpSListener;


C_BulEmp::C_BulEmp()
{
	Init();
}

C_BulEmp::~C_BulEmp()
{

}

void C_BulEmp::Init(void)
{

		SoundNum = 3;
		SoundSize = -2500;

		soundManager.GetSound(&SoundE[0], &Sound3DE[0], "../GameFolder/Material/wav/BulletEmpty2.wav");
		LPDIRECTSOUNDBUFFER lpSTmp;
		for (int i = 1; i < SoundNum; i++) {
			lpDSound->DuplicateSoundBuffer(SoundE[0], &lpSTmp);
			lpSTmp->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&SoundE[i]);
			SoundE[i]->QueryInterface(IID_IDirectSound3DBuffer8, (LPVOID*)&Sound3DE[i]);
			Sound3DE[i]->SetMode(DS3DMODE_NORMAL, DS3D_IMMEDIATE);
			lpSTmp->Release();
		}
}

bool C_BulEmp::Update(const D3DXVECTOR3 *SoundPos, const D3DXVECTOR3 *CamPos, const D3DXVECTOR3 *CamLook, const D3DXVECTOR3 *CamHead)
{
	DWORD SFlg;
	for (int i = 0; i < SoundNum; i++) {
		Sound3DE[i]->SetPosition(SoundPos->x, SoundPos->y, SoundPos->z, DS3D_IMMEDIATE);//�����̈ʒu
		lpSListener->SetPosition(CamPos->x, CamPos->y, CamPos->z, DS3D_IMMEDIATE);//���X�i�[�̈ʒu
		//���X�i�[�����Ă�������v�Z
		D3DXVECTOR3 Vec;
		Vec = *CamLook - *CamPos;
		D3DXVec3Normalize(&Vec, &Vec);

		lpSListener->SetOrientation(Vec.x, Vec.y, Vec.z, CamHead->x, CamHead->y, CamHead->z, DS3D_IMMEDIATE);//���X�i�[�����Ă�������ƃ��X�i�[�̓��̕���
		SoundE[i]->GetStatus(&SFlg);
		if ((SFlg&DSBSTATUS_PLAYING) == 0) {
			SoundE[i]->Play(0, 0, 0);
			SoundE[i]->SetVolume(SoundSize);
			break;
		}
	}
	return true;
}

void C_BulEmp::ChangeBgm(int Noo)
{
}
