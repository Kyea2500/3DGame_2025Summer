#include "Camera.h"
#include "../../Parts/Transform/transform.h"
#include"../../GameObject/Player/Player.h"
#include <cmath>
#include"../../InputDevice/Pad/Pad.h"
#include<memory>

namespace
{
	// カメラの近くと遠くの距離
	constexpr float k_Near = 1.0f;
	constexpr float k_Far = 10000.0f;

	// カメラの水平角度の範囲
	constexpr float k_Horizontal = 180.0f * DX_PI_F;
	// カメラの垂直角度の範囲
	constexpr float k_Vertical = 90.0f * DX_PI_F;

	// カメラの初期注視点X
	constexpr float k_TargetPosX = 0.0f;
	// カメラの初期注視点Y
	constexpr float k_TargetPosY = 100.0f;
	// カメラの初期注視点Z
	constexpr float k_TargetPosZ = 0.0f;

	// カメラの初期位置X
	constexpr float k_CameraPosX = 0.0f;
	// カメラの初期位置Y
	constexpr float k_CameraPosY = 400.0f;
	// カメラの初期位置Z
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
	// カメラの位置と向きを設定
	m_transform = std::make_shared<Transform>();
	m_pPlayer = std::make_shared<Player>(); // プレイヤーのポインタを初期化
	m_target = VGet(k_TargetPosX, k_TargetPosY, k_TargetPosZ); // 注視点を原点に設定
	
	m_transform->SetPosition(VGet(k_CameraPosX, k_CameraPosY, k_CameraPosZ)); // カメラの初期位置を設定
	m_horizontalAngle = 0.0f;
	m_verticalAngle = 0.0f;
	m_sinParam = std::sin(m_horizontalAngle / k_Horizontal);
	m_cosParam = std::cos(m_horizontalAngle / k_Horizontal);
	SetCameraPositionAndTarget_UpVecY(m_transform->GetPosition(), m_target);
	// カメラの近くと遠くの距離を設定
	SetCameraNearFar(k_Near, k_Far);
	// カメラの初期角度を設定
}

void Camera::Update()
{
	// カメラの位置を更新
// 一旦今は書かない

	//playerの位置を注視点に設定したい
	m_target = m_pPlayer->GetPos(); // プレイヤーの位置を注視点に設定


	// カメラの角度を更新
	m_sinParam = std::sin(m_horizontalAngle / k_Horizontal);
	m_cosParam = std::cos(m_horizontalAngle / k_Horizontal);

	// カメラの位置を更新
	SetCameraPositionAndTarget_UpVecY(m_transform->GetPosition(), m_target);
}