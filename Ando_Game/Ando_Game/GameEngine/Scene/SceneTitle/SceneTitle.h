#pragma once
#include"../Manager/SceneManager.h"
#include"../../Parts/Transform/transform.h"
#include"../../Parts/Velocity/Velocity.h"
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
	std::shared_ptr<Transform> m_transform; // タイトルの変形情報を保持するTransformオブジェクト
	std::shared_ptr<Velocity> m_velocity; // タイトルの速度情報を保持するVelocityオブジェクト
};