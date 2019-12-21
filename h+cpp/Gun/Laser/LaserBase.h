#pragma once
#include"../../GameSource/Struct.h"
#include<d3dx9.h>

class LaserBase {
private:
protected:
	Pol lasS;//�n�_
	Pol Las;//���[�U�[
	Pol lasE;//�I�_
	float LasDis;
	bool lasFlg;
public:
	virtual void Init() {
		lasFlg = false;
	};
	LaserBase();
	LaserBase(float Dis);
	~LaserBase() {};
	virtual bool UpdateS() { return true; };//�n�_
	virtual bool UpdateS(D3DXMATRIX Mat,D3DXMATRIX Tmp) { return true; };//�n�_
	virtual bool UpdateL() { return true; };//��
	virtual bool UpdateL(float Dis,bool Flg) { return true; };//��
	virtual bool UpdateE() { return true; };//�I�_
	virtual void Draw3D() {};
	D3DXMATRIX GetLasMat() {
		return Las.Base.Mat;
	};
	float GetLasDis() {
		return LasDis;
	}
	virtual D3DXVECTOR3 GetLasVec() {
		return D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}
	virtual void SetLasFlg(bool Flg) {
		lasFlg = Flg;
	}
	virtual bool GetLasFlg(void) {
		return lasFlg;
	}
};