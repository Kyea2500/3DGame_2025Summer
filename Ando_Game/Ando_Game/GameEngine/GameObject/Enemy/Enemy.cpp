#include "Enemy.h"

namespace
{
	// 敵の当たり判定半径
	constexpr float kColRadius = 64.0f; // 敵の当たり判定半径
	// 敵の当たり判定の色
	constexpr int kEnemyColor = 16; // 敵の当たり判定の色
	// 敵の移動速度
	constexpr float kEnemySpeed = 10.0f; // 敵の移動速度
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
	// でもとりあえずは向きなど考慮せずに、プレイヤーの方向へ移動してほしい

	if ((m_transform->GetPosition().x < m_playerPos.x) || (m_transform->GetPosition().x > m_playerPos.x))
	{
		// プレイヤーの位置に向かって移動
		if (m_transform->GetPosition().x < m_playerPos.x)
		{
			m_transform->SetPositionX(m_transform->GetPosition().x + kEnemySpeed * 0.1f); // プレイヤーの方向へ移動
		}
		else if (m_transform->GetPosition().x > m_playerPos.x)
		{
			m_transform->SetPositionX(m_transform->GetPosition().x - kEnemySpeed * 0.1f); // プレイヤーの方向へ移動
		}
	}
	if ((m_transform->GetPosition().z < m_playerPos.z) || (m_transform->GetPosition().z > m_playerPos.z))
	{
		// プレイヤーの位置に向かって移動
		if (m_transform->GetPosition().z < m_playerPos.z)
		{
			m_transform->SetPositionZ(m_transform->GetPosition().z + kEnemySpeed * 0.1f); // プレイヤーの方向へ移動
		}
		else if (m_transform->GetPosition().z > m_playerPos.z)
		{
			m_transform->SetPositionZ(m_transform->GetPosition().z - kEnemySpeed * 0.1f); // プレイヤーの方向へ移動
		}
	}
	//めためたについてくようになった
	// とは言えこれでは早すぎるため少しだけ早さを下げる
	// …っと言いたいところだが、敵をプレイヤーの方向に向く処理を入れるため、一旦後回しにする
	// 今回は例の通り、プレイヤーの位置に敵の向きを合わせる処理をする
	// とはいえX軸のみである
	// そのため、敵の向きはプレイヤーの位置に合わせてX軸のみを向くようにする
	// プレイヤーの位置＝敵の正面にしたい
		
	MV1SetPosition(EnemyHandle, m_transform->GetPosition()); // 敵の位置を更新 
}

void Enemy::Draw()
{// 敵のモデルを描画
	
	MV1DrawModel(EnemyHandle);

	DrawSphere3D(
		GetColPos(),
		GetColRadius(),
		kEnemyColor,
		0xff00ff,
		0xff00ff,
		false);
	
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

