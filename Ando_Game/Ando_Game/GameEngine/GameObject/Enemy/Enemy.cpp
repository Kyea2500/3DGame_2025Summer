#include "Enemy.h"

namespace
{
	// 敵の当たり判定半径
	constexpr float kColRadius = 64.0f; // 敵の当たり判定半径
	// 敵の当たり判定の色
	constexpr int kEnemyColor = 16; // 敵の当たり判定の色
	// 敵の移動速度
	constexpr float kEnemySpeed = 30.0f; // 敵の移動速度
}

Enemy::Enemy() : EnemyHandle(-1),
m_transform(std::make_shared<Transform>())
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// 敵のモデルを読み込む
	m_transform->SetPosition({ 0.f, 0.f, 0.f }); // 初期位置を設定
	m_transform->SetRotation({ 0.f, 0.f, 0.f }); // 初期回転を設定
}

void Enemy::End()
{
}

void Enemy::Update()
{
	// 敵はプレイヤーの方向へ移動し、体の向きもプレイヤーのいる方向を向くようにしたい
	if (EnemyHandle != -1)
	{
		MV1SetPosition(EnemyHandle, m_transform->GetPosition()); // 敵の位置を更新
		MV1SetRotationXYZ(EnemyHandle, m_transform->GetRotation()); // 敵の回転を更新
	}
	else
	{
		m_transform->SetPosition({ 15.0f, 0.0f, 12.0f }); // モデルがない場合は初期位置に戻す
		m_transform->SetRotation({ 0.f, 0.f, 0.f }); // モデルがない場合は初期回転に戻す
	}

	DrawSphere3D(
		GetColPos(),
		GetColRadius(),
		kEnemyColor,
		0xff00ff,
		0xff00ff,
		true);
}

void Enemy::Draw()
{// 敵のモデルを描画
	if (EnemyHandle != -1)
	{
		MV1DrawModel(EnemyHandle);
	}
	else
	{
		DrawSphere3D(m_transform->GetPosition(), 50.0f,7.0f,GetColor(0,255,0), GetColor(0, 255, 0), TRUE); // モデルがない場合は球体を描画
	}
}

VECTOR Enemy::GetColPos() const
{
	VECTOR result = m_transform->GetPosition();
	/*result.y += 160.0f;*/
	return result;
}

float Enemy::GetColRadius() const
{
	return  kColRadius;
}

