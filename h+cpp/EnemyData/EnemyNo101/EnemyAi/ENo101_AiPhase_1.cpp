#include "ENo101_AiPhase_1.h"
/*
�t�F�[�Y�O�F����
Speed���ŏ���̈ʒu�ɒ����ƃt�F�[�Y�P
�t�F�[�Y�P�F�e(1)�̉�]
�e(1)��Hp���O�ɂȂ�ƃt�F�[�Y�Q
�t�F�[�Y�Q�F�h�A�̃I�[�v���A�e(�Q)�̉�]�A�{��HP����true
�{��Hp���U�U���ȉ��ɂȂ�΃t�F�[�Y�R
�t�F�[�Y�R�F�t�F�[�Y�P�Ɠ���
�t�F�[�Y�S�Ŗ{��Hp��33���ȉ��ɂȂ�΃t�F�[�Y�T
�t�F�[�Y6�Ŗ{��Hp��0���ȉ��ɂȂ�΃t�F�[�Y�V

*/

C_E_No101_AiPhase_1::C_E_No101_AiPhase_1()
{
	InitFlg = true;
}

C_E_AiPhaseBase * C_E_No101_AiPhase_1::Action(const CHARABASE * Chara, int * NewPhase)
{
	float Hp=(float)Chara->NowHp, MaxHp = (float)Chara->MaxHp;
	float S = Hp / MaxHp;
	if (S < 0.67f) {
		if (S < 0.34f) {
			if (Chara->NowHp <= 0) {
				*NewPhase = Phase7;
				return nullptr;
			}
			else {
				if (*NewPhase == Phase4)*NewPhase = Phase5;
				return nullptr;
			}
		}
		else {
			if (*NewPhase == Phase2)*NewPhase = Phase3;
			return nullptr;
		}
	}
	return nullptr;
}
