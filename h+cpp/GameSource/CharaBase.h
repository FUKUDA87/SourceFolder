#pragma once
#include<d3dx9.h>
#include"Struct.h"

class C_CharaBase {
public:
	C_CharaBase();
	//�\���̑��
	void SetCharaBase(const CHARABASE *CharaBaseS);
	//�������n��
	CHARABASE GetInitAll(const int MaxHp, const bool DFlg);
	//MaxHp�̏�����
	virtual void SetHp(const int *MaxHp);
	//MaxHp�̏�����
	virtual void SetNowHp(const int *Hp);
	//����Hp�n��
	int GetHp(void);
	//���S�m�F(true�Ŏ�)
	bool Dead(void);
	//�_���[�W�ɂ��Hp���(����Hp������������true)
	bool HpDamage(const int *Damage);
	//�_���[�W���󂯂�Flg�̃Z�b�g
	void SetDamageFlg(const bool *DamageFlg);
	//�_���[�W���󂯂��ԓn��
	bool GetDamageFlg(void);
	//�\���̏�����
	CHARABASE GetInitCharaBase(void);
	//�\���̓n��
	CHARABASE GetCharaBase(void);
	//�ʂ̍\���̑��
	void SetCharaBase(const STATUS* S);

protected:

private: 
	CHARABASE CharaBase;
};