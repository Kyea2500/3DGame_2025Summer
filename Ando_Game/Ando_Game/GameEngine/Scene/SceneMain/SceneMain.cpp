#include "SceneMain.h"
#include "DxLib.h"
#include "../../GameObject/Player/Player.h"
#include "../../InputDevice/Camera/Camera.h"
#include"../../Parts/Transform/transform.h"
#include"../../GameObject/Map/Map.h"



SceneMain::SceneMain()
	:m_playerHandle(-1), // プレイヤーのハンドルを初期化 
	m_mapHandle(-1), // マップのハンドルを初期化
	m_pPlayer(nullptr), // プレイヤーのポインタを初期化
	m_pEnemy(nullptr),    // 敵のポインタを初期化
	m_pCamera(nullptr), // カメラのポインタを初期化
	m_pMap(nullptr) // マップのポインタを初期化
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	// モデルを読み込む
	m_playerHandle = MV1LoadModel("data/model/Player.mv1");
	m_mapHandle = MV1LoadModel("data/model/Map.mv1");

	// プレイヤーの初期化
	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetModel(m_playerHandle); // プレイヤーのモデルハンドルを設定
	m_pPlayer->Init();
	// 敵の初期化
	// m_pEnemy = std::make_shared<enemy>();
	// m_pEnemy->SetModel(m_enemyHandle); // 敵のモデルハンドルを設定
	// m_pEnemy->Init(); // 敵の初期化
	//Transform transform; // Transformオブジェクトを作成

	// カメラの初期化
	m_pCamera=std::make_shared<Camera>();
	m_pCamera->Init(); // カメラの初期化

	// マップの初期化
	m_pMap = std::make_shared<Map>();
	m_pMap->SetModel(m_mapHandle); // マップのモデルハンドルを設定
	m_pMap->Init(); // マップの初期化

}

void SceneMain::End()
{
	MV1DeleteModel(m_playerHandle); // プレイヤーのモデルを削除
	MV1DeleteModel(m_mapHandle); // マップのモデルを削除
	
}

void SceneMain::Update()
{
	// プレイヤーの更新処理
	m_pPlayer->Update(); // プレイヤーの更新
	// playerの足元に地形があるか
	
	// プレイヤーの位置をカメラの注視点に設定
	m_pCamera->SetTarget(m_pPlayer->GetPos()); // カメラの注視点をプレイヤーの位置に設定
	// カメラの更新処理
	m_pCamera->Update(); // カメラの更新
	
	// 敵の更新処理
	// m_pEnemy->Update(); // 敵の更新（必要ならコメントアウトを外す）
	// マップの更新処理
	m_pMap->Update(); // マップの更新
}

void SceneMain::Draw()
{
	// プレイヤーの描画処理
	m_pPlayer->Draw();
	// 敵の描画処理
	// m_pEnemy->Draw(); // 敵の描画（必要ならコメントアウトを外す）
	// マップの描画処理
	m_pMap->Draw(); // マップの描画


}