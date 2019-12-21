#pragma once
#include<d3dx9.h>
#include<vector>
#include"SceneBase.h"
#include"../Ground/Sky.h"
#include"../Player/Gun1.h"
#include"../Ground/BillBase.h"
#include"../Player/Aiming.h"
#include"../Enemy/MoveE.h"
#include"../3DDraw/Explosion.h"
#include"../Gun/Bullet/BulletManager.h"
#include"../Player/Camera.h"
#include"../GameSource/Countdown.h"
#include"../Ground/Bill1.h"
#include"../GameSource/Debug.h"
#include"../GameSource/Debug2.h"
#include"../2DDraw/GameOver.h"
#include"../GameSource/Struct.h"
#include"../2DDraw/Warning.h"
#include"../2DDraw/Pause.h"
#include"../GameSource/Judgment.h"
#include"../3DDraw/Spear.h"
#include"../GameSource/Motion.h"
#include"../3DDraw/Spark2.h"
#include"../2DDraw/Score.h"
#include"../3DDraw/SpaekDamage.h"
#include"../3DDraw/Smog.h"
#include"../3DDraw/BulletGround.h"
#include"../Sound/SoundGun1.h"
#include"GameSceneSoundManager.h"
#include"../3DDraw/Smoke2.h"
#include"../Enemy/EnemySky.h"
#include"../Key/CMouse.h"
#include"../Key/Key.h"
#include"../2DDraw/Fade.h"
#include"../3DDraw/BulletHole3D.h"
#include"../Player2/PlayerA.h"
#include"../Enemy2/EnemyA.h"
#include"../Player2/PlayerBody.h"
#include"../2DDraw/PauseTouch.h"
#include"../2DDraw/OverTouch.h"
#include"../GameSource/Count.h"
#include"../Enemy2/EnemySelect.h"
#include"../EnemyData/Base&Manager/EnemySpeedManager.h"

extern Judg judg;
extern Motion motion;

//#ifndef GameScene_H
//#define GameScene_H

#define RadChara 200//�L�����N�^�[�͈̔�

class GameScene :public SceneBase, public C_GameSSM
{
public:
	void StageSave(const bool *Flg);
	void NewWaveSave(int StagNo);
	void NewEnemySave(int StagNo,int WaveNo);
	bool road(void);
	GameScene(const int stageNum);
	~GameScene();
	void Render3D(void);
	void Render2D(void);
	void SetCamera(void);
	bool Update(void);
	bool UpdateE(void);
	void GDebug(void);
	//�n�ʎ擾
	bool NowGroNum(D3DXMATRIX Mat,unsigned int *Num,float *Dis);
	//�e�̃��C����
	void BulletJudg(const int *TypeCar,const unsigned int *CarNo);
	//�ǂƎԑ̉��̔���
	bool WallJudg(bool LeftFlg, bool PlayerFlg, bool EnemyFlg, unsigned int No);
	//�ǂƎԉ��̔���(�Ԃ��n�ʂ��痣�ꂽ���p)
	bool WallJudg(const D3DXMATRIX *JudgMat, D3DXMATRIX *TransMat, const SizePos *sizePos);
	//�G�̒a���Ǝv�l
	bool UpdateEnemyAI(void);
	//�G�̈ړ�
	bool UpdateEnemyMove(void);
	//�O�i���C����
	bool ForMoveJudg(CONSTITUTION Con, D3DXMATRIX StartMat, D3DXMATRIX EndMat, bool PlayerFlg, bool EnemyFlg, unsigned int No, D3DXVECTOR3 RayVec1, D3DXVECTOR3 RayVec2, D3DXVECTOR3 RayVec3, float *SpeedMul2,const D3DXVECTOR3 *ScalPosB);
	//�ړ����Mat�쐬
	D3DXMATRIX ForMoveEnd(CONSTITUTION Con, QuaForMove q, D3DXMATRIX TransMat);
	//�J�����ƕǔ���
	void CameraWallJudg(void);
	//BulletBirthFlg
	bool GetBulletBirthFlg(void);
	//�����C���X�^���X���֐�
	void BombInit(const D3DXMATRIX *Mat);
	//�f���[�g�G�l�~�[
	bool EnemyDelete(const unsigned int *EnemyNo);
	//�G�̏o�����
	bool EnemyBirth(const int *EnemyNo,D3DXMATRIX *GroundMat,float *TransX);

	//�`�F���W�V�[���p
	void ChangeSceneFade(int ChangeSceneNo);
	void ChangeSceneFade(int ChangeSceneNo, int NextStageNo);
	bool SetScene(void);

	//���j���[�̓���
	void SetMenu(bool PauseFlg, bool ClearFlg, bool OverFlg);
	//���j���[�̍폜
	void DeleteMenu(void);
	//���j���[�̏���
	bool UpdateMenu(void);
	//�n�ʂ̎�������
	bool GroundCreate(unsigned int *GNo);
	//Pos2D�v�Z
	void Pos2DUpdate(const D3DXMATRIX *mProj, const D3DXMATRIX *mView, const D3DVIEWPORT9 *Viewport);

protected:
	//�e����̏�񏉊���
	BULLETJUDGDATA GetInitBJD(const float *InitDis);
	//�e����W
	void BulletJudgGround(BULLETJUDGDATA* BJD,const RAYDATA *RD,bool *HitFlg,const float *Rad);
	void BulletJudgPlayer(BULLETJUDGDATA* BJD, const RAYDATA *RD, const float *Rad);
	void BulletJudgEnemy(BULLETJUDGDATA* BJD,const RAYDATA *RD, const float *Rad);
	//�e����ɂ��_���[�W�v�Z
	bool SetBulletDamage(const BULLETJUDGDATA* BJD, const RAYDATA *RD,const int Damage);
	bool SetBulletDamageGround(const BULLETJUDGDATA* BJD, const RAYDATA *RD);
	bool SetBulletDamageWall(const BULLETJUDGDATA* BJD, const RAYDATA *RD);
	bool SetBulletDamagePlaCar(const int *BulletJudgFlg, const int *Damage);
	bool SetBulletDamagePlaParts(const int *BulletJudgFlg, const unsigned int *HitMesh, const int *Damage);
	bool SetBulletDamagePlaGun(const int *BulletJudgFlg, const unsigned int *HitMesh, const int *Damage);
	bool SetBulletDamageEneCar(const int *BulletJudgFlg, const unsigned int *HitBodyNo, const int *Damage);
	bool SetBulletDamageEneParts(const int *BulletJudgFlg, const unsigned int *HitBodyNo, const unsigned int *HitMesh, const int *Damage);
	bool SetBulletDamageEneGun(const int *BulletJudgFlg, const unsigned int *HitBodyNo, const unsigned int *HitMesh, const int *Damage);
	void BulletJudgS(bool PlaBulFlg, unsigned int EnemyNo);
private:
	//�f�o�b�O�p----------------
	float Size, RaySize;
	int CountNum, MaxCount;//�X���[�Đ��p
	Spear *spear;
	D3DXMATRIX SpeMat;
	float DbgSize;
	//--------------------------
	//�v���C���[�̏��
	C_PlayerBody *PlayerBody;
	//�v���C���[
	C_PlayerBase *player;//

	//�n�ʂ̃����o
	std::vector<BillBase*>ground;
	Cou *cou;//bill
	std::vector<Cou*>GroCou;
	int GroType, GroKNum, *CurType, NowCur;
	float AngGro;//�J�[�u���̊p�x
	bool GroLenFlg;//�����̕ύX
	//�O���\���p�J�E���g�_�E��
	C_Count *LightCount;

	std::vector<C_EnemyAi*>enemy;
	bool eneFlg;//�o���̐؂�ւ�
	Sky *sky;
	Aiming *aiming;
	std::vector<Explo*>explo;
	Camera *camera;
	Debug *debug;
	DebugT *debugT;
	GameOver *GaOv;
	bool EndFlg;//�N���A�ƃG���h��Flg

	Warning *war;

	//�G�̏��������Ă���ϐ�
	char FRName[100];//���[�h�p
	char FSName[100];//�Z�[�u�p
	int StageNo;
	std::vector<EnemyPop*>ePop;
	int MaxWaveNum;//�ő�E�F�[�u��
	int NowWaveNum;//���̃E�F�[�u��
	int MaxEnemyNum;//���̃E�F�[�u�̍ő�G�̐�
	int NowEnemyNum;//���̃E�F�[�u�̓G�̐�
	int NextEnemyNo;//���̃E�F�[�u�̓G�̃i���o�[

	Pause *pause;

	//�Ήԕϐ�
	std::vector<C_Spark*>SparkV;

	//�X�R�A
	C_Score *score;

	//�o���b�g�o�[�XFlg
	bool BulletBirthFlg;

	//smog
	std::vector<C_Smog *>Smog;
	C_Smoke2 *PlaSmo;

	//�}�E�X
	C_Mouse *mouse;
	//�L�[
	Key key;
	//�t�F�[�h
	Fade *fade;
	//�`�F���W�V�[���p
	int SceneNo;
	bool SceneChangeFlg;
	int ChangeStageNo;

	//�e���RD
	std::vector<C_BulHol3D*>BHole3D;

	//�^�b�`
	std::vector<C_NextTouch*>Menu;

};

//#endif // !GameScene_H
