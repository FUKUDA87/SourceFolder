#pragma once
#include<d3dx9.h>
#include"Struct.h"

//�����p
class StateMove {
public:
	virtual StateMove* Action(ObjectParts *ObjPar) = 0;//=0:�������z�֐��ɂ���i�K���p�����A�h���N���X���ŃI�[�o�[���C�h���Ȃ��Ƃ����Ȃ��֐�
};


class StateDraw3D {
public:
	virtual StateDraw3D* Action(Object3D *Object) = 0;//=0:�������z�֐��ɂ���i�K���p�����A�h���N���X���ŃI�[�o�[���C�h���Ȃ��Ƃ����Ȃ��֐�
};