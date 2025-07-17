#include "SceneTitle.h"
#include "DxLib.h"
#include"../../InputDevice/Pad/Pad.h"
namespace
{
	constexpr int MoveVec = 4;
	constexpr int MaxPos = 300;
}

SceneTitle::SceneTitle()
	: m_titleHandle(-1) // タイトルのモデルハンドルを初期化
	, m_transform(std::make_shared<Transform>()) // タイトルの変形情報を保持するTransformオブジェクトを初期化
	, m_velocity(std::make_shared<Velocity>()) // タイトルの速度情報を保持するVelocityオブジェクトを初期化
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{// タイトルシーンの初期化処理
	m_transform->SetPositionX(0);
	m_velocity->SetVelocityX(MoveVec); // タイトルのY方向の速度を設定
}

void SceneTitle::End()
{
}

SceneManager::SceneKind SceneTitle::Update()
{
    // 修正: VECTOR型からfloat型への変換を行うために、GetPositionX()の戻り値を適切に処理する  
    float currentPositionX = m_transform->GetPosition().x; // GetPosition()でVECTOR型を取得し、x成分を使用
	float newPositionX = currentPositionX + m_velocity->GetVelocityX(); // 位置を更新  
	m_transform->SetPositionX(newPositionX); // 更新された位置を設定  

	if (currentPositionX < 0)
	{
		m_transform->SetPositionX(0); // タイトルの位置を0に設定  
		m_velocity->SetVelocityX(MoveVec); // タイトルの速度を正の方向に設定  
	}
	if (currentPositionX > MaxPos)
	{
		m_transform->SetPositionX(MaxPos);
		m_velocity->SetVelocityX(-MoveVec);
	}

	// ここでは特に何もしないが、必要に応じて更新処理を追加することができる
	if (PadInput::IsPress(PAD_INPUT_1))
	{
		return SceneManager::SceneKind::kSceneMain;
	}
	// 気持ち的にはタイトルを動かしてもいいかもしれないが…
	return SceneManager::SceneKind::kSceneTitle;
}

void SceneTitle::Draw()
{
	// タイトルシーンの描画処理
	// ここでは特に何もしないが、必要に応じて描画処理を追加することができる
	ClearDrawScreen(); // 裏画面をクリア
	DrawString(m_transform->GetPosition().x, 100, "Title Scene", GetColor(255, 255, 255)); // タイトルテキストを描画
	ScreenFlip(); // 裏画面を表画面に切り替える
}
