#include "SceneTitle.h"
#include "DxLib.h"


SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{// タイトルシーンの初期化処理
	// ここでは特に何もしないが、必要に応じて初期化処理を追加することができる
	SetDrawScreen(DX_SCREEN_BACK); // 描画先を裏画面に設定
	ClearDrawScreen(); // 裏画面をクリア
	DrawString(100, 100, "Title Scene", GetColor(255, 255, 255)); // タイトルテキストを描画
}

void SceneTitle::End()
{
}

void SceneTitle::Update()
{
	// タイトルシーンの更新処理
	// ここでは特に何もしないが、必要に応じて更新処理を追加することができる
	if (CheckHitKey(KEY_INPUT_RETURN)) // Enterキーが押されたら
	{
		// 次のシーンへ遷移する処理を追加することができる
	}
}

void SceneTitle::Draw()
{
	// タイトルシーンの描画処理
	// ここでは特に何もしないが、必要に応じて描画処理を追加することができる
	ClearDrawScreen(); // 裏画面をクリア
	DrawString(100, 100, "Title Scene", GetColor(255, 255, 255)); // タイトルテキストを描画
	ScreenFlip(); // 裏画面を表画面に切り替える
}
