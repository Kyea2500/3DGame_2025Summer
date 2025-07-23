#include "Enemy.h"

namespace
{
	// “G‚Ì“–‚½‚è”»’è”¼Œa
	constexpr float kColRadius = 64.0f; // “G‚Ì“–‚½‚è”»’è”¼Œa
	// “G‚Ì“–‚½‚è”»’è‚ÌF
	constexpr int kEnemyColor = 16; // “G‚Ì“–‚½‚è”»’è‚ÌF
	// “G‚ÌˆÚ“®‘¬“x
	constexpr float kEnemySpeed = 30.0f; // “G‚ÌˆÚ“®‘¬“x
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
	// “G‚Ìƒ‚ƒfƒ‹‚ğ“Ç‚İ‚Ş
	m_transform->SetPosition({ 0.f, 0.f, 0.f }); // ‰ŠúˆÊ’u‚ğİ’è
	m_transform->SetRotation({ 0.f, 0.f, 0.f }); // ‰Šú‰ñ“]‚ğİ’è
}

void Enemy::End()
{
}

void Enemy::Update()
{
	// “G‚ÍƒvƒŒƒCƒ„[‚Ì•ûŒü‚ÖˆÚ“®‚µA‘Ì‚ÌŒü‚«‚àƒvƒŒƒCƒ„[‚Ì‚¢‚é•ûŒü‚ğŒü‚­‚æ‚¤‚É‚µ‚½‚¢
	if (EnemyHandle != -1)
	{
		MV1SetPosition(EnemyHandle, m_transform->GetPosition()); // “G‚ÌˆÊ’u‚ğXV
		MV1SetRotationXYZ(EnemyHandle, m_transform->GetRotation()); // “G‚Ì‰ñ“]‚ğXV
	}
	else
	{
		m_transform->SetPosition({ 15.0f, 0.0f, 12.0f }); // ƒ‚ƒfƒ‹‚ª‚È‚¢ê‡‚Í‰ŠúˆÊ’u‚É–ß‚·
		m_transform->SetRotation({ 0.f, 0.f, 0.f }); // ƒ‚ƒfƒ‹‚ª‚È‚¢ê‡‚Í‰Šú‰ñ“]‚É–ß‚·
	}

	
}

void Enemy::Draw()
{// “G‚Ìƒ‚ƒfƒ‹‚ğ•`‰æ
	
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

