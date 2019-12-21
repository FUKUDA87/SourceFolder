#pragma once
#include<d3dx9.h>
#ifndef KEY_H
#define KEY_H

class Key{
protected:
	bool KeyAllFlg;
public:
	//true�ŃL�[����s�\
	void SetFlg(bool Flg) {
		KeyAllFlg = Flg;
	}
	void Init(void) {
		KeyAllFlg = false;
	}
	Key() { Init(); };
	~Key() {};
	//A�L�[
	bool AKey();
	//A�L�[+KeyFlg
	bool AKeyF();
	//W�L�[
	bool WKey();
	//W�L�[+KeyFlg
	bool WKeyF();
	//S�L�[
	bool SKey();
	//S�L�[+KeyFlg
	bool SKeyF();
	//D�L�[
	bool DKey();
	//D�L�[+KeyFlg
	bool DKeyF();
	//���N���b�N
	bool LClick();
	//���N���b�N+KeyFlg
	bool LClickF();
	//�E�N���b�N
	bool RClick();
	//�E�N���b�N+KeyFlg
	bool RClickF();
	//N�L�[
	bool NKey();
	//N�L�[+KeyFlg
	bool NKeyF();
	//T�L�[
	bool TKey();
	//T�L�[+KeyFlg
	bool TKeyF();
	//C�L�[
	bool CKey();
	//C�L�[+KeyFlg
	bool CKeyF();
	//ENTER�L�[
	bool RETURNKey();
	//ENTER�L�[+KeyFlg
	bool RETURNKeyF();
	//UP�L�[
	bool UPKey();
	//UP�L�[+KeyFlg
	bool UPKeyF();
	//DOWN�L�[
	bool DOWNKey();
	//DOWN�L�[+KeyFlg
	bool DOWNKeyF();
	//LEFT�L�[
	bool LEFTKey();
	//LEFT�L�[+KeyFlg
	bool LEFTKeyF();
	//RIGHT�L�[
	bool RIGHTKey();
	//RIGHT�L�[+KeyFlg
	bool RIGHTKeyF();
	//Z�L�[
	bool ZKey();
	//Z�L�[+KeyFlg
	bool ZKeyF();
	//E�L�[
	bool EKey();
	//E�L�[+KeyFlg
	bool EKeyF();
	//Y�L�[
	bool YKey();
	//Y�L�[+KeyFlg
	bool YKeyF();
};

#endif // !KEY_H

/*�O���[�o���Ő錾
#include"h+cpp/Key.h"
Key *key;
*/
/*cpp�Ő錾
#include"Key.h"

extern Key *key;
*/