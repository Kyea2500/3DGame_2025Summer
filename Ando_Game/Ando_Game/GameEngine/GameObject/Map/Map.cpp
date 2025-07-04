#include "Map.h"

namespace
{
	// �O���b�h�̃T�C�Y
	constexpr int kGridSize = 100;
	// �O���b�h�͈̔�
	constexpr int kGridRange = 500;
	// �c�O���b�h�̐F
	constexpr int kGridColorZ = 0xff0000; // �ԐF
	// ���O���b�h�̐F
	constexpr int kGridColorX = 0x0000ff; // �F
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
	m_transform->GetPosition() = VGet(0.0f, 0.0f, 0.0f); // �����ʒu��ݒ�
	m_transform->GetRotation() = VGet(0.0f, 0.0f, 0.0f); // ������]��ݒ�
	m_transform->GetScale() = VGet(1.0f, 1.0f, 1.0f); // �����X�P�[����ݒ�
}

void Map::End()
{
}

void Map::Update()
{	
	// �}�b�v�̈ʒu���X�V
	MV1SetPosition(m_mapHandle, m_transform->GetPosition());
	// �}�b�v�̉�]���X�V
	MV1SetRotationXYZ(m_mapHandle, m_transform->GetRotation());
	// �}�b�v�̃X�P�[�����X�V
	MV1SetScale(m_mapHandle, m_transform->GetScale());
}

void Map::Draw()
{
	// �}�b�v�̃��f����`��
	MV1DrawModel(m_mapHandle);
	// ���O���b�h��`��
	for (int z = -kGridRange; z <= kGridRange; z += kGridSize)
	{
		DrawLine3D(VGet(-kGridRange, 0, z), VGet(kGridRange, 0, z), kGridColorZ);
	}
	// �c�O���b�h��`��
	for (int x = -kGridRange; x <= kGridRange; x += kGridSize)
	{
		DrawLine3D(VGet(x, 0, -kGridRange), VGet(x, 0, kGridRange), kGridColorX);
	}
}
