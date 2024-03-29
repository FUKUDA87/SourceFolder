#pragma once
#include"../2DDraw/Window.h"

class C_OK :public Window {
public:
	C_OK(const D3DXVECTOR3 *CharScal, const D3DXVECTOR3 *WindPos, const D3DXVECTOR3 *WindScal);
	//表示
	void Draw2DOK(void);

	//タッチ
	bool Touch(void);

	//表示の有無入れ
	void SetDrawFlg(bool Flg) {
		OK.Base.DrawFlg = Flg;
	}

protected:
	//初期化
	void InitOK(void);
private:
	CHARA2D OK;
};