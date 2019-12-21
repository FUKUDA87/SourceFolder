#pragma once
#include<d3dx9.h>
#include<dsound.h>

//#ifndef Struct_H
//#define Strcut_H

//XFILE�̍\����
struct XFILE {
	LPD3DXMESH lpMesh;//���b�V���̌`��̃f�[�^
	DWORD NumMaterial;//�O���[�v�̐�
	D3DMATERIAL9 *Mat;//�}�e���A���̓��ex�O���[�v��
	LPDIRECT3DTEXTURE9 *Tex;//�e�N�X�`���̓��ex�O���[�v��
};
//VERTEX�̍\����
struct VERTEX
{
	D3DXVECTOR3 Pos;
	D3DCOLOR Color;
	D3DXVECTOR2 Tex;
};
//TEXTURE�̍\����
struct TEXTURE {
	LPDIRECT3DTEXTURE9 Tex;
	int Width, Height;
	int a, g, b;
};
//�\����3D�̍\����
struct  BASE3D {
	D3DXMATRIX Mat, Trans,Rot, RotX, RotY, RotZ, Scal,DrawMat;
	D3DXVECTOR3 Pos,ScaPos,TraPos;
	double AngX, AngY, AngZ;
	bool Flg, DrawFlg, UpdateFlg;//���݂̃I���ƃI�t
	float AttRad,BodRad;//�����蔻��̔��a
	bool MoveFlg;//�����Ă��邩�ǂ���
	DWORD NumVertex;
};
//�\����2D�̍\����
struct  BASE2D {
	D3DXMATRIX Mat, Trans, RotZ, Scal;
	D3DXVECTOR3 Pos,ScaPos,TraPos;
	D3DXVECTOR3 Pos2D;
	float AngZ;
	bool Flg,DrawFlg,UpdateFlg;//���݂̃I���ƃI�t
	bool MFlg;//�����Ă��邩�ǂ���
};
//�L�����̊�{���
struct CHARABASE {
	int MaxHp, NowHp;//Hp
	bool DamageSetFlg;//�_���[�W���󂯂�Flg
};
//�X�e�[�^�X�̍\����
struct STATUS {
	CHARABASE CharaBase;
	//int NowLevel, MaxLevel;
	//float Attack, Defense, Critical;//�U���͂Ǝ���͂Ɖ^
};
//�Q�[���V�X�e���̏��̍\����
struct CONSTITUTION {
	D3DXVECTOR3 Speed;//�X�s�[�h
	int NowSpeed,MaxSpeed;
	float SpeedMul, SpeedMulJudg;//multiplication
	bool CurFlg;//�Ԑ��ύX���̔���
	bool CurLFlg;//�Ԑ��ύX���̍��L�[�ݒ�
	bool CurRFlg;//�Ԑ��ύX���̉E�L�[�ݒ�
	bool DFlg;//�G�̍U������t���O
	bool PEFlg;//�G�Ǝ��@���Փ˃t���O
	unsigned int GroNum;//���̒n��
	D3DXMATRIX JudgMat;//�ԑ̂̕����𓾂邽�߂�Mat
	XFILE ColModMesh;//�R���W�������f��
	XFILE DeadMesh;//����̃��b�V��
	D3DXVECTOR3 PosBig;//���b�V���̃v���X�̉������W+����
	D3DXVECTOR3 PosSmall;//���b�V���̃v���X�̉������W-����
};
struct EneCon {
	float Size;//player�Ƌ���
	bool SiFlg;//player�Ƌ����̔���
};
//���̕�3D�̍\����
struct Object3D {
	XFILE Mesh;
	BASE3D Base;
};
//���̕�3D�̍\����
struct Object3D2 {
	XFILE Mesh;
	BASE3D Base;
	XFILE ColModMesh;//�R���W�������f��
	D3DXVECTOR3 PosBig;//���b�V���̃v���X�̉������W+����
	D3DXVECTOR3 PosSmall;//���b�V���̃v���X�̉������W-����
};
//�L�����N�^�[3D�̍\����
struct CHARA3D {
	XFILE Mesh;
	BASE3D Base;
	STATUS Sta;
	CONSTITUTION Con;
};
struct Enemy3D {
	CHARA3D CH;
	EneCon EC;
};
//�摜2D�̍\����
struct CHARA2D {
	TEXTURE TEX;
	BASE2D Base;
};
//�摜2D�̍\����2
struct CHARA2D2 {
	TEXTURE TEX;
	TEXTURE TEX2;
	BASE2D Base;
};
//�|���S���l�p�`�̍\����
struct Pol {
	VERTEX v[4];
	TEXTURE TEX;
	BASE3D Base;
	//��R�̃|���S���\���p
	D3DXMATRIX *PolMat;
};
//���̏��
struct Way
{
	int WayType;//�ԓ��̌^
	bool Cur;//�J�[�u�̎ԓ�����
	float Ang;
	D3DXMATRIX StartMat;//�N�H�[�^�j�I���p�̎n�_Mat
	int RailNum;//�Ԑ��̐�
	float *CurTransX;//�Ԑ��̏�����Ԃ̉��ړ�Mat
};
struct judgDeta {
	D3DXMATRIX Mat;
	float Rad;
	int Hp;
	int MaxHp;
};
struct QuaAnim {
	D3DXMATRIX EndMat, StartMat,NowMat,RotX,RotY,RotZ,RotA,Trans;
	float Ang;
	float AnimeFrame,FrameUp,Reverse;//Reverse��1.0f��-1.0f
	D3DXVECTOR3 Pos, Vec,StartPos,EndPos;
	bool MoveFlg,ReverseFlg;
	int Count, CountEnd;
};
struct QuaMove {
	float SpeB;
	//int Qup;//�N�H�[�^�j�I���p��Mat[�ϐ�]
	bool qFlg, qGFlg, cFlg;
	unsigned int GroNo;
	D3DXMATRIX StartMat, EndMat;
};
struct EnemyPop {
	int MaxNum;//�ő�o����
	int rePopTime[10];//�G�������܂ł̎���
	int EneNumber[10];//�G�̎��
};
struct CHARAData {
	D3DXMATRIX NowMat,StartMat,EndMat;
	float Rad;
	int Speed;
	unsigned int NowGround;
	bool GroundFlg,DrawFlg,CurFlg;
	LPD3DXMESH Mesh;
};

struct CLONEVERTEX {
	D3DXVECTOR3 Pos;//���W
	D3DXVECTOR3 Normal;//�@��
	D3DXVECTOR2 Tex;//�e�N�X�`�����W
};
struct QuaForMove{
	D3DXMATRIX NowMat, StartMat, EndMat;
	float AnimeFrame, BodyHeight,SpeedMul,SpeedMul2;
	bool QuaInitFlg,QuaMatInitFlg,CurFlg;
	D3DXVECTOR3 WayVec, CurVec;
};
//�v���C���[�ȊO�̃X�s�[�h�Ǘ��\����
struct SpeedMove {
	float NowSpeedMul, SpeedUp,MaxSpeed,StopSpeed;
};
//�T�E���h�p�J�����\����
struct SoundCamera {
	D3DXVECTOR3 CamPos, CamLook, CamHead;
};
//���b�V���̃T�C�Y
struct SizePos {
	D3DXVECTOR3 Big, Small;
};
//�T�E���h�\����
struct SoundCol {
	LPDIRECTSOUNDBUFFER8 Sound;
	LPDIRECTSOUND3DBUFFER8 Sound3D;
};
//�N�H�[�^�j�I���A�j���[�V����
struct QuaAnimeC {
	D3DXMATRIX NowMat, StartMat, EndMat;
	float NowAnime, AnimeFrame;
};
//�|���S���p�N�H�[�^�j�I��
struct PolQuaAni
{
	QuaAnimeC Qac;
	//�����x
	int Alpha,AlphaMax;
	float PolSizeNow, PolSizeMax,PolSizeSmall;
};
//�R�̃��b�V��
struct XFILE3 {
	XFILE Mesh1;
	XFILE Mesh2;
	XFILE Mesh3;
};
//�R�̃��b�V��
struct XFILE3B {
	XFILE DrawMesh;//�\���p���f��
	XFILE ColModMesh;//����p���f��
	XFILE DeadMesh;//����p���f��
};
//�p�[�c�p�N���X
struct PARTS {
	BASE3D Base;//��b
	XFILE3B Mesh;//���f��
	int MeshDrawFlg;//���b�V���̐؂�ւ�
	bool JudgFlg;//���C���肷�邩�ǂ���
	bool MoveFlg;//�������ǂ���
	int GunFlg;//�e�Ƃ�������
	SizePos SPos;//����p�̃��b�V���̍L��
	int MeshNo;//���b�V���̎��
	bool HpLinkFlg;//�J�[��Hp�̋��L
	bool PolFlg;//�|���S��Flg
};
//�p�[�c�p�N���X
struct PARTSBASE {
	float AngX, AngY, AngZ;//��]�p
	D3DXVECTOR3 TransPos, ScalPos;//�ړ��A�g��p
	int MeshNo;//���b�V�����
	int MeshDrawFlg;
	bool JudgFlg;//���C���肷�邩�ǂ���
	bool MoveFlg;//�������ǂ���
	int GunFlg;//�e�Ƃ�������
	bool ReverseFlg;//���]
	int MeshPartsNo;//���b�V���p�[�c�̎��
};
struct PARTSBASEINT {
	float AngX, AngY, AngZ;//��]�p
	D3DXVECTOR3 TransPos, ScalPos;//�ړ��A�g��p
	int MeshNo;//���b�V�����
	int MeshDrawFlg;
	int JudgFlg;//���C���肷�邩�ǂ���
	int MoveFlg;//�������ǂ���
	int GunFlg;//�e�Ƃ�������
	int ReverseFlg;//���]
	int MeshPartsNo;//���b�V���p�[�c�̎��
};
struct ObjectParts {
	BASE3D Base;
	D3DXMATRIX SuperMat;
};
//�o���b�g�p
struct BULLETRAYJUDG {
	D3DXVECTOR3 MoveVec;//�Ԃ̈ړ���
	D3DXVECTOR3 RayPos;//���C�����������ʒu
	bool JudgRayFlg;//���C������������
};

struct QUAMAT {
	D3DXMATRIX RotXMat, RotYMat;
};
//�G�̏e��]�p
struct GUNAI {
	BASE3D NowBase;
	//��]�N�H�[�^�j�I��
	QUAMAT Start, End;
	float NowAnime, AnimeFrame;
	//�e�̓�����Flg
	bool GunMoveFlg;

	//���C����t���O
	bool RayJudgFlg;

	//���C������������
	int RayCountNow,RayCountInit;

	//�_�����W
	D3DXVECTOR3 TragetPos;

	//���ː�
	int BulletNum;

	//����Flg
	bool BulletFlg;

	//���ˌ�̔��˃^�C�~���O
	int BulletCount;

	//���ˌ�̋x�e
	int GunCount;

	//�S�Ă̍H���I��
	bool EndFlg;

	//�����t���s��
	D3DXMATRIX ConnectMat;

	//AIFlg
	bool AIFlg;

	//��]�I��Flg
	bool GunMoveEndFlg;

	//���C�̒���
	float RayDis;
};

//�v���C���[�̎ԑ̏��
struct BODYDATA {
	int CarBodyNo;
	int TireNo;
	int StandNo;
	int GunNo;
};
//�v���C���[�̎ԑ̏��
struct BODYDATAFLG {
	bool CarBodyBulletFlg;
	bool CarBodyAttackFlg;
	bool TireBulletFlg;
};
//�ԑ̏��
struct BODYDATACar {
	BODYDATA Body;
	D3DXVECTOR3 ScalPos;
	int MaxHp;
	BODYDATAFLG JudgFlg;//�����蔻��̃_���[�W����Flg
	int EnemyNo;
};
//�e�̕\�����
struct GUNDRAWNOS {
	int GunNo;
	int BulletNo;
	int MuzFlaNo;
	int LaserNo;
};
//�e�̏��
struct GUNDATA {
	BASE3D Base;
	XFILE Mesh;
	//���[�U�[�n�_�ƏI�_
	D3DXVECTOR3 LaserPos_Start,LaserPos_End;
	//���[�U�[����ƃ��[�U�[����̋���
	bool HitRayFlg, JudgRayFlg;
	//���[�U�[�̒���
	float LaserSize;
	//�\���̏��ۊ�
	GUNDRAWNOS DrawNo;
};
struct Object3DGun {
	float AngX, AngY, AngZ;
	D3DXVECTOR3 TransPos, ScalPos;
	bool DrawFlg;
};
//�e�̏��������
struct GUNINITDATA {
	GUNDRAWNOS DrawNo;//�\�����
	CHARABASE  CharaBase;//hp�̃Z�b�g
	float LaserSize;//���C�̒���
	Object3DGun InitGun;
	
};
struct GETGUNDATA {
	int TexNo;
	int MeshNo;
	D3DXVECTOR3 MeshScalPos;
	int PolNum;
	float PolSize;
	int InitCountMax;
	D3DXMATRIX Mat;
	float Speed;
};
//�e����p
struct BULLETJUDGDATA {
	int Type;
	unsigned int JudgNo1;
	unsigned int JudgNo2;
	unsigned int JudgNo3;
	float SamllDis;//���C�̍ŏ��̒����ۊ�
};
//���C����
struct RAYDATA {
	D3DXMATRIX Mat;
	D3DXVECTOR3 Ray;
};
struct S_ENEMYGUNDATA {
	GUNDRAWNOS DrawNo;
	Object3DGun Gun;
	CHARABASE Hp;
	D3DXVECTOR3 TargetPos;
	int NowPhase;
	QUAMAT NowRot;
	D3DXMATRIX StandMat,TransMat;
	//���C
	bool RayJudgFlg, RayHitFlg;
	float RayDis;
	//���˃t���O
	bool BulletFlg;
	bool LaserFlg;
};
struct S_ENEMYPARTSDATA
{

};
struct S_ENEMYBODYDATA {
	BODYDATA Body;
	D3DXVECTOR3 ScalPos;
	float GroundHeight;
	CHARABASE CharaBase;
};

struct S_TEXPOS {
	int x;
	int y;
};

//#endif // !Struct_H