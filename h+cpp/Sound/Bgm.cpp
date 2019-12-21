#include "Bgm.h"
#include"../GameSource/SoundManager.h"

extern SoundManager soundManager;
extern LPDIRECTSOUNDBUFFER lpSPrimary;
extern LPDIRECTSOUND3DLISTENER8 lpSListener;


C_Bgm::C_Bgm()
{
	Init();
}

C_Bgm::~C_Bgm()
{
	delete[] SoundSize;
}

void C_Bgm::Init(void)
{

	SoundNum = 3;
	NowSound = 0;

	SoundSize = new int[SoundNum];
	SoundSize[0] = -3000;
	SoundSize[1] = -3000;
	SoundSize[2] = -3500;

	StopFlg = false;

	//�^�C�g��
	soundManager.GetSound(&SoundB[0], &Sound3DB[0], "../GameFolder/Material/wav/BGM1.wav");
	//�X�e�[�W
	soundManager.GetSound(&SoundB[1], &Sound3DB[1], "../GameFolder/Material/wav/BGM2-2.wav");
	//�Q�[��
	soundManager.GetSound(&SoundB[2], &Sound3DB[2], "../GameFolder/Material/wav/BGM2.wav");
}

bool C_Bgm::Update(const bool * Flg)
{
	//for (int s = 0; s < SoundNum; s++) {
	//	DWORD SFlg;
	//	Sound[s]->GetStatus(&SFlg);
	//	if (s == NowSound) {
	//		if ((SFlg&DSBSTATUS_PLAYING) == 0) {
	//			Sound[s]->Play(0, 0, 0);
	//		}
	//	}
	//	else {
	//		if ((SFlg&DSBSTATUS_PLAYING) != 0) {
	//			//Sound[NowSound]->Play(0, 0, 0);
	//			Sound[s]->Stop();
	//			Sound[s]->SetCurrentPosition(0);
	//		}
	//	}
	//}
	if (StopFlg == false) {
		Sound3DB[NowSound]->SetMode(DS3DMODE_DISABLE, DS3D_IMMEDIATE);
		DWORD SFlg;
		SoundB[NowSound]->GetStatus(&SFlg);
		if ((SFlg&DSBSTATUS_PLAYING) == 0) {
			SoundB[NowSound]->Play(0, 0, 0);
			SoundB[NowSound]->SetVolume(SoundSize[NowSound]);
		}
	}
	/*if (GetAsyncKeyState('S') & 0x8000) {
		Sound[NowSound]->Play(0, 0, 0);
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		Sound[NowSound]->Stop();
	}*/
	return true;
}

bool C_Bgm::Update(const bool * Flg, const SoundCamera * sc)
{
	if (StopFlg == false) {
		Sound3DB[NowSound]->SetPosition(sc->CamPos.x, sc->CamPos.y, sc->CamPos.z, DS3D_IMMEDIATE);//�����̈ʒu
		lpSListener->SetPosition(sc->CamPos.x, sc->CamPos.y, sc->CamPos.z, DS3D_IMMEDIATE);//���X�i�[�̈ʒu
		//���X�i�[�����Ă�������v�Z
		D3DXVECTOR3 Vec;
		Vec = sc->CamLook - sc->CamPos;
		D3DXVec3Normalize(&Vec, &Vec);

		lpSListener->SetOrientation(Vec.x, Vec.y, Vec.z, sc->CamHead.x, sc->CamHead.y, sc->CamHead.z, DS3D_IMMEDIATE);//���X�i�[�����Ă�������ƃ��X�i�[�̓��̕���
		DWORD SFlg;
		SoundB[NowSound]->GetStatus(&SFlg);
		if ((SFlg&DSBSTATUS_PLAYING) == 0) {
			SoundB[NowSound]->Play(0, 0, 0);
			/*if (NowSound == 2) {
				SoundSize = -1500;
			}
			else {
				SoundSize = -1000;
			}*/
			SoundB[NowSound]->SetVolume(SoundSize[NowSound]);
		}
	}
	return true;
}

void C_Bgm::StopSound(void)
{
	SoundB[NowSound]->Stop();
	StopFlg = true;
}

void C_Bgm::StartSound(void)
{
	SoundB[NowSound]->Play(0, 0, 0);
	SoundB[NowSound]->SetVolume(SoundSize[NowSound]);
	StopFlg = false;
}

void C_Bgm::ChangeBgm(int Noo)
{
	if ((Noo < 0) || (Noo >= SoundNum)|| (NowSound == Noo))return;
	SoundB[NowSound]->Stop();
	SoundB[NowSound]->SetCurrentPosition(0);
	NowSound = Noo;
	StopFlg = false;
}
