#pragma once
#include"Struct.h"
#include<stdio.h>
#include"Const.h"

//�P�̃e�N�X�`��
class C_TexManagerBase {
public:
	//���f�����n��
	virtual LPDIRECT3DTEXTURE9 GetTex(int MeshNo) = 0;
protected:
	//���f�����T��
	//virtual bool GetMeshJudg(int MeshNo) = 0;
};