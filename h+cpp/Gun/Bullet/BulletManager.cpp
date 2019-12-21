#include"BulletManager.h"
#include"../../Sound/BulletEmpty1.h"

//��e
extern C_BulEmp *bulEmp;


void BulletManager::InitBM()
{
	bul1 = 5;
	bulFlg = false;

}

BulletManager::BulletManager(){
	InitBM();
}
BulletManager::~BulletManager()
{
	//�e�̍폜
	for (unsigned int i = 0; i < bullet.size(); i++) {
		BulDelete(&i);
	}
	//�}�[���t���b�V���̍폜
	for (unsigned int i = 0; i < mf.size(); i++) {
		delete mf[i];
		mf.erase(mf.begin() + i);
		i--;
	}
	//��̒e�̍폜
	for (unsigned int b = 0; b < BulletOut.size(); b++) {
		delete BulletOut[b];
		BulletOut.erase(BulletOut.begin() + b);
		b--;
	}


}

bool BulletManager::UpdateBM(D3DXVECTOR3 mVec,BulletBase* bulletBase, MuzFlaBase* muzFlaBase,const D3DXMATRIX *GunMat) {
	if (bulFlg == false) {
		if(key.LClick()){
			bulFlg = true;
			bulCnt = bul1;
			bullet.push_back(bulletBase);
			mf.push_back(muzFlaBase);
			BulletOut.push_back(new C_Bullet3D(GunMat));
		}
	}
	else {
		bulCnt--;
		if (bulCnt <= 0) {
			bulFlg = false;
		}
	}
	//�e�̃A�b�v�f�[�g
	if (bullet.size() > 0) {
		for (unsigned int i = 0; i < bullet.size(); i++) {
			bullet[i]->UpdateMove(mVec);
		}
	}
	//�}�[���t���b�V���̃A�b�v�f�[�g
	if (mf.size() > 0) {
		for (unsigned int i = 0; i < mf.size(); i++) {
			if (mf[i]->Update() == false) {
				delete mf[i];
				mf.erase(mf.begin() + i);
				i--;
			}
		}
	}
	//��̒e�̃A�b�v�f�[�g
	if (BulletOut.size() > 0) {
		for (unsigned int b = 0; b < BulletOut.size(); b++) {
			if (BulletOut[b]->Update(&mVec) == false) {
				delete BulletOut[b];
				BulletOut.erase(BulletOut.begin() + b);
				b--;
			}
		}
	}
	return true;
}
bool BulletManager::UpdateBM(const bool * BirthFlg, D3DXVECTOR3 mVec, BulletBase * bulletBase, MuzFlaBase * muzFlaBase, const D3DXMATRIX * GunMat)
{
	if (bulFlg == false) {
		if (key.LClick()) {
			if (*BirthFlg == true) {
				bulFlg = true;
				bulCnt = bul1;
				bullet.push_back(bulletBase);
				mf.push_back(muzFlaBase);
				BulletOut.push_back(new C_Bullet3D(GunMat));
			}
		}
	}
	else {
		bulCnt--;
		if (bulCnt <= 0) {
			bulFlg = false;
		}
	}
	//�e�̃A�b�v�f�[�g
	if (bullet.size() > 0) {
		for (unsigned int i = 0; i < bullet.size(); i++) {
			bullet[i]->UpdateMove(mVec);
		}
	}
	//�}�[���t���b�V���̃A�b�v�f�[�g
	if (mf.size() > 0) {
		for (unsigned int i = 0; i < mf.size(); i++) {
			if (mf[i]->Update() == false) {
				delete mf[i];
				mf.erase(mf.begin() + i);
				i--;
			}
		}
	}
	//��̒e�̃A�b�v�f�[�g
	if (BulletOut.size() > 0) {
		for (unsigned int b = 0; b < BulletOut.size(); b++) {
			if (BulletOut[b]->Update(&mVec) == false) {
				delete BulletOut[b];
				BulletOut.erase(BulletOut.begin() + b);
				b--;
			}
		}
	}
	return true;
}
bool BulletManager::UpdateBM(const bool * BirthFlg, D3DXVECTOR3 mVec, BulletBase * bulletBase, MuzFlaBase * muzFlaBase, const D3DXMATRIX * GunMat, const SoundCamera * sc)
{
	SoundCamera scc = *sc;
	bool InitSouFlg = false;
	if (bulFlg == false) {
		if (key.LClick()) {
			if (*BirthFlg == true) {
				bulFlg = true;
				bulCnt = bul1;
				bullet.push_back(bulletBase);
				mf.push_back(muzFlaBase);
				BulletOut.push_back(new C_Bullet3D(GunMat));
				InitSouFlg = true;
			}
		}
	}
	else {
		bulCnt--;
		if (bulCnt <= 0) {
			bulFlg = false;
		}
	}

	//�e�̃A�b�v�f�[�g
	if (bullet.size() > 0) {
		for (unsigned int i = 0; i < bullet.size(); i++) {
			bullet[i]->UpdateMove(mVec);
		}
	}
	//�}�[���t���b�V���̃A�b�v�f�[�g
	if (mf.size() > 0) {
		for (unsigned int i = 0; i < mf.size(); i++) {
			if (mf[i]->Update() == false) {
				delete mf[i];
				mf.erase(mf.begin() + i);
				i--;
			}
		}
	}

	//��̒e�̃A�b�v�f�[�g
	if (BulletOut.size() > 0) {
		for (unsigned int b = 0; b < BulletOut.size(); b++) {
			if (BulletOut[b]->Update(&mVec) == false) {
				scc = *sc;
				bulEmp->Update(&judg.SetPosM(BulletOut[b]->GetMat()), &scc.CamPos, &scc.CamLook, &scc.CamHead);
				delete BulletOut[b];
				BulletOut.erase(BulletOut.begin() + b);
				b--;
			}
		}
	}

	return true;
}
bool BulletManager::UpdateBM(const bool * KeyFlg, const bool * BirthFlg, D3DXVECTOR3 mVec, BulletBase * bulletBase, MuzFlaBase * muzFlaBase, const D3DXMATRIX * GunMat, const SoundCamera * sc)
{
	SoundCamera scc = *sc;
	BulletBirthFlgB = false;
	if (bulFlg == false) {
		if (*KeyFlg==true) {
			if (*BirthFlg == true) {
				bulFlg = true;
				bulCnt = bul1;
				bullet.push_back(bulletBase);
				mf.push_back(muzFlaBase);
				BulletOut.push_back(new C_Bullet3D(GunMat));
				BulletBirthFlgB = true;
			}
		}
	}
	else {
		bulCnt--;
		if (bulCnt <= 0) {
			bulFlg = false;
		}
	}
	//�e�̃A�b�v�f�[�g
	if (bullet.size() > 0) {
		for (unsigned int i = 0; i < bullet.size(); i++) {
			bullet[i]->UpdateMove(mVec);
		}
	}
	//�}�[���t���b�V���̃A�b�v�f�[�g
	if (mf.size() > 0) {
		for (unsigned int i = 0; i < mf.size(); i++) {
			if (mf[i]->Update() == false) {
				delete mf[i];
				mf.erase(mf.begin() + i);
				i--;
			}
		}
	}

	//��̒e�̃A�b�v�f�[�g
	if (BulletOut.size() > 0) {
		for (unsigned int b = 0; b < BulletOut.size(); b++) {
			if (BulletOut[b]->Update(&mVec) == false) {
				scc = *sc;
				bulEmp->Update(&judg.SetPosM(BulletOut[b]->GetMat()), &scc.CamPos, &scc.CamLook, &scc.CamHead);
				delete BulletOut[b];
				BulletOut.erase(BulletOut.begin() + b);
				b--;
			}
		}
	}

	return true;
}
bool BulletManager::UpdateBM(void)
{
	if (bullet.size() > 0) {
		for (unsigned int i = 0; i < bullet.size(); i++) {
			if (bullet[i]->Update() == false) {
				BulDelete(&i);
			}
		}
	}
	return true;
}
bool BulletManager::UpdateBM(D3DXMATRIX mat) {
	if (bulFlg == false) {
		if (key.LClick()) {
			bulFlg = true;
			bulCnt = bul1;
			//bullet.push_back(new BulletBase(mat));
		}
	}
	else {
		bulCnt--;
		if (bulCnt <= 0) {
			bulFlg = false;
		}
	}
	if (bullet.size() > 0) {
		for (unsigned int i = 0; i < bullet.size(); i++) {
			if (bullet[i]->Update() == false) {
				BulDelete(&i);
			}
		}
	}
	return true;
}
void BulletManager::DrawBM(void) {
	//�}�[���t���b�V���̕\��
	for (unsigned int i = 0; i < mf.size(); i++) {
		mf[i]->Draw3D();
	}
	//�e�̕\��
	for (unsigned int i = 0; i < bullet.size(); i++) {
		bullet[i]->Draw3D();
	}
	//��̒e�̕\��
	for (unsigned int b = 0; b < BulletOut.size(); b++) {
		BulletOut[b]->Draw3D();
	}

}
void BulletManager::BulDelete(unsigned int * i)
{
	delete bullet[*i];
	bullet.erase(bullet.begin() + *i);
	*i--;
}
