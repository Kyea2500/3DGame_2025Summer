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
	// カメラとプレイヤーの位置は一定の距離を保つ
	// 奥に行けばカメラも追従して奥に行き、
	// 手前に動けばカメラも引いて追従する
	VECTOR playerPos = m_pPlayer->GetPos(); // プレイヤーの位置を取得
	m_transform->SetPosition(VGet(playerPos.x + k_CameraPosX, playerPos.y + k_CameraPosY, playerPos.z + k_CameraPosZ)); // カメラの位置をプレイヤーの位置に設定

	


	// カメラの角度を更新
	m_sinParam = std::sin(m_horizontalAngle / k_Horizontal);
	m_cosParam = std::cos(m_horizontalAngle / k_Horizontal);
	// 垂直角度の制限
	if (m_verticalAngle > k_Vertical)
	{
		m_verticalAngle = k_Vertical; // 垂直角度が上限を超えた場合は上限に設定
	}
	else if (m_verticalAngle < -k_Vertical)
	{
		m_verticalAngle = -k_Vertical; // 垂直角度が下限を超えた場合は下限に設定
	}
	// カメラの位置を計算
	VECTOR cameraPos;
	cameraPos.x = m_transform->GetPosition().x + m_cosParam * std::cos(m_verticalAngle) * 1000.0f; // カメラのX位置
	cameraPos.y = m_transform->GetPosition().y + m_sinParam * std::cos(m_verticalAngle) * 1000.0f; // カメラのY位置
	cameraPos.z = m_transform->GetPosition().z + std::sin(m_verticalAngle) * 1000.0f; // カメラのZ位置


	// カメラの位置を更新
	SetCameraPositionAndTarget_UpVecY(m_transform->GetPosition(), m_target);
}