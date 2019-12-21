#include "Motion.h"

float Motion::CurveFloat(float A, float B, float C, float AnimeFlame)
{
	return (pow((1.0f - AnimeFlame), 2.0f)*A + 2 * (1.0f - AnimeFlame)*AnimeFlame*B + pow(AnimeFlame, 2.0f)*C);
}

D3DXVECTOR3 Motion::CurvePos(D3DXMATRIX MatS, D3DXVECTOR3 PosV, D3DXMATRIX MatE, float AnimeFlame)
{
	D3DXVECTOR3 Pos;
	Pos.x = CurveFloat(MatS._41, PosV.x, MatE._41, AnimeFlame);
	Pos.y = CurveFloat(MatS._42, PosV.y, MatE._42, AnimeFlame);
	Pos.z = CurveFloat(MatS._43, PosV.z, MatE._43, AnimeFlame);
	return Pos;
}
//bool Motion::Formove(CONSTITUTION Con, D3DXMATRIX * Mat, float * Anime, std::vector<BillBase*> ground, bool * qGFlg, bool * qFlg, float * SpeB, D3DXMATRIX * StartMat, D3DXMATRIX * EndMat, D3DXVECTOR3 * WayVec, float * NowSpeed, D3DXVECTOR3 * CurVec, bool * CurFlg, float Y)
//{
//	bool OverFlg = false;//�N�H�[�^�j�I����1.0f�𒴂����Ƃ���Flg
//	bool EndFlg = false;
//	float VecSize,CurDrawSpeed;
//	while (EndFlg == false) {
//		unsigned int GNo = Con.GroNum, NextGNo = GNo + 1;
//		if (OverFlg == true) {
//			//�n�ʔ���
//			if (ground.size() <= 0) {
//				return false;
//			}
//			float size;
//			//�n�ʃ��C����
//			bool JudgFlg = false;
//			for (unsigned int g = 0; g < ground.size(); g++) {
//				if (judg.ball(*Mat, ground[g]->GetMat(), 40.0f) == true) {//�����̎��͂̒n�ʂ����𔻒�
//					D3DXVECTOR3 v[4];
//					for (int i = 0; i < 4; i++) {
//						v[i] = ground[g]->GetVer(i);
//					}
//					if (ground[g]->GetIdenFlg() == false) {//�n�ʂ�IdentityMat�ŏo���Ă��邩�̔���
//						if (judg.RayPolM(*Mat, v[0], v[1], v[2], v[3], ground[g]->GetMat(), D3DXVECTOR3(0.0f, -1.0f, 0.0f), &size) == true)//�|���S���ƃ��C����
//						{
//							GNo = g;
//							NextGNo = GNo + 1;
//							JudgFlg = true;
//							break;
//						}
//					}
//					else {
//						if (judg.RayPolM(*Mat, v[0], v[1], v[2], v[3], D3DXVECTOR3(0.0f, -1.0f, 0.0f), &size) == true)//�|���S���ƃ��C����
//						{
//							GNo = g;
//							NextGNo = GNo + 1;
//							JudgFlg = true;
//							break;
//						}
//					}
//				}
//			}
//			if (JudgFlg == false) {
//				return false;
//			}
//		}
//		//�n�ʂ̔ԍ��O����
//		if (ground.size() - 1 < NextGNo) {
//			return false;
//		}
//		bool Flg = false, curFlg = false,CurveFlg=true;
//		int RailNum;
//		unsigned int Type = ground[GNo]->GetWay().WayType;
//		//������
//		if (*qGFlg == false) {
//		    *NowSpeed = Con.Speed;
//			*qGFlg = true;
//			Flg = true;
//			D3DXVECTOR3 Vec;
//			bool CurHeikinFlg = false;
//			//�J�[�u�̑��x��������
//			if ((Type == 0) && (ground[NextGNo]->GetWay().WayType == 0)) {
//				CurveFlg = false;
//			}
//			//�J�[�u�̔���
//			if (CurveFlg == true) {
//				float Ang;
//				if (Type != 0) {
//					Ang = ground[GNo]->GetWay().Ang;
//				}
//				else {
//					Ang = 0.0f;
//				}
//				bool NoFlg = false;
//				for (unsigned int g = NextGNo; g < ground.size(); g++) {
//					if ((ground[g]->GetWay().WayType == Type) || (Type == 0)) {
//						Type = ground[g]->GetWay().WayType;
//					}
//					else {
//						NextGNo = g;
//						NoFlg = true;
//						break;
//					}
//					if(Ang < 90.0f) {
//						Ang += ground[g]->GetWay().Ang;
//						if (Ang > 90.0f) {
//							NextGNo = g - 1;
//							NoFlg = false;
//							break;
//						}
//					}
//				}
//				if (NoFlg == false) {
//					return false;
//				}
//			}
//			//�J�[�u�̑��x����
//			if(Type!=0){
//				*SpeB = 1.1f;
//			}
//			else {
//				*SpeB = 1.0f;
//			}
//			//start����end�܂ł�Vec�v�Z
//			RailNum = Con.NowRail;
//			judg.MatMatVec(&Vec, ground[GNo]->GetWay().qMat[RailNum], ground[NextGNo]->GetWay().qMat[RailNum]);
//			*WayVec = Vec;
//			//�x�W�F�Ȑ��̔���
//			if (Type!=0) {
//				*CurFlg = true;
//				curFlg = true;
//			}
//			else {
//				*CurFlg = false;
//			}
//		}
//		//startMat��endMat�̃Z�b�g
//		if (*qFlg == false) {
//			*StartMat = ground[GNo]->GetWay().qMat[Con.NowRail];
//			*EndMat = ground[NextGNo]->GetWay().qMat[Con.NowRail];
//			*qFlg = true;
//		}
//		//�x�W�F�Ȑ��̌v�Z
//		if (curFlg == true) {
//			D3DXMATRIX Mat, MatE, RotX, RotY;
//			D3DXVECTOR3 wVec = *WayVec / 2.0f, wPos;
//			D3DXMatrixTranslation(&Mat, 0.0f, 0.0f, 0.0f);
//			judg.TarEndMat(&MatE, Mat, &RotX, &RotY, *WayVec, D3DXVECTOR3(0.0f, 0.0f, 1.0f));
//			judg.SetPosM(&wPos, *StartMat);
//			judg.SetMatP(&MatE, (wPos + wVec));
//			float Size=0.0f,LR=1.0f;
//			if (Type==1) {
//				LR *= -1.0f;
//			}
//			D3DXVECTOR3 Vec;
//			for (unsigned int i = GNo; i < NextGNo; i++) {
//				judg.MatMatVec(&Vec, ground[i]->GetWay().qMat[Con.NowRail], ground[i + 1]->GetWay().qMat[Con.NowRail]);
//				Size += D3DXVec3Length(&Vec);
//			}
//			Size += D3DXVec3Length(WayVec);
//			D3DXVec3TransformCoord(CurVec, &D3DXVECTOR3(CurSize*(float)(NextGNo - GNo)*Size*LR, 0.0f, 0.0f), &MatE);
//		}
//		//�X�s�[�h�̌v�Z
//		if (OverFlg==false) {
//			if (*CurFlg == true) {//�J�[�u���ɃX�s�[�h��x������
//				CurDrawSpeed = 0.8f;
//			}
//			else {
//				CurDrawSpeed = 1.0f;
//			}
//			float Size = D3DXVec3Length(WayVec);
//			Size *= *SpeB;
//			float Speed = *NowSpeed*CurDrawSpeed / Size;
//			*Anime += Speed;
//		}
//		else {
//			//�I�[�o�[���̏���
//			float wVec;
//			wVec = D3DXVec3Length(WayVec);
//			wVec *= *SpeB;
//			wVec = VecSize / wVec;
//			*Anime += wVec;
//		}
//		bool qeFlg = false;
//		//�I�[�o�[���̌v�Z
//		if (*Anime > 1.0f) {
//			D3DXVECTOR3 Vec;
//			Vec = *WayVec;
//			VecSize = D3DXVec3Length(&(Vec*(*Anime) - Vec));
//			*Anime = 1.0f;
//			OverFlg = true;
//			qeFlg = true;
//		}
//		else {
//			EndFlg = true;
//		}
//		//�N�H�[�^�j�I��
//		judg.AnimeProc(Mat, *StartMat, *EndMat, *Anime);
//		//�x�W�F�Ȑ��̃N�H�[�^�j�I��
//		if (*CurFlg == true) {
//			D3DXVECTOR3 Pos;
//			Pos = CurvePos(*StartMat, *CurVec, *EndMat, *Anime);
//			judg.SetMatP(Mat, Pos);
//		}
//		//�N�H�[�^�j�I���̏I������
//		if (qeFlg == true) {//�O�i
//			*qFlg = false;
//			*qGFlg = false;
//			*Anime = 0.0f;
//		}
//		//��������
//		D3DXMATRIX Tmp;
//		D3DXMatrixTranslation(&Tmp, 0, Y, 0);
//		*Mat = Tmp * (*Mat);
//		//�I������
//		if (EndFlg == true) {
//			break;
//		}
//	}
//	return true;
//}

bool Motion::Formove(CONSTITUTION Con, D3DXMATRIX * Mat, float * Anime, std::vector<BillBase*> ground, bool * QuaInitFlg, bool * QuaMatInitFlg ,float *SpeedMul, float SpeedMul2 , D3DXMATRIX * StartMat, D3DXMATRIX * EndMat, D3DXVECTOR3 * WayVec,bool *CurFlg,D3DXVECTOR3 *CurVec, float BodyHeight)
{
	bool OverFlg = false;//�N�H�[�^�j�I����1.0f�𒴂����Ƃ���Flg
	bool EndFlg = false;//�N�H�[�^�j�I���I��Flg
	float VecSize,CurDrawSpeed=1.0f;
	while (EndFlg == false) {
		//�n�ʂ̃i���o�[�Ǝ��̃i���o�[
		unsigned int GNo = Con.GroNum, NextGNo = GNo + 1;
		//AnimeFrame��1.0f�𒴂��Ă�������
		if (OverFlg == true) {
			//�n�ʂ��L���m�F
			if (ground.size() <= 0) {
				return false;
			}
			//���C���莞�̃��C�̒�������p
			float Dis;
			//�n�ʃ��C����
			bool JudgFlg = false;
			for (unsigned int g = 0; g < ground.size(); g++) {
				if (judg.ball(*Mat, ground[g]->GetMat(), 40.0f) == true) {//�����̎��͂̒n�ʂ����𔻒�
					D3DXVECTOR3 v[4];
					for (int i = 0; i < 4; i++) {
						v[i] = ground[g]->GetVer(i);
					}
					if (ground[g]->GetIdenFlg() == false) {//�n�ʂ�IdentityMat�ŏo���Ă��邩�̔���
						if (judg.RayPolM(*Mat, v[0], v[1], v[2], v[3], ground[g]->GetMat(), D3DXVECTOR3(0.0f, -1.0f, 0.0f), &Dis) == true)//�|���S���ƃ��C����
						{
							GNo = g;
							NextGNo = GNo + 1;
							JudgFlg = true;
							break;
						}
					}
					else {
						if (judg.RayPolM(*Mat, v[0], v[1], v[2], v[3], D3DXVECTOR3(0.0f, -1.0f, 0.0f), &Dis) == true)//�|���S���ƃ��C����
						{
							GNo = g;
							NextGNo = GNo + 1;
							JudgFlg = true;
							break;
						}
					}
				}
			}
			//����
			if (JudgFlg == false) {
				//�������Ă��Ȃ�
				return false;
			}
		}
		//���̒n�ʂ̗L��
		if (ground.size() - 1 < (unsigned int)(NextGNo)) {
			//�����Ƃ�
			return false;
		}
		bool /*Flg = false,*/ CurInitFlg = false,CurveFlg=true;
		//�n�ʂ̌`
		unsigned int Type = ground[GNo]->GetWay().WayType;
		//������
		if (*QuaInitFlg == false) {
			//����������
			*QuaInitFlg = true;
			//Flg = true;
			D3DXVECTOR3 Vec;
			//�J�[�u����Flg
			bool CurHeikinFlg = false;
			//�J�[�u�̑��x��������
			if ((Type == 0) && (ground[NextGNo]->GetWay().WayType == 0)) {
				CurveFlg = false;
			}
			//�J�[�u�̔���
			if (CurveFlg == true) {
				float Ang;
				if (Type != 0) {
					Ang = ground[GNo]->GetWay().Ang;
				}
				else {
					Ang = 0.0f;
				}
				bool NoFlg = false;
				//�J�[�u�̒T��
				for (unsigned int g = NextGNo; g < ground.size(); g++) {
					if ((ground[g]->GetWay().WayType == Type) || (Type == 0)) {
						Type = ground[g]->GetWay().WayType;
					}
					else {
						NextGNo = g;
						NoFlg = true;
						break;
					}
					if(Ang < 90.0f) {
						Ang += ground[g]->GetWay().Ang;
						if (Ang > 90.0f) {
							NextGNo = g-1;
							NoFlg = true;
							break;
						}
					}
				}
				//������Ȃ�������
				if (NoFlg == false) {
					return false;
				}
			}
			//�J�[�u�̑��x����
			if(Type!=0){
				//�J�[�u
				*SpeedMul = 1.1f;
			}
			else {
				//�X�g���[�g
				*SpeedMul = 1.0f;
			}
			//start����end�܂ł�Vec�v�Z
			judg.MatMatVec(&Vec, ground[GNo]->GetWay().StartMat, ground[NextGNo]->GetWay().StartMat);
			*WayVec = Vec;
			//�x�W�F�Ȑ��̔���
			if (Type!=0) {
				*CurFlg = true;
				CurInitFlg = true;
			}
			else {
				*CurFlg = false;
			}
		}
		//startMat��endMat�̃Z�b�g
		if (*QuaMatInitFlg == false) {
			*StartMat = ground[GNo]->GetWay().StartMat;
			*EndMat = ground[NextGNo]->GetWay().StartMat;
			*QuaMatInitFlg = true;
		}
		//�x�W�F�Ȑ��̌v�Z
		if (CurInitFlg == true) {
			D3DXMATRIX Mat, MatE, RotX, RotY;
			D3DXVECTOR3 wVec = *WayVec / 2.0f, wPos;
			D3DXMatrixTranslation(&Mat, 0.0f, 0.0f, 0.0f);
			judg.TarEndMat(&MatE, Mat, &RotX, &RotY, *WayVec, D3DXVECTOR3(0.0f, 0.0f, 1.0f));
			judg.SetPosM(&wPos, *StartMat);
			judg.SetMatP(&MatE, (wPos + wVec));
			float Size=0.0f,LR=1.0f;
			if (Type==1) {
				LR *= -1.0f;
			}
			D3DXVECTOR3 Vec;
			for (unsigned int i = GNo; i < NextGNo; i++) {
				judg.MatMatVec(&Vec, ground[i]->GetWay().StartMat, ground[i + 1]->GetWay().StartMat);
				Size += D3DXVec3Length(&Vec);
			}
			Size += D3DXVec3Length(WayVec);
			D3DXVec3TransformCoord(CurVec, &D3DXVECTOR3(CurSize*(float)(NextGNo-GNo)*Size*LR, 0.0f, 0.0f), &MatE);
		}
		//�X�s�[�h�̌v�Z
		if (OverFlg ==false) {
			if (*CurFlg == true) {//�J�[�u���ɃX�s�[�h��x������
				CurDrawSpeed = 0.8f;
			}
			else {
				CurDrawSpeed = 1.0f;
			}
			float Size = D3DXVec3Length(WayVec),NowSpeed= D3DXVec3Length(&Con.Speed)*SpeedMul2;
			Size *= *SpeedMul;
			float Speed =NowSpeed*CurDrawSpeed / Size;
			*Anime += Speed;
		}
		else {
			//�I�[�o�[���̏���
			float wVec;
			wVec = D3DXVec3Length(WayVec);
			wVec *= *SpeedMul;
			wVec = VecSize / wVec;
			*Anime += wVec;
		}
		bool qeFlg = false;
		//�I�[�o�[���̌v�Z
		if (*Anime > 1.0f) {
			D3DXVECTOR3 Vec;
			Vec = *WayVec;
			VecSize = D3DXVec3Length(&(Vec*(*Anime) - Vec));
			*Anime = 1.0f;
			OverFlg = true;
			qeFlg = true;
		}
		else {
			EndFlg = true;
		}
		//�N�H�[�^�j�I��
		judg.AnimeProc(Mat, *StartMat, *EndMat, *Anime);
		//�x�W�F�Ȑ��̃N�H�[�^�j�I��
		if (*CurFlg == true) {
			D3DXVECTOR3 Pos;
			Pos = CurvePos(*StartMat, *CurVec, *EndMat, *Anime);
			judg.SetMatP(Mat, Pos);
		}
		//�N�H�[�^�j�I���̏I������
		if (qeFlg == true) {//�O�i
			*QuaInitFlg = false;
			*QuaMatInitFlg = false;
			*Anime = 0.0f;
		}
		//��������
		D3DXMATRIX Tmp;
		D3DXMatrixTranslation(&Tmp, 0,BodyHeight, 0);
		*Mat = Tmp * (*Mat);
		//�I������
		if (EndFlg == true) {
			break;
		}
	}
	return true;
}

bool Motion::CurveMove(D3DXMATRIX * TransMat, D3DXMATRIX StartMat, D3DXMATRIX EndMat, float * AnimeFarme, float Up)
{
	bool MoveFlg = true;
	*AnimeFarme += Up;
	if (*AnimeFarme > 1.0f) {
		*AnimeFarme = 1.0f;
		MoveFlg = false;
	}
	judg.AnimeProc(TransMat, StartMat, EndMat, *AnimeFarme);
	if (MoveFlg == false) {
		*AnimeFarme = 0.0f;
	}
	return MoveFlg;
}

bool Motion::CurveMove(D3DXMATRIX * TransMat, D3DXMATRIX StartMat, D3DXMATRIX RotMat, D3DXMATRIX EndMat, float * AnimeFarme, float Up, bool * Reverse)
{
	bool MoveFlg = true;
	*AnimeFarme += Up;
	if (*AnimeFarme > 1.0f) {
		*AnimeFarme = 1.0f;
		MoveFlg = false;
	}
	if (*Reverse == false) {
		judg.AnimeProc(TransMat, StartMat, RotMat, *AnimeFarme);
	}
	else {
		judg.AnimeProc(TransMat, RotMat, EndMat, *AnimeFarme);
	}
	if (MoveFlg == false) {
		*AnimeFarme = 0.0f;
		if (*Reverse == false) {
			MoveFlg = true;
			*Reverse = true;
		}
		else {
			*Reverse = false;
		}
	}
	return MoveFlg;
}
