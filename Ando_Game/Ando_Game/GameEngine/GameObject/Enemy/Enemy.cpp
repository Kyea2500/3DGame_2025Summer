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
	// �G�̃��f����ǂݍ���
	m_modelHandle = MV1LoadModel("../../../../model/enemy.mv1");
	m_transform->SetPosition({ 0.f, 0.f, 0.f }); // �����ʒu��ݒ�
	m_transform->SetRotation({ 0.f, 0.f, 0.f }); // ������]��ݒ�
}

void Enemy::End()
{
}

void Enemy::Update()
{
	// �G�̓v���C���[�̕����ֈړ����A�̂̌������v���C���[�̂�������������悤�ɂ�����
	if (m_modelHandle != -1)
	{
		MV1SetPosition(m_modelHandle, m_transform->GetPosition()); // �G�̈ʒu���X�V
		MV1SetRotationXYZ(m_modelHandle, m_transform->GetRotation()); // �G�̉�]���X�V
	}
	else
	{
		m_transform->SetPosition({ 0.f, 0.f, 0.f }); // ���f�����Ȃ��ꍇ�͏����ʒu�ɖ߂�
		m_transform->SetRotation({ 0.f, 0.f, 0.f }); // ���f�����Ȃ��ꍇ�͏�����]�ɖ߂�
	}

}

void Enemy::Draw()
{// �G�̃��f����`��
	if (m_modelHandle != -1)
	{
		MV1DrawModel(m_modelHandle);
	}
	else
	{
		DrawSphere3D(m_transform->GetPosition(), 50.0f,7.0f,GetColor(255,0,0), GetColor(255, 0, 0), TRUE); // ���f�����Ȃ��ꍇ�͋��̂�`��
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
