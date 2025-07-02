#include "Player.h"
#include"../../InputDevice/Pad/Pad.h"

namespace
{
	// プレイヤーの移動速度
	constexpr float kPlayerSpeed = 15.0f;

	// プレイヤーの当たり判定半径
	constexpr float kColRadius = 85.0f;

	// プレイヤーが立札を読むための当たり判定半径
	constexpr float kColRadiusSign = 200.0f; // 立札の当たり判定半径

	// ジャンプの回数
	constexpr int kMaxJumpCount = 2; // 最大ジャンプ回数

	// プレイヤーの当たり判定
	constexpr int kPlayerColor = 16;
	// プレイヤーの重力
	constexpr float kGravity = -0.5f; // 重力の値

	// プレイヤーのジャンプ力
	constexpr float kJumpPower = 22.0f;

	// プレイヤーの移動加速度
	constexpr float kMoveAccel = 2.50f;
	// 移動減速率
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
	m_velocity->SetVelocityX(m_velocity->GetVelocityX() * kMoveDecRate);// X軸の速度を減速
		// m_vec.z *= kMoveDecRate;
	m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() * kMoveDecRate); // Z軸の速度を減速

	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, DX_PI_F, 0.0f));
	// 当たり判定の描画
	DrawSphere3D(
		GetColPos(),
		GetColRadius(),
		kPlayerColor,
		0xffffff,
		0xffffff,
		false);
	// 立札を読むための当たり判定
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
		m_velocity->SetVelocityY(m_velocity->GetVelocityY() + kGravity); // 重力を適用
	}
	else
	{
		/*m_vec.y = 0.0f;
		m_pos.y = 0.0f;*/
		m_velocity->SetVelocityY(0.0f); // ジャンプしていない場合はY軸の速度を0にする
		m_transform->SetPositionY(0.0f); // 地面に戻す
	}
	PadInput::Update(); // パッドの入力を更新
	// ジャンプの更新
	UpdateJump();
	// 移動の更新
	UpdateMove();

	// プレイヤーの位置を更新
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
	// プレイヤーのモデルを描画する
	MV1DrawModel(m_modelHandle);
}

void Player::Final()
{
}

void Player::UpdateJump()
{
	if (PadInput::IsTrigger(PAD_INPUT_1)) // ジャンプボタンが押されたら
	{
		if (m_isJump < kMaxJumpCount) // 1段目または2段目のジャンプ中でない場合
		{
			m_isJump++; // ジャンプ状態を更新
			m_isSky = true; // 空中にいる状態にする
			//m_vec.y = kJumpPower; // ジャンプ力を適用
			m_velocity->SetVelocityY(kJumpPower); // ジャンプ力を適用
		}

	}
	else if (!isJumping()) // ジャンプ中でない場合
	{
		m_isJump = 0; // ジャンプ状態をリセット
		m_isSky = false; // 空中状態を解除
		//m_vec.y += kGravity; // 重力を適用
		//m_velocity->SetVelocityY(m_velocity->GetVelocityY() + kGravity); // 重力を適用
		m_velocity->SetVelocityY(0.0f);
		m_transform->SetPositionY(0.0f); // 地面に戻す
	}
}

void Player::UpdateMove()
{
	// プレイヤーの移動処理
	m_isMove = false; // 移動中フラグを初期化

	if (!m_isMove)
	{
		//m_vec.x = 0.0f; // 水平方向の移動ベクトルをリセット
		m_velocity->SetVelocityX(0.0f); // X軸の速度をリセット
		//m_vec.z = 0.0f; // 垂直方向の移動ベクトルをリセット
		m_velocity->SetVelocityZ(0.0f); // Z軸の速度をリセット
	}

	// 上下左右の入力に応じて移動ベクトルを更新
	if (PadInput::IsPress(PAD_INPUT_UP))
	{
		// 上に移動
		//m_vec.z += speed;
		m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() + speed);
		m_isMove = true; // 移動中にする
	}
	if (PadInput::IsPress(PAD_INPUT_DOWN))
	{
		// 下に移動
	//	m_vec.z -= speed;
		m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() - speed);
		m_isMove = true; // 移動中にする
	}
	if (PadInput::IsPress(PAD_INPUT_LEFT))
	{
		// 左に移動
	//	m_vec.x -= speed;
		m_velocity->SetVelocityX(m_velocity->GetVelocityX() - speed);
		m_isMove = true; // 移動中にする
	}
	if (PadInput::IsPress(PAD_INPUT_RIGHT))
	{
		// 右に移動
//		m_vec.x += speed;
		m_velocity->SetVelocityX(m_velocity->GetVelocityX() + speed);
		m_isMove = true; // 移動中にする
	}

	//	移動の正規化
	// 移動ベクトルがゼロでない場合に正規化を行う
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


	// 位置を更新
	/*m_pos = VecAdd(m_pos, m_vec);*/
	m_transform->SetPosition(VAdd(m_transform->GetPosition(), m_velocity->GetVelocity()));
}

bool Player::isJumping() const
{
	return  (m_transform->GetPosition().y > 0.0f);
}
