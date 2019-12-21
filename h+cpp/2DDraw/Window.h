#pragma once
#include<d3dx9.h>
#include"../GameSource/Struct.h"
#include"../GameSource/TextureManager.h"
#include"../GameSource/Judgment.h"

extern TextureManager textureManager;
extern LPD3DXSPRITE lpSprite;	// �X�v���C�g

#define	SCRW		1280	// �E�B���h�E���iWidth
#define	SCRH		720		// �E�B���h�E�����iHeight

class Window {
protected:
	CHARA2D wind;
	D3DXVECTOR3 TexPos;//texture��Pos
	//�N�H�[�^�j�I��
	bool MoveFlg;
	QuaAnim qua;
	Judg judg;
public:
	Window();
	~Window() {};
	void Draw2D();
	bool GetMoveFlg(void) {
		return MoveFlg;
	}
	void SetMoveFlg(bool Flg);
	bool Update();

	void DrawSu() {
		Draw2D();
	};
	bool UpdateSu() {
		Update();
	};
};