#pragma once
#include <DxLib.h>
#include"../Base/GameObject.h"
#include <memory>
class Map : public GameObject
{
private:
	int m_mapHandle; // �}�b�v�̃��f���n���h��
	std::shared_ptr<Transform> m_transform; // �}�b�v�̕ό`����ێ�����Transform�I�u�W�F�N�g

public:
	Map();
	~Map();
	void Init();
	void End();
	void SetModel(int modelHandle) { m_mapHandle = modelHandle; }
	void Update();
	void Draw();


};

