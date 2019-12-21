
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<d3dx9.h>
#include<time.h>
#include"Scene/SceneManager.h"
#include"Scene/TitleScene.h"
#include"GameSource/TextureManager.h"
#include"GameSource/XfileManager.h"
#include"GameSource/option.h"
#include"GameSource/Judgment.h"
#include"GameSource/Debug.h"
#include"GameSource/Struct.h"
#include"GameSource/InvBi.h"
#include"GameSource/Motion.h"
#include"GameSource/SoundManager.h"
#include"Sound/Bgm.h"
#include"Sound/BulletEmpty1.h"
#include"Sound/SoundGun1.h"
#include"Sound/BombSound1.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

#define	SCRW		1280	// �E�B���h�E���iWidth
#define	SCRH		720		// �E�B���h�E�����iHeight
#define FRI 90 //�t�H�O�̓����a
#define FRO 200 //�t�H�O�̊O���a

LPDIRECT3D9				lpD3D;		// Direct3D�C���^�[�t�F�C�X

LPDIRECT3DDEVICE9		lpD3DDevice;	// Direct3DDevice�C���^�[�t�F�C�X

D3DPRESENT_PARAMETERS d3dpp;




// ���_�t�H�[�}�b�g�̒�`
/*struct VERTEX
{
	D3DXVECTOR3 Pos;
	D3DCOLOR Color;
	D3DXVECTOR2 Tex;
};*/


////  �O���[�o���ϐ��錾

LPD3DXSPRITE lpSprite;	// �X�v���C�g
LPD3DXFONT lpFont;		// �t�H���g

//�T�E���h
#include<dsound.h>
#include"GameSource/wavread.h"
#pragma comment(lib, "dsound.lib")
LPDIRECTSOUND8 lpDSound;	//DirectSound�I�u�W�F�N�g
LPDIRECTSOUNDBUFFER lpSPrimary;
LPDIRECTSOUND3DLISTENER8 lpSListener;
//�G�p
LPDIRECTSOUND3DLISTENER8 lpSListenerE;

SceneManager sceneManager;
TextureManager textureManager;
XfileManager xfileManager;
D3DLIGHT9 Light;
LPD3DXFONT lpFontS;
HWND Hwnd;
//�T�E���h�}�l�[�W���[
SoundManager soundManager;

Option option;
Judg judg;
Inv inv;

float AngD;
unsigned int NumD;
bool FlgD;
D3DXMATRIX MatD;

D3DXVECTOR3 CamPosG;
Motion motion;
//Manager��
int CountManager;
//�T�E���h�ϐ�------------------------------
C_Bgm *bgm;
//��e
C_BulEmp *bulEmp;
//����
C_BombSound *BombSound;
//------------------------------------------

bool gameFullScreen;	// �t���X�N���[���itrue,false)



#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

void DrawMesh(XFILE *XFile) {
	for (DWORD i = 0; i < XFile->NumMaterial; i++) {
		lpD3DDevice->SetMaterial(&(XFile->Mat[i]));
		lpD3DDevice->SetTexture(0, XFile->Tex[i]);
		XFile->lpMesh->DrawSubset(i);//i�Ԗڂ̃O���[�v��\��
	}
}
//9.17
//������
void DrawMesh(XFILE *XFile,float Alpha) {
	D3DMATERIAL9 Mat;
	for (DWORD i = 0; i < XFile->NumMaterial; i++) {
		Mat = XFile->Mat[i];
		Mat.Diffuse.a = Alpha;
		//�ԃt���b�V��
		Mat.Ambient.r = 2.0f;
		lpD3DDevice->SetMaterial(&(Mat));//XFile->Mat[i]�Ƀ}�e���A���������Ă���
		lpD3DDevice->SetTexture(0, XFile->Tex[i]);
		XFile->lpMesh->DrawSubset(i);//i�Ԗڂ̃O���[�v��\��
	}
}
void DrawMesh(XFILE *XFile, bool *Flg) {
	static int i = 0;
	D3DMATERIAL9 Mat;
	for (DWORD i = 0; i < XFile->NumMaterial; i++) {
		Mat = XFile->Mat[i];
		//�ԃt���b�V��
		if (*Flg == true) {
			Mat.Ambient.r = 2.0f;
		}
		lpD3DDevice->SetMaterial(&(Mat));//XFile->Mat[i]�Ƀ}�e���A���������Ă���
		lpD3DDevice->SetTexture(0, XFile->Tex[i]);
		XFile->lpMesh->DrawSubset(i);//i�Ԗڂ̃O���[�v��\��
	}
	if (*Flg == true) {
		i++;
		if (i > 10) {
			*Flg = false;
			i = 0;
		}
	}
}
void LoadMesh(struct XFILE *XFile, const char FName[])
{
	LPD3DXBUFFER lpD3DXBuffer;

	D3DXLoadMeshFromX(FName, D3DXMESH_MANAGED, lpD3DDevice, NULL, &lpD3DXBuffer, NULL, &(XFile->NumMaterial), &(XFile->lpMesh));

	XFile->Mat = new D3DMATERIAL9[XFile->NumMaterial];
	XFile->Tex = new LPDIRECT3DTEXTURE9[XFile->NumMaterial];

	D3DXMATERIAL* D3DXMat = (D3DXMATERIAL*)lpD3DXBuffer->GetBufferPointer();

	DWORD i;
	for (i = 0; i < XFile->NumMaterial; i++) {
		XFile->Mat[i] = D3DXMat[i].MatD3D;
		XFile->Mat[i].Ambient = XFile->Mat[i].Diffuse;
		if (FAILED(D3DXCreateTextureFromFile(lpD3DDevice, D3DXMat[i].pTextureFilename, &(XFile->Tex[i])))) {
			XFile->Tex[i] = NULL;
		}
	}

	lpD3DXBuffer->Release();
}

void ReleaseMesh(struct XFILE *XFile)
{
	if (XFile->lpMesh != NULL) {
		DWORD i;

		delete[] XFile->Mat;
		for (i = 0; i < XFile->NumMaterial; i++) {
			if (XFile->Tex[i] != NULL) {
				XFile->Tex[i]->Release();
				XFile->Tex[i] = NULL;
			}
		}
		delete[] XFile->Tex;
		XFile->lpMesh->Release();

		XFile->lpMesh = NULL;
	}
}

// �X�V����
void Update(void)
{
	
}

// 3D�`��
void Render3D(void)
{
	
}

// 2D�`��
void Render2D(void)
{
	//////////////////////////////////////////////////
	///	�X�v���C�g�̕`�揈��
	//////////////////////////////////////////////////
	// �`��J�n
	lpSprite->Begin(D3DXSPRITE_ALPHABLEND);
	

	// �`��I��
	lpSprite->End();
}

void LoadWAVE3D(LPDIRECTSOUNDBUFFER8 &pDSData, LPDIRECTSOUND3DBUFFER8 &pDSData3D, const char *fname)
{
	HRESULT hr;

	// WAVE�t�@�C�����J��
	CWaveSoundRead WaveFile;
	WaveFile.Open((char*)fname);

	// �Z�J���_���E�o�b�t�@���쐬����
	// DSBUFFERDESC�\���̂�ݒ�
	DSBUFFERDESC dsbdesc;
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC);

	//(DSBCAPS_CTRL3D=�R�c�T�E���h���g�p)
	dsbdesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRL3D |
		DSBCAPS_CTRLVOLUME | /*DSBCAPS_CTRLPAN |*/ DSBCAPS_CTRLFREQUENCY;
	dsbdesc.dwBufferBytes = WaveFile.m_ckIn.cksize;
	dsbdesc.lpwfxFormat = WaveFile.m_pwfx;

	//3D�T�E���h��HEL�A���S���Y����I��
	dsbdesc.guid3DAlgorithm = DS3DALG_NO_VIRTUALIZATION;
	//	dsbdesc.guid3DAlgorithm=DS3DALG_DEFAULT;

		// �o�b�t�@�����
	LPDIRECTSOUNDBUFFER pDSTmp;
	//	lpDSound->CreateSoundBuffer(&dsbdesc, &pDSData, NULL); 
	lpDSound->CreateSoundBuffer(&dsbdesc, &pDSTmp, NULL);
	pDSTmp->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&pDSData);
	pDSTmp->Release();

	// �Z�J���_���E�o�b�t�@��Wave�f�[�^����������
	LPVOID lpvPtr1;		// �ŏ��̃u���b�N�̃|�C���^
	DWORD dwBytes1;		// �ŏ��̃u���b�N�̃T�C�Y
	LPVOID lpvPtr2;		// �Q�Ԗڂ̃u���b�N�̃|�C���^
	DWORD dwBytes2;		// �Q�Ԗڂ̃u���b�N�̃T�C�Y

	hr = pDSData->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);

	// DSERR_BUFFERLOST���Ԃ��ꂽ�ꍇ�CRestore���\�b�h���g���ăo�b�t�@�𕜌�����
	if (DSERR_BUFFERLOST == hr)
	{
		pDSData->Restore();
		hr = pDSData->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);
	}
	if (SUCCEEDED(hr))
	{
		// ���b�N����

		// �����ŁC�o�b�t�@�ɏ�������
		// �o�b�t�@�Ƀf�[�^���R�s�[����
		UINT rsize;
		WaveFile.Read(dwBytes1, (LPBYTE)lpvPtr1, &rsize);
		if (0 != dwBytes2)
			WaveFile.Read(dwBytes2, (LPBYTE)lpvPtr2, &rsize);

		// �������݂��I������炷����Unlock����D
		hr = pDSData->Unlock(lpvPtr1, dwBytes1, lpvPtr2, dwBytes2);
	}

	//3D�̃Z�J���_���o�b�t�@�����
	pDSData->QueryInterface(IID_IDirectSound3DBuffer8, (LPVOID*)&pDSData3D);
}


void GameFrame(void)
{
	// �o�b�N�o�b�t�@�� Z �o�b�t�@���N���A
	lpD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);


	// �X�V����
	Update();


	// �`��J�n
	lpD3DDevice->BeginScene();

	D3DXMATRIX mView, mProj;

	// ���_�s��̐ݒ�
	D3DXMatrixLookAtLH(&mView,
		&D3DXVECTOR3(0.0f, 0.0f, -5.0f),
		&D3DXVECTOR3(0.0f, 0.0f, 0.0f),	// �J�����̎��_
		&D3DXVECTOR3(0.0f, 1.0f, 0.0f)	// �J�����̓��̕���
	);

	// ���e�s��̐ݒ�
	D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), (float)SCRW / (float)SCRH, 1.0f, 1000.0f);

	//�s��ݒ�
	lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
	lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);



	// 3D�`��
	Render3D();

	// 2D�`��
	Render2D();



	// �`��I��
	lpD3DDevice->EndScene();

	// �o�b�N�o�b�t�@���v���C�}���o�b�t�@�ɃR�s�[
	lpD3DDevice->Present(NULL, NULL, NULL, NULL);
}

LRESULT APIENTRY WndFunc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_ESCAPE:
			PostQuitMessage(0);
			return 0;
		}
		return 0;

	}
	return DefWindowProc(hwnd, msg, wParam, lParam);

}

void LoadTexture(LPDIRECT3DTEXTURE9 *lpTex, const char fname[], int W, int H, D3DCOLOR Color)
{
	if (W == 0)W = D3DX_DEFAULT;
	if (H == 0)H = D3DX_DEFAULT;
	D3DXCreateTextureFromFileEx(lpD3DDevice, fname, W, H, 1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT, Color, NULL, NULL, lpTex);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev,
	LPSTR lpszCmdParam, int nCmdshow)
{
	MSG msg;
	
	HWND hwnd;
	WNDCLASS wc;
	char szAppName[] = "Generic Game SDK Window";

	wc.style = CS_DBLCLKS;
	wc.lpfnWndProc = WndFunc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;

	RegisterClass(&wc);

	hwnd = CreateWindowEx(
		0,
		szAppName,
		"One Way Survivor Ver0.9.0",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCRW, SCRH,
		NULL, NULL, hInst,
		NULL);

	if (!hwnd)return FALSE;

	ShowWindow(hwnd, nCmdshow);
	UpdateWindow(hwnd);
	SetFocus(hwnd);

	gameFullScreen = false;	// �E�B���h�E���[�h

	if (MessageBox(NULL, "�t���X�N���[���ŋN�����܂����H", "�N���m�F", MB_YESNO | MB_DEFBUTTON2) == IDYES) {//MB_ICONQUESTION
		gameFullScreen = true;
	}

	if (gameFullScreen) {
		ShowCursor(FALSE);
	}
	else {
		RECT rc = { 0,0,SCRW,SCRH };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
		SetWindowPos(hwnd, NULL, 50, 50, rc.right - rc.left, rc.bottom - rc.top, SWP_SHOWWINDOW | SWP_NOZORDER);
	}

	//---------------------DirectX Graphics�֘A-----------------------

	// Direct3D �I�u�W�F�N�g���쐬
	lpD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!lpD3D)
	{
		// �I�u�W�F�N�g�쐬���s
		MessageBox(NULL, "Direct3D �̍쐬�Ɏ��s���܂����B", "ERROR", MB_OK | MB_ICONSTOP);
		// �I������
		return 0;
	}
	int adapter;

	// �g�p����A�_�v�^�ԍ�
	adapter = D3DADAPTER_DEFAULT;

	// �E�C���h�E�̍쐬�����������̂ŁADirect3D ������������
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	// Direct3D �������p�����[�^�̐ݒ�
	if (gameFullScreen)
	{
		// �t���X�N���[�� : �قƂ�ǂ̃A�_�v�^�ŃT�|�[�g����Ă���t�H�[�}�b�g���g�p
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	}
	else
	{
		// �E�C���h�E : ���݂̉�ʃ��[�h���g�p
		D3DDISPLAYMODE disp;
		// ���݂̉�ʃ��[�h���擾
		lpD3D->GetAdapterDisplayMode(adapter, &disp);
		d3dpp.BackBufferFormat = disp.Format;
	}
	// �\���̈�T�C�Y�̐ݒ�
	d3dpp.BackBufferWidth = SCRW;
	d3dpp.BackBufferHeight = SCRH;
	d3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;

	if (!gameFullScreen)
	{
		// �E�C���h�E���[�h
		d3dpp.Windowed = 1;
	}

	// Z �o�b�t�@�̎����쐬
	d3dpp.EnableAutoDepthStencil = 1;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	//�ޯ��ޯ̧��ۯ��\�ɂ���(GetDC���\�ɂȂ�)
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	//8.30
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;//D3DPRESENT_INTERVAL_IMMEDIATE:��������

	// �f�o�C�X�̍쐬 - T&L HAL
	if (FAILED(lpD3D->CreateDevice(adapter, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice)))
	{
		// ���s�����̂� HAL �Ŏ��s
		if (FAILED(lpD3D->CreateDevice(adapter, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice)))
		{
			// ���s�����̂� REF �Ŏ��s
			if (FAILED(lpD3D->CreateDevice(adapter, D3DDEVTYPE_REF, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice)))
			{
				// ���ǎ��s����
				MessageBox(NULL, "DirectX9���������ł��܂���B\n���Ή��̃p�\�R���Ǝv���܂��B", "ERROR", MB_OK | MB_ICONSTOP);
				lpD3D->Release();
				// �I������
				return 0;
			}
		}
	}

	// �����_�����O�E�X�e�[�g��ݒ�
	// Z �o�b�t�@�L����->�O��֌W�̌v�Z�𐳊m�ɂ��Ă����
	lpD3DDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// �A���t�@�u�����f�B���O�L����
	lpD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

	// �A���t�@�u�����f�B���O���@��ݒ�
	lpD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// �����_�����O���̃A���t�@�l�̌v�Z���@�̐ݒ�
	lpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	// �e�N�X�`���̐F���g�p
	lpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	// ���_�̐F���g�p
	lpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	// �����_�����O���̐F�̌v�Z���@�̐ݒ�
	lpD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	//���ʃJ�����O
	lpD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	// �t�B���^�ݒ�
	lpD3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	lpD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	lpD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

	// ���C�g
	lpD3DDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	Light.Type = D3DLIGHT_DIRECTIONAL;
	/*D3DLIGHT_DIRECTIONAL
���͎w�����̂�������ł��B
D3DLIGHT_GLSPOT
����GL�X�^�C���̃X�|�b�g���C�g�ł��B
D3DLIGHT_PARALLELPOINT
���͕��s�ȓ_�����ł��B
D3DLIGHT_POINT
���͓_�����ł��B
D3DLIGHT_SPOT
���̓X�|�b�g���C�g�̌��ł��B*/

	Light.Diffuse.r = 1.0f;
	Light.Diffuse.g = 1.0f;
	Light.Diffuse.b = 1.0f;

	//9.17
	//�S�̓I�Ȗ��邳(�A���r�G���g
	float f =0.6f;
	Light.Ambient.r = f;
	Light.Ambient.g = f;
	Light.Ambient.b = f;

	Light.Direction = D3DXVECTOR3(-0.0f, -1.0f, 0.0f);
	lpD3DDevice->SetLight(0, &Light);
	lpD3DDevice->LightEnable(0, TRUE);

	lpD3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);
	// ���_�t�H�[�}�b�g�̐ݒ�
	lpD3DDevice->SetFVF(FVF_VERTEX);

	timeBeginPeriod(1);

	// �Q�[���Ɋւ��鏉�������� ---------------------------





	// �X�v���C�g�쐬
	D3DXCreateSprite(lpD3DDevice, &lpSprite);
	lpSprite->OnResetDevice();

	// �t�H���g�쐬
	D3DXCreateFont(lpD3DDevice, 30, 30, FW_REGULAR, NULL, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, PROOF_QUALITY, FIXED_PITCH | FF_MODERN, "�l�r �S�V�b�N", &lpFont);
	D3DXCreateFont(lpD3DDevice, 25, 25, FW_REGULAR, NULL, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, PROOF_QUALITY, FIXED_PITCH | FF_MODERN, "�l�r �S�V�b�N", &lpFontS);
	lpFontS->OnResetDevice();

	lpFont->OnResetDevice();

	//�T�E���h������
	//������-------------------------------------------------------------
		//---------------------DirectSound�֘A-----------------------
	DirectSoundCreate8(NULL, &lpDSound, NULL);

	//�������x����ݒ�
	lpDSound->SetCooperativeLevel(hwnd, DSSCL_PRIORITY);

	// �v���C�}���E�o�b�t�@�̍쐬
	// DSBUFFERDESC�\���̂�ݒ�
	DSBUFFERDESC dsbdesc;
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC);
	// �v���C�}���E�o�b�t�@���w��
	dsbdesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;
	dsbdesc.dwBufferBytes = 0;
	dsbdesc.lpwfxFormat = NULL;

	// �o�b�t�@�����
	lpDSound->CreateSoundBuffer(&dsbdesc, &lpSPrimary, NULL);

	// �v���C�}���E�o�b�t�@��Wave�t�H�[�}�b�g��ݒ�
	// �@�@�@�D�拦�����x���ȏ�̋������x�����ݒ肳��Ă���K�v������܂��D
	WAVEFORMATEX pcmwf;
	ZeroMemory(&pcmwf, sizeof(WAVEFORMATEX));
	pcmwf.wFormatTag = WAVE_FORMAT_PCM;
	pcmwf.nChannels = 2;		// �Q�`�����l���i�X�e���I�j
	pcmwf.nSamplesPerSec = 44100;	// �T���v�����O�E���[�g�@44.1kHz
	pcmwf.nBlockAlign = 4;
	pcmwf.nAvgBytesPerSec = pcmwf.nSamplesPerSec * pcmwf.nBlockAlign;
	pcmwf.wBitsPerSample = 16;		// 16�r�b�g
	lpSPrimary->SetFormat(&pcmwf);

	Hwnd = hwnd;


	lpSPrimary->QueryInterface(IID_IDirectSound3DListener8, (LPVOID*)&lpSListener);
	lpSListener->SetRolloffFactor(0.5f, DS3D_IMMEDIATE);
	lpSPrimary->QueryInterface(IID_IDirectSound3DListener8, (LPVOID*)&lpSListenerE);
	lpSListenerE->SetRolloffFactor(0.05f, DS3D_IMMEDIATE);

	//Bgm�̃R���X�g���N�^
	bgm = new C_Bgm();
	//��e
	bulEmp = new C_BulEmp();
	//����
	BombSound = new C_BombSound();

	sceneManager.changeScene(new TitleScene());
	FlgD = false;
	D3DXMatrixTranslation(&MatD, 0.0f, 0.0f, 0.0f);

	lpD3DDevice->SetRenderState(D3DRS_FOGENABLE, TRUE);
	lpD3DDevice->SetRenderState(D3DRS_FOGCOLOR, D3DCOLOR_XRGB(255, 255, 255));
	lpD3DDevice->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR);
	float Start = (float)FRI, End = (float)FRO;
	lpD3DDevice->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&Start));
	lpD3DDevice->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&End));


	while (1) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, 0, 0))
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			sceneManager.NowScene();
		}
	}

	// �Q�[���Ɋւ���I������ ---------------------------



	lpSprite->Release();	// �X�v���C�g
	lpFont->Release();		// �t�H���g
	lpFontS->Release();

	//�T�E���h�I��
	// �I������
	lpSPrimary->Release();
	lpDSound->Release();

	//bgm�̍폜
	delete bgm;
	delete bulEmp;
	delete BombSound;

	CoUninitialize();
	

	timeEndPeriod(1);

	

	// Direct3D �I�u�W�F�N�g�����
	lpD3DDevice->Release();
	lpD3D->Release();

	return (int)msg.wParam;
}