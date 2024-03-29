#pragma once
#include<d3dx9.h>
#include"../../../GameSource/Struct.h"
#include"../../Bullet/BulletBase.h"
#include"../../../GameSource/XfileManager.h"
#include"../../Muz/MuzFlaBase.h"
#include"../../Laser/LaserBase.h"
#include"../../../GameSource/Judgment.h"
#include"../../../GameSource/CharaBase.h"
#include"../../../EnemyData/Base&Manager/EnemyDataBase.h"
#include"../../../EnemyData/Base&Manager/EnemyGunMoveBase.h"
#include"../../../EnemyData/Base&Manager/EnemyDataManager.h"

class C_GunBase2:public C_CharaBase {
public:
	C_GunBase2() {
		Gun.Base.DrawFlg = true;
	};
	C_GunBase2(const GUNINITDATA* GunInitDataS);
	~C_GunBase2();
	//ú»
	void Init_Gun(const GUNINITDATA* GunInitDataS);
	//\¦
	void Draw3D_Gun();
	////p³Abvf[g
	bool Update();
	////p³\¦
	bool Update_Gun(const D3DXMATRIX *Mat, int *NowPhase);

	//eÌîñnµ
	GUNDATA GetGunData(void) {
		return Gun;
	}

	//gåüê
	void SetScalPos(const D3DXVECTOR3 *sPos) {
		Gun.Base.ScaPos = *sPos;
	}

	////////////////////////////////////////////////////////////////////////////////////////

	//\¦psñÌnµ
	D3DXMATRIX GetDrawMatGun(void) {
		return judg.GetDrawMat(&Gun.Base.Mat, &Gun.Base.Scal, &Gun.Base.ScaPos);
	}

	//\¦RDÌØèÖ¦
	void SetMeshGun(int MeshNo);

	void GetTargetPos(const D3DXVECTOR3* Pos) {
		s_Data.TargetPos = *Pos;
	}

	bool GetRayJudgFlg(void) {
		return s_Data.RayJudgFlg;
	}
	S_ENEMYGUNDATA GetEnemyGunData(void) {
		return s_Data;
	}
	
	void SetHitRayFlg(const bool *Flg) {
		s_Data.RayHitFlg = *Flg;
	}
	void SetBulletFlg(const bool *Flg) {
		s_Data.BulletFlg = *Flg;
	}

protected:
	GUNDATA Gun;

	S_ENEMYGUNDATA s_Data;

	C_E_GunMoveBase *m_Move;

	Judg judg;
};