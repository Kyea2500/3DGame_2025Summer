#pragma once
#include <memory>
#include"../Base/GameObject.h"
class Player; // 前方宣言
class Enemy : public GameObject
{
private:
	int m_modelHandle; // 敵のモデルハンドル
	std::shared_ptr<Transform> m_transform; // 敵の変形情報を保持するTransformオブジェクト
	std::shared_ptr<Velocity> m_velocity; // 敵の速度を保持するVelocityオブジェクト
	// プレイヤーのポインタ
	std::shared_ptr<Player> m_pPlayer; // プレイヤーのポインタ
	// プレイヤーの位置を取得するための変数
	VECTOR m_playerPos; // プレイヤーの位置
public:
	Enemy();
	~Enemy();
	void Init();
	void End();
	void SetModel(int modelHandle) { m_modelHandle = modelHandle; }
	void Update();
	void Draw();
	VECTOR GetColPos() const; // 当たり判定の位置を取得
	float GetColRadius() const; // 当たり判定の半径を取得
	float GetColRadiusSign() const; // 立札の当たり判定半径を取得

public:
	// 敵がプレイヤーの位置まで突撃できるように、
	// プレイヤーの位置を取得する
	void SetPlayer(const VECTOR& _Player){m_playerPos = _Player;}
	VECTOR GetPlayer() const { return m_playerPos; } // プレイヤーの位置を取得
};

