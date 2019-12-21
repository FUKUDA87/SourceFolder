#include "Key.h"

//A�L�[�̃Z�b�g
bool Key::AKey(){
	if (GetAsyncKeyState('A') & 0x8000) {
		return true;
	}
	return false;
}
bool Key::AKeyF(){
	static bool KeyFlg=false;
	if (AKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::WKey()
{
	if (GetAsyncKeyState('W') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::WKeyF()
{
	static bool KeyFlg = false;
	if (WKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::SKey()
{
	if (GetAsyncKeyState('S') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::SKeyF()
{
	static bool KeyFlg = false;
	if (SKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::DKey()
{
	if (GetAsyncKeyState('D') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::DKeyF()
{
	static bool KeyFlg = false;
	if (DKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::LClick()
{
	if (KeyAllFlg == false) {
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
			return true;
		}
	}
	return false;
}

bool Key::LClickF()
{
	static bool KeyFlg = false;
	if (LClick() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::RClick()
{
	if (KeyAllFlg == false) {
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
			return true;
		}
	}
	return false;
}

bool Key::RClickF()
{
	static bool KeyFlg = false;
	if (RClick() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::NKey()
{
	if (GetAsyncKeyState('N') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::NKeyF()
{
	static bool KeyFlg = false;
	if (NKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::TKey()
{
	if (GetAsyncKeyState('T') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::TKeyF()
{
	static bool KeyFlg = false;
	if (TKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::CKey()
{
	if (GetAsyncKeyState('C') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::CKeyF()
{
	static bool KeyFlg = false;
	if (CKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::RETURNKey()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
		return true;
	}
	return false;
}

bool Key::RETURNKeyF()
{
	static bool KeyFlg = false;
	if (RETURNKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::UPKey()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return true;
	}
	return false;
}

bool Key::UPKeyF()
{
	static bool KeyFlg = false;
	if (UPKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::DOWNKey()
{
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return true;
	}
	return false;
}

bool Key::DOWNKeyF()
{
	static bool KeyFlg = false;
	if (DOWNKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::LEFTKey()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		return true;
	}
	return false;
}

bool Key::LEFTKeyF()
{
	static bool KeyFlg = false;
	if (LEFTKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::RIGHTKey()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		return true;
	}
	return false;
}

bool Key::RIGHTKeyF()
{
	static bool KeyFlg = false;
	if (RIGHTKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::ZKey()
{
	if (GetAsyncKeyState('Z') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::ZKeyF()
{
	static bool KeyFlg = false;
	if (ZKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::EKey()
{
	if (GetAsyncKeyState('E') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::EKeyF()
{
	static bool KeyFlg = false;
	if (EKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

bool Key::YKey()
{
	if (GetAsyncKeyState('Y') & 0x8000) {
		return true;
	}
	return false;
}

bool Key::YKeyF()
{
	static bool KeyFlg = false;
	if (YKey() == true) {
		if (KeyFlg == false) {
			KeyFlg = true;
			return true;
		}
	}
	else {
		KeyFlg = false;
	}
	return false;
}

