#pragma once
#include<d3dx9.h>

#ifndef Countdown_H
#define Countdown_H


class Cou{
private:
	int num;
	int start,stop,update;
	//���Ɓ����f
	bool updo;
	//=�̔��f
	bool epu;
protected:
public:
	Cou() {};
	Cou(int Start,int Stop,int countdown_i,bool stopbig,bool iko)
	{
		num =start= Start;
		stop = Stop;
		update = countdown_i;
		//stopbig��true�������灃
		updo = stopbig;
		//iko��true�������灁
		epu = iko;
	};
	~Cou() {};
	//��������������Ȃ���false
	bool CouJudge() {
		if (updo == true) {
			if (epu == true) {
				if (num <= stop) {
					return true;
				}
			}
			else {
				if (num < stop) {
					return true;
				}
			}
		}
		else {
			if (epu == true) {
				if (num >= stop) {
					return true;
				}
			}
			else {
				if (num > stop) {
					return true;
				}
			}
		}
		return false;
	};
	bool CouUpd(){
		num += update;
		return true;
	};
	int GetNum() {
		return num;
	}
	void SetNum(int i) {
		num = i;
	}
};

#endif // !Countdown_H