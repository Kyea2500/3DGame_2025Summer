#include "SceneMain.h"
#include "DxLib.h"
#include "../../GameObject/Player/Player.h"
#include "../../InputDevice/Camera/Camera.h"
#include"../../Parts/Transform/transform.h"
#include"../../GameObject/Map/Map.h"
#include "../../GameObject/Enemy/Enemy.h"


SceneMain::SceneMain()
	:m_playerHandle(-1),// プレイヤーのハンドルを初期化 
	m_enemyHandle(-1),	// 敵のハンドルを初期化
	m_mapHandle(-1),	// マップのハンドルを初期化
	m_pPlayer(nullptr), // プレイヤーのポインタを初期化
	m_pEnemy(nullptr),	// 敵のポインタを初期化
	m_pCamera(nullptr), // カメラのポインタを初期化
	m_pMap(nullptr)		// マップのポインタを初期化
{
}

SceneMain::~SceneMain()
{
}

void SceneMain::Init()
{
	// モデルを読み込む
	m_playerHandle =MV1LoadModel("../../Ando_Game/data/Model/player.mv1"); // プレイヤーのモデルを読み込み


	// プレイヤーの初期化
	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetModel(m_playerHandle); // プレイヤーのモデルハンドルを設定
	m_pPlayer->Init();
	// 敵の初期化
	 m_pEnemy = std::make_shared<Enemy>();
	 m_pEnemy->SetModel(m_enemyHandle); // 敵のモデルハンドルを設定
	 m_pEnemy->Init(); // 敵の初期化
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
	 MV1DeleteModel(m_enemyHandle); // 敵のモデルを削除（必要ならコメントアウトを外す）
	 m_pPlayer->Final(); // プレイヤーの終了処理
	 m_pEnemy->End(); // 敵の終了処理

}

void SceneMain::Update()
{
	// マップの更新処理
	m_pMap->Update(); // マップの更新
	// プレイヤーの更新処理
	m_pPlayer->Update(); // プレイヤーの更新
	// playerの足元に地形があるか
	
	// プレイヤーの位置をカメラの注視点に設定
	m_pCamera->SetTarget(m_pPlayer->GetPos()); // カメラの注視点をプレイヤーの位置に設定
	// カメラの位置をプレイヤーの位置に設定
	m_pCamera->SetHAngle(m_pPlayer->GetPos().x); // カメラの水平角度をプレイヤーのX座標に設定
	m_pCamera->SetVAngle(m_pPlayer->GetPos().y);
	// カメラの更新処理
	m_pCamera->Update(); // カメラの更新
	
	// 敵のプレイヤーの位置情報を取得
	m_pEnemy->SetPlayer(m_pPlayer->GetPos());
	// 敵の更新処理
	 m_pEnemy->Update(); // 敵の更新


}

void SceneMain::Draw()
{
	m_pMap->Draw(); // マップの描画
	// プレイヤーの描画処理
	m_pPlayer->Draw();
	// 敵の描画処理
	 m_pEnemy->Draw(); // 敵の描画
	// マップの描画処理

}