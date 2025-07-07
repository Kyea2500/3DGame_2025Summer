#pragma once
#include <memory>
class Player;
class Enemy;
class Camera;
class Map;
class SceneMain
{
public:
	SceneMain();
	~SceneMain();
	void Init();
	void End();
	void Update();
	void Draw();

private:
	int m_playerHandle;
	int m_mapHandle; // マップのモデルハンドル
	int m_enemyHandle; // 敵のモデルハンドル

	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Enemy> m_pEnemy;
	std::shared_ptr<Camera> m_pCamera; // カメラのポインタ
	std::shared_ptr<Map> m_pMap; // マップのポインタ
};

