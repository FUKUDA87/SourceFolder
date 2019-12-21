#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include"../GameSource/TextureManager.h"
#include"../GameSource/Judgment.h"

extern TextureManager textureManager;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g
extern Judg judg;

#define	SCRW		1280	// �E�B���h�E���iWidth
#define	SCRH		720		// �E�B���h�E�����iHeight

class GameOver {
public:
	GameOver();
	~GameOver() {};
	void Draw2D();
	bool Update(bool CLEor, bool Flg);
	//�ǂ���̂ɂȂ�����Flg�n��
	bool GetFlg(void);

protected:
	CHARA2D gaov;
	CHARA2D stcl;
};