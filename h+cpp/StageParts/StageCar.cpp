#include "StageCar.h"

StageCar::StageCar(const BODYDATA * Data):C_PlayerA(Data)
{
	D3DXMatrixTranslation(&Car.Base.Mat, 0.0f, 0.0f, 0.0f);
	Car.Con.NowSpeed = 0;
}

bool StageCar::UpdateAll(void)
{


	//�e�̂������s��T��
	D3DXMATRIX GunMat = GetMatCar();
	//�W���p�[�c�̃A�b�v�f�[�g
	if (Parts.size() > 0) {
		for (unsigned int p = 0; p < Parts.size(); p++) {
			Parts[p]->SetSpeed(&Car.Con.NowSpeed, &Car.Con.MaxSpeed);
			Parts[p]->UpdateParts(&GetMatCar());
			//�e�̂���������
			if (Parts[p]->GetParts().GunFlg >0) {
				GunMat = Parts[p]->GetParts().Base.Mat;
			}
		}
	}

	//�e�̃A�b�v�f�[�g
	D3DXMATRIX Tmp;
	D3DXMatrixTranslation(&Tmp, 0.0f, 0.0f, 0.0f);
	ConnectGunMat = Tmp * GunMat;
	D3DXMATRIX Car;
	D3DXMatrixRotationX(&Car, D3DXToRadian(1.0f));
	UpdateGun(&Car);

	return true;
}
