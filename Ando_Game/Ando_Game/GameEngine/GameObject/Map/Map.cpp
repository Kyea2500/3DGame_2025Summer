#include "Map.h"

Map::Map() : m_mapHandle(-1),
m_transform(std::make_shared<Transform>())
{
}

Map::~Map()
{
}

void Map::Init()
{
	m_transform->GetPosition() = VGet(0.0f, 0.0f, 0.0f); // 初期位置を設定
	m_transform->GetScale() = VGet(1.0f, 1.0f, 1.0f); // 初期スケールを設定
	m_transform->GetRotation() = VGet(0.0f, 0.0f, 0.0f); // 初期回転を設定
}

void Map::End()
{
}

void Map::Update()
{
}

void Map::Draw()
{
}
