#include"SceneManager.h"
SceneManager::SceneManager() {
	nowScene = nullptr;
}
SceneManager::~SceneManager() {
	if (nowScene != nullptr) {
		delete nowScene;
	}
}
void SceneManager::NowScene(void) {
	if (nowScene != nullptr) {
		nowScene->Frame();//���̃V�[�������s
	}
}
void SceneManager::changeScene(SceneBase *NewScene) {
	if (nowScene != nullptr) {
		delete nowScene;
	}
	nowScene = NewScene;
}