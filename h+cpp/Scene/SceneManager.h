#pragma once
#pragma once
#include"SceneBase.h"
class SceneManager
{
private:
	SceneBase *nowScene;//���A���s���Ă���V�[��
	SceneBase *Scene;
public:
	SceneManager();
	~SceneManager();
	void NowScene(void);
	void changeScene(SceneBase *NewScene);
};
