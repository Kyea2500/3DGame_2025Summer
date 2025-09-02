#include "Map.h"

namespace
{
	// グリッドのサイズ
	constexpr int kGridSize = 100;
	// グリッドの範囲
	constexpr int kGridRange = 1200;
	// 縦グリッドの色
	constexpr int kGridColorZ = 0xff0000; // 赤色
	// 横グリッドの色
	constexpr int kGridColorX = 0x0000ff; // 青色
	
	constexpr float PositionX = 8.0f;
	constexpr float PositionY = 8.0f;
	constexpr float PositionZ = 8.0f;

	constexpr float ScaleY = -795.0f;
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
	m_transform->SetPosition(VGet(PositionX, PositionY, PositionZ)); // 初期位置を設定
	m_transform->Setscale(VGet(0.0f, ScaleY, 0.0f)); // 初期スケールを設定
}

void Map::End()
{
}

void Map::Update()
{	
	// マップの位置を更新
	MV1SetPosition(m_mapHandle, m_transform->GetPosition());
	// マップの回転を更新
	// マップのスケールを更新
	MV1SetScale(m_mapHandle, m_transform->GetScale());


	// マップのモデルを更新
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
bool Map::IsGround()
{
	// グリッド線上は地面として扱う(trueにする)
	for (int z = -kGridRange; z <= kGridRange; z += kGridSize)
		{
		for (int x = -kGridRange; x <= kGridRange; x += kGridSize)
		{
			if (m_transform->GetPosition().x == x && m_transform->GetPosition().z == z)
			{
				return true;
			}
		}
	}
	return false;
}
