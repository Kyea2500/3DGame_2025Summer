#include "Player.h"
#include"../../InputDevice/Pad/Pad.h"

namespace
{
	// プレイヤーの移動速度
	constexpr float kPlayerNormalSpeed = 40.0f;
	// ダッシュ時の移動速度
	constexpr float kPlayerDashSpeed = 80.0f;

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

	//// プレイヤーの移動加速度
	//constexpr float kMoveAccel = 6.00f;
	// 移動減速率
	constexpr float kMoveDecRate = 0.80f;

}

Player::Player() :speed(0.0f),
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
	// プレイヤーの初期位置を設定
	m_transform->SetPosition(VGet(0.0f, 0.0f, 0.0f));
	// プレイヤーの初期回転を設定
	m_transform->SetRotation(VGet(0.0f, 0.0f, 0.0f));
	// プレイヤーの初期スケールを設定
	m_transform->Setscale(VGet(1.0f, 1.0f, 1.0f));
	
	m_velocity->GetVelocity() = VGet(0.0f, 0.0f, 0.0f); // 初期速度を設定
}

void Player::Update()
{
	// m_vec.x *= kMoveDecRate;
	m_velocity->SetVelocityX(m_velocity->GetVelocityX() * kMoveDecRate);// X軸の速度を減速
		// m_vec.z *= kMoveDecRate;
	m_velocity->SetVelocityZ(m_velocity->GetVelocityZ() * kMoveDecRate); // Z軸の速度を減速


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

	// パッドの入力を更新
	PadInput::Update(); 

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
	result.y += 80.0f;
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

void Player::OnDamage(std::shared_ptr<Enemy> enemy)
{
	// 敵とぶつかった時、ミスになる
	// つまり、プレイヤーが一回死ぬ
	// ここでは、プレイヤーの位置を初期位置に戻す
	m_transform->SetPosition(VGet(0.0f, 0.0f, 0.0f)); // プレイヤーの位置を初期位置に戻す
	// 本音を言うなら残り残機の表示、ロードまでしたい
	// しかし、時間的にも今回はプレイヤーの位置を初期位置に戻すだけにする

}

void Player::Final()
{

}

void Player::UpdateJump()
{
	if (PadInput::IsTrigger(PAD_INPUT_2)) // ジャンプボタンが押されたら
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
	
	// 移動速度を設定
	// 2ボタン(Bボタン)を押している間はダッシュする
	if (PadInput::IsPress(PAD_INPUT_1))
	{
		// ダッシュ中の移動速度
		speed = kPlayerDashSpeed;
	}
	// 2ボタン(Bボタン)を押していない場合は通常の移動速度
	else
	{
		// 通常の移動速度
		speed = kPlayerNormalSpeed;
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
		m_velocity->VectorNormalizeXZ(); // XZ平面での正規化
	}

	// 位置を更新
	/*m_pos = VecAdd(m_pos, m_vec);*/
	m_transform->SetPosition(VAdd(m_transform->GetPosition(), m_velocity->GetVelocity()));
}

bool Player::isJumping() const
{
	return  (m_transform->GetPosition().y > 0.0f);
}
