#pragma once
#include"../2DDraw/Window.h"

class C_OK :public Window {
public:
	C_OK(const D3DXVECTOR3 *CharScal, const D3DXVECTOR3 *WindPos, const D3DXVECTOR3 *WindScal);
	//�\��
	void Draw2DOK(void);

	//�^�b�`
	bool Touch(void);

	//�\���̗L������
	void SetDrawFlg(bool Flg) {
		OK.Base.DrawFlg = Flg;
	}

protected:
	//������
	void InitOK(void);
private:
	CHARA2D OK;
};