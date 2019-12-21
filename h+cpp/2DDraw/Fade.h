#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include"../GameSource/TextureManager.h"
#include"FadeMove.h"
#include"FadeOut.h"
#include"FadeIn.h"

extern TextureManager textureManager;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g

#define	SCRW		1280	// �E�B���h�E���iWidth
#define	SCRH		720		// �E�B���h�E�����iHeight

class Fade {
public:
	void Init();
	Fade();
	~Fade();
	virtual bool Update();
	void ChaFlg(bool b);
	bool GetFlg() {
		return out;
	}
	void Draw();
	void Draw(int Color);

	//�����̃t���O����
	void SetIn(void) {
		MoveFlg = true;
	}
	void SetIn(bool BlackFlg) {
		MoveFlg = true;
		SetColor(BlackFlg, true);
	}
	//�F�ς�
	void SetColor(bool BlackFlg, bool FlgChangeFlg) {
		static bool ColorFlg = true;
		if (FlgChangeFlg == true) ColorFlg = BlackFlg;
		if (ColorFlg == false) {
			FadeColor = 255;
		}
		else {
			FadeColor = 0;
		}
	}
	//�����̃t���O�n��
	bool GetMoveFlg(void) {
		return MoveFlg;
	}
	//Move����Flg�n��
	bool GetMoveEndFlg(void) {
		return MoveEndFlg;
	}

protected:
	CHARA2D fade;
	int alpha;
	bool out;//out��true�Ȃ獕
	//�t�F�[�h��Flg;
	bool MoveFlg,MoveEndFlg;
	//�t�F�[�h�F
	int FadeColor;
private:
	C_FadeMove *FadeMove;
};