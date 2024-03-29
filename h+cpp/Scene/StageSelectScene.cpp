#include"StageSelectScene.h"
#include"GameScene.h"
#include"TitleScene.h"
#include"SceneManager.h"
#include"../Sound/Bgm.h"

extern C_Bgm *bgm;
extern SceneManager sceneManager;

#define	SCRW		1280	// ウィンドウ幅（Width
#define	SCRH		720		// ウィンドウ高さ（Height
#define GameNo 2
#define TitleNo 1

StageSelectScene::StageSelectScene()
{
	mouse = new C_Mouse();
	mouse->ChaDrawFlg(true);
	sky = new StageSky();

	//プレイヤーの初期化前に初期化
	PlayerBody = new C_PlayerBody();

	car = new StageCar(&PlayerBody->GetPData());
	cam = new StageCam();
	modoru = new Modoru();

	//シーンの切り替え初期化
	SceneChangeFlg = false;
	//フェードの初期化
	fade = new Fade();
	fade->ChaFlg(false);

	key.Init();

	//bgmのコンストラクタ
	bgm->ChangeBgm(1);


	//選択モードの初期化の前に初期化
	Ok = new C_OK(&D3DXVECTOR3(1.1f, 1.1f, 0.0f), &D3DXVECTOR3(1280.0f/2.0f, 720.0f*0.93f, 0.0f), &D3DXVECTOR3(0.25f, 0.11f, 0.0f));
	

	//選択モードの初期化
	InitStaSel();

}

StageSelectScene::~StageSelectScene()
{
	delete sky;
	delete car;
	delete cam;
	delete modoru;

	//マウスの削除
	delete mouse;
	//フェードの削除
	delete fade;

	DeleteCarSel();

	DeleteStaSel();

	//プレイヤーの情報削除
	delete PlayerBody;
	//Okボタンの削除
	delete Ok;

	EndFlg = false;
}

void StageSelectScene::Render2D(void)
{
	//////////////////////////////////////////////////
	///	スプライトの描画処理
	//////////////////////////////////////////////////
	// 描画開始
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);
	//戻る
	modoru->DrawSu();
	//ステージ
	if (stage.size() > 0) {
		for (unsigned int s = 0; s < stage.size(); s++) {
			stage[s]->DrawSu();
		}
	}

	if (CarSel.size() > 0) {
		for (unsigned int c = 0; c < CarSel.size(); c++) {
			CarSel[c]->Draw2DAll();
		}
	}

	Ok->Draw2DOK();

	fade->Draw();
	mouse->Draw2D();
	// 描画終了
	lpSprite->End();
}

void StageSelectScene::Render3D(void)
{
	//ステージ外

	//ガレージ
	sky->Draw();
	//車体
	car->Draw3DAll();
}

bool StageSelectScene::Update(void)
{

	//bgmのアップデート
	bool bFlg = true;
	SoundCamera scB;
	scB.CamPos = cam->GetPos();
	scB.CamLook = cam->GetLook();
	scB.CamHead = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	bgm->Update(&bFlg/*,&scB*/);

	mouse->Update();

	//フェードのアップデート
	if (fade->Update() == true) {
		//キーの無力化

	}
	else {
		if (fade->GetMoveEndFlg() == true) {
			if (SceneChangeFlg == true)return SetScene();
		}
	}

	ChangeMode();

	D3DXMATRIX cTmp;
	D3DXMatrixTranslation(&cTmp, 0.0f, 1.0f, 0.0f);
	cam->Update(car->GetMatCar(), cTmp, true);

	car->UpdateAll();

	D3DXMATRIX tmp;
	D3DXMatrixTranslation(&tmp, 0.0f, 2.0f, 0.0f);
	sky->Update(tmp);
	return true;
}

void StageSelectScene::SetCamera(void)
{
	D3DXMATRIX mView, mProj;
	D3DXMatrixLookAtLH(&mView,
		&cam->GetPos(),//カメラの位置
		&cam->GetLook(),// カメラの視点
		&D3DXVECTOR3(0.0f, 1.0f, 0.0f)	// カメラの頭の方向
	);

	// 投影行列の設定
	D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), (float)SCRW / (float)SCRH, 1.0f, 1000.0f);

	//行列設定
	lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
	lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);
}

void StageSelectScene::ChangeSceneFade(int ChangeSceneNo)
{
	if (fade->GetMoveFlg() == false) {
		if (SceneChangeFlg == false) {
			SceneNo = ChangeSceneNo;
			if (ChangeSceneNo == GameNo)return;
			StartFade();
			return;
		}
	}
}

void StageSelectScene::ChangeSceneFade(int ChangeSceneNo, int NextStageNo)
{
	ChangeSceneFade(ChangeSceneNo);
	ChangeStageNo = NextStageNo;
}

bool  StageSelectScene::SetScene(void)
{
	if (SceneNo == TitleNo) {
		sceneManager.changeScene(new TitleScene());
		return false;
	}
	if (SceneNo = GameNo) {
		sceneManager.changeScene(new GameScene(ChangeStageNo));
		return false;
	}
	return true;
}

void StageSelectScene::DeleteCarSel(void)
{
	//削除
	if (CarSel.size() > 0) {
		for (unsigned int c = 0; c < CarSel.size(); c++) {
			delete CarSel[c];
			CarSel.erase(CarSel.begin() + c);
			c--;
		}
	}
}

void StageSelectScene::DeleteStaSel(void)
{
	//削除
	if (stage.size() > 0) {
		for (unsigned int i = 0; i < stage.size(); i++) {
			delete stage[i];
			stage.erase(stage.begin() + i);
			i--;
		}
	}
}

void StageSelectScene::ChangeMode()
{
	//ステージ選択モード
	if (StageModeFlg == true) {
		StageSelectMode();
		return;
	}
	//車選択モード
	if(CarModeFlg == true) {
		CarSelectMode();
		return;
	}
}

bool StageSelectScene::StageSelectMode()
{
	//キー確認
	bool KeyFlg = key.LClickF();
	//戻るボタン
	if (modoru->UpdateSu() == false) {
		mouse->SetTouchFlg();
		if (KeyFlg == true) {
			ChangeSceneFade(TitleNo);
			StageModeFlg = false;
			CarModeFlg = false;
			return true;
		}
	}
	//ステージ選択ボタン
	if (stage.size() > 0) {
		for (unsigned int s = 0; s < stage.size(); s++) {
			if (stage[s]->UpdateSu() == false) {
				mouse->SetTouchFlg();
				if (KeyFlg == true) {
					ChangeSceneFade(GameNo, stage[s]->GetStageNo());
					InitCarSel();
					return true;
				}
			}
		}
	}
	return true;
}

void StageSelectScene::InitStaSel(void)
{
	//フラグのセット
	StageModeFlg = true;
	CarModeFlg = false;

	//表示の削除
	DeleteCarSel();
	//Okボタンの表示セット
	Ok->SetDrawFlg(false);

	//ステージ選択アイコン作成
	for (int s = 0; s < 1; s++) {
		stage.push_back(new StageTex(s + 1, D3DXVECTOR3((float)SCRW / 6.0f*(float)(s + 1), (float)SCRH / 4.0f, 0.0f)));
	}
}

bool StageSelectScene::CarSelectMode()
{
	//キー確認
	bool KeyFlg = key.LClickF();
	//戻るボタン
	if (modoru->UpdateSu() == false) {
		mouse->SetTouchFlg();
		if (KeyFlg == true) {
			InitStaSel();
			return true;
		}
	}
	//車ボタン
	if (CarSel.size() > 0) {
		int tNo;
		for (auto && c: CarSel) {
			tNo = c->Touch();
			if (tNo > 0) {
				if (KeyFlg==true) {
					if (tNo == 1) {
						int No = c->GetNo() - 1;
						ChangeCar(&No);
						c->UpdateNo(&No);
						return true;
					}
					if (tNo == 2) {
						int No = c->GetNo() +1;
						ChangeCar(&No);
						c->UpdateNo(&No);
						return true;
					}
				}
			}
		}
	}
	//Okボタン
	if (KeyFlg == true) {
		if (Ok->Touch() == true) {
			StartFade();
			return true;
		}
	}
	
	return true;
}

void StageSelectScene::InitCarSel(void)
{
	//フラグのセット
	StageModeFlg = false;
	CarModeFlg = true;

	DeleteStaSel();
	//Okボタンの表示セット
	Ok->SetDrawFlg(true);

	//選択の初期化
	CarSel.push_back(new C_CarSelect(
		&D3DXVECTOR3(1280.0f / 5.0f*4.0f, 720.0f / 4.0f*3.0f, 0.0f), &D3DXVECTOR3(0.15f, 0.11f, 0.0f), &D3DXVECTOR3(0.33f, 0.31f, 0.0f), &D3DXVECTOR3(-100.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.85f, 0.85f, 0.0f)
	));
	int No = PlayerBody->GetPData().CarBodyNo;
	CarSel[CarSel.size() - 1]->UpdateNo(&No);

}

void StageSelectScene::StartFade(void)
{
	SceneChangeFlg = true;
	bool BlackFlg = true;
	if (SceneNo == GameNo)BlackFlg = false;
	fade->SetIn(BlackFlg);
}

void StageSelectScene::ChangeCar(int * No)
{
	//メッシュの種類変え
	if (*No > 2)*No = 1;
	if (*No < 1)*No = 2;

	BODYDATA pData = PlayerBody->GetPData();
	pData.CarBodyNo = *No;
	//車に反映
	car->SetBody(&pData);
	//データにセット
	PlayerBody->SetPData(&pData);

}
