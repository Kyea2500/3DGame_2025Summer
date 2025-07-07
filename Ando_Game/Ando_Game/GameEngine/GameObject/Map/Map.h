#pragma once
#include <DxLib.h>
#include"../Base/GameObject.h"
#include <memory>
class Map : public GameObject
{
private:
	int m_mapHandle; // マップのモデルハンドル
	std::shared_ptr<Transform> m_transform; // マップの変形情報を保持するTransformオブジェクト

public:
	Map();
	~Map();
	void Init();
	void End();
	void SetModel(int modelHandle) { m_mapHandle = modelHandle; }
	void Update();
	void Draw();


};

