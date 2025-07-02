#include "Camera.h"
#include "../../Parts/Transform/transform.h"
#include"../../GameObject/Player/Player.h"
#include <cmath>
#include"../../InputDevice/Pad/Pad.h"
#include<memory>

namespace
{
	// �J�����̋߂��Ɖ����̋���
	constexpr float k_Near = 1.0f;
	constexpr float k_Far = 10000.0f;

	// �J�����̐����p�x�͈̔�
	constexpr float k_Horizontal = 180.0f * DX_PI_F;
	// �J�����̐����p�x�͈̔�
	constexpr float k_Vertical = 90.0f * DX_PI_F;

	// �J�����̏��������_X
	constexpr float k_TargetPosX = 0.0f;
	// �J�����̏��������_Y
	constexpr float k_TargetPosY = 100.0f;
	// �J�����̏��������_Z
	constexpr float k_TargetPosZ = 0.0f;

	// �J�����̏����ʒuX
	constexpr float k_CameraPosX = 0.0f;
	// �J�����̏����ʒuY
	constexpr float k_CameraPosY = 400.0f;
	// �J�����̏����ʒuZ
	constexpr float k_CameraPosZ = -1000.0f;

	



}

Camera::Camera(): m_target(VGet(0,0,0))
	, m_sinParam(0.0f)
	, m_cosParam(0.0f)
	, m_horizontalAngle(0.0f)
	, m_verticalAngle(0.0f)
	
{
}

void Camera::Init()
{
	// �J�����̈ʒu�ƌ�����ݒ�
	m_transform = std::make_shared<Transform>();
	m_pPlayer = std::make_shared<Player>(); // �v���C���[�̃|�C���^��������
	m_target = VGet(k_TargetPosX, k_TargetPosY, k_TargetPosZ); // �����_�����_�ɐݒ�
	
	m_transform->SetPosition(VGet(k_CameraPosX, k_CameraPosY, k_CameraPosZ)); // �J�����̏����ʒu��ݒ�
	m_horizontalAngle = 0.0f;
	m_verticalAngle = 0.0f;
	m_sinParam = std::sin(m_horizontalAngle / k_Horizontal);
	m_cosParam = std::cos(m_horizontalAngle / k_Horizontal);
	SetCameraPositionAndTarget_UpVecY(m_transform->GetPosition(), m_target);
	// �J�����̋߂��Ɖ����̋�����ݒ�
	SetCameraNearFar(k_Near, k_Far);
	// �J�����̏����p�x��ݒ�
}

void Camera::Update()
{
	// �J�����̈ʒu���X�V
// ��U���͏����Ȃ�

	//player�̈ʒu�𒍎��_�ɐݒ肵����
	m_target = m_pPlayer->GetPos(); // �v���C���[�̈ʒu�𒍎��_�ɐݒ�


	// �J�����̊p�x���X�V
	m_sinParam = std::sin(m_horizontalAngle / k_Horizontal);
	m_cosParam = std::cos(m_horizontalAngle / k_Horizontal);

	// �J�����̈ʒu���X�V
	SetCameraPositionAndTarget_UpVecY(m_transform->GetPosition(), m_target);
}