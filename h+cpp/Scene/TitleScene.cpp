#include"TitleScene.h"
#include"SceneManager.h"
#include"GameScene.h"
#include"../GameSource/TextureManager.h"
#include"../GameSource/XfileManager.h"
#include"StageSelectScene.h"
#include"../Sound/Bgm.h"

extern TextureManager textureManager;
extern XfileManager xfileManager;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g
extern SceneManager sceneManager;
extern LPDIRECT3DDEVICE9		lpD3DDevice;	// Direct3DDevice�C���^�[�t�F�C�X
extern C_Bgm *bgm;

#define	SCRW		1280	// �E�B���h�E���iWidth
#define	SCRH		720		// �E�B���h�E�����iHeight
#define StageSelectNo 1

void LoadTexture(LPDIRECT3DTEXTURE9 *lpTex, const char fname[], int W, int H, D3DCOLOR Color);


TitleScene::TitleScene()
{
	//�V�[���̐؂�ւ�������
	SceneChangeFlg = false;
	//�t�F�[�h�̏�����
	fade = new Fade();
	fade->ChaFlg(false);

	//�v���C���[�̏������̑O�ɏ�����
	PlaBodData = new C_PlayerBody();

	player = new C_PlayerA(&PlaBodData->GetPData());
	//�n�ʏ�����--------------------------------------------------------
	//�O���̊Ԋu������
	int CountInit = 4;
	LightCount = new C_Count(&CountInit);

	cou = new Cou(0, 5, 1, true, false);
	int i = 0, z;
	ground.push_back(new BillBase(i));
	z = (int)ground[0]->GetPosZ() * 2;
	i = (int)player->GetRadF() / z;
	delete ground[0];
	ground.erase(ground.begin() + 0);
	for (int n = i * (-1); n < i; n++) {
		if (cou->CouJudge() == false) {
			cou->SetNum(0);
		}
		if (cou->GetNum() == 1) {
			ground.push_back(new Bill(n)); //ground.push_back(new BillBase(n));
		}
		else {
			ground.push_back(new Bill(n));
		}
		//�O���̏�����
		if (LightCount->Update() == true) {
			int wNum = 2;
			ground[ground.size() - 1]->InitLight(&wNum);
		}
		cou->CouUpd();
	}
	for (unsigned int i = 0; i < ground.size(); i++) {
		if (judg.ball(player->GetMatCar(), ground[i]->GetMat(), player->GetRadF()) == false) {
			delete ground[i];
			ground.erase(ground.begin() + i);
			i--;
		}
	}
	int c = 2;
	/*for (int i = (ground.size() - 1); i >= 0; i--) {
		if (ground[i]->GetObjFlg() == true) {
			if (c == 4) c = 1;
			break;
		}
		else {
			c++;
		}
	}*/
	cou->SetNum(c);
	//�J�[�u�̌`��������
	GroKNum = 4;
	GroType = 1;
	CurType = new int[GroKNum];
	CurType[0] = CurType[3] = 1;
	CurType[1] = CurType[2] = 2;
	NowCur = 0;
	//player�̈ʒu����
	unsigned int num;
	float Dis;
	if (ground.size() > 100) {
		i = (int)(ground.size() - ground.size() / 10);
		D3DXMATRIX gMat, Trans;
		gMat = ground[i]->GetWay().StartMat;
		D3DXMatrixTranslation(&Trans, 0.0f, 0.1f, 0.0f);

		D3DXMATRIX TmpMat= Trans * gMat;
		player->SetMatCar(&TmpMat);
		player->SetRadF(player->GetRadF() / 2.0f);
	}
	if (NowGroNum(player->GetMatCar(), &num, &Dis) == true) {
		player->SetGroNum(num);//�n�ʂ̎擾
	}

	//---------------------------------------------------------------------
	//�}�E�X�̏�����
	mouse = new C_Mouse();
	mouse->ChaDrawFlg(true);

	titleTex = new TitleTex();
	startTex = new StartTex();

	camera = new TitleCamera();
	sky = new Sky();

	key.Init();

	//bgm0��
	int sNo = 0;
	bgm->ChangeBgm(sNo);

	//�e���̏�����
	if (false) {
		float AngZ = -90.0f;
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(250.0f, 720.0f / 4.0f*3.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 1));
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(250.0f, 720.0f / 4.0f*3.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 2));
		AngZ = (70.0f)*-1.0f;
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(1050.0f, 500.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 1));
		AngZ += 50.0f;
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(990.0f, 380.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 1));
		AngZ -= 50.0f;
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(1050.0f, 500.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 2));
		AngZ += 50.0f;
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(990.0f, 380.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 2));
		AngZ = -0.0f;
		//BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(455.0f, 85.0f, 0.0f), &AngZ, &D3DXVECTOR3(1.2f, 1.2f, 1.0f)));
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(300.0f, 200.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 1));
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(300.0f, 200.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 2));

		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(1100.0f, 100.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 1));
		BulHol.push_back(new C_BulletHole(&D3DXVECTOR3(1100.0f, 100.0f, 0.0f), &AngZ, &D3DXVECTOR3(2.1f, 2.1f, 1.0f), 2));
	}

}
TitleScene::~TitleScene()
{
	delete player;
	delete titleTex;
	delete startTex;
	delete camera;
	delete sky;
	//�n�ʂ̍폜
	for (unsigned int i = 0; i < ground.size(); i++) {
		delete ground[i];
		ground.erase(ground.begin() + i); i--;
	}
	delete[] CurType;
	if (GroCou.size() > 0) {
		for (unsigned int g = 0; g < GroCou.size(); g++) {
			delete GroCou[g];
			GroCou.erase(GroCou.begin() + g);
			g--;
		}
	}
	delete cou;
	//�e���폜
	if (BulHol.size() > 0) {
		for (unsigned int b = 0; b < BulHol.size(); b++) {
			delete BulHol[b];
			BulHol.erase(BulHol.begin() + b);
			b--;
		}
	}
	//�}�E�X�̍폜
	delete mouse;
	//�t�F�[�h�̍폜
	delete fade;

	delete PlaBodData;

	//���C�g�̃J�E���g�_�E���̍폜
	if (LightCount != nullptr) {
		delete LightCount;
	}

	//textureManager.AllDelete();
	//xfileManager.AllDelete();
}
bool TitleScene::Update(void)
{
	//bgm�̃A�b�v�f�[�g
	bool bFlg = true;
	SoundCamera scB;
	scB.CamPos = camera->GetPos();
	scB.CamLook = camera->GetLook();
	scB.CamHead = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	bgm->Update(&bFlg/*,&scB*/);

	mouse->Update();

	//�t�F�[�h�̃A�b�v�f�[�g
	if (fade->Update() == true) {
		//�L�[�̖��͉�

	}
	else {
		if (fade->GetMoveEndFlg() == true) {
			if (SceneChangeFlg == true)return SetScene();
		}
	}

	if (startTex->UpdateSu() == false) {
		mouse->SetTouchFlg();
		if (startTex->GetMoveFlg() == false) {
			if (key.LClickF() == true) {
				startTex->SetMoveFlg(true);
				ChangeSceneFade(StageSelectNo);
				bool CFlg = true;
				ClickSound->UpdateCli(&CFlg);
				bgm->StopSound();
			}
		}
	}

	//================================================================================
	//�n��
	//================================================================================
	if (ground.size() > 0) {
		for (unsigned int i = 0; i < ground.size(); i++) {
			ground[i]->SuperUpdate();
			//�����̓��̍폜�ƍ쐬
			if (player->GetGroNum() > i) {
				if (judg.ball(player->GetMatCar(), ground[i]->GetMat(), player->GetRadF()) == false) {
					if (ground[i]->GetFlg() == true) {
						delete ground[i];
						ground.erase(ground.begin() + i);
						i--;

						bool Flg = true;
						if (Flg == true) {
							D3DXMATRIX Mat[2];
							Mat[0] = ground[ground.size() - 1]->GetMat0();
							Mat[1] = ground[ground.size() - 1]->GetMat1();
							int StopNum;
							if (GroCou.size() == 0) {//�n�ʂ̌`��
								if (GroType == 0) {
									GroType = CurType[NowCur];
									NowCur++;
									if (NowCur == GroKNum)NowCur = 0;
								}
								else {
									GroType = 0;
									cou->SetNum(2);
								}
								if (GroType == 0)StopNum = rand() % 20 + 40;
								if (GroType == 1)StopNum = 5;
								if (GroType == 2)StopNum = 5;
								if (GroType != 0) {
									AngGro = 90.0f / 5.0f;
									GroLenFlg = false;
								}
								else {
									GroLenFlg = true;
								}
								GroCou.push_back(new Cou(0, StopNum, 1, true, false));
							}
							if (cou->CouJudge() == false) {
								cou->SetNum(0);
							}
							if ((cou->GetNum() == 1) && (GroType == 0)) {
								ground.push_back(new Bill(Mat[1], Mat[0], GroType, AngGro, 5.0f, GroLenFlg)); //ground.push_back(new BillBase(Mat[1], Mat[0], GroType, AngGro, 5.0f, GroLenFlg));
							}
							else {
								ground.push_back(new Bill(Mat[1], Mat[0], GroType, AngGro, 5.0f, GroLenFlg));
							}

							//�O���̏�����
							if (LightCount->Update() == true) {
								int wNum = 2;
								ground[ground.size() - 1]->InitLight(&wNum);
							}

							if (GroCou.size() > 0) {
								for (unsigned int g = 0; g < GroCou.size(); g++) {
									GroCou[g]->CouUpd();
									if (GroCou[g]->CouJudge() == false) {
										for (unsigned int g = 0; g < GroCou.size(); g++) {
											delete GroCou[g];
											GroCou.erase(GroCou.begin() + g);
											g--;
										}
										if (GroCou.size() <= 0) {
											break;
										}
									}
								}
							}
							if (GroType == 0) {
								cou->CouUpd();
							}
						}
					}
				}
				else {
					//�V�i�̓��𔻒�ł���悤�ɂ���
					if (ground[i]->GetFlg() == false) {
						ground[i]->SetFlg(true);
					}
				}
			}
		}
	}
	//�v���C���[�ƒn�ʔ���
	float Dis;
	unsigned int num;
	if (NowGroNum(player->GetMatCar(), &num, &Dis) == true) {
		player->SetGroNum(num);//�n�ʂ̎擾
	}
	player->UpdateCarFM(ground);
	D3DXMATRIX Mat = player->GetMatCar();
	judg.SetMatP(&Mat, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	player->UpdateAll(&Mat);
	camera->Update(player->GetMatCar());
	sky->Update(player->GetMatCar());

	
	return true;
}

void TitleScene::Render2D(void)
{
	//////////////////////////////////////////////////
	///	�X�v���C�g�̕`�揈��
	//////////////////////////////////////////////////
	// �`��J�n
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);

	//titleTex�̕\��
	titleTex->Draw();

	startTex->DrawSu();

	fade->Draw();

	//�e���\��
	if (BulHol.size() > 0) {
		for (unsigned int b = 0; b < BulHol.size(); b++) {
			BulHol[b]->Draw2DBH();
		}
	}
	

	mouse->Draw2D();
	// �`��I��
	lpSprite->End();
}

void TitleScene::Render3D(void)
{
	for (unsigned int i = 0; i < ground.size(); i++) {
		ground[i]->SuperDraw();
	}
	player->Draw3DAll();
	sky->Draw();
}

void TitleScene::SetCamera(void)
{
	D3DXMATRIX mView, mProj;
	D3DXMatrixLookAtLH(&mView,
		&camera->GetPos(),//�J�����̈ʒu
		&camera->GetLook(),// �J�����̎��_
		&D3DXVECTOR3(0.0f, 1.0f, 0.0f)	// �J�����̓��̕���
	);

	// ���e�s��̐ݒ�
	D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), (float)SCRW / (float)SCRH, 0.1f, 1200.0f);

	//�s��ݒ�
	lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
	lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);

}
bool TitleScene::NowGroNum(D3DXMATRIX Mat, unsigned int *Num, float *Dis)
{
	if (ground.size() <= 0) {
		return false;
	}
	float size;
	//�n�ʃ��C����
	for (unsigned int g = 0; g < ground.size(); g++) {
		if (judg.ball(Mat, ground[g]->GetMat(), 40.0f) == true) {//�����̎��͂̒n�ʂ����𔻒�
			D3DXVECTOR3 v[4];
			for (int i = 0; i < 4; i++) {
				v[i] = ground[g]->GetVer(i);
			}
			if (ground[g]->GetIdenFlg() == false) {//�n�ʂ�IdentityMat�ŏo���Ă��邩�̔���
				if (judg.RayPolM(Mat, v[0], v[1], v[2], v[3], ground[g]->GetMat(), D3DXVECTOR3(0.0f, -1.0f, 0.0f), &size) == true)//�|���S���ƃ��C����
				{
					*Num = g;
					*Dis = size;
					return true;
				}
			}
			else {
				if (judg.RayPolM(Mat, v[0], v[1], v[2], v[3], D3DXVECTOR3(0.0f, -1.0f, 0.0f), &size) == true)//�|���S���ƃ��C����
				{
					*Num = g;
					*Dis = size;
					return true;
				}
			}
		}
	}
	return false;
}

void TitleScene::ChangeSceneFade(int ChangeSceneNo)
{
	if (fade->GetMoveFlg() == false) {
		if (SceneChangeFlg == false) {
			SceneNo = ChangeSceneNo;
			SceneChangeFlg = true;
			bool BlackFlg = true;
			//if (ChangeSceneNo == GameNo)BlackFlg = false;
			fade->SetIn(BlackFlg);
		}
	}
}

bool TitleScene::SetScene(void)
{
	if (SceneNo == StageSelectNo) {
		sceneManager.changeScene(new StageSelectScene());
		return false;
	}
	return true;
}
