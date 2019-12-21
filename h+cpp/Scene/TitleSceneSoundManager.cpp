#include "TitleSceneSoundManager.h"

C_TitleSSM::C_TitleSSM()
{
	InitSSM();
}

C_TitleSSM::~C_TitleSSM()
{
	EndSSM();
}

void C_TitleSSM::InitSSM(void)
{
	//�N���b�N���̏�����
	ClickSound = new C_ClickSound();
}

void C_TitleSSM::EndSSM(void)
{
	if (ClickSound != nullptr) {
		delete ClickSound;
	}
}
