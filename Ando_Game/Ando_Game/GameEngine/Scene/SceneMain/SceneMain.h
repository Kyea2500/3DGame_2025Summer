#pragma once
#include <memory>
class Player;
class enemy;
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
	int m_mapHandle; // �}�b�v�̃��f���n���h��
	//int m_enemyHandle; // �G�̃��f���n���h��

	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<enemy> m_pEnemy;
	std::shared_ptr<Camera> m_pCamera; // �J�����̃|�C���^
	std::shared_ptr<Map> m_pMap; // �}�b�v�̃|�C���^
};

