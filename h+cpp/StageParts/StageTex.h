#pragma once
#include<d3dx9.h>
#include"../2DDraw/modoru.h"
#include"../2DDraw/NumA.h"

class StageTex :public Modoru,NumA {
private:
protected:
	int StageNo;//�ԍ�
public:
	StageTex() {};
	StageTex(const int No, const D3DXVECTOR3 WindPos);
	~StageTex() {};
	void Draw2DN();
	void DrawSu();
	int GetStageNo(void) {
		return StageNo;
	}
};