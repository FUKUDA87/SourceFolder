#pragma once
#include<d3dx9.h>
#include"Wall.h"

class BillBase:public Wall{
private:
protected:
	Object3D bill;
	bool obj;
public:
	void InitBB();
	BillBase();
	BillBase(int i) :Wall(i) { InitBB(); };
	BillBase(D3DXMATRIX Mat3, D3DXMATRIX Mat4, int gType, float Ang, float Length, bool LengthAuto) :Wall(Mat3, Mat4,gType, Ang, Length, LengthAuto) { InitBB(); };
	~BillBase();
	virtual bool UpdateBil();
	virtual void DrawBil();
	void SuperUpdate() {
		Update();
		WaUpdate();
		UpdateBil();
	}
	void SuperDraw() {
		Draw();
		WaDraw();
		DrawBil();
	}
	bool GetObjFlg() {
		return obj;
	};
	//�\����FlgSet
	//void SetAllDrawFlg(bool Flg) {
	//	//Flg�������
	//	ground.Base.DrawFlg = WallDrawFlg = bill.Base.DrawFlg = Flg;
	//}
};
