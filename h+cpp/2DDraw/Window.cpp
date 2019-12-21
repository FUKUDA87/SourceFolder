#include "Window.h"

Window::Window()
{
	wind.TEX = { NULL,928,552,NULL,NULL };
	wind.TEX.Tex = textureManager.GetTexture("../GameFolder/Material/Texture/frame1to.png", wind.TEX.Width, wind.TEX.Height, NULL);
	wind.Base.Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	wind.Base.ScaPos = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	TexPos = D3DXVECTOR3((float)wind.TEX.Width / 2.0f, (float)wind.TEX.Height / 2.0f, 0);
	MoveFlg = false;
}

void Window::Draw2D()
{
	RECT rcH = { 0,0, wind.TEX.Width, wind.TEX.Height };
	D3DXMatrixTranslation(&wind.Base.Mat, wind.Base.Pos.x, wind.Base.Pos.y, NULL);
	D3DXMatrixScaling(&wind.Base.Scal, wind.Base.ScaPos.x, wind.Base.ScaPos.y, wind.Base.ScaPos.z);
	D3DXMATRIX tmp;
	tmp = wind.Base.Scal*wind.Base.Mat;
	lpSprite->SetTransform(&tmp);
	lpSprite->Draw(wind.TEX.Tex, &rcH, &TexPos, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));//
}

void Window::SetMoveFlg(bool Flg)
{
	if (MoveFlg == false) {
		MoveFlg = Flg;
		if (MoveFlg == true) {
			//�N�H�[�^�j�I���̏�����
			qua.Count = 0;
			qua.CountEnd = 2;
			qua.StartPos = wind.Base.ScaPos;
			qua.EndPos = qua.StartPos*0.95f;
			qua.AnimeFrame = 0.0f;
			qua.FrameUp = 0.2f;
		}
	}
}

bool Window::Update()
{
	if (MoveFlg == true) {
		//�E�B���h�E�̊g��E�k��
		if (judg.Quaternion(&wind.Base.ScaPos, qua.StartPos, qua.EndPos, &qua.AnimeFrame, qua.FrameUp, true) == false) {
			qua.Count += 1;
			if (qua.Count != qua.CountEnd) {
				//�߂�����
				qua.FrameUp *= -1.0f;
			}
			else {
				//�N�H�[�^�j�I����End
				MoveFlg = false;
			}
		}
	}
	return true;
}
