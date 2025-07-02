#include "Camera.h"
#include "../../Parts/Transform/transform.h"
#include"../../GameObject/Player/Player.h"
#include <cmath>
#include"../../InputDevice/Pad/Pad.h"

namespace
{
	// �J�����̋߂��Ɖ����̋���
	constexpr float k_Near = 1.0f;
	constexpr float k_Far = 10000.0f;

	// �J�����̐����p�x�͈̔�
	constexpr float k_Horizontal = 180.0f * DX_PI_F;
	// �J�����̐����p�x�͈̔�
	constexpr float k_Vertical = 90.0f * DX_PI_F;
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
	m_target = VGet(0,0,0); // �����_�����_�ɐݒ�
	m_transform->SetPosition(VGet(
		m_target.x + 1000.0f * m_sinParam,
		m_target.y + 500.0f * std::sin(m_verticalAngle / k_Vertical),
		m_target.z + 1000.0f * m_cosParam));
	m_horizontalAngle = 0.0f;
	m_verticalAngle = 0.0f;
	m_sinParam = std::sin(m_horizontalAngle / k_Horizontal);
	m_cosParam = std::cos(m_horizontalAngle / k_Horizontal);
}

void Camera::Update()
{
	// �J�����̈ʒu���X�V
	m_transform->SetPosition(VGet(
		m_target.x + 1000.0f * m_sinParam,
		m_target.y + 500.0f * std::sin(m_verticalAngle / k_Vertical),
		m_target.z + 1000.0f * m_cosParam));
	// �J�����̒����_��ݒ�
	SetCameraPositionAndTarget_UpVecY(
		m_transform->GetPosition(),
		m_target);

	// �J�����̊p�x���X�V
	m_sinParam = std::sin(m_horizontalAngle / k_Horizontal);
	m_cosParam = std::cos(m_horizontalAngle / k_Horizontal);
}