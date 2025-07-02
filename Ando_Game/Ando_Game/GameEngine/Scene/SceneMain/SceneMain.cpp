#include "SceneMain.h"
#include "DxLib.h"
#include "../../GameObject/Player/Player.h"
#include "../../InputDevice/Camera/Camera.h"
#include"../../Parts/Transform/transform.h"


namespace
{
	// グリッドのサイズ
	constexpr int kGridSize = 100;
	// グリッドの範囲
	constexpr int kGridRange = 500;
	// 縦グリッドの色
	constexpr int kGridColorZ = 0xff0000; // 赤色
	// 横グリッドの色
	constexpr int kGridColorX = 0x0000ff; // 青色
}

SceneMain::SceneMain()
	:m_playerHandle(-1), // プレイヤーのハンドルを初期化 
	m_pPlayer(nullptr), // プレイヤーのポインタを初期化
	m_pEnemy(nullptr),    // 敵のポインタを初期化
	m_pCamera(nullptr) // カメラのポインタを初期化
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	// モデルを読み込む
	m_playerHandle = MV1LoadModel("Ando_Game/data/model/player2.mv1");
	// m_enemyHandle = MV1LoadModel("data/model/Enemy.mv1"); // 敵のモデルを読み込む（必要ならコメントアウトを外す）

	// プレイヤーの初期化
	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetModel(m_playerHandle); // モデルハンドルを設定
	m_pPlayer->Init();
	// 敵の初期化
	// m_pEnemy = std::make_shared<enemy>();
	// m_pEnemy->SetModel(m_enemyHandle); // 敵のモデルハンドルを設定
	// m_pEnemy->Init(); // 敵の初期化
	Transform transform; // Transformオブジェクトを作成

	// カメラの初期化
	m_pCamera=std::make_shared<Camera>();
	m_pCamera->Init(); // カメラの初期化


}

void SceneMain::End()
{
	MV1DeleteModel(m_playerHandle);
	//	MV1DeleteModel(m_enemyHandle);
}

void SceneMain::Update()
{
	// プレイヤーの更新処理
	m_pPlayer->Update();
	// カメラの更新処理
	m_pCamera->Update(); // カメラの更新
	
	// 敵の更新処理
	// m_pEnemy->Update(); // 敵の更新（必要ならコメントアウトを外す）
}

void SceneMain::Draw()
{
	DrawGrid();
	// プレイヤーの描画処理
	m_pPlayer->Draw();
	// 敵の描画処理
	// m_pEnemy->Draw(); // 敵の描画（必要ならコメントアウトを外す）


}

void SceneMain::DrawGrid() const
{
	for (int z = -kGridRange; z <= kGridRange; z += kGridSize)
	{
		DrawLine3D(VGet(-kGridRange, 0, z), VGet(kGridRange, 0, z), 0xff0000);
	}
	for (int x = -kGridRange; x <= kGridRange; x += kGridSize)
	{
		DrawLine3D(VGet(x, 0, -kGridRange), VGet(x, 0, kGridRange), 0x0000ff);
	}
}
