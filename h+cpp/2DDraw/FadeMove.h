#pragma once
#include<d3dx9.h>

class C_FadeMove {
public:
	virtual C_FadeMove* Action(bool *MoveFlg, int *Alpha,int alphaUp) = 0;
};

//何もしない状態
class C_FadeNoMove:public C_FadeMove {
public:
	C_FadeMove* Action(bool *MoveFlg, int *Alpha, int alphaUp);
};