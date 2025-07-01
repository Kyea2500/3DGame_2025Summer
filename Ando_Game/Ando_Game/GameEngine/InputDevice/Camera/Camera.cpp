#include "Camera.h"
#include "../../Parts/Transform/transform.h"
#include <cmath>
#include"../../InputDevice/InputManager/InputManager.h"

namespace
{
	// �J�����̋߂��Ɖ����̋���
	constexpr float k_Near = 1.0f;
	constexpr float k_Far = 10000.0f;
}
Camera::Camera(std::shared_ptr<Transform>& _transform)
	: m_transform(_transform)
	, m_target(VGet(0,0,0))
	, m_sinParam(0.0f)
	, m_cosParam(0.0f)
	, m_horizontalAngle(0.0f)
	, m_verticalAngle(0.0f)
	
{
}

void Camera::Init()
{
	// �J�����̈ʒu�ƌ�����ݒ�
	
	m_target = VGet(0.0f, 0.0f, 0.0f); // �����_�����_�ɐݒ�
	m_horizontalAngle = 0.0f;
	m_verticalAngle = 0.0f;
	m_sinParam = std::sin(m_horizontalAngle / 180.0f * DX_PI_F);
	m_cosParam = std::cos(m_horizontalAngle / 180.0f * DX_PI_F);
}

void Camera::Update()
{
	//// ���̓f�o�C�X����̓��͂��擾
	//auto joyPad = InputManager::GetInstance().GetJoyPad();

	//m_horizontalAngle -= joyPad->GetRightStick().X() * 4.5f;
	//m_verticalAngle += joyPad->GetRightStick().Y() * 4.5f;
}