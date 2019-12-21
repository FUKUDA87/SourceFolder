#pragma once
#include<d3dx9.h>

#ifndef Ball_H
#define Ball_H


class Ball {
private:
	LPD3DXMESH lpBall;//���b�V���̌`��̃f�[�^������ϐ�
	D3DMATERIAL9 BallMaterial;//�}�e���A���i�F�E�ގ��j
	D3DXMATRIX BaMat;
protected:
public:
	void Init();
	Ball() {};
	Ball(float radius);
	~Ball() ;
	void Draw();
	bool Update(D3DXMATRIX mat);
};

#endif // !Ball_H
