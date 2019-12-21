#include"SceneBase.h"
extern LPDIRECT3DDEVICE9 lpD3DDevice;
void SceneBase::Frame(void)
{
	//60FPS�v�Z
	NowTime = timeGetTime();
	if ((NowTime - PrevTime0) < (1000 / 60)) {
		return;
	}
	else {
		PrevTime0 = NowTime;
	}
	if ((NowTime - PrevTime) >= 1000) {
		PrevTime = NowTime;
		Fps = Cnt;
		Cnt = 0;
	}
	Cnt++;

	if (Update() == false) {
		return;
	}
	// �`��J�n
	lpD3DDevice->BeginScene();
	// �o�b�N�o�b�t�@�� Z �o�b�t�@���N���A
	lpD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	SetCamera();
	Render3D();

	// 2D�`��
	Render2D();



	// �`��I��
	lpD3DDevice->EndScene();

	// �o�b�N�o�b�t�@���v���C�}���o�b�t�@�ɃR�s�[
	lpD3DDevice->Present(NULL, NULL, NULL, NULL);
}
void SceneBase::Render3D(void)
{
	/*�h���N���X���ŃI�[�o�[���C�h���Ȃ������Ƃ��ɋ���ۂ̊֐�������Ă���*/
}
void SceneBase::Render2D(void)
{
	/*�h���N���X���ŃI�[�o�[���C�h���Ȃ������Ƃ��ɋ���ۂ̊֐�������Ă���*/
}
void SceneBase::SetCamera(void)
{
	/*�h���N���X���ŃI�[�o�[���C�h���Ȃ������Ƃ��ɋ���ۂ̊֐�������Ă���*/
}
bool  SceneBase::Update(void) {
	return true;
}
SceneBase::~SceneBase()
{

}