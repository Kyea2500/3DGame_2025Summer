#include "SceneTitle.h"
#include "DxLib.h"
#include"../../InputDevice/Pad/Pad.h"
namespace
{
	constexpr int kHandleinit = -1;
	constexpr int kMoveVec = 6;
	constexpr int kMaxPos = 1190;
	constexpr int kTextPosY = 100;
	constexpr int kColor = 0xffffff;
}

SceneTitle::SceneTitle():m_titleHandle(kHandleinit),
m_textPosX(0),
m_textVec(kMoveVec)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
}

void SceneTitle::End()
{
}

SceneManager::SceneKind SceneTitle::Update()
{
	m_textPosX += m_textVec;
	if (m_textPosX < 0)
	{
		m_textPosX = 0;
		m_textVec = kMoveVec;
	}
	if (m_textPosX > kMaxPos)
	{
		m_textPosX = kMaxPos;
		m_textVec = -kMoveVec;
	}

	 	// タイトルシーンの更新処理
	if (PadInput::IsPress(PAD_INPUT_1))
	{
		return SceneManager::SceneKind::kSceneMain;
	}
	return SceneManager::SceneKind::kSceneTitle;
}

void SceneTitle::Draw()
{
	// タイトルシーンの描画処理
	// ここでは特に何もしないが、必要に応じて描画処理を追加することができる
	ClearDrawScreen(); // 裏画面をクリア
	DrawString(m_textPosX, kTextPosY, "Title Scene", kColor); // タイトルテキストを描画
	ScreenFlip(); // 裏画面を表画面に切り替える
}
