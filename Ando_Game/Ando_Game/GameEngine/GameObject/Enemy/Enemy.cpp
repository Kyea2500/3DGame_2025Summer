#include "Enemy.h"

namespace
{
	// 敵の当たり判定半径
	constexpr float kColRadius = 64.0f; // 敵の当たり判定半径
	// 敵の当たり判定の色
	constexpr int kEnemyColor = 16; // 敵の当たり判定の色
	// 敵の移動速度
	constexpr float kEnemySpeed = 5.0f; // 敵の移動速度
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
	m_transform->SetPosition({ -500.f, 0.f, -500.f }); // 初期位置を設定
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
	
	// 速度の調整完了
	// 続いては向きの調整に移りたい
	// プレイヤーの位置を取得
//	m_playerPos = m_pPlayer->GetTransform()->GetPosition(); // プレイヤーの位置を取得



	MV1SetPosition(EnemyHandle, m_transform->GetPosition()); // 敵の位置を更新 
}

void Enemy::Draw()
{// 敵のモデルを描画
	
	MV1DrawModel(EnemyHandle);

#ifdef _DEBUG
	// デバック状態なら当たり判定を描画
	DrawSphere3D(
		GetColPos(),
		GetColRadius(),
		kEnemyColor,
		0xff00ff,
		0xff00ff,
		false;
#endif // _DEBUG
	
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