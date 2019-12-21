#pragma once
#include<d3dx9.h>

#ifndef Const_H
#define Const_H


const int TNUM = 4;
const int TITLE_NUM = 2;
const int GNUM = 8;//bullet��smoke

//���b�V���i���o�[
const int MeshTireNo = 2;
const int MeshStandNo = 3;
const int MeshCarPartsNo = 4;



//�Ԃ̃i���o�[
const int CarNo1 = 1;
const int CarNo2 = 2;
const int CarNo101 = 101;
const int CarNo201 = 201;

//�e
const int GunNo1 = 1;
const int GunNo2 = 2;
const int GunNo3 = 3;

enum{TireNo1=1,TireNo101=101};
const int TireNo201 = 201;
enum{StandNo1=1,StandNo101=101};
const int StandNo201 = 201;

//�e����
const int co_PlayerCar = 1;
const int co_PlayerParts = 2;
const int co_PlayerGun = 3;
const int co_EnemyCar = 4;
const int co_EnemyParts = 5;
const int co_EnemyGun = 6;
const int co_Ground = 7;
const int co_Wall = 8;

#endif // !Const_H