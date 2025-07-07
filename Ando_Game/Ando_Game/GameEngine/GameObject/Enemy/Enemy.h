#pragma once
#include <memory>
#include"../Base/GameObject.h"
class Player; // �O���錾
class Enemy : public GameObject
{
private:
	int m_modelHandle; // �G�̃��f���n���h��
	std::shared_ptr<Transform> m_transform; // �G�̕ό`����ێ�����Transform�I�u�W�F�N�g
	std::shared_ptr<Velocity> m_velocity; // �G�̑��x��ێ�����Velocity�I�u�W�F�N�g
	// �v���C���[�̃|�C���^
	std::shared_ptr<Player> m_pPlayer; // �v���C���[�̃|�C���^
	// �v���C���[�̈ʒu���擾���邽�߂̕ϐ�
	VECTOR m_playerPos; // �v���C���[�̈ʒu
public:
	Enemy();
	~Enemy();
	void Init();
	void End();
	void SetModel(int modelHandle) { m_modelHandle = modelHandle; }
	void Update();
	void Draw();
	VECTOR GetColPos() const; // �����蔻��̈ʒu���擾
	float GetColRadius() const; // �����蔻��̔��a���擾
	float GetColRadiusSign() const; // ���D�̓����蔻�蔼�a���擾

public:
	// �G���v���C���[�̈ʒu�܂œˌ��ł���悤�ɁA
	// �v���C���[�̈ʒu���擾����
	void SetPlayer(const VECTOR& _Player){m_playerPos = _Player;}
	VECTOR GetPlayer() const { return m_playerPos; } // �v���C���[�̈ʒu���擾
};

