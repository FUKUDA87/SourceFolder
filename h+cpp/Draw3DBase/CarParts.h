#pragma once
#include"PartsBase.h"
#include<vector>
#include"BaseDataManager/CarDataManager.h"
#include"../Draw3DBase/Draw3DManager/TireMeshManager.h"
#include"../Draw3DBase/Draw3DManager/StandMeshManager.h"
#include"../Draw3DBase/TireParts.h"
#include"../GameSource/Judgment.h"
#include"Draw3DManager/PartsMeshManager.h"
#include"EnemyParts.h"
#include"../EnemyData/Base&Manager/EnemyDataManager.h"

class C_CarParts {
public:
	~C_CarParts();
	//�p�[�c�폜
	void DeleteParts(void);
	//�p�[�c�̈ʒu���̓ǂݍ��݂ƃp�[�c���Z�b�g����
	void SetCarParts(const BODYDATA * Data, const bool SaveFlg);
	//�p�[�c���n��
	unsigned int GetPartsNum(void) {
		return Parts.size();
	}
	//�p�[�c�̏��n��
	PARTS GetPartsData(unsigned int *No);
	//�p�[�c�̕\���s��n��
	D3DXMATRIX GetPartsMat(unsigned int *No);
	//�p�[�c�̃_���[�W����
	bool SetDamageParts(const unsigned int *pNo, const int *Damage);
	//�p�[�c�̐����m�F(0�Ŏ��A�P�Ő��A�Q�͔��ʕs�\)
	int PartsDeadFlg(unsigned int *pNo);
protected:
	BODYDATA BodyData;
	//�W���p�[�c�p
	std::vector<C_PartsBase*>Parts;
	//�ԃp�[�c�p���}�l�[�W���[
	C_CarDataManager CarDataManager;
	//�^�C���}�l�[�W���[
	C_TireMeshManager TireMeshManager;
	//�X�^���h�}�l�[�W���[
	C_StandMeshManager StandMeshManager;
	//�p�[�c�}�l�[�W���[
	C_PartsMeshManager PartsMeshManager;

	//�p�[�c�̈ʒu���̓ǂݍ��݂ƃp�[�c���Z�b�g����
	void SetCarParts(const BODYDATA * Data,const int *EnemyNo, const int *MaxHp, const bool SaveFlg);

private:
	//�^�C���̃p�[�c�Z�b�g
	void SetTireParts(const BODYDATA * Data, const PARTSBASE *PBase);
	//�X�^���h�̃p�[�c�Z�b�g
	void SetStandParts(const BODYDATA * Data, const PARTSBASE *PBase);
	//�J�[�p�[�c�̃p�[�c�Z�b�g
	void SetCarParts(const BODYDATA * Data, const PARTSBASE *PBase);	//�p�[�c�̍\���̕ϊ��n��
	PARTS GetPartsData(const PARTSBASE *PBase);

	Judg judgCP;
};