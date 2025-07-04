#include "Map.h"

namespace
{
	// グリッドのサイズ
	constexpr int kGridSize = 100;
	// グリッドの範囲
	constexpr int kGridRange = 500;
	// 縦グリッドの色
	constexpr int kGridColorZ = 0xff0000; // 赤色
	// 横グリッドの色
	constexpr int kGridColorX = 0x0000ff; // 青色
	// 
}


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
	m_transform->GetRotation() = VGet(0.0f, 0.0f, 0.0f); // 初期回転を設定
	m_transform->GetScale() = VGet(1.0f, 1.0f, 1.0f); // 初期スケールを設定
}

void Map::End()
{
}

void Map::Update()
{	
	// マップの位置を更新
	MV1SetPosition(m_mapHandle, m_transform->GetPosition());
	// マップの回転を更新
	MV1SetRotationXYZ(m_mapHandle, m_transform->GetRotation());
	// マップのスケールを更新
	MV1SetScale(m_mapHandle, m_transform->GetScale());
}

void Map::Draw()
{
	// マップのモデルを描画
	MV1DrawModel(m_mapHandle);
	// 横グリッドを描画
	for (int z = -kGridRange; z <= kGridRange; z += kGridSize)
	{
		DrawLine3D(VGet(-kGridRange, 0, z), VGet(kGridRange, 0, z), kGridColorZ);
	}
	// 縦グリッドを描画
	for (int x = -kGridRange; x <= kGridRange; x += kGridSize)
	{
		DrawLine3D(VGet(x, 0, -kGridRange), VGet(x, 0, kGridRange), kGridColorX);
	}
}
