#include "DxLib.h"
#include"GameEngine/InputDevice/Game.h"
#include"GameEngine/Scene/SceneMain/SceneMain.h"


namespace
{
	constexpr int MaxTime = 16667;
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// フルスクリーンではなく、ウィンドウモードで開くようにする
	ChangeWindowMode(Game::kDefaultWindowMode);
	SetWindowText("<Untitle>");
	// 画面サイズ
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);



	std::shared_ptr<SceneMain> Scene = std::make_shared<SceneMain>();	// シーンのインスタンスを作成
	Scene->Init();




	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// ゲームループ
	while (ProcessMessage() == 0)
	{
		// ループが始まった時間を覚えておく
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面をクリアに
		ClearDrawScreen();

		// ここにゲームの処理を書く
		Scene->Update();		// シーンの更新処理
		Scene->Draw();		// シーンの描画処理
		



		// 画面の切り替わりを待つ必要がある
		ScreenFlip();
		//FPS(Frame Per Second)60に固定


		// escキーで終了(いったん終了)
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		while (GetNowHiPerformanceCount() - time< MaxTime)
		{
		}

	}

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理
	Scene->End();			// シーンの終了処理

	return 0;				// ソフトの終了 
}