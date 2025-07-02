#include "Player.h"
#include"../../InputDevice/Pad/Pad.h"

namespace
{
	// �v���C���[�̈ړ����x
	constexpr float kPlayerSpeed = 15.0f;

	// �v���C���[�̓����蔻�蔼�a
	constexpr float kColRadius = 85.0f;

	// �v���C���[�����D��ǂނ��߂̓����蔻�蔼�a
	constexpr float kColRadiusSign = 200.0f; // ���D�̓����蔻�蔼�a

	// �W�����v�̉�
	constexpr int kMaxJumpCount = 2; // �ő�W�����v��

	// �v���C���[�̓����蔻��
	constexpr int kPlayerColor = 16;
	// �v���C���[�̏d��
	constexpr float kGravity = -0.5f; // �d�͂̒l

	// �v���C���[�̃W�����v��
	constexpr float kJumpPower = 22.0f;

	// �v���C���[�̈ړ������x
	constexpr float kMoveAccel = 2.50f;
	// �ړ�������
	constexpr float kMoveDecRate = 0.80f;

}

Player::Player() :speed(kPlayerSpeed),
m_transform(std::make_shared<Transform>()),
m_velocity(std::make_shared<Velocity>()),
m_modelHandle(-1),
m_isMoveRight(false),
m_isMoveLeft(false),
m_isMove(false),
m_isJump(0),
m_isSky(false)
{
	
}

void Player::Init()
{
	m_transform->SetPosition({ 0.f, 0.f, 0.f });
	m_velocity->SetVelocity({ 0.f, 0.f, 0.f });
}

void Player::Update()
{
	// m_vec.x *= kMoveDecRate;
	m_velocity->SetVelocityX(m_velocity->GetVelocityX() * kMoveDecRate);// X���̑��x������
		// m_vec.z *= kMoveDecRate;
	m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() * kMoveDecRate); // Z���̑��x������

	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, DX_PI_F, 0.0f));
	// �����蔻��̕`��
	DrawSphere3D(
		GetColPos(),
		GetColRadius(),
		kPlayerColor,
		0xffffff,
		0xffffff,
		false);
	// ���D��ǂނ��߂̓����蔻��
	DrawSphere3D(
		GetColPos(),
		GetColRadiusSign(),
		kPlayerColor,
		0x00ff00,
		0x00ff00,
		false);
	
	if (isJumping())
	{
		/*m_vec.y += kGravity;*/
		m_velocity->SetVelocityY(m_velocity->GetVelocityY() + kGravity); // �d�͂�K�p
	}
	else
	{
		/*m_vec.y = 0.0f;
		m_pos.y = 0.0f;*/
		m_velocity->SetVelocityY(0.0f); // �W�����v���Ă��Ȃ��ꍇ��Y���̑��x��0�ɂ���
		m_transform->SetPositionY(0.0f); // �n�ʂɖ߂�
	}
	PadInput::Update(); // �p�b�h�̓��͂��X�V
	// �W�����v�̍X�V
	UpdateJump();
	// �ړ��̍X�V
	UpdateMove();

	// �v���C���[�̈ʒu���X�V
	MV1SetPosition(m_modelHandle,m_transform->GetPosition());
}

VECTOR Player::GetColPos() const
{
	VECTOR result = m_transform->GetPosition();
	result.y += 160.0f;
	return result;
}

float Player::GetColRadius() const
{
	return  kColRadius;
}

float Player::GetColRadiusSign() const
{
	return kColRadiusSign;
}

void Player::Draw()
{
	// �v���C���[�̃��f����`�悷��
	MV1DrawModel(m_modelHandle);
}

void Player::Final()
{
}

void Player::UpdateJump()
{
	if (PadInput::IsTrigger(PAD_INPUT_1)) // �W�����v�{�^���������ꂽ��
	{
		if (m_isJump < kMaxJumpCount) // 1�i�ڂ܂���2�i�ڂ̃W�����v���łȂ��ꍇ
		{
			m_isJump++; // �W�����v��Ԃ��X�V
			m_isSky = true; // �󒆂ɂ����Ԃɂ���
			//m_vec.y = kJumpPower; // �W�����v�͂�K�p
			m_velocity->SetVelocityY(kJumpPower); // �W�����v�͂�K�p
		}

	}
	else if (!isJumping()) // �W�����v���łȂ��ꍇ
	{
		m_isJump = 0; // �W�����v��Ԃ����Z�b�g
		m_isSky = false; // �󒆏�Ԃ�����
		//m_vec.y += kGravity; // �d�͂�K�p
		//m_velocity->SetVelocityY(m_velocity->GetVelocityY() + kGravity); // �d�͂�K�p
		m_velocity->SetVelocityY(0.0f);
		m_transform->SetPositionY(0.0f); // �n�ʂɖ߂�
	}
}

void Player::UpdateMove()
{
	// �v���C���[�̈ړ�����
	m_isMove = false; // �ړ����t���O��������

	if (!m_isMove)
	{
		//m_vec.x = 0.0f; // ���������̈ړ��x�N�g�������Z�b�g
		m_velocity->SetVelocityX(0.0f); // X���̑��x�����Z�b�g
		//m_vec.z = 0.0f; // ���������̈ړ��x�N�g�������Z�b�g
		m_velocity->SetVelocityZ(0.0f); // Z���̑��x�����Z�b�g
	}

	// �㉺���E�̓��͂ɉ����Ĉړ��x�N�g�����X�V
	if (PadInput::IsPress(PAD_INPUT_UP))
	{
		// ��Ɉړ�
		//m_vec.z += speed;
		m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() + speed);
		m_isMove = true; // �ړ����ɂ���
	}
	if (PadInput::IsPress(PAD_INPUT_DOWN))
	{
		// ���Ɉړ�
	//	m_vec.z -= speed;
		m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() - speed);
		m_isMove = true; // �ړ����ɂ���
	}
	if (PadInput::IsPress(PAD_INPUT_LEFT))
	{
		// ���Ɉړ�
	//	m_vec.x -= speed;
		m_velocity->SetVelocityX(m_velocity->GetVelocityX() - speed);
		m_isMove = true; // �ړ����ɂ���
	}
	if (PadInput::IsPress(PAD_INPUT_RIGHT))
	{
		// �E�Ɉړ�
//		m_vec.x += speed;
		m_velocity->SetVelocityX(m_velocity->GetVelocityX() + speed);
		m_isMove = true; // �ړ����ɂ���
	}

	//	�ړ��̐��K��
	// �ړ��x�N�g�����[���łȂ��ꍇ�ɐ��K�����s��
	if (m_velocity->GetVelocityX() != 0.0f || m_velocity->GetVelocityZ() != 0.0f)
	{
		/*float length = sqrtf(m_vec.x * m_vec.x + m_vec.z * m_vec.z);*/
		float length = sqrtf(m_velocity->GetVelocityX() * m_velocity->GetVelocityX() +
			m_velocity->GetVelocityZ() * m_velocity->GetVelocityZ());

		if (length > 0.0f)
		{
			/*m_vec.x /= length;*/
			m_velocity->SetVelocityX(m_velocity->GetVelocityX() / length);
			/*m_vec.z /= length;*/
			m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() / length);
		}
	}


	// �ʒu���X�V
	/*m_pos = VecAdd(m_pos, m_vec);*/
	m_transform->SetPosition(VAdd(m_transform->GetPosition(), m_velocity->GetVelocity()));
}

bool Player::isJumping() const
{
	return  (m_transform->GetPosition().y > 0.0f);
}
