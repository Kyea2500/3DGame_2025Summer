#include "Enemy.h"

namespace
{
	// “G‚Ì“–‚½‚è”»’è”¼Œa
	constexpr float kColRadius = 50.0f; // “G‚Ì“–‚½‚è”»’è”¼Œa
	// “G‚Ì“–‚½‚è”»’è‚ÌF
	constexpr int kEnemyColor = 16; // “G‚Ì“–‚½‚è”»’è‚ÌF
	// “G‚ÌˆÚ“®‘¬“x
	constexpr float kEnemySpeed = 30.0f; // “G‚ÌˆÚ“®‘¬“x
}

Enemy::Enemy() : m_modelHandle(-1),
m_transform(std::make_shared<Transform>())
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// “G‚Ìƒ‚ƒfƒ‹‚ğ“Ç‚İ‚Ş
	m_modelHandle = MV1LoadModel("../../../../model/enemy.mv1");
	m_transform->SetPosition({ 0.f, 0.f, 0.f }); // ‰ŠúˆÊ’u‚ğİ’è
	m_transform->SetRotation({ 0.f, 0.f, 0.f }); // ‰Šú‰ñ“]‚ğİ’è
}

void Enemy::End()
{
}

void Enemy::Update()
{
	// “G‚ÍƒvƒŒƒCƒ„[‚Ì•ûŒü‚ÖˆÚ“®‚µA‘Ì‚ÌŒü‚«‚àƒvƒŒƒCƒ„[‚Ì‚¢‚é•ûŒü‚ğŒü‚­‚æ‚¤‚É‚µ‚½‚¢
	if (m_modelHandle != -1)
	{
		MV1SetPosition(m_modelHandle, m_transform->GetPosition()); // “G‚ÌˆÊ’u‚ğXV
		MV1SetRotationXYZ(m_modelHandle, m_transform->GetRotation()); // “G‚Ì‰ñ“]‚ğXV
	}
	else
	{
		m_transform->SetPosition({ 15.0f, 0.0f, 12.0f }); // ƒ‚ƒfƒ‹‚ª‚È‚¢ê‡‚Í‰ŠúˆÊ’u‚É–ß‚·
		m_transform->SetRotation({ 0.f, 0.f, 0.f }); // ƒ‚ƒfƒ‹‚ª‚È‚¢ê‡‚Í‰Šú‰ñ“]‚É–ß‚·
	}

	DrawSphere3D(
		GetColPos(),
		GetColRadius(),
		kEnemyColor,
		0xff00ff,
		0xff00ff,
		false);
}

void Enemy::Draw()
{// “G‚Ìƒ‚ƒfƒ‹‚ğ•`‰æ
	if (m_modelHandle != -1)
	{
		MV1DrawModel(m_modelHandle);
	}
	else
	{
		DrawSphere3D(m_transform->GetPosition(), 50.0f,7.0f,GetColor(0,255,0), GetColor(0, 255, 0), TRUE); // ƒ‚ƒfƒ‹‚ª‚È‚¢ê‡‚Í‹…‘Ì‚ğ•`‰æ
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

