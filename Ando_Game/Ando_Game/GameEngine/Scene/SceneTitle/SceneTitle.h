#pragma once
#include"../Manager/SceneManager.h"
#include <memory>
class SceneTitle
{
public:
	SceneTitle();
	~SceneTitle();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	int m_titleHandle; // タイトルのモデルハンドル
	int m_textPosX;
	int m_textVec;
};