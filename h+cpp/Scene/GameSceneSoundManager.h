#pragma once
#include"SceneSoundManager.h"
//�T�E���h
#include"../Sound/SoundGun1.h"

class C_GameSSM :public C_SceneSoundManager {
public:
	C_GameSSM();
	~C_GameSSM();

	//�N���X
	//�e��
	C_SoundGun *SoundGun;

protected:

private:
	void InitSSM(void);
	void EndSSM(void);
};