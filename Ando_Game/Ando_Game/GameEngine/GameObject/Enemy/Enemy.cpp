#include "Enemy.h"

Enemy::Enemy() : m_modelHandle(-1),
m_transform(std::make_shared<Transform>())
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// 敵のモデルを読み込む
	m_modelHandle = MV1LoadModel("../../../../model/enemy.mv1");
	m_transform->SetPosition({ 0.f, 0.f, 0.f }); // 初期位置を設定
	m_transform->SetRotation({ 0.f, 0.f, 0.f }); // 初期回転を設定
}

void Enemy::End()
{
}

void Enemy::Update()
{
	// 敵はプレイヤーの方向へ移動し、体の向きもプレイヤーのいる方向を向くようにしたい
	if (m_modelHandle != -1)
	{
		MV1SetPosition(m_modelHandle, m_transform->GetPosition()); // 敵の位置を更新
		MV1SetRotationXYZ(m_modelHandle, m_transform->GetRotation()); // 敵の回転を更新
	}
	else
	{
		m_transform->SetPosition({ 0.f, 0.f, 0.f }); // モデルがない場合は初期位置に戻す
		m_transform->SetRotation({ 0.f, 0.f, 0.f }); // モデルがない場合は初期回転に戻す
	}

}

void Enemy::Draw()
{// 敵のモデルを描画
	if (m_modelHandle != -1)
	{
		MV1DrawModel(m_modelHandle);
	}
	else
	{
		DrawSphere3D(m_transform->GetPosition(), 50.0f,7.0f,GetColor(255,0,0), GetColor(255, 0, 0), TRUE); // モデルがない場合は球体を描画
	}
}

VECTOR Enemy::GetColPos() const
{
	return VECTOR();
}

float Enemy::GetColRadius() const
{
	return 0.0f;
}

float Enemy::GetColRadiusSign() const
{
	return 0.0f;
}
