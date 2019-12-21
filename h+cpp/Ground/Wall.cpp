#include"Wall.h"
#include"../GameSource/TextureManager.h"
#include"../GameSource/XfileManager.h"
#include"../GameSource/Judgment.h"

extern XfileManager xfileManager;
extern LPDIRECT3DDEVICE9 lpD3DDevice;
extern TextureManager textureManager;

void Wall::InitW()
{
	//�ǂ̕\��Flg������
	WallDrawFlg = true;

	//=============================================================================================
	//��3D�̏�����
	//�ǂ̃��[�h
	xfileManager.GetXfile(&Wall3D[0].Mesh, "../GameFolder/Material/Xfile/Wall3-3.x");
	xfileManager.GetXfile(&Wall3DS, "../GameFolder/Material/Xfile/Wall1-3.x");
	DrawRadFlg = false;
	//�ǂ̃R���W�������f���̃��[�h
	xfileManager.GetXfile(&Wall3D[0].ColModMesh, "../GameFolder/Material/Xfile/Wall2CM1.x");
	//��񂾂��v�Z
	static bool GetRadFlg = true;
	static DWORD NumVertex;
	static D3DXVECTOR3 PosSmall;
	static D3DXVECTOR3 PosBig;
	if (GetRadFlg == true) {
		judg.GetRad(&Wall3D[0].Mesh, &Wall3D[0].Base.NumVertex, &Wall3D[0].PosBig, &Wall3D[0].PosSmall);
		NumVertex = Wall3D[0].Base.NumVertex;
		PosSmall = Wall3D[0].PosSmall;
		PosBig = Wall3D[0].PosBig;
		GetRadFlg = false;
	}
	else {
		Wall3D[0].Base.NumVertex= NumVertex;
		Wall3D[0].PosSmall= PosSmall;
		Wall3D[0].PosBig= PosBig;
	}
	//�T�C�Y����
	Wall3D[0].Base.ScaPos = D3DXVECTOR3(1.0f*0.5f, 3.0f, 1.0f);
	//�ǂ̕��v�Z
	D3DXVECTOR3 Vec= D3DXVECTOR3(0.0f, 0.0f, Wall3D[0].PosSmall.z) - D3DXVECTOR3(0.0f, 0.0f, Wall3D[0].PosBig.z);
	Wall3D[0].Base.ScaPos.z = D3DXVec3Length(&Vec);
	if (Wall3D[0].Base.ScaPos.z < 0)Wall3D[0].Base.ScaPos.z *= -1.0f;

	Wall3D[0].Base.Mat = ground.Base.Mat;
	Wall3D[1] = Wall3D[0];
	for (int wNum=0; wNum < 2; wNum++) {
		//��
		Wall3D[wNum].Base.TraPos = D3DXVECTOR3(ground.v[wNum].Pos.x, Wall3D[wNum].PosSmall.y*-1.0f, 0.0f);
		//���̒���
		if (wNum == 0) {
			//��
			Vec = ground.v[0].Pos - ground.v[3].Pos;
		}
		else {
			//�E
			Vec = ground.v[1].Pos - ground.v[2].Pos;
		}
		Wall3D[wNum].Base.ScaPos.z = D3DXVec3Length(&Vec) / Wall3D[wNum].Base.ScaPos.z + 0.02f;
		if (Wall3D[wNum].Base.ScaPos.z < 0)Wall3D[wNum].Base.ScaPos.z *= -1.0f;
		judg.ScalingMat(&Wall3D[wNum].Base.Scal, &Wall3D[wNum].Base.ScaPos);
		Wall3D[wNum].Base.TraPos.y *= Wall3D[wNum].Base.ScaPos.y;
		//���f
		judg.SetTransMat(&Wall3D[wNum].Base.Trans, &Wall3D[wNum].Base.TraPos);
		//��]
		float AngY;
		if (wNum == 0) {
			AngY = 0.0f;
		}
		else {
			AngY = 180.0f;
		}
		D3DXMatrixRotationY(&Wall3D[wNum].Base.RotY, D3DXToRadian(AngY));
	}
	//============================================================================================

}
Wall::Wall()
{
	InitW();
}
Wall::Wall(int i) :C_Ground(i)
{
	InitW();
}

Wall::Wall(D3DXMATRIX Mat3, D3DXMATRIX Mat4, int gType, float Ang, float Length, bool LengthAuto) : C_Ground(Mat3,Mat4,gType, Ang, Length, LengthAuto)
{
	InitW();

	//=======================================================
	//��3D�̏���
		if (IdenFlg == true) {
			for (int wNum=0; wNum < 2; wNum++) {
				//�ʒu�̏�����
				D3DXMatrixTranslation(&Wall3D[wNum].Base.Mat, 0.0f, 0.0f, 0.0f);
				//�傫���̏�����
				//����
				int s, e;
				if (wNum == 0) {
					s = 3;
					e = 0;
				}
				else {
					s = 2;
					e = 1;
				}
				D3DXVECTOR3 wVec = ground.v[e].Pos - ground.v[s].Pos, FrontVec = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
				//�ʒu�̑��
				D3DXVECTOR3 Pos = ground.v[s].Pos + wVec / 2.0f;
				judg.SetMatP(&Wall3D[wNum].Base.Mat, Pos);
				//��]
				D3DXMATRIX RotX, RotY;
				judg.TarEndMat(&Wall3D[wNum].Base.Mat, Wall3D[wNum].Base.Mat, &RotX, &RotY, ground.v[e].Pos, FrontVec);
				//�������Ɉړ�������TransMat�̍쐬
				Pos.y = Wall3D[wNum].PosSmall.y*Wall3D[wNum].Base.ScaPos.y;
				if (Pos.y < 0.0f)Pos.y *= -1.0f;
				D3DXMatrixTranslation(&Wall3D[wNum].Base.Trans, 0.0f,Pos.y , 0.0f);

			}
		}
	//=======================================================

}
Wall::~Wall()
{
	//�O���̍폜
	if (light.size()>0) {
		for (unsigned int l = 0; l < light.size(); l++) {
			delete light[l];
			light.erase(light.begin() + l);
			l++;
		}
	}
}
bool Wall::WaUpdate(void) {
	
	return true;
}
#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
void DrawMesh(XFILE *XFile);
void Wall::WaDraw(void) {
	//�\���m

	//��3D�\��
	lpD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	bool LeftFlg;
	for (int w = 0; w < 2; w++) {
		if (w == 0) {
			LeftFlg = true;
		}
		else {
			LeftFlg = false;
		}
		lpD3DDevice->SetTransform(D3DTS_WORLD, &GetWaMat(&LeftFlg));
		DrawMesh(&Wall3D[w].Mesh);
	}
	lpD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);


	//�O���̕\��
	if (light.size() > 0) {
		for (unsigned int l = 0; l < light.size(); l++) {
			if (l > 1)return;
			if (l == 0) {
				LeftFlg = true;
			}
			else {
				LeftFlg = false;
			}
			light[l]->Draw3D(&GetWaMat(&LeftFlg,0));
		}

	}
}

void Wall::InitLightOne(const int * wNum)
{
	if (*wNum < 0) return;
	if(*wNum > 1) return;

	//�O���̕\��������
	//D3DXMATRIX InvMat, Mat;
	//D3DXMatrixInverse(&InvMat, NULL, &Wall3D[*wNum].Base.Scal);
	//if (*wNum == 1) {
	//	Mat = Wall3D[*wNum].Base.Scal*Wall3D[*wNum].Base.Mat;
	//}
	//else {
	//	Mat = Wall3D[*wNum].Base.Scal*Wall3D[*wNum].Base.Mat;
	//}
	//light.push_back(new C_Light(&(InvMat*Mat)));
}

void Wall::InitLightW(const int * wNum)
{
	if (*wNum < 2) return;
	//�ǂɕ\��
	bool LeftFlg;
	for (int w = 0; w < 2; w++) {
		if (w == 0) {
			LeftFlg = true;
		}
		else {
			LeftFlg = false;
		}
		//�O��������
		light.push_back(new C_Light(&GetWaMat(&LeftFlg, 0)));
	}

}

void Wall::InitLight(const int *wNum)
{

	InitLightOne(wNum);
	InitLightW(wNum);
	
}

void Wall::SuperUpdate()
{
	Update();
	WaUpdate();
}

void Wall::SuperDraw()
{
	Draw();
	WaDraw();
}


LPD3DXMESH Wall::GetColModWall(const bool * LeftFlg)
{
	int w;
	if (*LeftFlg == true) {
		w = 0;
	}
	else {
		w = 1;
	}
	return Wall3D[w].ColModMesh.lpMesh;
}

D3DXMATRIX Wall::GetWaMat(const bool * LeftFlg)
{
	int w;
	if (*LeftFlg == true) {
		w = 0;
	}
	else {
		w = 1;
	}
	D3DXMATRIX TmpMat;
	TmpMat = Wall3D[w].Base.Scal*GetWaMat(LeftFlg,0);
	return TmpMat;
}

D3DXMATRIX Wall::GetWaMat(const bool * LeftFlg, int i)
{
	int w;
	if (*LeftFlg == true) {
		w = 0;
	}
	else {
		w = 1;
	}
	D3DXMATRIX TmpMat;
	TmpMat=Wall3D[w].Base.RotY*Wall3D[w].Base.Trans*Wall3D[w].Base.Mat;
	return TmpMat;
}
