#include "SceneMiss.h"

namespace
{
	// 残機の初期値
	const int kInitialRemainingLives = 3;
}
SceneMiss::SceneMiss() : Remaining(kInitialRemainingLives) // 残機の初期値を設定
{
}

SceneMiss::~SceneMiss()
{
}

void SceneMiss::Init()
{// 残機の初期化
	Remaining = kInitialRemainingLives;
	// ここで必要な初期化処理を行う
	// 例えば、残機の表示や背景の設定など
}

void SceneMiss::End()
{
}

void SceneMiss::Update()
{
	// 残機の更新処理

}

void SceneMiss::Draw()
{
}
