#include "Camera.h"
#include "../../Parts/Transform/transform.h"
#include <cmath>
#include"../../InputDevice/Pad/Pad.h"

namespace
{

	// ƒJƒƒ‰‚Ì‹ß‚­‚Æ‰“‚­‚Ì‹——£
	constexpr float k_Near = 1.0f;
	constexpr float k_Far = 10000.0f;
}
Camera::Camera(std::shared_ptr<Transform>& _transform)
	: m_transform(_transform)
	, m_target(VGet(0, 0, 0))
	, m_sinParam(0.0f)
	, m_cosParam(0.0f)
	, m_horizontalAngle(0.0f)
	, m_verticalAngle(0.0f)
{
}

void Camera::Init()
{
	m_target = VGet(0, 0, 0);
	m_horizontalAngle = 0.0f;
	m_verticalAngle = 0.0f;
	m_sinParam = std::sin(m_horizontalAngle / 180.0f * DX_PI_F);
	m_cosParam = std::cos(m_horizontalAngle / 180.0f * DX_PI_F);
	SetCameraNearFar(k_Near, k_Far);
}

void Camera::Update()
{

}