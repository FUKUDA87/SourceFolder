#pragma once
#include"State.h"

//�\��1
class C_Draw3DStateA :public StateDraw3D {
public:
	StateDraw3D* Action(Object3D *Object);
};