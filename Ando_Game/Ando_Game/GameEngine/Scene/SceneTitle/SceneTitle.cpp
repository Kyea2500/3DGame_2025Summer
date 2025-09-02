#include "SceneTitle.h"
#include "DxLib.h"
#include"../../InputDevice/Pad/Pad.h"
#include"../../InputDevice/Game.h"
namespace
{
	constexpr int kHandleinit = -1;
	constexpr int kMoveVec = 6;
	constexpr int kMaxPos = 1190;
	constexpr int kTextPosY = 100;
	constexpr int kColor = 0xffffff;

	// 各種計算および数値
	constexpr int Half = 2;
	constexpr int InitialGraph = -1;
	constexpr int FontSize = 32;
	constexpr float magnification = 0.6f;

	constexpr int kBGMHandleInit = -1;
}

SceneTitle::SceneTitle():m_titleHandle(kHandleinit),
m_textPosX(0),
m_textVec(kMoveVec),
m_BGMHandle(kBGMHandleInit),
m_tapSoundHandle(kBGMHandleInit)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	m_titleHandle = LoadGraph("../Ando_Game/data/Model/Title.png"); // タイトルのモデルを読み込み
	m_textPosX = 0; // テキストの初期X位置
	m_textVec = kMoveVec; // テキストの移動速度
	m_BGMHandle=LoadSoundMem("../Ando_Game/data/Sound/maou_bgm_piano28.mp3"); // BGMをメモリにロード
	PlaySoundMem(m_BGMHandle, DX_PLAYTYPE_LOOP); // BGMをループ再生
	m_tapSoundHandle = LoadSoundMem("../Ando_Game/data/Sound/jamp.wav"); // タップ音をメモリにロード
}

void SceneTitle::End()
{
	DeleteGraph(m_titleHandle); // タイトルのモデルを削除
// BGMの停止
	StopSoundFile(); // BGMを停止
}

SceneManager::SceneKind SceneTitle::Update()
{
	//Titleで待機中には背景でBGMをループ再生
	//PlaySoundFile("../Ando_Game/data/Sound/maou_bgm_piano28.mp3", DX_PLAYTYPE_LOOP); // BGMをループ再生
	// こちらも同じく重たい。
	//　どうすれば解消するのか模索中

	// こうすればいける？
	// 重さ的には解決したが、音は相変わらず聞こえない。
	// 原因はおそらく綴りミスか、参照ミスをしているか、バグっているのかのどれか
	// 原因を突き止め次第、修正する



	// テキストの移動処理
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
		// スタートボタンが押されたら音を鳴らしてからメインシーンに切り替える
		PlaySoundMem(m_tapSoundHandle, DX_PLAYTYPE_BACK); // タップ音を再生
		return SceneManager::SceneKind::kSceneMain;
	}
	return SceneManager::SceneKind::kSceneTitle;
}

void SceneTitle::Draw()
{
	// タイトルシーンの描画処理
	ClearDrawScreen(); // 裏画面をクリア
	DrawString(m_textPosX, kTextPosY, "Title Scene", kColor); // タイトルテキストを描画
	DrawRotaGraph(Game::kScreenWidth / Half, Game::kScreenHeight / Half,
		magnification, 0,
		m_titleHandle, true, false);
	//　タイトル画面に張る予定の画像が一生出力されない
	// まさかの死んだ後に表示されることが判明。理由がマジでわかんない

	ScreenFlip(); // 裏画面を表画面に切り替える
}
